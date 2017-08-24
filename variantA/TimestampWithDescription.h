#pragma once

#include "Timestamp.h"

class TimestampWithDescription: public Timestamp {
public:
    TimestampWithDescription() noexcept;

    ~TimestampWithDescription() noexcept;

    TimestampWithDescription(const TimestampWithDescription& other);

    TimestampWithDescription& operator=(const TimestampWithDescription& other);

public:
    const char* GetDescription() const noexcept;

    void SetDescription(const char* description);

private:
    static char* copyDescription(const char* description);

private:
    char* description;
};

std::istream& operator>>(std::istream& in, TimestampWithDescription& timestampWithDescription);

std::ostream& operator<<(std::ostream& out, const TimestampWithDescription& timestampWithDescription);