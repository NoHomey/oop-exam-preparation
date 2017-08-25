#include "StateCompany.h"

StateCompany::StateCompany(const std::string& name)
: Company{name} { }

bool StateCompany::performProject(const Project&) const noexcept {
    return ((getAllProjectsCount() + 1) % successfulRate) != 0;
}
    
void StateCompany::print(std::ostream& out) const {
    out << "state: " << getName();
}
    
Company* StateCompany::clone() const {
    return new StateCompany(*this);
}