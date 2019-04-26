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
#ifndef DSOUND_HPP
#define DSOUND_HPP

#define DEFAULT_FRAMERATE 44100

/* Calculate number of frames given sample length in seconds. */
int seconds_to_frames(float seconds, int framerate);

/* Calculate length of sample given the framecount and framerate. */
float frames_to_seconds(int frame_count, int framerate);

#endif
