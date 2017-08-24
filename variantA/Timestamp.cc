#include "Timestamp.h"

Timestamp::Timestamp() noexcept
: timestamp{0} { }

Timestamp::Timestamp(Time timestamp) noexcept
: timestamp{timestamp} { }

void Timestamp::SetValue(Time timestamp) noexcept {
    this->timestamp = timestamp;
}

Timestamp::Time Timestamp::GetValue() const noexcept {
    return timestamp;
}

Timestamp& Timestamp::operator+=(int time) noexcept {
    timestamp += time;
    return *this;
}

Timestamp Timestamp::operator+(int time) const noexcept {
    Timestamp copy{*this};
    copy += time;
    return copy;
}

std::istream& operator>>(std::istream& in, Timestamp& timestamp) {
    Timestamp::Time time;
    in >> time;
    timestamp.SetValue(time);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Timestamp& timestamp) {
    out << timestamp.GetValue();
    return out;
}