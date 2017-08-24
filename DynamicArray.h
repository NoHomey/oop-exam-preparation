#pragma once

#include <cstddef>

template<typename Type>
class DynamicArray {
public:
    DynamicArray() noexcept;

    ~DynamicArray() noexcept;

    explicit DynamicArray(size_t capacity);

    DynamicArray(const DynamicArray& other);

    DynamicArray(DynamicArray&& other) noexcept;

    DynamicArray& operator=(const DynamicArray& other);

    DynamicArray& operator=(DynamicArray&& other);

public:
    size_t size() const noexcept;

    size_t capacity() const noexcept;

    const Type* data() const noexcept;

    bool isEmpty() const noexcept;
    
    bool isFull() const noexcept;

    Type& operator[](size_t index);

    const Type& operator[](size_t index) const;

    void extend(size_t size);

    void push(const Type& element);
    
    void pop();
    
    void shrinkToFit();

private:
    void copyOtherArray(const DynamicArray& other) noexcept;
    
    void null() noexcept;
    
    void moveOther(DynamicArray&& other) noexcept;

protected:
    size_t arraySize;

    size_t arrayCapacity;

    Type* array;
};

#include "DynamicArray.cc"