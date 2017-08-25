#pragma once

#include "String.h"

class WritingInstrument {
public:
    using Year = unsigned short;

public:
    WritingInstrument() noexcept;
    
    virtual ~WritingInstrument() noexcept = default;
    
    WritingInstrument(const WritingInstrument& other) = default;
    
    WritingInstrument(WritingInstrument&& other) noexcept = default;
    
    WritingInstrument& operator=(const WritingInstrument& other) = default;
        
    WritingInstrument& operator=(WritingInstrument&& other) noexcept = default;


public:
    const String& getBrand() const noexcept;

    Year getYear() const noexcept;

    void setBrand(const String& newBrand);

    void setBrand(String&& newBrand) noexcept;

    void setYear(Year newYear) noexcept;

    virtual std::istream& read(std::istream& in);

    virtual std::ostream& write(std::ostream& out) const;

protected:
    String brand;

    Year year;
};

std::istream& operator>>(std::istream& in, WritingInstrument& writingInstrument);

std::ostream& operator<<(std::ostream& out, const WritingInstrument& writingInstrument);