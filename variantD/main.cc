#include "Marker.h"
#include "Pencil.h"
#include <iostream>
#include <fstream>

int main() {
    WritingInstrument* instruments[10];
    String brand;
    bool written = false;
    std::ofstream file{"branded.txt"};

    for(int i = 0; i < 5; ++i) {
        instruments[i] = new Marker;
        instruments[i]->read(std::cin);
        instruments[i]->write(std::cout);
        std::cout << std::endl;
    }

    for(int i = 5; i < 10; ++i) {
        instruments[i] = new Pencil;
        instruments[i]->read(std::cin);
        instruments[i]->write(std::cout);
        std::cout << std::endl;
    }

    std::cin >> brand;
    std::cout << brand << std::endl;

    for(int i = 0; i < 10; ++i) {
        if(instruments[i]->getBrand() == brand) {
            if(written) {
                file << '\n';
            }
            instruments[i]->write(file);
            written = true;
        }
        delete instruments[i];
    }
    
    return 0;
}