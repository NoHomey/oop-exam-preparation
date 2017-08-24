#include "String.h"
#include <cstring>
#include <utility>
#include <stdexcept>

String::String() noexcept
: data{nullptr}, strLength{0} { }

String::~String() noexcept {
    delete[] data;
}

char* String::copyString(const char* string, size_t length) {
    if((string == nullptr) || (length == 0)) {
        return nullptr;
    }
    const size_t count = length + 1;
    char* result = new char[count];
    std::memcpy(result, string, count);
    return result;
}

String::String(const char* string, size_t length)
: data{copyString(string, length)}, strLength{length} { }

String::String(const String& other)
: String{other.data, other.strLength} { }

void String::null() noexcept {
    data = nullptr;
    strLength = 0;
}

void String::moveOther(String&& string) noexcept {
    delete[] data;
    data = string.data;
    strLength = string.strLength;
    string.null();
}

String::String(String&& other) noexcept
: String{} {
    moveOther(std::move(other));
}

String& String::operator=(const String& other) {
    if(this != &other) {
        String copy{other};
        moveOther(std::move(copy));
    }
    return *this;
}
    
String& String::operator=(String&& other) noexcept {
    if(this != &other) {
        moveOther(std::move(other));
    }
    return *this;
}

size_t String::stringLength(const char* string) noexcept {
    return string == nullptr ? 0 : std::strlen(string);
}

String::String(const char* string)
: String(string, stringLength(string)) { }

size_t String::length() const noexcept {
    return strLength;
}

char& String::operator[](const size_t index) {
    if(index < strLength) {
        return data[index];
    }
    throw std::out_of_range{"invalid subscript index"};
}

char String::operator[](const size_t index) const {
    return const_cast<String*>(this)->operator[](index);
}

const char* String::cString() const noexcept {
    return data;
}

bool String::operator==(const String& other) const noexcept {
    if(length() == 0) {
        return other.length() == 0;
    }
    return std::strcmp(cString(), other.cString()) == 0;
}

bool String::operator!=(const String& other) const noexcept {
    return !operator==(other);
}

bool String::operator<(const String& other) const noexcept {
    if(length() == 0) {
        return other.length() > 0;
    }
    return  std::strcmp(cString(), other.cString()) < 0;
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

static bool isDelimiter(char symbol) noexcept {
    return (symbol == ' ') || (symbol == '\t') || (symbol == '\n');
}

std::istream& operator>>(std::istream& in, String& string) {
    size_t capacity = 10;
    size_t size = 0;
    char* buffer = new char[capacity];
    char* temp = nullptr;
    char symbol = in.peek();
    if(isDelimiter(symbol)) {
        in.ignore();
    }
    while(true) {
        symbol = in.get();
        if(size == capacity) {
            capacity = 2 * capacity + 1;
            temp = new char[capacity];
            std::memcpy(temp, buffer, size);
            delete[] buffer;
            buffer = temp;
        }
        if(isDelimiter(symbol) || in.eof()) {
            buffer[size] = '\0';
            string = {buffer};
            delete[] buffer;
            return in;
        }
        buffer[size] = symbol;
        ++size;
    }
}

std::ostream& operator<<(std::ostream& out, const String& string) {
    return out << string.cString();
}