#pragma once

#include <iostream>

class String {
public:
    String() noexcept;

    ~String() noexcept;

    String(const String& other);

    String& operator=(const String& other);

    String(String&& other) noexcept;
    
    String& operator=(String&& other);

    String(const char* string);

public:
    size_t length() const noexcept;

    char operator[](size_t index) const;

    const char* cString() const noexcept;

private:
    String(const char* string, size_t length);

private:
    static char* copyString(const char* string, size_t length);

    static size_t stringLength(const char* string) noexcept;

private:
    void null() noexcept;

    void moveOther(String&& other) noexcept;

private:
    char* data;

    size_t strLength;
};

std::istream& operator>>(std::istream& in, String& string);

std::ostream& operator<<(std::ostream& out, const String& string);