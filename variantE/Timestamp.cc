#include "Timestamp.h"

Timestamp::Timestamp() noexcept
: Timestamp{std::time(nullptr)} { }

Timestamp::Timestamp(std::time_t timestamp)
: timestamp{timestamp} { }

std::time_t Timestamp::GetValue() const noexcept {
    return timestamp;
}

void Timestamp::SetValue(std::size_t newTimestamp) noexcept {
    timestamp = newTimestamp;
}

bool Timestamp::operator==(const Timestamp& other) const noexcept {
    return timestamp == other.timestamp;
}

bool Timestamp::operator!=(const Timestamp& other) const noexcept {
    return !operator==(other);
}

bool Timestamp::operator<(const Timestamp& other) const noexcept {
    return timestamp < other.timestamp;
}
    
bool Timestamp::operator>(const Timestamp& other) const noexcept {
    return other < *this;
}

bool Timestamp::operator<=(const Timestamp& other) const noexcept {
    return !operator>(other);
}
    
bool Timestamp::operator>=(const Timestamp& other) const noexcept {
    return !operator<(other);
}