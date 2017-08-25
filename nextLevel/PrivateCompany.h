#pragma once

#include "Company.h"

class PrivateCompany: public Company {
public:
    PrivateCompany(const std::string& name, Counter successfulRate);

public:
    Counter getsuccessfulRate() const noexcept;

    bool performProject(const Project& project) const noexcept final;
    
    void print(std::ostream& out) const final;
    
    Company* clone() const final;

private:
    Counter successfulRate;
};