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
#include <complex>

#define _USE_MATH_DEFINES
#include <cmath>

#include "logging.hpp"
#include "wavegen.hpp"

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


/* WaveGenerator Constructor */
WaveGenerator::WaveGenerator(void): phasor_amplitude(1.0),
                                    framerate(DEFAULT_FRAMERATE),
                                    generated_frames(0),
                                    last_phase(0),
                                    frequency(0),
                                    last_frequency(0)
{}

/* Reset the WaveGenerator to start a new waveform.*/
void WaveGenerator::reset(void){
  this->frequency = 0;
  this->last_frequency = 0;
  this->last_phase = 0;
  this->generated_frames = 0;
}

/* Calculate the sinusoid phase angle for a given frame and frequency. */
float WaveGenerator::angle(int frame, float frequency){
  return 2.0 * M_PI * frequency * (float) frame / (float) this->framerate;
}

/* Build a phasor from given frame and phase. */
std::complex<float> WaveGenerator::phasor(int frame, float phase){
  return std::polar(this->phasor_amplitude,
                    this->angle(frame, this->frequency) + phase);
}

/* Calculate the new phase when the frequency changes.
 *
 * Conceptually, this shifts the generated waveform in the new frequency so
 * that the waveform matches the value of the previously generated waveform of
 * the old frequency.
 * | /-\     /-\|            -/--\-   |
 * |/   \   /   |-\-      -/-      -\-|
 * |     \-/    |   -\--/-            |
 * vs
 * | /-\     /-\|      -/--\-         |
 * |/   \   /   |   -/-      -\-      |
 * |     \-/    |-/-            -\--/-|
 */
float WaveGenerator::correct_phase(void){
  log(L_WARNING, "WaveGenerator::correct_phase() not implemented.");
  return this->last_phase;
}

/* Generate a waveform at a constant frequency. */
void WaveGenerator::constant(float frequency, float *channel, int framecount){
  this->frequency = frequency;
  float phase;
  if (this->frequency != this->last_frequency)
    phase = this->correct_phase();
  else
    phase = this->last_phase;
  int frame;
  std::complex<float> phasor;
  for (frame=0; frame <= framecount; frame++) {
    phasor = this->phasor(this->generated_frames + 1 + frame, phase);
    channel[frame] = phasor.real();
  }
  this->generated_frames += frame;
  this->last_phase = std::arg(phasor);
  this->last_frequency = this->frequency;
}
