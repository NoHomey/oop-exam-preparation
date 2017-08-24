#pragma once

#include <ctime>

class Timestamp {
public:
    Timestamp() noexcept;

    Timestamp(std::time_t timestamp);

public:
    std::time_t GetValue() const noexcept;

    void SetValue(std::size_t newTimestamp) noexcept;

    bool operator==(const Timestamp& other) const noexcept;

    bool operator!=(const Timestamp& other) const noexcept;

    bool operator<(const Timestamp& other) const noexcept;
    
    bool operator>(const Timestamp& other) const noexcept;

    bool operator<=(const Timestamp& other) const noexcept;
    
    bool operator>=(const Timestamp& other) const noexcept;

private:
    std::time_t timestamp;
};