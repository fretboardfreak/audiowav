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
