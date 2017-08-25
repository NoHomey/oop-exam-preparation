#include "Book.h"
#include "Magazine.h"
#include <fstream>

int main() {
    Book b;
    Magazine m;

    bool written = false;

    std::ofstream file{"popular.txt"};

    std::ifstream all{"all.txt"};

    for(int i = 0; i < 2; ++i) {
        all >> b;
        if(b.getEdition() >= 1000) {
            if(written) {
                file << std::endl;
            }
            file << b;
            written = true;
        }
    }

    for(int i = 0; i < 2; ++i) {
        all >> m;
        if(m.getEdition() >= 1000) {
            if(written) {
                file << std::endl;
            }
            file << m;
            written = true;
        }
    }

    return 0;
}