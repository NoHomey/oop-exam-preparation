#include "String.h"
#include <cstring>
#include <stdexcept>
#include <utility>

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
: data{nullptr}, strLength{length} {
    data = copyString(string, length);
}

String::String(const String& other)
: String{other.data, other.strLength} { }

String& String::operator=(const String& other) {
    if(this != &other) {
        String copy{other};
        moveOther(std::move(copy));
    }
    return *this;
}

void String::null() noexcept {
    data = nullptr;
    strLength = 0;
}

void String::moveOther(String&& other) noexcept {
    delete[] data;
    data = other.data;
    strLength = other.strLength;
    other.null();
}

String::String(String&& other) noexcept
: String{} {
    moveOther(std::move(other));
}

String& String::operator=(String&& other) {
    if(this != &other) {
        moveOther(std::move(other));
    }
    return *this;
}

size_t String::stringLength(const char* string) noexcept {
    return string == nullptr ? 0 : std::strlen(string);
}

String::String(const char* string)
: String{string, stringLength(string)} { }

size_t String::length() const noexcept {
    return strLength;
}

char String::operator[](size_t index) const {
    if(index < strLength) {
        return data[index];
    }
    throw std::out_of_range{"invalid subscript index"};
}

const char* String::cString() const noexcept {
    return data;
}

static bool isDelimiter(char symbol) {
    return (symbol == ' ') || (symbol == '\t') || (symbol == '\n');
}

std::istream& operator>>(std::istream& in, String& string) {
    size_t capacity = 10;
    size_t size = 0;
    char* buffer = new char[capacity];
    char* temp;
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
    out << string.cString();
    return out;
}