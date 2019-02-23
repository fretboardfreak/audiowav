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
#ifndef WAVEGEN_HPP
#define WAVEGEN_HPP

#include <complex>

#define DEFAULT_FRAMERATE 44100

/* Calculate number of frames given sample length in seconds. */
int seconds_to_frames(float seconds, int framerate);
/* Calculate length of sample given the framecount and framerate. */
float frames_to_seconds(int frame_count, int framerate);

/* WaveGenerator : generate a continuous waveform using phasor math. */
class WaveGenerator {
public:
  /* Constructor */
  WaveGenerator(void);
  /* Reset the WaveGenerator to start a new waveform.*/
  void reset(void);
  /* Generate a waveform at a constant frequency. */
  void constant(float frequency, float *channel, int framecount);
  /* Generate a waveform of linearly changeng frequency.
   * note: only end frequency is needed because current fruency is the start.
   *       if linear is first call after reset/initialization, must manually
   *       set frequency member.
   */
  // void linear(int end_frequency, float *channel, int framecount);
protected:
  const float phasor_amplitude;
  const int framerate;
  int generated_frames;
  float last_phase, frequency, last_frequency;
  /* Calculate the sinusoid phase angle for a given frame and frequency. */
  float angle(int frame, float frequency);
  /* Build a phasor from given frame and phase. */
  std::complex<float> phasor(int frame, float phase);
  /* Calculate the new phase when the frequency changes. */
  float correct_phase(void);
};


#endif
