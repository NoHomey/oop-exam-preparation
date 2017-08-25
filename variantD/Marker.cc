#include "Marker.h"

const String& Marker::getColor() const noexcept {
    return color;
}

void Marker::setColor(const String& newColor) {
    color = newColor;
}

void Marker::setColor(String&& newColor) noexcept {
    color = std::move(newColor);
}

std::istream& Marker::read(std::istream& in) {
    String newColor;
    WritingInstrument::read(in);
    in >> newColor;
    setColor(newColor);
    return in;
}

std::ostream& Marker::write(std::ostream& out) const {
    WritingInstrument::write(out);
    return out << ", " << getColor();
}

/*std::istream& operator>>(std::istream& in, Marker& marker) {
    return marker.read(in);
}
    
std::ostream& operator<<(std::ostream& out, const Marker& marker) {
    return marker.write(out);
}*/