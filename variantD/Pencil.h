#pragma once

#include "WritingInstrument.h"

class Pencil: public WritingInstrument {
public:
    using Hardness = unsigned char;

public:
    Pencil() noexcept;
    
    ~Pencil() noexcept = default;
    
    Pencil(const Pencil& other) = default;
    
    Pencil(Pencil&& other) noexcept = default;
    
    Pencil& operator=(const Pencil& other) = default;
        
    Pencil& operator=(Pencil&& other) noexcept = default;

public:
    Hardness getHardness() const noexcept;

    void setHardness(Hardness newHardness) noexcept;

private:
    Hardness hardness;
};

std::istream& operator>>(std::istream& in, Pencil& pencil);

std::ostream& operator<<(std::ostream& out, const Pencil& pencil);