#include "Marker.h"
#include "Pencil.h"
#include <iostream>
#include <fstream>

int main() {
    Marker markers[5];
    Pencil pencils[5];
    String brand;
    bool written = false;
    std::ofstream file{"branded.txt"};

    for(int i = 0; i < 5; ++i) {
        std::cin >> markers[i];
        std::cout << markers[i] << std::endl;
    }

    for(int i = 0; i < 5; ++i) {
        std::cin >> pencils[i];
        std::cout << pencils[i] << std::endl;
    }

    std::cin >> brand;
    std::cout << brand << std::endl;

    for(int i = 0; i < 5; ++i) {
        if(markers[i].getBrand() == brand) {
            if(written) {
                file << '\n';
            }
            file << markers[i];
            written = true;
        }
    }

    for(int i = 0; i < 5; ++i) {
        if(pencils[i].getBrand() == brand) {
            if(written) {
                file << '\n';
            }
            file << pencils[i];
            written = true;
        }
    }

    return 0;
}