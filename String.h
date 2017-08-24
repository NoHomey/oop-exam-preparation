#pragma once

#include "DynamicArray.h"
#include <iostream>

class String {
public:
    String();

    ~String() noexcept = default;

    String(const char* content);

    String(const String& other) = default;

    String(String&& other) noexcept = default;

    String& operator=(const String& other) = default;

    String& operator=(String&& other) noexcept = default;

public:
    size_t length() const noexcept;

    const char* cString() const noexcept;

    char& operator[](size_t index);

    char operator[](size_t index) const;

    bool operator==(const String& other) const noexcept;

    bool operator!=(const String& other) const noexcept;

    bool operator<(const String& other) const noexcept;
    
    bool operator>(const String& other) const noexcept;

    bool operator<=(const String& other) const noexcept;
    
    bool operator>=(const String& other) const noexcept;

    String& operator+=(const String& other);

    String operator+(const String& other) const;

    friend std::istream& operator>>(std::istream& in, String& string);

private:
    static size_t calculateLength(const char* string) noexcept;

private:
    DynamicArray<char> string;
};

std::istream& operator>>(std::istream& in, String& string);

std::ostream& operator<<(std::ostream& out, const String& string);