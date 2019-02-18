#ifndef WAVEGEN_HPP
#define WAVEGEN_HPP

#define DEFAULT_FRAMERATE 44100

int secondsToFrames(float /*seconds*/, int /*framerate*/);
float framesToSeconds(int /*frameCount*/, int /*framerate*/);

class WaveGenerator {
  int freq, framerate;
public:
  int genFrames(float /*frequency*/, int /*count*/);
private:
  float sinusoidAngle(int /*frame*/, float /*frequency*/);
  float sinusoidValue(int /*frame*/, float /*frequency*/);
};


#endif
