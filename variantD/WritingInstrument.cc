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

std::istream& WritingInstrument::read(std::istream& in) {
    String newBrand;
    WritingInstrument::Year newYear;
    in >> newBrand >> newYear;
    setBrand(std::move(newBrand));
    setYear(newYear);
    return in;
}

std::ostream& WritingInstrument::write(std::ostream& out) const {
    return out << getBrand() << ", " << getYear();
}

std::istream& operator>>(std::istream& in, WritingInstrument& writingInstrument) {
    return writingInstrument.read(in);
}
    
std::ostream& operator<<(std::ostream& out, const WritingInstrument& writingInstrument) {
    return writingInstrument.write(out);
}