#include "TimestampWithDescription.h"
#include <fstream>

int main() {
    std::ifstream timestamps{"timestamps.txt"};
    if(!timestamps) {
        std::cerr << "Could not open timestamps.txt" << std::endl;
        return EXIT_FAILURE;
    }
    TimestampWithDescription object;
    while(!timestamps.eof()) {
        if(timestamps.bad() || timestamps.fail()) {
            std::cerr << "Error while reading timestamps.txt" << std::endl;
            return EXIT_FAILURE;
        }
        timestamps >> object;
        std::cout << object << std::endl;
    }

    return 0;
}