#pragma once

#include "String.h"

class Publication {
public:
    using Edition = unsigned int;

public:
    Publication() noexcept;

    ~Publication() noexcept = default;

    Publication(const Publication& other) = default;

    Publication(Publication&& other) noexcept = default;

    Publication& operator=(const Publication& other) = default;

    Publication& operator=(Publication&& other) = default;

public:
    const String& getTitle() const noexcept;

    Edition getEdition() const noexcept;

public:
    void setTitle(const String& newTitle);

    void setTitle(String&& newTitle) noexcept;

    void setEdition(Edition newEdition) noexcept;

protected:
    String title;
    
    Edition edition;
};

std::istream& operator>>(std::istream& in, Publication& publication);

std::ostream& operator<<(std::ostream& out, const Publication& publication);