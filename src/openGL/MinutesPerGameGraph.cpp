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

#include <bb/cascades/Application>
#include <bb/cascades/CustomControl>
#include <bb/cascades/Container>
#include <bb/cascades/AbsoluteLayout>
#include <bb/cascades/Window>
#include <screen/screen.h>Ê

#include "MinutesPerGameGraph.hpp"
#include "qdebug.h"
#include "GLThread.h"
using namespace bb::cascades;

MinutesPerGameGraph::MinutesPerGameGraph(QObject* parent) : bb::cascades::CustomControl()
{
    Q_UNUSED(parent);

    QObject::connect(this, SIGNAL(creationCompleted()), this, SLOT(onCreationCompleted()));
}

MinutesPerGameGraph::~MinutesPerGameGraph()
{
}

void MinutesPerGameGraph::onWindowAttached(screen_window_t handle, const QString& group, const QString& id)
{
    screen_flush_context(GLThread::instance()->getContext(), SCREEN_WAIT_IDLE);

    m_foreignWindow->setVisible(false);
}

void MinutesPerGameGraph::initGLRenderer()
{
    QObject::connect(m_foreignWindow, SIGNAL(windowAttached(screen_window_t, QString, QString)), this, SLOT(onWindowAttached(screen_window_t, QString, QString)));
    GLThread::instance()->setRenderer(m_renderer);
}

void MinutesPerGameGraph::stopGLRenderer()
{
    GLThread::instance()->setRenderer(NULL);
}


void MinutesPerGameGraph::onCreationCompleted()
{
    setRoot(Container::create().layout(AbsoluteLayout::create()).preferredSize(preferredWidth(), preferredHeight()).add(m_foreignWindow = ForeignWindowControl::create().preferredSize(preferredWidth(), preferredHeight())));

    // Create an instance of OpenGLThread where the window initialization takes place.
    m_renderer = new MinutesPerGameRenderer(bb::cascades::Application::instance()->mainWindow()->groupId(), "mpgGraphThread", preferredWidth(), preferredHeight());
}
