#include "Pencil.h"

Pencil::Pencil() noexcept
: WritingInstrument{}, hardness{0} { }

Pencil::Hardness Pencil::getHardness() const noexcept {
    return hardness;
}

void Pencil::setHardness(Hardness newHardness) noexcept {
    hardness = newHardness;
}

std::istream& operator>>(std::istream& in, Pencil& pencil) {
    Pencil::Hardness hardness;
    in >> static_cast<WritingInstrument&>(pencil) >> hardness;
    pencil.setHardness(hardness);
    return in;
}
    
std::ostream& operator<<(std::ostream& out, const Pencil& pencil) {
    return out << static_cast<const WritingInstrument&>(pencil) << ", " << pencil.getHardness();
}