#include <iostream>
#include "String.h"

int main() {
    String str1{"some text"};

    String str2;

    std::cin >> str2;

    std::cout << str1.length() << ' ' << str1 << ' ' << str1.cString() << std::endl;
    std::cout << str2.length() << ' ' << str2 << ' ' << str2.cString() << std::endl;

    String str3 = str1 + str2;

    std::cout << str3.length() << ' ' << str3 << ' ' << str3.cString() << std::endl;

    std::cout << (String{"abcd"} == String{"abcd"}) << std::endl;

    std::cout << (String{"abdd"} != String{"abcd"}) << std::endl;

    std::cout << (String{"abcd"} < String{"abdd"}) << std::endl;

    std::cout << (String{"abdd"} > String{"abcd"}) << std::endl;

    std::cout << (String{"abcd"} <= String{"abdd"}) << std::endl;
    std::cout << (String{"abcd"} <= String{"abcd"}) << std::endl;
    
    std::cout << (String{"abdd"} >= String{"abcd"}) << std::endl;
    std::cout << (String{"abcd"} >= String{"abcd"}) << std::endl;

    return 0;
}