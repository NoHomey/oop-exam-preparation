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
        instruments[5 + i] = new Pencil;
    }

    for(int i = 0; i < 10; ++i) {
        WritingInstrument& instrument = *(instruments[i]);
        std::cin >> instrument;
        std::cout << instrument << std::endl;
    }

    std::cin >> brand;
    std::cout << brand << std::endl;

    for(int i = 0; i < 10; ++i) {
        if(instruments[i]->getBrand() == brand) {
            if(written) {
                file << '\n';
            }
            file << *(instruments[i]);
            written = true;
        }
        delete instruments[i];
    }

    return 0;
}