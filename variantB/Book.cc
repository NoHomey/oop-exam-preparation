#include "Book.h"

const String& Book::getAuthor() const noexcept {
    return author;
}

void Book::setAuthor(const String& newAuthrow) {
    author = newAuthrow;
}

void Book::setAuthrow(String&& newAuthor) {
    author = std::move(newAuthor);
}

std::istream& operator>>(std::istream& in, Book& book) {
    String author;
    in >> static_cast<Publication&>(book);
    in >> author;
    book.setAuthor(std::move(author));
    return in;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << static_cast<const Publication&>(book) << ", " << book.getAuthor();
    return out;
}