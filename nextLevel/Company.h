#pragma once
#include <string>
#include <iostream>

class Company {
public:
    using Project = std::string;

    using Counter = unsigned int;

public:
    Company(const std::string& name);

    virtual ~Company() noexcept;

public:
    bool perform(const Project& project) noexcept;

    double reliabilityRate() const noexcept;

    Counter getSuccessfulProjectsCount() const noexcept;

    Counter getAllProjectsCount() const noexcept;

    const std::string& getName() const noexcept;

    void setName(const std::string& newName);

public:
    virtual Company* clone() const = 0;

    virtual void print(std::ostream& out) const = 0;

protected:
    virtual bool performProject(const Project& project) const noexcept = 0;

protected:
    std::string name;

    Counter successfulProjects;

    Counter allProjects;
};