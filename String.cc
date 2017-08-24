#include "String.h"
#include <stdexcept>
#include <cstring>

size_t String::calculateLength(const char* string) noexcept {
    if(string == nullptr) {
        throw std::invalid_argument{"got null pointer"};
    }
    size_t length = 0;
    while(string[length] != '\0') {
        ++length;
    }
    return length;
}

String::String()
: string{1} {
    string.push('\0');
}

String::String(const char* content)
: string{calculateLength(content) + 1} {
    const size_t length = string.capacity() - 1;
    for(size_t index = 0; index < length; ++index) {
        string.push(content[index]);
    }
    string.push('\0');
}

size_t String::length() const noexcept {
    return string.size() - 1;
}

const char* String::cString() const noexcept {
    return string.data();
}

char& String::operator[](size_t index) {
    return string[index];
}

char String::operator[](size_t index) const {
    return string[index];
}

bool String::operator==(const String& other) const noexcept {
    return std::strcmp(cString(), other.cString()) == 0;
}

bool String::operator!=(const String& other) const noexcept {
    return !operator==(other);
}

bool String::operator<(const String& other) const noexcept {
    return std::strcmp(cString(), other.cString()) < 0;
}
    
bool String::operator>(const String& other) const noexcept {
    return other < *this;
}

bool String::operator<=(const String& other) const noexcept {
    return !operator>(other);
}
    
bool String::operator>=(const String& other) const noexcept {
    return !operator<(other);
}

String& String::operator+=(const String& other) {
    const size_t otherLength = other.length();
    if(otherLength == 0) {
        return * this;
    }
    string.pop();
    string.extend(otherLength);
    for(size_t index = 0; index < otherLength; ++index) {
        string.push(other[index]);
    }
    string.push('\0');
    return *this;
}

String String::operator+(const String& other) const {
    String copy{*this};
    copy += other;
    return copy;
}

std::istream& operator>>(std::istream& in, String& string) {
    char symbol;
    string.string.pop();
    string.string.extend(10);
    while(true) {
        symbol = in.get();
        if(!in || (symbol == '\n')) {
            string.string.push('\0');
            try {
                string.string.shrinkToFit();
            } catch(const std::bad_alloc& error) { }
            in.clear();
            return in;
        }
        string.string.push(symbol);
    }
}

std::ostream& operator<<(std::ostream& out, const String& string) {
    const size_t length = string.length();
    for(size_t index = 0; index < length; ++index) {
        out << string[index];
    }
    return out;
}