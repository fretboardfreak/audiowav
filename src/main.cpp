//#include "config.h"
#include "wavegen.hpp"
#include <iostream>

int main(int argc, char **argv){
    std::cout << "audiowav" << std::endl;

#ifdef DEBUG
    std::cout << "I was compiled with DEBUG defined." << std::endl;
#endif

    return 0;
}
