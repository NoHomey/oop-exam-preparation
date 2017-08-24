#pragma once

#include "DynamicArray.h"
#include <utility>
#include <stdexcept>

template<typename Type>
DynamicArray<Type>::DynamicArray() noexcept
: arraySize{0}, arrayCapacity{0}, array{nullptr} { }

template<typename Type>
DynamicArray<Type>::~DynamicArray() noexcept {
    delete[] array;
}

template<typename Type>
DynamicArray<Type>::DynamicArray(size_t capacity)
: DynamicArray{} {
    if(capacity > 0) {
        array = new Type[capacity];
        arrayCapacity = capacity;
    }
}

template<typename Type>
void DynamicArray<Type>::copyOtherArray(const DynamicArray& other) noexcept {
    for(; arraySize < other.arraySize; ++arraySize) {
        array[arraySize] = other.array[arraySize];
    }
}

template<typename Type>
DynamicArray<Type>::DynamicArray(const DynamicArray& other)
: DynamicArray{other.arraySize} {
    copyOtherArray(other);
}

template<typename Type>
void DynamicArray<Type>::null() noexcept {
    array = nullptr;
    arraySize = 0;
    arrayCapacity = 0;
}

template<typename Type>
void DynamicArray<Type>::moveOther(DynamicArray&& other) noexcept {
    delete[] array;
    array = other.array;
    arraySize = other.arraySize;
    arrayCapacity = other.arrayCapacity;
    other.null();
}

template<typename Type>
DynamicArray<Type>::DynamicArray(DynamicArray&& other) noexcept
: DynamicArray{} {
    moveOther(std::move(other));
}

template<typename Type>
DynamicArray<Type>& DynamicArray<Type>::operator=(const DynamicArray& other) {
    if(this != &other) {
        DynamicArray<Type> copy{other};
        moveOther(std::move(copy));
    }
    return *this;
}

template<typename Type>
DynamicArray<Type>& DynamicArray<Type>::operator=(DynamicArray&& other) noexcept {
    if(this != &other) {
        mmoveOther(std::move(other));
    }
    return *this;
}

template<typename Type>
size_t DynamicArray<Type>::size() const noexcept {
    return arraySize;
}

template<typename Type>
size_t DynamicArray<Type>::capacity() const noexcept {
    return arrayCapacity;
}

template<typename Type>
const Type* DynamicArray<Type>::data() const noexcept {
    return array;
}

template<typename Type>
bool DynamicArray<Type>::isEmpty() const noexcept {
    return arraySize == 0;
}
    
template<typename Type>
bool DynamicArray<Type>::isFull() const noexcept {
    return arraySize == arrayCapacity;
}

template<typename Type>
Type& DynamicArray<Type>::operator[](size_t index) {
    if(index < arraySize) {
        return array[index];
    }
    throw std::out_of_range("index is out of range");
}

template<typename Type>
const Type& DynamicArray<Type>::operator[](size_t index) const {
    return const_cast<DynamicArray<Type>* const>(this)->operator[](index);
}

template<typename Type>
void DynamicArray<Type>::extend(size_t size) {
    if(size > 0) {
        DynamicArray<Type> extened{arrayCapacity + size};
        extened.copyOtherArray(*this);
        moveOther(std::move(extened));
    }
}

template<typename Type>
void DynamicArray<Type>::push(const Type& element) {
    if(isFull()) {
        extend(arraySize + 2);
    }
    array[arraySize] = element;
    ++arraySize;
}
    
template<typename Type>
void DynamicArray<Type>::pop() {
    if(isEmpty()) {
        throw std::logic_error("array is empty");
    }
    --arraySize;
}

template<typename Type>
void DynamicArray<Type>::shrinkToFit() {
    DynamicArray<Type> copy{*this};
    moveOther(std::move(copy));
}