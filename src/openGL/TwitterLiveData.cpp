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

//#include <iostream>
#include "TwitterLiveData.h"

/* Generated C++ static data (don't forget to adjust member signature .hpp .cpp)*/
const char* teamHandles[] =
{
    "@atlanta_hawks",
    "@celtics",
    "@bobcats",
    "@chicagobulls",
    "@cavs",
    "@dallasmavs",
    "@denvernuggets",
    "@detroitpistons",
    "@warriors",
    "@HoustonRockets",
    "@indianapacers",
    "@LAClippers",
    "@lakers",
    "@memgrizz",
    "@MIAMIHEAT",
    "@bucks",
    "@mntimberwolves",
    "@netsbasketball",
    "@hornets",
    "@thenyknicks",
    "@okcthunder",
    "@Orlando_Magic",
    "@sixers",
    "@phoenixsuns",
    "@pdxtrailblazers",
    "@sacramentokings",
    "@spurs",
    "@raptors",
    "@utah_jazz",
    "@washwizards",
};
const float twitterCounts[][240] =
{
    {0, 11, 60, 29, 11, 2, 9, 50, 35, 41, 11, 3, 2, 17, 9, 0, 0, 1, 4, 1, 2, 1, 13, 2, 15, 3, 4, 2, 9, 13, 7, 5, 1, 2, 4, 3, 2, 2, 0, 1, 1, 2, 4, 3, 2, 6, 24, 20, 15, 10, 14, 28, 124, 35, 31, 133, 187, 274, 43, 18, 11, 4, 1, 6, 2, 4, 4, 2, 16, 81, 8, 65, 16, 10, 10, 13, 8, 11, 5, 3, 3, 3, 8, 10, 0, 0, 2, 0, 3, 1, 1, 1, 2, 10, 2, 8, 204, 103, 158, 592, 177, 42, 23, 15, 15, 10, 9, 7, 27, 3, 2, 3, 0, 1, 1, 8, 1, 3, 13, 7, 11, 12, 32, 4, 11, 29, 7, 6, 6, 2, 14, 4, 0, 1, 1, 1, 1, 1, 2, 2, 2, 0, 6, 16, 11, 0, 7, 20, 12, 9, 18, 98, 105, 130, 193, 25, 13, 11, 3, 4, 1, 3, 1, 3, 10, 68, 39, 11, 2, 2, 1, 3, 10, 11, 2, 4, 1, 8, 8, 4, 6, 3, 0, 1, 1, 0, 3, 2, 5, 7, 12, 7, 11, 37, 28, 9, 6, 17, 12, 16, 58, 38, 93, 23, 20, 14, 8, 2, 1, 0, 1, 3, 7, 8, 16, 9, 8, 8, 101, 44, 20, 12, 16, 8, 70, 21, 5, 5, 5, 5, 2, 1, 6, 2, 3, 22, 2, 6, 13, 2},
    {23, 138, 91, 50, 144, 384, 135, 232, 997, 336, 2147, 481, 134, 64, 44, 25, 18, 11, 19, 35, 41, 30, 52, 50, 31, 101, 133, 45, 39, 18, 27, 29, 27, 36, 34, 27, 19, 8, 12, 6, 4, 5, 12, 16, 12, 28, 83, 37, 30, 134, 112, 97, 127, 44, 61, 213, 294, 399, 56, 51, 29, 18, 24, 3, 2, 5, 13, 5, 7, 13, 25, 20, 7, 18, 20, 13, 17, 10, 15, 22, 12, 9, 20, 16, 11, 6, 6, 3, 4, 7, 5, 5, 6, 2, 6, 11, 14, 14, 13, 19, 22, 26, 41, 19, 17, 19, 32, 56, 20, 1, 10, 9, 5, 3, 8, 7, 14, 26, 11, 30, 17, 27, 28, 17, 36, 49, 46, 38, 37, 30, 20, 34, 18, 10, 8, 6, 6, 5, 8, 4, 9, 307, 70, 42, 47, 30, 21, 22, 61, 339, 118, 655, 761, 1190, 1677, 199, 87, 47, 25, 39, 17, 19, 24, 17, 36, 117, 53, 48, 17, 16, 22, 46, 23, 31, 25, 22, 19, 33, 88, 66, 28, 7, 7, 1, 7, 8, 18, 13, 19, 576, 150, 116, 83, 52, 396, 53, 41, 25, 49, 69, 259, 215, 187, 120, 59, 35, 19, 13, 7, 10, 12, 40, 52, 49, 125, 108, 108, 32, 30, 49, 29, 30, 35, 32, 93, 45, 20, 19, 14, 12, 10, 6, 11, 8, 9, 14, 12, 23, 31, 10},
    {4, 22, 9, 11, 7, 18, 27, 46, 37, 314, 34, 18, 11, 6, 2, 1, 3, 0, 2, 1, 3, 28, 22, 12, 9, 10, 3, 9, 4, 6, 7, 13, 6, 8, 16, 12, 2, 0, 0, 8, 4, 0, 3, 1, 3, 2, 12, 5, 6, 7, 13, 7, 10, 19, 40, 66, 127, 137, 26, 15, 12, 3, 0, 0, 0, 1, 2, 4, 2, 0, 10, 7, 7, 1, 4, 1, 3, 1, 1, 4, 1, 8, 4, 3, 2, 1, 2, 0, 1, 0, 0, 1, 2, 1, 1, 7, 7, 7, 4, 18, 15, 8, 64, 46, 40, 24, 13, 15, 5, 4, 3, 0, 6, 1, 3, 3, 6, 4, 16, 9, 4, 5, 5, 7, 12, 24, 7, 42, 68, 95, 39, 25, 4, 5, 1, 2, 1, 1, 1, 2, 1, 11, 20, 45, 7, 14, 7, 6, 2, 7, 5, 3, 11, 4, 12, 7, 0, 2, 0, 0, 1, 4, 1, 1, 2, 2, 3, 12, 2, 9, 2, 10, 13, 8, 11, 25, 107, 161, 36, 23, 12, 5, 3, 2, 1, 2, 4, 6, 6, 18, 53, 43, 48, 21, 20, 35, 35, 119, 55, 138, 161, 187, 984, 151, 50, 41, 16, 13, 5, 5, 12, 6, 18, 15, 16, 18, 28, 27, 12, 12, 2, 6, 15, 7, 4, 4, 4, 1, 0, 3, 2, 1, 0, 2, 0, 0, 3, 1, 2, 0},
    {156, 41, 63, 50, 90, 184, 57, 790, 1125, 434, 107, 92, 63, 38, 27, 19, 7, 9, 17, 18, 33, 90, 227, 77, 62, 83, 66, 69, 208, 75, 233, 935, 2796, 2597, 5238, 1398, 202, 112, 64, 47, 33, 11, 36, 56, 47, 41, 61, 39, 232, 167, 73, 34, 26, 17, 47, 30, 38, 24, 22, 25, 40, 10, 18, 4, 6, 9, 11, 2, 14, 204, 236, 76, 90, 49, 70, 35, 124, 47, 109, 301, 961, 1085, 2259, 358, 123, 75, 44, 21, 12, 17, 17, 25, 15, 23, 43, 82, 56, 28, 33, 24, 21, 24, 32, 31, 22, 22, 29, 32, 18, 9, 9, 14, 16, 6, 10, 10, 23, 30, 24, 60, 25, 34, 18, 369, 100, 62, 42, 85, 31, 37, 24, 64, 20, 23, 14, 9, 8, 4, 5, 6, 8, 22, 24, 13, 14, 17, 19, 21, 47, 23, 37, 31, 47, 32, 1933, 658, 161, 133, 50, 32, 32, 14, 37, 40, 45, 40, 142, 287, 58, 34, 40, 53, 45, 52, 41, 1374, 1331, 1209, 167, 122, 112, 40, 28, 20, 11, 10, 25, 35, 244, 131, 129, 613, 192, 265, 96, 60, 119, 95, 170, 105, 458, 495, 1670, 400, 167, 71, 34, 20, 20, 24, 26, 30, 50, 288, 151, 118, 146, 164, 146, 141, 381, 175, 81, 113, 309, 85, 42, 63, 61, 59, 24, 37, 15, 17, 24, 21, 56, 191, 212, 55},
    {6, 5, 0, 1, 12, 10, 11, 24, 61, 62, 10, 6, 4, 1, 1, 0, 1, 3, 1, 8, 3, 2, 3, 29, 11, 3, 4, 8, 8, 2, 2, 4, 2, 5, 7, 4, 10, 2, 1, 0, 0, 0, 0, 3, 2, 1, 49, 33, 7, 5, 8, 3, 8, 13, 10, 21, 130, 241, 94, 23, 5, 10, 3, 4, 5, 0, 3, 1, 4, 1, 4, 1, 5, 10, 2, 4, 0, 0, 0, 5, 4, 6, 5, 3, 4, 0, 0, 0, 2, 2, 1, 3, 0, 3, 1, 4, 2, 10, 2, 1, 3, 7, 16, 8, 71, 13, 5, 5, 3, 2, 0, 1, 1, 2, 3, 2, 3, 1, 4, 2, 2, 3, 1, 20, 9, 1, 50, 22, 30, 12, 23, 2, 0, 1, 2, 1, 1, 0, 0, 0, 2, 5, 9, 51, 11, 4, 2, 3, 6, 3, 3, 1, 3, 2, 4, 1, 1, 4, 2, 0, 1, 0, 3, 4, 3, 4, 8, 20, 8, 2, 14, 6, 7, 12, 21, 22, 81, 271, 40, 11, 7, 11, 3, 1, 1, 1, 7, 3, 4, 2, 11, 6, 8, 0, 9, 7, 41, 18, 9, 18, 253, 202, 291, 26, 10, 3, 6, 1, 1, 3, 3, 2, 4, 0, 4, 9, 4, 4, 13, 3, 10, 3, 4, 3, 1, 6, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {7, 7, 19, 20, 68, 35, 25, 49, 65, 105, 137, 226, 50, 29, 9, 3, 4, 2, 7, 3, 9, 8, 15, 14, 22, 7, 9, 4, 11, 6, 20, 7, 10, 11, 59, 62, 52, 18, 12, 6, 1, 1, 3, 17, 11, 7, 63, 36, 30, 21, 9, 17, 21, 21, 33, 20, 59, 93, 121, 114, 36, 20, 5, 5, 2, 3, 7, 4, 4, 11, 16, 13, 23, 10, 13, 16, 102, 35, 20, 28, 109, 63, 83, 19, 14, 4, 4, 3, 1, 7, 4, 8, 3, 7, 7, 4, 3, 9, 2, 8, 2, 6, 13, 8, 11, 10, 11, 27, 10, 0, 5, 4, 5, 8, 7, 6, 6, 9, 14, 10, 9, 16, 5, 12, 34, 48, 30, 11, 17, 12, 13, 29, 10, 13, 1, 1, 3, 1, 3, 0, 1, 9, 9, 5, 6, 10, 3, 8, 9, 8, 6, 5, 3, 3, 8, 10, 8, 18, 4, 3, 2, 3, 1, 2, 5, 2, 10, 36, 10, 12, 4, 13, 99, 40, 22, 9, 7, 11, 10, 5, 11, 2, 1, 5, 0, 0, 4, 4, 9, 5, 14, 18, 27, 20, 9, 24, 12, 8, 89, 36, 72, 37, 214, 43, 37, 20, 9, 3, 2, 3, 3, 9, 18, 18, 23, 19, 17, 25, 15, 22, 14, 11, 13, 18, 13, 23, 83, 56, 13, 28, 12, 14, 3, 5, 13, 18, 8, 14, 41, 13},
    {13, 31, 13, 7, 16, 8, 43, 25, 22, 137, 115, 455, 68, 17, 10, 6, 2, 5, 4, 1, 0, 3, 4, 1, 21, 5, 2, 1, 8, 2, 3, 3, 1, 0, 2, 1, 3, 0, 2, 0, 0, 1, 0, 0, 1, 0, 2, 3, 2, 3, 1, 0, 7, 1, 6, 0, 2, 4, 4, 3, 1, 0, 0, 2, 0, 0, 1, 0, 0, 1, 1, 2, 6, 5, 6, 7, 97, 93, 46, 93, 64, 15, 9, 3, 5, 4, 3, 0, 2, 4, 0, 2, 2, 5, 0, 2, 6, 3, 5, 10, 8, 4, 5, 11, 31, 53, 182, 37, 21, 8, 7, 3, 5, 2, 0, 2, 5, 3, 5, 8, 8, 7, 6, 1, 1, 74, 18, 12, 11, 9, 8, 8, 6, 4, 2, 0, 0, 0, 2, 5, 1, 3, 2, 0, 5, 0, 4, 3, 5, 16, 7, 8, 2, 11, 3, 8, 2, 2, 1, 0, 1, 0, 1, 1, 4, 2, 6, 4, 3, 4, 5, 13, 72, 11, 54, 20, 115, 349, 397, 74, 20, 12, 7, 1, 2, 21, 9, 5, 7, 2, 7, 10, 13, 9, 2, 6, 5, 7, 8, 8, 20, 34, 858, 286, 67, 30, 21, 8, 4, 23, 4, 9, 16, 12, 10, 7, 9, 34, 121, 33, 20, 18, 24, 13, 2, 53, 33, 107, 45, 22, 7, 14, 14, 3, 10, 21, 8, 9, 9, 0},
    {2, 5, 5, 8, 2, 5, 3, 14, 18, 15, 1, 1, 1, 3, 3, 1, 1, 2, 1, 2, 5, 6, 5, 0, 6, 3, 2, 8, 6, 5, 0, 9, 56, 26, 90, 17, 9, 5, 3, 1, 1, 1, 1, 2, 1, 5, 1, 7, 2, 12, 3, 2, 11, 5, 2, 1, 3, 8, 7, 2, 3, 0, 0, 0, 0, 2, 0, 0, 1, 1, 2, 0, 5, 6, 2, 2, 0, 0, 1, 0, 2, 1, 1, 0, 1, 1, 0, 0, 0, 1, 2, 1, 0, 5, 0, 1, 1, 3, 18, 2, 3, 13, 32, 82, 126, 14, 5, 8, 2, 3, 0, 2, 2, 0, 1, 1, 3, 9, 2, 1, 4, 13, 4, 4, 8, 8, 4, 8, 10, 21, 5, 3, 1, 2, 0, 0, 1, 0, 1, 2, 1, 3, 7, 4, 4, 1, 1, 2, 2, 2, 2, 3, 2, 1, 1, 0, 0, 1, 0, 2, 0, 0, 2, 3, 2, 4, 2, 5, 12, 2, 3, 5, 0, 3, 0, 1, 3, 1, 3, 1, 3, 0, 0, 0, 0, 0, 1, 0, 2, 5, 3, 5, 9, 8, 5, 4, 9, 8, 12, 22, 122, 211, 186, 34, 17, 16, 5, 0, 0, 0, 2, 4, 10, 11, 7, 4, 4, 5, 3, 14, 4, 4, 3, 1, 1, 2, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 2, 1},
    {13, 186, 38, 19, 94, 29, 33, 24, 62, 78, 80, 90, 261, 201, 40, 10, 14, 6, 5, 6, 4, 7, 5, 8, 3, 7, 4, 3, 10, 4, 3, 2, 5, 2, 5, 6, 4, 3, 1, 3, 0, 0, 12, 0, 0, 0, 0, 1, 2, 6, 0, 9, 10, 5, 5, 11, 6, 61, 58, 68, 19, 4, 1, 2, 1, 1, 0, 1, 1, 4, 5, 0, 2, 16, 5, 5, 2, 2, 3, 1, 77, 91, 45, 6, 4, 4, 2, 1, 1, 3, 0, 0, 0, 5, 2, 1, 3, 7, 6, 5, 3, 2, 12, 33, 24, 100, 14, 9, 10, 10, 2, 5, 0, 1, 1, 0, 4, 1, 0, 2, 41, 23, 18, 9, 4, 8, 9, 6, 6, 3, 4, 0, 1, 1, 0, 0, 1, 0, 0, 4, 2, 0, 5, 5, 1, 5, 5, 19, 20, 139, 15, 7, 12, 22, 63, 68, 188, 48, 18, 12, 2, 2, 2, 2, 3, 5, 6, 10, 4, 9, 5, 3, 24, 38, 9, 4, 12, 18, 4, 6, 3, 2, 2, 4, 2, 2, 2, 4, 2, 1, 4, 2, 27, 28, 6, 14, 132, 100, 27, 22, 20, 35, 87, 228, 364, 332, 111, 63, 31, 15, 9, 14, 8, 21, 15, 13, 8, 13, 6, 36, 19, 10, 5, 13, 4, 3, 8, 1, 1, 1, 2, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {11, 8, 5, 15, 22, 2, 15, 153, 141, 186, 352, 285, 49, 16, 9, 5, 2, 1, 2, 8, 8, 16, 8, 65, 608, 120, 35, 34, 29, 12, 58, 33, 137, 134, 607, 192, 51, 16, 6, 5, 2, 2, 2, 2, 3, 7, 16, 14, 13, 6, 12, 6, 11, 4, 3, 17, 2, 5, 1, 2, 1, 0, 1, 0, 1, 0, 0, 0, 0, 4, 2, 4, 4, 9, 11, 7, 6, 12, 8, 27, 203, 128, 166, 47, 45, 164, 25, 7, 9, 2, 1, 2, 2, 27, 7, 20, 28, 20, 22, 16, 17, 610, 606, 1483, 3129, 270, 69, 52, 43, 27, 21, 15, 7, 5, 9, 7, 1, 11, 21, 9, 14, 11, 9, 3, 4, 6, 5, 2, 3, 5, 6, 0, 4, 1, 0, 1, 1, 0, 0, 0, 2, 2, 3, 7, 5, 7, 3, 0, 6, 3, 0, 2, 4, 1, 7, 7, 7, 2, 2, 34, 18, 6, 5, 0, 6, 3, 5, 4, 6, 2, 76, 30, 34, 48, 38, 206, 39, 15, 9, 20, 8, 3, 0, 1, 3, 0, 1, 3, 2, 4, 4, 5, 28, 26, 24, 15, 30, 17, 35, 31, 96, 92, 235, 112, 131, 40, 5, 10, 1, 1, 2, 3, 8, 5, 6, 0, 6, 45, 19, 10, 13, 6, 6, 3, 5, 0, 2, 2, 2, 3, 0, 0, 0, 5, 0, 0, 0, 1, 7, 2},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {8, 26, 17, 9, 9, 12, 25, 16, 48, 188, 189, 787, 156, 67, 48, 7, 8, 11, 13, 17, 7, 32, 137, 25, 41, 24, 43, 21, 167, 43, 28, 61, 38, 29, 129, 283, 230, 542, 89, 27, 14, 4, 3, 15, 12, 11, 8, 12, 5, 43, 13, 18, 20, 10, 10, 26, 10, 4, 6, 10, 26, 12, 4, 2, 3, 1, 1, 0, 1, 1, 3, 1, 5, 5, 130, 13, 7, 13, 15, 8, 7, 23, 14, 11, 3, 1, 3, 7, 4, 1, 1, 5, 3, 2, 6, 13, 25, 16, 10, 13, 8, 95, 50, 26, 42, 186, 291, 247, 899, 108, 39, 36, 12, 20, 8, 20, 12, 162, 66, 22, 37, 46, 17, 14, 6, 10, 16, 71, 29, 5, 18, 6, 12, 2, 6, 4, 1, 0, 1, 2, 1, 6, 8, 46, 28, 15, 14, 15, 11, 23, 21, 80, 69, 65, 110, 37, 17, 72, 7, 8, 4, 4, 3, 4, 8, 89, 26, 28, 33, 17, 21, 65, 22, 121, 43, 39, 425, 369, 759, 87, 57, 20, 12, 27, 14, 16, 16, 19, 20, 3, 25, 9, 10, 10, 12, 2, 12, 13, 11, 14, 9, 11, 30, 25, 33, 19, 10, 6, 3, 7, 2, 3, 10, 12, 5, 8, 192, 8, 21, 11, 29, 30, 241, 123, 31, 19, 16, 11, 60, 31, 17, 12, 12, 4, 13, 8, 10, 3, 11, 5},
    {64, 245, 167, 94, 172, 69, 160, 96, 124, 159, 322, 638, 842, 532, 148, 46, 41, 25, 32, 46, 57, 39, 56, 73, 86, 63, 50, 567, 131, 62, 52, 50, 53, 62, 54, 67, 68, 66, 28, 15, 11, 10, 12, 61, 24, 26, 27, 38, 60, 373, 348, 81, 156, 74, 83, 94, 137, 1126, 803, 1038, 981, 133, 92, 43, 23, 31, 37, 15, 21, 24, 63, 52, 34, 28, 41, 18, 31, 110, 57, 37, 71, 58, 67, 46, 41, 57, 54, 24, 7, 21, 10, 14, 28, 47, 189, 410, 431, 298, 347, 829, 1993, 1697, 9538, 1201, 533, 901, 1389, 663, 255, 162, 154, 87, 55, 38, 57, 53, 83, 201, 112, 113, 80, 128, 192, 123, 152, 132, 128, 100, 92, 119, 101, 104, 103, 77, 12, 26, 10, 14, 17, 30, 94, 66, 65, 64, 38, 86, 67, 57, 57, 78, 106, 362, 489, 184, 512, 154, 114, 118, 53, 59, 22, 31, 47, 46, 56, 57, 73, 93, 51, 49, 66, 78, 68, 113, 69, 59, 82, 114, 115, 897, 241, 82, 65, 32, 32, 24, 29, 31, 34, 39, 68, 212, 134, 756, 702, 659, 921, 207, 466, 188, 159, 195, 1108, 656, 440, 183, 116, 72, 33, 22, 22, 32, 60, 55, 76, 110, 94, 135, 90, 100, 88, 79, 73, 86, 40, 82, 56, 177, 122, 97, 40, 22, 35, 11, 30, 32, 38, 64, 35, 10},
    {7, 12, 21, 16, 22, 4, 18, 25, 37, 120, 328, 55, 26, 24, 8, 1, 1, 3, 1, 4, 9, 10, 13, 10, 4, 2, 6, 12, 3, 4, 5, 3, 6, 24, 14, 20, 8, 7, 0, 0, 0, 1, 0, 0, 6, 1, 6, 3, 10, 7, 13, 5, 19, 24, 15, 41, 72, 124, 16, 11, 7, 2, 3, 1, 0, 0, 0, 3, 1, 2, 8, 8, 5, 8, 8, 5, 8, 9, 14, 17, 44, 66, 167, 46, 5, 6, 2, 1, 3, 0, 0, 4, 1, 4, 4, 1, 6, 3, 6, 13, 11, 26, 32, 8, 16, 22, 2, 6, 27, 14, 2, 5, 0, 2, 1, 0, 6, 23, 13, 6, 13, 4, 1, 18, 8, 93, 69, 32, 54, 53, 157, 64, 15, 5, 2, 3, 0, 1, 3, 2, 8, 5, 18, 27, 11, 26, 9, 20, 11, 7, 8, 27, 21, 9, 21, 4, 4, 7, 0, 1, 0, 0, 3, 2, 7, 11, 3, 7, 10, 1, 12, 12, 11, 6, 11, 3, 14, 6, 115, 44, 12, 4, 5, 1, 1, 1, 3, 7, 7, 48, 19, 25, 28, 34, 25, 21, 28, 49, 47, 51, 109, 107, 193, 70, 31, 21, 14, 3, 4, 4, 1, 5, 11, 14, 11, 20, 14, 20, 81, 68, 58, 42, 30, 36, 31, 23, 6, 15, 55, 27, 11, 7, 7, 3, 6, 5, 7, 15, 9, 4},
    {88, 102, 58, 101, 98, 63, 541, 890, 1772, 5282, 1038, 227, 142, 104, 54, 37, 31, 26, 31, 43, 63, 734, 347, 190, 158, 113, 105, 185, 293, 236, 419, 1370, 3471, 4179, 11241, 2657, 362, 198, 98, 82, 58, 28, 85, 78, 69, 157, 124, 69, 263, 178, 72, 66, 63, 29, 58, 35, 45, 34, 27, 33, 43, 18, 16, 13, 23, 17, 16, 9, 14, 316, 100, 95, 48, 68, 53, 37, 49, 99, 614, 403, 1569, 3105, 1270, 94, 69, 28, 19, 17, 20, 15, 11, 21, 23, 374, 102, 58, 101, 105, 59, 74, 216, 858, 1118, 1912, 5031, 511, 144, 96, 67, 58, 45, 13, 18, 21, 32, 22, 24, 140, 52, 58, 38, 75, 520, 575, 197, 111, 83, 126, 54, 69, 38, 45, 27, 20, 17, 13, 11, 3, 12, 23, 19, 649, 138, 85, 89, 45, 53, 124, 168, 324, 140, 1061, 2201, 2407, 2227, 218, 84, 81, 41, 35, 14, 13, 35, 20, 49, 52, 293, 82, 64, 36, 49, 191, 46, 57, 44, 65, 39, 52, 74, 78, 44, 31, 10, 9, 9, 10, 26, 25, 25, 224, 63, 62, 96, 217, 105, 77, 66, 82, 55, 568, 594, 1004, 2204, 1056, 277, 100, 58, 38, 28, 34, 44, 64, 121, 95, 96, 277, 205, 103, 104, 168, 197, 219, 143, 375, 225, 161, 75, 114, 69, 102, 36, 18, 41, 29, 35, 54, 89, 1881, 712, 94},
    {6, 5, 7, 6, 5, 2, 21, 25, 49, 212, 15, 19, 4, 8, 3, 1, 0, 1, 2, 1, 4, 3, 9, 8, 7, 3, 6, 6, 9, 13, 24, 33, 97, 161, 28, 20, 15, 3, 4, 2, 2, 0, 0, 2, 4, 5, 5, 5, 2, 4, 5, 13, 11, 13, 6, 9, 4, 6, 0, 2, 1, 3, 2, 0, 0, 0, 0, 1, 0, 3, 6, 15, 12, 17, 4, 0, 6, 10, 5, 20, 32, 54, 149, 51, 15, 13, 1, 3, 5, 0, 0, 15, 10, 6, 4, 112, 20, 3, 1, 3, 7, 4, 3, 5, 5, 8, 3, 3, 1, 1, 2, 2, 1, 1, 0, 4, 8, 8, 3, 21, 32, 13, 18, 7, 13, 10, 20, 35, 36, 36, 158, 43, 12, 16, 1, 2, 2, 0, 11, 7, 11, 10, 3, 9, 0, 7, 3, 4, 9, 16, 10, 4, 12, 17, 9, 19, 5, 2, 5, 0, 2, 0, 2, 0, 4, 2, 9, 11, 5, 5, 9, 15, 21, 10, 16, 27, 43, 53, 125, 62, 41, 9, 5, 6, 5, 1, 3, 0, 3, 3, 10, 11, 3, 1, 9, 11, 8, 14, 4, 17, 18, 12, 34, 2, 2, 9, 3, 1, 0, 1, 2, 0, 0, 1, 0, 5, 4, 3, 5, 0, 3, 7, 3, 1, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0},
    {3, 3, 12, 4, 1, 0, 2, 0, 0, 0, 2, 2, 1, 0, 0, 1, 0, 0, 0, 0, 2, 2, 2, 0, 2, 1, 2, 8, 4, 9, 25, 21, 81, 23, 105, 20, 9, 4, 2, 1, 1, 1, 0, 0, 2, 0, 0, 4, 1, 5, 5, 1, 9, 2, 2, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 2, 31, 5, 1, 1, 2, 0, 0, 0, 6, 2, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 10, 0, 2, 4, 5, 2, 2, 4, 12, 10, 30, 16, 17, 5, 2, 3, 2, 0, 0, 0, 1, 1, 2, 1, 2, 2, 3, 0, 3, 2, 13, 6, 4, 4, 4, 1, 5, 3, 6, 4, 0, 0, 0, 1, 0, 0, 0, 0, 3, 3, 0, 2, 2, 4, 5, 2, 5, 4, 7, 3, 8, 11, 12, 6, 17, 5, 1, 0, 0, 2, 0, 2, 3, 4, 4, 5, 2, 2, 5, 1, 0, 1, 2, 1, 3, 2, 2, 3, 0, 0, 0, 0, 1, 0, 1, 5, 1, 3, 1, 1, 3, 2, 8, 10, 13, 12, 8, 23, 22, 26, 4, 3, 3, 1, 1, 0, 0, 0, 2, 0, 0, 6, 12, 3, 1, 4, 1, 5, 2, 4, 3, 2, 2, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {24, 12, 15, 94, 31, 36, 39, 110, 870, 333, 207, 79, 10, 4, 5, 4, 3, 2, 2, 3, 8, 1, 4, 7, 6, 10, 64, 14, 15, 13, 41, 9, 2, 7, 10, 10, 2, 0, 0, 0, 1, 0, 0, 0, 0, 5, 4, 36, 41, 14, 26, 13, 19, 37, 20, 2, 2, 2, 2, 5, 0, 0, 1, 1, 0, 0, 0, 0, 2, 1, 1, 7, 3, 25, 13, 9, 6, 21, 12, 67, 33, 56, 126, 44, 8, 12, 1, 2, 2, 0, 0, 3, 4, 3, 1, 1, 7, 39, 13, 6, 10, 9, 12, 8, 4, 2, 5, 5, 7, 2, 0, 1, 1, 1, 3, 3, 8, 35, 28, 47, 31, 38, 44, 39, 214, 145, 168, 242, 194, 202, 120, 42, 20, 12, 11, 3, 4, 7, 4, 12, 18, 133, 40, 26, 16, 23, 20, 15, 92, 176, 37, 20, 10, 11, 9, 5, 6, 1, 0, 2, 1, 2, 4, 3, 6, 3, 5, 13, 19, 30, 72, 21, 8, 47, 25, 12, 2, 2, 7, 3, 1, 3, 1, 0, 0, 0, 1, 3, 14, 9, 10, 14, 10, 8, 60, 14, 31, 22, 26, 67, 43, 162, 41, 7, 9, 7, 2, 4, 1, 1, 0, 3, 4, 14, 9, 14, 20, 28, 15, 6, 92, 43, 22, 14, 0, 9, 7, 3, 9, 4, 0, 2, 1, 1, 0, 0, 1, 2, 0, 0},
    {32, 29, 11, 20, 28, 17, 16, 15, 24, 66, 218, 34, 16, 25, 11, 4, 1, 0, 3, 2, 5, 6, 18, 10, 7, 13, 5, 8, 19, 7, 40, 47, 61, 115, 253, 74, 25, 6, 4, 2, 4, 3, 0, 2, 7, 1, 10, 7, 3, 4, 10, 4, 15, 6, 5, 5, 3, 2, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, 4, 4, 3, 10, 0, 1, 1, 5, 0, 6, 21, 7, 10, 4, 1, 1, 2, 1, 1, 0, 2, 2, 1, 1, 4, 21, 13, 10, 1, 2, 82, 14, 8, 28, 112, 191, 172, 568, 69, 20, 23, 8, 9, 4, 16, 10, 6, 7, 10, 8, 10, 8, 7, 6, 1, 3, 3, 1, 7, 4, 0, 2, 1, 1, 0, 0, 0, 0, 2, 1, 3, 5, 4, 3, 3, 3, 3, 1, 1, 4, 1, 7, 9, 41, 28, 64, 30, 3, 1, 1, 2, 0, 2, 3, 58, 7, 4, 5, 16, 3, 3, 3, 5, 5, 4, 1, 2, 2, 0, 3, 0, 0, 0, 1, 0, 1, 0, 1, 2, 5, 5, 11, 16, 7, 13, 7, 7, 7, 3, 6, 17, 80, 13, 16, 13, 15, 6, 0, 3, 2, 0, 5, 4, 9, 8, 14, 63, 12, 4, 6, 5, 2, 4, 1, 2, 1, 1, 1, 1, 0, 1, 0, 0, 0, 3, 1, 1, 2, 0},
    {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 1, 1, 0},
    {3, 11, 4, 25, 70, 28, 19, 18, 32, 100, 214, 373, 1134, 213, 74, 21, 21, 13, 26, 22, 24, 12, 183, 96, 38, 22, 4, 15, 23, 93, 9, 17, 13, 18, 12, 19, 10, 5, 2, 1, 1, 0, 1, 2, 6, 8, 7, 10, 10, 7, 12, 6, 13, 3, 14, 8, 93, 16, 173, 382, 490, 51, 26, 15, 7, 2, 0, 7, 7, 5, 14, 9, 58, 14, 10, 8, 7, 9, 10, 2, 8, 8, 64, 19, 10, 3, 6, 4, 2, 2, 1, 4, 8, 8, 148, 349, 348, 103, 192, 310, 608, 818, 2799, 310, 107, 172, 88, 58, 36, 16, 36, 18, 15, 6, 10, 13, 15, 16, 36, 37, 24, 32, 15, 14, 30, 32, 28, 21, 32, 43, 27, 16, 6, 15, 5, 7, 0, 3, 3, 8, 10, 19, 23, 34, 44, 110, 59, 29, 27, 31, 55, 45, 233, 127, 412, 111, 29, 12, 16, 5, 7, 4, 9, 6, 11, 75, 20, 88, 71, 15, 10, 19, 38, 90, 49, 34, 120, 524, 351, 85, 35, 15, 6, 3, 3, 3, 2, 9, 15, 11, 7, 27, 29, 13, 29, 25, 54, 28, 24, 15, 11, 22, 40, 27, 42, 26, 9, 2, 3, 8, 6, 8, 18, 28, 30, 28, 36, 25, 16, 25, 31, 20, 50, 30, 19, 17, 97, 69, 17, 34, 8, 8, 10, 7, 12, 21, 15, 22, 43, 14},
    {8, 6, 1, 7, 92, 24, 21, 16, 72, 93, 862, 204, 39, 25, 15, 8, 6, 2, 3, 7, 16, 12, 9, 12, 10, 12, 6, 11, 18, 10, 10, 2, 6, 28, 42, 17, 9, 4, 6, 1, 0, 1, 2, 1, 5, 31, 22, 8, 12, 18, 9, 4, 14, 4, 8, 7, 5, 8, 9, 1, 1, 3, 3, 0, 2, 1, 3, 0, 2, 1, 4, 1, 7, 10, 2, 2, 89, 25, 8, 5, 9, 6, 30, 53, 88, 79, 16, 12, 1, 4, 2, 2, 5, 8, 5, 0, 6, 6, 0, 6, 3, 2, 6, 2, 42, 35, 146, 34, 15, 10, 3, 6, 4, 2, 4, 8, 7, 11, 4, 9, 4, 23, 3, 6, 7, 10, 11, 7, 5, 4, 1, 3, 1, 0, 2, 1, 1, 2, 1, 2, 1, 3, 7, 3, 13, 7, 10, 8, 3, 5, 1, 5, 6, 5, 4, 3, 4, 4, 3, 1, 1, 11, 7, 2, 8, 8, 7, 6, 6, 19, 19, 14, 22, 9, 14, 46, 115, 226, 62, 21, 16, 1, 6, 2, 1, 2, 6, 3, 11, 21, 19, 14, 13, 12, 22, 12, 11, 6, 20, 22, 47, 37, 33, 12, 13, 5, 5, 4, 3, 2, 2, 8, 9, 13, 7, 11, 6, 6, 2, 5, 11, 6, 48, 13, 11, 4, 3, 12, 10, 6, 5, 6, 6, 2, 5, 9, 4, 15, 6, 6},
    {8, 5, 9, 30, 28, 32, 14, 72, 141, 159, 24, 10, 11, 10, 5, 0, 1, 0, 6, 5, 12, 47, 13, 19, 11, 6, 7, 9, 9, 4, 4, 9, 6, 13, 4, 38, 6, 9, 14, 2, 2, 0, 2, 1, 0, 5, 6, 4, 28, 10, 10, 4, 8, 4, 6, 3, 4, 21, 8, 6, 3, 0, 3, 0, 0, 1, 2, 1, 10, 8, 16, 13, 14, 1, 2, 2, 8, 3, 25, 86, 129, 321, 182, 25, 7, 12, 4, 4, 4, 4, 4, 0, 2, 7, 6, 9, 3, 5, 13, 11, 186, 45, 22, 10, 9, 4, 10, 9, 7, 1, 3, 1, 2, 0, 6, 6, 9, 21, 13, 23, 8, 22, 30, 13, 10, 35, 49, 247, 286, 585, 395, 158, 64, 58, 8, 6, 9, 5, 8, 28, 19, 117, 35, 33, 11, 17, 11, 45, 7, 9, 11, 139, 36, 54, 48, 29, 17, 10, 3, 5, 4, 1, 5, 22, 77, 39, 17, 22, 13, 15, 11, 18, 14, 23, 14, 29, 116, 143, 326, 57, 18, 14, 2, 5, 3, 0, 4, 6, 8, 4, 21, 30, 53, 29, 20, 34, 18, 44, 29, 65, 65, 165, 368, 162, 40, 15, 10, 3, 3, 2, 5, 14, 13, 19, 22, 14, 23, 17, 20, 23, 106, 135, 55, 28, 14, 17, 22, 13, 10, 9, 10, 11, 6, 4, 10, 14, 50, 61, 123, 23},
    {6, 9, 20, 41, 71, 44, 22, 31, 27, 34, 245, 311, 473, 81, 28, 10, 11, 5, 5, 7, 12, 37, 140, 21, 15, 23, 33, 13, 165, 51, 38, 53, 46, 36, 148, 359, 323, 736, 104, 19, 11, 3, 6, 9, 13, 88, 16, 11, 15, 15, 16, 16, 19, 11, 14, 6, 5, 4, 8, 6, 3, 2, 2, 3, 1, 0, 2, 6, 2, 1, 11, 9, 10, 8, 41, 79, 113, 454, 222, 140, 51, 40, 20, 10, 12, 19, 3, 12, 5, 4, 2, 1, 0, 1, 6, 8, 7, 6, 6, 8, 2, 6, 1, 5, 4, 5, 5, 7, 4, 2, 2, 4, 6, 1, 0, 6, 5, 4, 2, 6, 11, 32, 15, 8, 15, 9, 13, 14, 16, 15, 11, 16, 7, 12, 10, 11, 15, 0, 5, 8, 6, 8, 9, 29, 36, 43, 55, 17, 121, 276, 74, 86, 66, 65, 295, 268, 314, 591, 89, 36, 16, 9, 8, 17, 17, 15, 20, 10, 12, 95, 39, 65, 18, 179, 60, 25, 44, 67, 194, 285, 349, 208, 36, 29, 10, 5, 7, 8, 10, 12, 12, 11, 17, 8, 27, 16, 15, 23, 33, 28, 26, 18, 15, 9, 7, 4, 6, 1, 0, 0, 0, 2, 6, 4, 2, 20, 8, 3, 4, 2, 1, 3, 7, 14, 0, 4, 4, 2, 4, 3, 1, 1, 1, 0, 1, 0, 2, 1, 1, 0},
    {1, 7, 14, 8, 5, 33, 28, 19, 202, 69, 61, 46, 87, 27, 20, 5, 6, 2, 1, 3, 4, 7, 0, 2, 7, 16, 12, 17, 14, 6, 4, 13, 10, 2, 5, 4, 3, 4, 6, 0, 0, 0, 0, 2, 2, 0, 3, 5, 7, 4, 4, 3, 4, 7, 4, 1, 0, 6, 2, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 2, 4, 6, 2, 2, 4, 6, 12, 53, 161, 32, 6, 5, 1, 3, 2, 0, 1, 1, 2, 3, 1, 2, 3, 2, 3, 1, 0, 2, 6, 0, 0, 1, 1, 2, 5, 0, 1, 3, 0, 1, 2, 0, 3, 2, 1, 2, 1, 1, 4, 3, 4, 10, 3, 12, 20, 19, 15, 7, 0, 5, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4, 4, 3, 0, 4, 10, 3, 3, 0, 1, 2, 0, 2, 2, 3, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 2, 5, 3, 5, 1, 0, 0, 2, 2, 4, 3, 2, 2, 1, 0, 0, 0, 0, 0, 0, 2, 3, 1, 4, 5, 2, 2, 10, 10, 6, 12, 43, 162, 27, 12, 7, 8, 1, 1, 1, 0, 1, 3, 2, 7, 3, 2, 0, 7, 0, 10, 9, 6, 10, 6, 6, 1, 3, 3, 3, 0, 1, 0, 0, 0, 2, 3, 0, 0, 0},
    {2, 5, 11, 2, 4, 8, 10, 16, 17, 15, 81, 83, 114, 43, 78, 16, 10, 3, 5, 5, 5, 4, 8, 5, 4, 5, 11, 6, 9, 4, 3, 12, 7, 5, 5, 4, 7, 3, 3, 1, 1, 1, 0, 1, 4, 3, 0, 0, 6, 10, 11, 10, 10, 9, 9, 15, 22, 18, 37, 166, 275, 29, 14, 4, 3, 2, 0, 4, 6, 3, 2, 3, 2, 2, 5, 7, 1, 5, 3, 4, 0, 2, 3, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 2, 4, 4, 2, 2, 6, 8, 25, 39, 38, 19, 10, 16, 7, 4, 4, 0, 3, 0, 0, 1, 0, 1, 2, 3, 1, 5, 0, 1, 0, 6, 2, 6, 4, 6, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 2, 1, 1, 5, 42, 12, 8, 7, 7, 13, 15, 118, 44, 36, 16, 5, 6, 4, 1, 1, 1, 1, 0, 2, 1, 2, 1, 2, 3, 5, 4, 9, 4, 3, 4, 4, 7, 11, 11, 3, 3, 2, 4, 0, 0, 2, 1, 1, 5, 7, 10, 36, 359, 58, 28, 754, 89, 59, 32, 29, 24, 76, 151, 229, 99, 44, 13, 6, 4, 5, 2, 6, 6, 5, 6, 3, 5, 19, 30, 14, 8, 13, 5, 4, 15, 10, 8, 5, 5, 4, 6, 1, 1, 0, 2, 2, 2, 1, 1},
    {28, 17, 15, 19, 10, 15, 34, 15, 15, 40, 83, 124, 284, 55, 21, 5, 10, 3, 6, 13, 11, 12, 8, 16, 3, 9, 15, 449, 73, 23, 25, 19, 14, 7, 11, 9, 2, 7, 7, 3, 1, 0, 8, 3, 8, 13, 35, 22, 12, 262, 68, 20, 120, 51, 121, 57, 66, 350, 498, 783, 1075, 155, 74, 33, 27, 18, 10, 18, 22, 86, 58, 30, 14, 17, 9, 9, 14, 15, 5, 7, 5, 6, 5, 8, 4, 6, 0, 3, 3, 4, 3, 3, 1, 4, 5, 3, 11, 37, 11, 12, 15, 31, 73, 120, 141, 254, 83, 32, 34, 14, 10, 8, 2, 5, 3, 5, 2, 11, 34, 24, 30, 15, 13, 107, 76, 38, 30, 61, 88, 152, 508, 240, 74, 36, 22, 11, 3, 2, 4, 10, 9, 117, 99, 32, 26, 16, 26, 18, 12, 14, 20, 43, 131, 87, 36, 33, 14, 49, 10, 5, 6, 4, 4, 4, 597, 230, 123, 59, 52, 54, 35, 49, 150, 282, 91, 75, 60, 40, 190, 186, 276, 172, 30, 21, 6, 10, 10, 8, 14, 15, 44, 35, 59, 36, 17, 28, 24, 101, 27, 98, 25, 25, 244, 164, 340, 451, 92, 56, 33, 18, 11, 29, 23, 23, 32, 64, 62, 25, 33, 36, 57, 42, 39, 32, 17, 53, 42, 16, 8, 20, 8, 7, 6, 3, 7, 5, 9, 14, 20, 3},
    {2, 11, 8, 13, 6, 4, 247, 241, 775, 2113, 435, 83, 39, 22, 13, 12, 11, 8, 5, 7, 10, 8, 4, 5, 4, 4, 4, 4, 10, 7, 13, 5, 3, 7, 4, 4, 2, 3, 2, 0, 0, 0, 0, 0, 0, 1, 1, 4, 110, 8, 3, 2, 5, 3, 0, 5, 3, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 3, 2, 4, 1, 1, 0, 0, 2, 1, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 1, 3, 1, 1, 11, 7, 5, 1, 2, 41, 43, 105, 162, 13, 7, 10, 3, 2, 1, 1, 2, 0, 0, 1, 6, 6, 3, 1, 3, 6, 7, 3, 2, 8, 11, 48, 92, 41, 67, 16, 2, 6, 2, 0, 3, 0, 4, 1, 1, 11, 3, 3, 0, 3, 2, 6, 1, 41, 5, 3, 3, 4, 7, 22, 3, 4, 3, 0, 0, 3, 0, 2, 0, 8, 1, 3, 2, 11, 6, 4, 13, 20, 9, 13, 4, 5, 6, 2, 3, 0, 1, 0, 1, 0, 3, 6, 6, 13, 11, 43, 32, 16, 28, 17, 25, 31, 100, 138, 187, 243, 58, 87, 70, 22, 6, 1, 4, 2, 4, 3, 14, 17, 33, 32, 22, 7, 9, 4, 6, 5, 19, 5, 8, 5, 2, 1, 7, 5, 0, 1, 0, 0, 2, 1, 1, 1, 5, 5},
    {1, 0, 0, 6, 0, 0, 1, 3, 5, 1, 1, 0, 6, 7, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 4, 2, 6, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 5, 4, 5, 1, 1, 1, 0, 1, 0, 0, 2, 2, 4, 1, 3, 1, 2, 2, 2, 0, 1, 4, 0, 5, 2, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 2, 0, 1, 0, 1, 0, 0, 2, 0, 0, 0, 1, 1, 3, 1, 6, 6, 1, 0, 0, 1, 0, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7, 2, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 2, 1, 0, 0, 3, 0, 0, 1, 4, 0, 1, 6, 1, 0, 0, 0, 0, 0, 4, 4, 1, 2, 1, 1, 1, 3, 1, 2, 1, 1, 1, 1, 0, 1, 0, 3, 1, 3, 0, 1, 1, 2, 0, 0, 0, 0},
    {3, 4, 0, 1, 3, 2, 12, 37, 28, 188, 15, 14, 12, 5, 9, 2, 0, 2, 0, 4, 2, 45, 16, 7, 19, 32, 33, 15, 9, 6, 4, 12, 3, 3, 8, 9, 2, 0, 1, 0, 0, 0, 0, 0, 2, 1, 4, 1, 5, 4, 3, 5, 5, 5, 6, 2, 3, 5, 4, 1, 6, 1, 2, 0, 0, 0, 2, 2, 1, 151, 29, 29, 11, 11, 17, 3, 3, 6, 268, 106, 397, 1416, 715, 94, 27, 15, 8, 4, 7, 5, 1, 3, 5, 7, 3, 0, 26, 14, 3, 0, 1, 8, 3, 4, 3, 5, 1, 1, 2, 1, 1, 1, 4, 0, 0, 2, 3, 2, 9, 5, 1, 4, 8, 2, 19, 13, 11, 64, 135, 155, 16, 11, 4, 3, 2, 0, 3, 1, 5, 7, 3, 16, 43, 50, 13, 8, 6, 3, 7, 6, 3, 0, 1, 2, 3, 4, 5, 2, 1, 0, 1, 1, 1, 2, 3, 2, 6, 10, 7, 0, 13, 17, 11, 4, 15, 23, 74, 297, 261, 69, 24, 6, 7, 3, 0, 4, 19, 8, 23, 233, 28, 19, 15, 12, 9, 13, 25, 19, 26, 296, 191, 525, 609, 41, 23, 7, 5, 4, 3, 2, 1, 4, 5, 2, 28, 8, 13, 9, 4, 2, 4, 1, 1, 5, 0, 4, 0, 1, 2, 1, 0, 0, 1, 0, 0, 1, 0, 2, 3, 0},
};
/* end of generated data */

/*
 * index lookup from wheel index into the twitterCounts array
 */
const int wheelLookup[] =
{
    14, // Miami
    19, // New York
    10, // Indiana
    21, // Orlando
    1, // Boston
    0, // Atlanta
    26, // San Antonio @spurs
    23, // Phoenix
    20, // Oklahoma
    5, // Dallas
    12, // Los Angeles (lakers)
    6, // Denver
    11, // Los Angles (clippers)
    13, // Memphis
    3, // Chicago
    22, // Philadelphia
};

const float teamColors[][3] =
{
    {0.588f, 0.000f, 0.208f}, // Miami
    {0.922f, 0.341f, 0.173f}, // New York
    {0.965f, 0.694f, 0.118f}, // Indiana
    {0.204f, 0.443f, 0.749f}, // Orlando
    {0.000f, 0.467f, 0.212f}, // Boston
    {0.129f, 0.110f, 0.314f}, // Atlanta
    {0.749f, 0.780f, 0.800f}, // San Antonio @spurs
    {0.306f, 0.090f, 0.396f}, // Phoenix
    {0.925f, 0.176f, 0.180f}, // Oklahoma
    {0.255f, 0.361f, 0.694f}, // Dallas
    {0.961f, 0.690f, 0.090f}, // Los Angeles (lakers)
    {0.345f, 0.494f, 0.776f}, // Denver
    {0.922f, 0.000f, 0.341f}, // Los Angles (clippers)
    {0.361f, 0.439f, 0.698f}, // Memphis
    {0.827f, 0.000f, 0.247f}, // Chicago
    {0.204f, 0.380f, 0.706f}, // Philadelphia
// 16 finalists done
    {1.000f, 0.000f, 0.000f}, // fake red
    {0.000f, 0.000f, 1.000f}, // fake blue
    {1.000f, 0.000f, 0.000f}, // fake red
    {0.000f, 0.000f, 1.000f}, // fake blue
    {1.000f, 0.000f, 0.000f}, // fake red
    {0.000f, 0.000f, 1.000f}, // fake blue
    {1.000f, 0.000f, 0.000f}, // fake red
    {0.000f, 0.000f, 1.000f}, // fake blue
    {1.000f, 0.000f, 0.000f}, // fake red
    {0.000f, 0.000f, 1.000f}, // fake blue
    {1.000f, 0.000f, 0.000f}, // fake red
    {0.000f, 0.000f, 1.000f}, // fake blue
    {1.000f, 0.000f, 0.000f}, // fake red
};

int TwitterLiveData::teamSetIndex = 0;

TwitterLiveData::TwitterLiveData()
{
    // TODO Auto-generated constructor stub

}

void TwitterLiveData::setTeamSetIndex(int setIndex)
{
    teamSetIndex = (setIndex + 800000) % 8;
}

const char** TwitterLiveData::handles()
{
    return teamHandles;
}

const float(*TwitterLiveData::color())[3]
{
    return teamColors;

}

const float* TwitterLiveData::data(int teamIndex)
{
    teamIndex = wheelLookup[teamIndex % 16];
    return twitterCounts[teamIndex];
}

// http://en.wikipedia.org/wiki/B-spline - Uniform cubic B-splines
float cspline3(float p0, float p1, float p2, float p3, float t)  // t in 0,1, pn are the four values
{
    float t0 = 1, t1 = t, t2 = t * t, t3 = t * t * t;
    float k0 = -1 * t3 +  3 * t2 + -3 * t1 +  1 * t0;
    float k1 =  3 * t3 + -6 * t2 +  0 * t1 +  4 * t0;
    float k2 = -3 * t3 +  3 * t2 +  3 * t1 +  1 * t0;
    float k3 =  1 * t3 +  0 * t2 +  0 * t1 +  0 * t0;
    return (k0 * p0 + k1 * p1 + k2 * p2 + k3 * p3) / 6.0f;
}

// this spline passes through all control points.
// http://en.wikipedia.org/wiki/Cubic_Hermite_spline
float hspline3(float p0, float p1, float p2, float p3, float t)  // t in 0,1, pn are the four values
{
    float m1 = (p2 - p0) / 2;
    float m2 = (p3 - p1) / 2;

    float t0 = 1, t1 = t, t2 = t * t, t3 = t * t * t;
    float h00 =  2 * t3 + -3 * t2 +  0 * t1 +  1 * t0;
    float h10 =  1 * t3 + -2 * t2 +  1 * t1 +  0 * t0;
    float h01 = -2 * t3 +  3 * t2 +  0 * t1 +  0 * t0;
    float h11 =  1 * t3 + -1 * t2 +  0 * t1 +  0 * t0;
    return (h00 * p1 + h10 * m1 + h01 * p2 + h11 * m2);
}

// evalueate the spline at position x using surrounding points
float TwitterLiveData::spline(int teamIndex, float x)
{

    teamIndex = wheelLookup[teamIndex % 16];

    int nPoints =  sizeof(twitterCounts) / sizeof(float);
    const float* p = twitterCounts[teamIndex];
    if (x <= 0)
    {
        return p[0];
    }
    if (x >= nPoints - 1)
    {
        return p[nPoints - 1];
    }
    int i = (int)x;
    float t = x - (float)i;
    float p0 = (i > 0) ? p[i - 1] : p[0];
    float p1 = p[i];
    float p2 = (i < nPoints - 1) ? p[i + 1] : p[nPoints - 1];
    float p3 = (i < nPoints - 2) ? p[i + 2] : p[nPoints - 1];
//    printf("    x=%f  i=%d t=%f p=%f,%f,%f,%f\n",x,i,t,p0,p1,p2,p3);

    return hspline3(p0, p1, p2, p3, t);
}

TwitterLiveData::~TwitterLiveData()
{
    // TODO Auto-generated destructor stub
}

