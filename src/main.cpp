//#include "config.h"
#include "wavegen.hpp"
#include <iostream>

int main(int argc, char **argv){
    std::cout << "audiowav" << std::endl;
    WaveGenerator *generator = new WaveGenerator();

#ifdef DEBUG
    std::cout << "I was compiled with DEBUG defined." << std::endl;
#endif

    std::cout << generator->genSamples(440, 1000) << std::endl;
    return 0;
}
