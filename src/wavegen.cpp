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
#include "wavegen.hpp"
#include <iostream>
#include <cmath>

int secondsToFrames(float seconds, int framerate){
  /* Calculate number of frames given sample length in seconds.
   * framerate = frames / seconds
   * frames = framerate * seconds = (frames / seconds) * seconds */
  return (int) floor(framerate * seconds);
}

float framesToSeconds(int framecount, int framerate){
  /* Calculate length of sample given the framecount and framerate.
   * framerate = frames / seconds
   * seconds = framecount / framerate = (frames) / (frames / seconds) */
  return (float) framecount / (float) framerate;
}

int WaveGenerator::genFrames(float frequency, int count){
  /* Generate frames in the given frequency */
  freq = frequency;
  return 1;
}
