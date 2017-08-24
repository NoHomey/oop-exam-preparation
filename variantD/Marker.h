#pragma once

#include "WritingInstrument.h"

class Marker: public WritingInstrument {
public:
    Marker() noexcept = default;
    
    ~Marker() noexcept = default;
    
    Marker(const Marker& other) = default;
    
    Marker(Marker&& other) noexcept = default;
    
    Marker& operator=(const Marker& other) = default;
        
    Marker& operator=(Marker&& other) noexcept = default;

public:
    const String& getColor() const noexcept;

    void setColor(const String& newColor);

    void setColor(String&& newColor) noexcept;

private:
    String color;
};

std::istream& operator>>(std::istream& in, Marker& marker);

std::ostream& operator<<(std::ostream& out, const Marker& marker);