#pragma once

#include "DynamicArray.h"
#include <utility>
#include <stdexcept>

template<typename Element>
DynamicArray<Element>::DynamicArray() noexcept
: arraySize{0}, arrayCapacity{0}, array{nullptr} { }

template<typename Element>
DynamicArray<Element>::~DynamicArray() noexcept {
    delete[] array;
}

template<typename Element>
DynamicArray<Element>::DynamicArray(size_t capacity)
: DynamicArray{} {
    if(capacity > 0) {
        array = new Element[capacity];
        arrayCapacity = capacity;
    }
}

template<typename Element>
void DynamicArray<Element>::copyOtherArray(const DynamicArray& other) noexcept {
    for(; arraySize < other.arraySize; ++arraySize) {
        array[arraySize] = other.array[arraySize];
    }
}

template<typename Element>
DynamicArray<Element>::DynamicArray(const DynamicArray& other)
: DynamicArray{other.arraySize} {
    copyOtherArray(other);
}

template<typename Element>
void DynamicArray<Element>::null() noexcept {
    array = nullptr;
    arraySize = 0;
    arrayCapacity = 0;
}

template<typename Element>
void DynamicArray<Element>::moveOther(DynamicArray&& other) noexcept {
    delete array;
    array = other.array;
    arraySize = other.arraySize;
    arrayCapacity = other.arrayCapacity;
    other.null();
}

template<typename Element>
DynamicArray<Element>::DynamicArray(DynamicArray&& other) noexcept
: DynamicArray{} {
    moveOther(std::move(other));
}

template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(const DynamicArray& other) {
    if(this != &other) {
        DynamicArray copy{other};
        moveOther(std::move(copy));
    }
    return *this;
}

template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(DynamicArray&& other) noexcept {
    if(this != &other) {
        moveOther(std::move(other));
    }
    return *this;
}

template<typename Element>
size_t DynamicArray<Element>::size() const noexcept {
    return arraySize;
}

template<typename Element>
size_t DynamicArray<Element>::capacity() const noexcept {
    return arrayCapacity;
}

template<typename Element>
const Element* DynamicArray<Element>::data() const noexcept {
    return array;
}

template<typename Element>
bool DynamicArray<Element>::isEmpty() const noexcept {
    return arraySize == 0;
}

template<typename Element>
bool DynamicArray<Element>::isFull() const noexcept {
    return arraySize == arrayCapacity;
}

template<typename Element>
Element& DynamicArray<Element>::operator[](size_t index) {
    if(index < arraySize) {
        return array[index];
    }
    throw std::out_of_range("invalid index");
}

template<typename Element>
const Element& DynamicArray<Element>::operator[](size_t index) const {
    return const_cast<DynamicArray* const>(this)->operator[](index);
}

template<typename Element>
void DynamicArray<Element>::extend(size_t size) {
    if(size > 0) {
        DynamicArray extended{arrayCapacity + size};
        extended.copyOtherArray(*this);
        moveOther(std::move(extended));
    }
}

template<typename Element>
void DynamicArray<Element>::push(const Element& element) {
    if(isFull()) {
        extend(arraySize + 2);
    }
    array[arraySize] = element;
    ++arraySize;
}

template<typename Element>
void DynamicArray<Element>::pop() {
    if(isEmpty()) {
        throw std::logic_error{"array is empty"};
    }
    --arraySize;
}

template<typename Element>
void DynamicArray<Element>::shrinkToFit() {
    DynamicArray copy{*this};
    moveOther(std::move(copy));
}

template<typename Element>
void DynamicArray<Element>::clear() noexcept {
    delete[] array;
    null();
}