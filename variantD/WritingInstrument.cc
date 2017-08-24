#include "WritingInstrument.h"

WritingInstrument::WritingInstrument() noexcept
: brand{}, year{0} { }

const String& WritingInstrument::getBrand() const noexcept {
    return brand;
}

WritingInstrument::Year WritingInstrument::getYear() const noexcept {
    return year;
}

void WritingInstrument::setBrand(const String& newBrand) {
    brand = newBrand;
}

void WritingInstrument::setBrand(String&& newBrand) noexcept {
    brand = std::move(newBrand);
}

void WritingInstrument::setYear(Year newYear) noexcept {
    year = newYear;
}

std::istream& operator>>(std::istream& in, WritingInstrument& writingInstrument) {
    String brand;
    WritingInstrument::Year year;
    in >> brand >> year;
    writingInstrument.setBrand(std::move(brand));
    writingInstrument.setYear(year);
    return in;
}
    
std::ostream& operator<<(std::ostream& out, const WritingInstrument& writingInstrument) {
    return out << writingInstrument.getBrand() << ", " << writingInstrument.getYear();
}