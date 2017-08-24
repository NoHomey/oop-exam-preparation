#pragma once

#include <iostream>

class Timestamp {
public:
    using Time = unsigned long;

public:
    Timestamp() noexcept;

    Timestamp(Time timestamp) noexcept;

public:
    void SetValue(Time timestamp) noexcept;

    Time GetValue() const noexcept;

public:
    Timestamp& operator+=(int time) noexcept;

    Timestamp operator+(int time) const noexcept;

private:
    Time timestamp;
};

std::istream& operator>>(std::istream& in, Timestamp& timestamp);

std::ostream& operator<<(std::ostream& out, const Timestamp& timestamp);