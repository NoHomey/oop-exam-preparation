#include "Pencil.h"

Pencil::Pencil() noexcept
: WritingInstrument{}, hardness{0} { }

Pencil::Hardness Pencil::getHardness() const noexcept {
    return hardness;
}

void Pencil::setHardness(Hardness newHardness) noexcept {
    hardness = newHardness;
}

std::istream& Pencil::read(std::istream& in) {
    Pencil::Hardness newHardness;
    WritingInstrument::read(in);
    in >> newHardness;
    setHardness(newHardness);
    return in;
}

std::ostream& Pencil::write(std::ostream& out) const {
    WritingInstrument::write(out);
    return out << ", " << getHardness();
}

std::istream& operator>>(std::istream& in, Pencil& pencil) {
    return pencil.read(in);
}
    
std::ostream& operator<<(std::ostream& out, const Pencil& pencil) {
    return pencil.write(out);
}