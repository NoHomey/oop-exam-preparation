#include "Consortium.h"
#include <algorithm>

Consortium::Consortium(const std::string& name)
: Company{name}, companies{} { }

Consortium::~Consortium() noexcept {
    removeAll();
}

void Consortium::removeAll() noexcept {
    std::for_each(companies.begin(), companies.end(), [](Company* company) {
        delete company;
    });
    companies.clear();
}

void Consortium::copy(const Consortium& other) {
    companies.reserve(other.companies.capacity());
    std::for_each(other.companies.begin(), other.companies.end(), [this](Company* company) {
        companies.push_back(company->clone());
    });
}

Consortium::Consortium(const Consortium& other)
: Consortium{other.getName()} {
    copy(other);
}

Consortium& Consortium::operator=(const Consortium& other) {
    if(this != &other) {
        removeAll();
        setName(other.getName());
        copy(other);
    }
    return *this;
}

bool Consortium::performProject(const Project& project) const noexcept {
    if(companies.empty()) {
        return false;
    }
    std::vector<Company*>::const_iterator min = std::min_element(
        companies.cbegin(),
        companies.cend(),
        [](const Company* a, const Company* b) {
            return a->getAllProjectsCount() < b->getAllProjectsCount();
    });
    return companies[companies.cbegin() - min]->perform(project);
}
    
void Consortium::print(std::ostream& out) const {
    out << "consortium: " << companies.size() << ' ' << getName();
}
    
Company* Consortium::clone() const {
    return new Consortium{*this};
}

void Consortium::addCompany(Company* company) {
    companies.push_back(company);
}

void Consortium::removeCompany(const std::string& name) {
    const std::vector<Company*>::iterator end = companies.end();
    for(std::vector<Company*>::iterator it = companies.begin(); it != end; ++it) {
        if((*it)->getName() == name) {
            delete *it;
            companies.erase(it);
            break;
        }
    }
}

void Consortium::printStatus(std::ostream& out) const {
    size_t counter = 1;
    std::for_each(companies.cbegin(), companies.cend(), [&out, &counter](const Company* company) {
        out << counter << ". " << company->getName() << " reability: " << company->reliabilityRate() << std::endl;
        ++counter;
    });
}
