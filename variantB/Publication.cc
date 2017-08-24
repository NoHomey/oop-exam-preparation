#include "Publication.h"

Publication::Publication() noexcept
: title{}, edition{0} { }

const String& Publication::getTitle() const noexcept {
    return title;
}

Publication::Edition Publication::getEdition() const noexcept {
    return edition;
}

void Publication::setTitle(const String& newTitle) {
    title = newTitle;
}

void Publication::setTitle(String&& newTitle) noexcept {
    title = std::move(newTitle);
}

void Publication::setEdition(Edition newEdition) noexcept {
    edition = newEdition;
}

std::istream& operator>>(std::istream& in, Publication& publication) {
    Publication::Edition edition;
    String title;
    in >> title;
    in >> edition;
    publication.setTitle(std::move(title));
    publication.setEdition(edition);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Publication& publication) {
    out << publication.getTitle() << ", " << publication.getEdition();
    return out;
}