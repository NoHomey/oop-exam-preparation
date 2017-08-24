#include <iostream>
#include "DynamicArray.h"

using Array = DynamicArray<int>;

int main() {
    Array array;
    for(size_t i = 0; i < 100; ++i) {
        array.push(i);
    }

    Array copy = array;

    std::cout << array.size() << ' ' << array.capacity() << ' ' << array[9] << std::endl;
    std::cout << copy.size() << ' ' << copy.capacity() << ' ' << copy[9] << std::endl;

    for(size_t i = 0; i < 20; ++i) {
        array.pop();
        copy.pop();
    }

    std::cout << array.size() << ' ' << array.capacity() << ' ' << array[9] << std::endl;
    std::cout << copy.size() << ' ' << copy.capacity() << ' ' << copy[9] << std::endl;

    array.shrinkToFit();

    std::cout << array.size() << ' ' << array.capacity() << ' ' << array[9] << std::endl;
    std::cout << copy.size() << ' ' << copy.capacity() << ' ' << copy[9] << std::endl;

    copy.extend(20);

    std::cout << array.size() << ' ' << array.capacity() << ' ' << array[9] << std::endl;
    std::cout << copy.size() << ' ' << copy.capacity() << ' ' << copy[9] << std::endl;

    copy = array;

    std::cout << array.size() << ' ' << array.capacity() << ' ' << array[9] << std::endl;
    std::cout << copy.size() << ' ' << copy.capacity() << ' ' << copy[9] << std::endl;

    return 0;
}