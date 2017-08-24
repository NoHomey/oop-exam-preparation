#include "Appointment.h"
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file{"calendar.txt"};
    Appointment appointment;
    while(file) {
        try {
            file >> appointment;
        } catch(const std::bad_alloc& error) {
            std::cerr << "Eror while reading calendar.txt, not enough memory" << std::endl;
            return EXIT_FAILURE;
        }
        if(file.good() || file.eof()) {
            std::cout << appointment << std::endl;
        } else {
            std::cerr << "Eror while reading calendar.txt" << std::endl;
            return EXIT_FAILURE;
        }
    }

    return 0;
}