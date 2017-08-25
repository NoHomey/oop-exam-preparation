#pragma once

#include "Company.h"
#include <vector>

class Consortium: public Company {
public:
    Consortium(const std::string& name);

    ~Consortium() noexcept;

    Consortium(const Consortium& other);

    Consortium& operator=(const Consortium& other);

public:
    bool performProject(const Project& project) const noexcept final;
    
    void print(std::ostream& out) const final;
    
    Company* clone() const final;

public:
    void addCompany(Company* company);

    void removeCompany(const std::string& name);

    void printStatus(std::ostream& out) const;

private:
    void removeAll() noexcept;

    void copy(const Consortium& other);

private:
    std::vector<Company*> companies;
};