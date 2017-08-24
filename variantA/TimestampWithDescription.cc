#include "TimestampWithDescription.h"
#include <cstring>

TimestampWithDescription::TimestampWithDescription() noexcept
: Timestamp{}, description{nullptr} { }

TimestampWithDescription::~TimestampWithDescription() noexcept {
    delete[] description;
}

char* TimestampWithDescription::copyDescription(const char* description) {
    if(description == nullptr) {
        return nullptr;
    }
    const size_t otherDescriptionLength = std::strlen(description);
    if(otherDescriptionLength == 0) {
        return nullptr;
    }
    const size_t count = otherDescriptionLength + 1;
    char* copy = new char[count];
    std::memcpy(copy, description, count);
    return copy;
}

TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& other)
: Timestamp{other}, description{nullptr} {
    SetDescription(other.description);
}

TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& other) {
    if(this != &other) {
        SetDescription(other.description);
        SetValue(other.GetValue());
    }
    return *this;
}

const char* TimestampWithDescription::GetDescription() const noexcept {
    return description;
}

void TimestampWithDescription::SetDescription(const char* description) {
    char* copy = copyDescription(description);
    delete[] this->description;
    this->description = copy;
}

std::istream& operator>>(std::istream& in, TimestampWithDescription& timestampWithDescription) {
    in >> static_cast<Timestamp&>(timestampWithDescription);
    in.ignore();
    const size_t chunk = 10;
    char * buffer = new char[chunk];
    size_t extra = 0;
    char* temp = nullptr;
    while(true) {
        in.getline(buffer + extra, chunk);
        if(in.good() || in.eof()) {
            break;
        }
        extra += in.gcount();
        temp = new char[chunk + extra];
        memcpy(temp, buffer, extra);
        delete[] buffer;
        buffer = temp;
        if(in.fail()) {
            in.clear();
        }
    }
    timestampWithDescription.SetDescription(buffer);
    delete[] buffer;
    return in;
}

std::ostream& operator<<(std::ostream& out, const TimestampWithDescription& timestampWithDescription) {
    out << timestampWithDescription.GetValue() << ' ' << timestampWithDescription.GetDescription();
    return out;
}