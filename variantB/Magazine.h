#pragma once

#include "Publication.h"

class Magazine: public Publication {
public:
    using Count = unsigned int;

public:
    Magazine() noexcept;
    
    ~Magazine() noexcept = default;
    
    Magazine(const Magazine& other) = default;
    
    Magazine(Magazine&& other) noexcept = default;
    
    Magazine& operator=(const Magazine& other) = default;
    
    Magazine& operator=(Magazine&& other) = default;

public:
    Count getCount() const noexcept;

    void setCount(Count newCount) noexcept;

private:
    Count count;
};

std::istream& operator>>(std::istream& in, Magazine& magazine);

std::ostream& operator<<(std::ostream& out, const Magazine& magazine);