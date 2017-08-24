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

std::istream& operator>>(std::istream& in, Marker& marker) {
    String color;
    in >> static_cast<WritingInstrument&>(marker) >> color;
    marker.setColor(color);
    return in;
}
    
std::ostream& operator<<(std::ostream& out, const Marker& marker) {
    return out << static_cast<const WritingInstrument&>(marker) << ", " << marker.getColor();
}