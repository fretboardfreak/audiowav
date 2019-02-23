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

#define _USE_MATH_DEFINES
#include <cmath>

/* Calculate number of frames given sample length in seconds.
 * frames = framerate * seconds = (frames / seconds) * seconds */
int seconds_to_frames(float seconds, int framerate){
  return (int) floor(framerate * seconds);
}

/* Calculate length of sample given the framecount and framerate.
 * seconds = framecount / framerate = (frames) / (frames / seconds) */
float frames_to_seconds(int framecount, int framerate){
  return (float) framecount / (float) framerate;
}


WaveGenerator::WaveGenerator(int framerate, int fade_percentage){}

/* Generate a waveform at a constant frequency. */
void WaveGenerator::constant(int frequency, float *channel, int frame_count){
}

/* Generate a waveform of linearly changeng frequency.
 * note: only end frequency is needed because current fruency is the start.*/
void WaveGenerator::linear(int end_frequency, float *channel, int frame_count){
}

/* Reset the WaveGenerator to start a new waveform.*/
bool WaveGenerator::reset(void){
  return true;
}

/* Calculate the sinusoid phase angle for a given frame and frequency. */
float WaveGenerator::sinusoid_angle(int frame, float frequency){
  return 0;
}

/* Calculate the value of a sinusoid wave at given frame and frequency. */
float WaveGenerator::sinusoid_value(int frame, float frequency){
  return 0;
}
