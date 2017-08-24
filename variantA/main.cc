#include "TimestampWithDescription.h"
#include <fstream>

int main() {
    std::ifstream timestamps{"timestamps.txt"};
    if(!timestamps) {
        std::cerr << "Could not open timestamps.txt" << std::endl;
        return EXIT_FAILURE;
    }
    TimestampWithDescription object;
    try {
        while(timestamps >> object) {
            std::cout << object << std::endl;
        }
    } catch(std::bad_alloc& error) {
        std::cerr << "Error while reading timestamps.txt, not enough memory" << std::endl;
        return EXIT_FAILURE;
    }
    if(timestamps.bad() || timestamps.fail()) {
        std::cerr << "Error while reading timestamps.txt" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}