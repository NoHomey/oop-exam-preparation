#pragma once

#include <cstddef>
#include <iostream>

class String {
public:
    String() noexcept;

    ~String() noexcept;

    String(const String& other);

    String(String&& other) noexcept;

    String& operator=(const String& other);
    
    String& operator=(String&& other) noexcept;

    String(const char* string);

private:
    String(const char* string, size_t length);

public:
    size_t length() const noexcept;

    char& operator[](const size_t index);

    char operator[](const size_t index) const;

    const char* cString() const noexcept;

    bool operator==(const String& other) const noexcept;

    bool operator!=(const String& other) const noexcept;

    bool operator<(const String& other) const noexcept;

    bool operator>(const String& other) const noexcept;

    bool operator<=(const String& other) const noexcept;

    bool operator>=(const String& other) const noexcept;

private:
    static char* copyString(const char* string, size_t length);

    static size_t stringLength(const char* string) noexcept;

private:
    void null() noexcept;

    void moveOther(String&& string) noexcept;

private:
    char* data;

    size_t strLength;
};

std::istream& operator>>(std::istream& in, String& string);

std::ostream& operator<<(std::ostream& out, const String& string);