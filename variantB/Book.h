#pragma once

#include "Publication.h"

class Book: public Publication {
public:
    Book() noexcept = default;
    
    ~Book() noexcept = default;
    
    Book(const Book& other) = default;
    
    Book(Book&& other) noexcept = default;
    
    Book& operator=(const Book& other) = default;
    
    Book& operator=(Book&& other) = default;

public:
    const String& getAuthor() const noexcept;

    void setAuthor(const String& newAuthrow);

    void setAuthrow(String&& newAuthor);

private:
    String author;
};

std::istream& operator>>(std::istream& in, Book& book);

std::ostream& operator<<(std::ostream& out, const Book& book);