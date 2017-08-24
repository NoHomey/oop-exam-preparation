#include "Magazine.h"

Magazine::Magazine() noexcept
: Publication{}, count{0} { }

Magazine::Count Magazine::getCount() const noexcept {
    return count;
}

void Magazine::setCount(Magazine::Count newCount) noexcept {
    count = newCount;
}

std::istream& operator>>(std::istream& in, Magazine& magazine) {
    Magazine::Count count;
    in >> static_cast<Publication&>(magazine);
    in >> count;
    magazine.setCount(count);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Magazine& magazine) {
    out << static_cast<const Publication&>(magazine) << ", " << magazine.getCount();
    return out;
}