#pragma once

#include <cstddef>

template<typename Element>
class DynamicArray {
public:
    DynamicArray() noexcept;

    ~DynamicArray() noexcept;

    explicit DynamicArray(size_t capacity);

    DynamicArray(const DynamicArray& other);

    DynamicArray(DynamicArray&& other) noexcept;

    DynamicArray& operator=(const DynamicArray& other);
    
    DynamicArray& operator=(DynamicArray&& other) noexcept;

public:
    size_t size() const noexcept;

    size_t capacity() const noexcept;

    const Element* data() const noexcept;

    bool isEmpty() const noexcept;

    bool isFull() const noexcept;

    Element& operator[](size_t index);

    const Element& operator[](size_t index) const;

    void extend(size_t size);

    void push(const Element& element);

    void pop();

    void shrinkToFit();

    void clear() noexcept;

private:
    void copyOtherArray(const DynamicArray& other) noexcept;

    void null() noexcept;

    void moveOther(DynamicArray&& other) noexcept;

protected:
    size_t arraySize;

    size_t arrayCapacity;

    Element* array;
};

#include "DynamicArray.cc"