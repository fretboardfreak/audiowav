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
