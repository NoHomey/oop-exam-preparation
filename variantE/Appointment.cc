#include "Appointment.h"
#include <cstring>
#include <stdexcept>

Appointment::Appointment() noexcept
: timestamp{}, description{new char[1]} {
    description[0] = '\0';
}

Appointment::~Appointment() noexcept {
    delete[] description;
}

Appointment::Appointment(const Appointment& other)
: timestamp{other.GetTimestamp()}, description{nullptr} {
    SetDescription(other.GetDescription());
}


Appointment& Appointment::operator=(const Appointment& other) {
    if(this != &other) {
        SetDescription(other.GetDescription());
        SetTimestamp(other.GetTimestamp());
    }
    return *this;
}

const Timestamp& Appointment::GetTimestamp() const noexcept {
    return timestamp;
}

void Appointment::SetTimestamp(const Timestamp& other) noexcept {
    timestamp.SetValue(other.GetValue());
}

const char* Appointment::GetDescription() const noexcept {
    return description;
}

void Appointment::SetDescription(const char* newDescription) {
    if(newDescription == nullptr) {
        throw std::invalid_argument{"got null pointer"};
    }
    const size_t count = std::strlen(newDescription) + 1;
    char* temp = new char[count];
    std::memcpy(temp, newDescription, count);
    delete[] description;
    description = temp;
}

std::istream& operator>>(std::istream& in, Appointment& appointment) {
    std::time_t timestamp;
    in >> timestamp;
    in.ignore();
    size_t capacity = 10;
    size_t size = 0;
    char* buffer = new char[capacity];
    char* temp = nullptr;
    char symbol;
    while(true) {
        symbol = in.get();
        if(size == capacity) {
            capacity = 2 * capacity + 1;
            temp = new char[capacity];
            std::memcpy(temp, buffer, size);
            delete[] buffer;
            buffer = temp;
        }
        if((symbol == '\n') || in.eof()) {
            buffer[size] = '\0';
            try {
                appointment.SetDescription(buffer);
            } catch(const std::bad_alloc& error) {
                delete[] buffer;
                in.setstate(std::ios_base::badbit | std::ios_base::failbit);
                return in;
            }
            appointment.SetTimestamp({timestamp});
            delete[] buffer;
            return in;
        }
        buffer[size] = symbol;
        ++size;
    }
}

std::ostream& operator<<(std::ostream& out, const Appointment& appointment) {
    return out << appointment.GetTimestamp().GetValue() << ' ' << appointment.GetDescription();
}