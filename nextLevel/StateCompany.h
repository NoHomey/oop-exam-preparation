#pragma once

#include "Company.h"

class StateCompany: public Company {
public:
    StateCompany(const std::string& name);

public:
    bool performProject(const Project& project) const noexcept final;
    
    void print(std::ostream& out) const final;
    
    Company* clone() const final;

private:
    static const Counter successfulRate = 20;
};