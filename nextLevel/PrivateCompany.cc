#include "PrivateCompany.h"
#include <stdexcept>

PrivateCompany::PrivateCompany(const std::string& name, Counter successfulRate)
: Company{name}, successfulRate{successfulRate} {
    if(successfulRate == 0) {
        throw std::invalid_argument{"rate of success can not be zero!"};
    }
}

PrivateCompany::Counter PrivateCompany::getsuccessfulRate() const noexcept {
    return successfulRate;
}

bool PrivateCompany::performProject(const Project&) const noexcept {
    return ((getAllProjectsCount() + 1) % successfulRate) != 0;
}
    
void PrivateCompany::print(std::ostream& out) const {
    out << "private: " << successfulRate << ' ' << getName();
}
    
Company* PrivateCompany::clone() const {
    return new PrivateCompany(*this);
}