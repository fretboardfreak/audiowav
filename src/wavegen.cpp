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
#include <cstring>
#include <sysexits.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include <sndfile.hh>

#include "logging.hpp"
#include "dsound.hpp"
#include "wavegen.hpp"

/* Test method to create a file using continuous WaveGenerator. */
int create_wavegen_test_file(const char *fname){
  static int buffer_len = 1024;
  static float buffer[1024]; // using values between -1.0, 1.0

	SndfileHandle file;
	int channels = 1;
	int srate = DEFAULT_FRAMERATE; // srate for sample rate

	log(L_INFO, "Creating file named '%s'\n", fname);
	file = SndfileHandle(fname, SFM_WRITE, SF_FORMAT_WAV | SF_FORMAT_FLOAT,
                       channels, srate);
	memset(buffer, 0, sizeof(buffer));

  float tone_len = 1.0; // seconds
  int tone_frames = seconds_to_frames(tone_len, srate);

  WaveGenerator generator = WaveGenerator();

  float frequency = 440.0;

  int tones = 5;
  while (tones > 0) {
    int remaining_frames = tone_frames;
    while (remaining_frames > 0) {
      if (remaining_frames >= buffer_len) {
        generator.constant(frequency, buffer, buffer_len);
        file.write(buffer, buffer_len);
        remaining_frames -= buffer_len;
      } else {
        generator.constant(frequency, buffer, remaining_frames);
        file.write(buffer, remaining_frames);
        remaining_frames = 0;
      }
    }
    tones--;
    frequency *= 1.33;
  }

  // SndfileHandle destructor called when object out of scope
  return EX_OK;
}

/* WaveGenerator Constructor */
WaveGenerator::WaveGenerator(void): amplitude(1.0),
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

/* Generate a waveform at a constant frequency. */
void WaveGenerator::constant(float frequency, float *channel, int framecount){
  log(L_DEBUG, "frequency: %f\n", frequency);
  this->frequency = frequency;
  float phase;
  if (this->frequency != this->last_frequency && this->last_frequency != 0) {
    // calculate phase correction for change in frequency
    float curr = this->angle(this->generated_frames, this->last_frequency) + this->last_phase;
    float next = this->angle(this->generated_frames, this->frequency);
    phase = curr - next;
    log(L_DEBUG, "    cur %f : next %f\n", curr, next);
  } else
    phase = this->last_phase;
  log(L_DEBUG, "  phase: %f\n", phase);
  int frame;
  for (frame=0; frame <= framecount; frame++) {
    float value = std::sin(this->angle(this->generated_frames + frame + 1, this->frequency) + phase);
    channel[frame] = value * this->amplitude;
    if(frame <= 5 || frame >= framecount - 5)
      log(L_DEBUG, "frame %d: %f\n", this->generated_frames + frame + 1, value);
  }
  this->generated_frames += frame;
  this->last_frequency = this->frequency;
  this->last_phase = phase;
}
