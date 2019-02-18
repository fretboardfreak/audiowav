/*
 * Copyright 2019 Curtis Sand
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <iostream>

#include "mygtest.hpp"
#include "gtest/gtest.h"

#include "wavegen.hpp"

TEST(WavegenTests, HandlesFramesToSeconds){
  float seconds = framesToSeconds(DEFAULT_FRAMERATE, DEFAULT_FRAMERATE);
  std::cout << DEFAULT_FRAMERATE << " frames at " << \
    DEFAULT_FRAMERATE << " frames per second is " << seconds << \
    " seconds long." << std::endl;
  ASSERT_EQ(seconds, 1.0);
}

TEST(WavegenTests, HandlesSecondsToFrames){
  int frames = secondsToFrames(1.0, DEFAULT_FRAMERATE);
  std::cout << "1.0 seconds at " << DEFAULT_FRAMERATE << \
    " frames per second is " << frames << " frames long." << std::endl;
  ASSERT_EQ(frames, DEFAULT_FRAMERATE);
}
