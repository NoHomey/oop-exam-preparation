#include "Company.h"

Company::Company(const std::string& name)
: name{name}, successfulProjects{0}, allProjects{0} { }

Company::~Company() noexcept { }

bool Company::perform(const Project& project) noexcept {
    const bool success = performProject(project);
    ++allProjects;
    if(success) {
        ++successfulProjects;
    }
    return success;
}

double Company::reliabilityRate() const noexcept {
    if(allProjects == 0) {
        return 0;
    }
    return static_cast<double>(successfulProjects) / static_cast<double>(allProjects);
}

Company::Counter Company::getSuccessfulProjectsCount() const noexcept {
    return successfulProjects;
}

Company::Counter Company::getAllProjectsCount() const noexcept {
    return allProjects;
}

const std::string& Company::getName() const noexcept {
    return name;
}

void Company::setName(const std::string& newName) {
    name = newName;
}