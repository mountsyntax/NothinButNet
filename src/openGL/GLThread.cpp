/*
 * Copyright (c) 2011-2012 Research In Motion Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "GLThread.h"
#include "bbutil.h"
#include <QDebug>
#include <Math.h>
#include "IGLRenderer.h"

GLThread* GLThread::m_instance = NULL;

GLThread* GLThread::initInstance(int width, int height)
{
    if (!m_instance)
    {
        m_instance = new GLThread(width, height);
    }
    return m_instance;
}

GLThread* GLThread::instance()
{
    if (!m_instance)
    {
        assert(false);  // call initinstance first
        return initInstance(300, 300);
    }
    return m_instance;
}

GLThread::GLThread(int width, int height)
    : m_isReady(false)
    , m_runState(Pause)
    , m_width(width)
    , m_height(height)
    , m_renderer(NULL)
{
    m_isRunning = true;
}

GLThread::~GLThread()
{
}

int GLThread::resize(int width, int height)
{
    bbutil_terminate();

    //Use utility code to initialize EGL for rendering with GL ES 1.1
    if (EXIT_SUCCESS != bbutil_init_egl(m_screen_cxt, GL_ES_1, width, height))
    {
        fprintf(stderr, "bbutil_init_egl failed\n");
        bbutil_terminate();
        screen_destroy_context(m_screen_cxt);
        return 0;
    }

    return EXIT_SUCCESS;
}

int GLThread::initBPS()
{
    //Create a screen context that will be used to create an EGL surface to to receive libscreen events
    screen_create_context(&m_screen_cxt, SCREEN_APPLICATION_CONTEXT);

    //Initialize BPS library
    bps_initialize();

    //Use utility code to initialize EGL for rendering with GL ES 1.1
    if (EXIT_SUCCESS != bbutil_init_egl(m_screen_cxt, GL_ES_1, m_width, m_height))
    {
        fprintf(stderr, "bbutil_init_egl failed\n");
        bbutil_terminate();
        screen_destroy_context(m_screen_cxt);
        return 0;
    }

    //Signal BPS library that navigator and screen events will be requested
    if (BPS_SUCCESS != screen_request_events(m_screen_cxt))
    {
        fprintf(stderr, "screen_request_events failed\n");
        bbutil_terminate();
        screen_destroy_context(m_screen_cxt);
        return 0;
    }

    if (BPS_SUCCESS != navigator_request_events(0))
    {
        fprintf(stderr, "navigator_request_events failed\n");
        bbutil_terminate();
        screen_destroy_context(m_screen_cxt);
        return 0;
    }

    //Signal BPS library that navigator orientation is not to be locked
    if (BPS_SUCCESS != navigator_rotation_lock(false))
    {
        fprintf(stderr, "navigator_rotation_lock failed\n");
        bbutil_terminate();
        screen_destroy_context(m_screen_cxt);
        return 0;
    }

    return EXIT_SUCCESS;
}

void GLThread::run()
{
    if (EXIT_SUCCESS != initBPS())
    {
        return;
    }

    while (m_isRunning)
    {
        //Request and process BPS next available event
        bps_event_t* event = NULL;
        int rc = bps_get_event(&event, 0);
        assert(rc == BPS_SUCCESS);

        if (event)
        {
            int domain = bps_event_get_domain(event);

            if (domain == screen_get_domain())
            {
                if (m_renderer != NULL)
                {
                    m_renderer->screenEvent(event);
                }
            }
            else if ((domain == navigator_get_domain()) && (NAVIGATOR_WINDOW_STATE == bps_event_get_code(event)))
            {
                // starting to render too early will cause the UI not to appear
                // wait until we get a FULLSCREEN event from bps before initializing renderer
                if (!m_isReady)
                {
                    navigator_window_state_t winState = navigator_event_get_window_state(event);
                    if (winState == NAVIGATOR_WINDOW_FULLSCREEN)
                    {
                        m_isReady = true;
                        if (m_renderer)
                        {
                            m_renderer->initialize();
                            m_runState = Run;
                        }
                    }
                }
            }
            else if ((domain == navigator_get_domain()) && (NAVIGATOR_EXIT == bps_event_get_code(event)))
            {
                m_isRunning = false;
            }
        }

        if (m_isReady)
        {
            if (m_runState == Pause)
            {
                qDebug() << "run is paused!";
                m_mutex.lock();
                if (m_renderer)
                {
                    m_renderer->shutdown();
                }
                qDebug() << "m_renderer.wakeAll();";
                m_rendererShutdown.wakeAll();
                m_mutex.unlock();

                m_mutex.lock();
                qDebug() << "m_rendererReady.wait(&m_mutex);";
                m_rendererReady.wait(&m_mutex);
                qDebug() << "m_renderer->initialize();";
                m_renderer->initialize();
                m_runState = Run;
                m_mutex.unlock();
                qDebug() << "run is running freely!";
            }

            m_renderer->render();
        }
    }
    //Stop requesting events from libscreen
    screen_stop_events(m_screen_cxt);

    //Shut down BPS library for this process
    bps_shutdown();

    //Use utility code to terminate EGL setup
    bbutil_terminate();

    //Destroy libscreen context
    screen_destroy_context(m_screen_cxt);
}

void GLThread::previousRenderer()
{
    m_renderStack.pop();
    setRenderer(m_renderStack.top());
}

void GLThread::setRenderer(IGLRenderer* renderer)
{
    // Nothing to do if the cascades is not ready
    if (!m_isReady && m_renderer == NULL)
    {
        qDebug() << "GLThread::setRenderer(). cascades not ready";
        m_renderer = renderer;
        m_renderStack.push(m_renderer);
        return;
    }

    qDebug() << "GLThread::setRenderer() enter";

    // release old renderer if one exists
    if (m_renderer != NULL)
    {
        m_mutex.lock();
        m_runState = Pause;
        qDebug() << "m_rendererShutdown.wait(&m_mutex);";
        m_rendererShutdown.wait(&m_mutex);
        m_mutex.unlock();
        m_renderer = NULL;
    }

    // set new renderer
    if (renderer)
    {
        m_mutex.lock();
        m_renderStack.push(renderer);
        m_renderer = renderer;
        qDebug() << "m_rendererReady.wakeAll()";
        m_rendererReady.wakeAll();
        m_mutex.unlock();
    }
    else
    {
        //remove it from the stack
        m_renderStack.pop();
    }
    qDebug() << "GLThread::setRenderer() exit";
}

screen_context_t GLThread::getContext()
{
    return m_screen_cxt;
}
