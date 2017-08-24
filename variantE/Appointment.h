#pragma once

#include "Timestamp.h"
#include <iostream>

class Appointment {
public:
    Appointment() noexcept;

    ~Appointment() noexcept;

    Appointment(const Appointment& other);

    Appointment& operator=(const Appointment& other);

public:
    const Timestamp& GetTimestamp() const noexcept;
    
    void SetTimestamp(const Timestamp& other) noexcept;

    const char* GetDescription() const noexcept;

    void SetDescription(const char* newDescription);

private:
    Timestamp timestamp;

    char* description;
};

std::istream& operator>>(std::istream& in, Appointment& appointment);

std::ostream& operator<<(std::ostream& in, const Appointment& appointment);