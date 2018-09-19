// fn45342_prob1_oopprakt.cpp : Defines the entry point for the console application.
//

/////////////////////////////////////////////////////////////
//
// Author: ��� �������
// FN: 45342
// Program: �����������
// Date: 31.08.2017
//

//#include "stdafx.h"
#include <cstddef>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <new>

template<typename Element>
class DynamicArray {
public:
	DynamicArray() noexcept
		: arraySize{0}, arrayCapacity{0}, array{nullptr} { }

	~DynamicArray() noexcept {
		delete[] array;
	}

	explicit DynamicArray(size_t capacity)
		: DynamicArray{} {
		if (capacity > 0) {
			array = new Element[capacity];
			arrayCapacity = capacity;
		}
	}

	void copyOther(const DynamicArray& other) noexcept {
		for (arraySize = 0; arraySize < other.arraySize; ++arraySize) {
			array[arraySize] = other.array[arraySize];
		}
	}

	DynamicArray(const DynamicArray& other)
		: DynamicArray{ other.arraySize } {
		copyOther(other);
	}

	void null() noexcept {
		array = nullptr;
		arraySize = 0;
		arrayCapacity = 0;
	}

	void moveOther(DynamicArray&& other) noexcept {
		delete[] array;
		array = other.array;
		arraySize = other.arraySize;
		arrayCapacity = other.arrayCapacity;
		other.null();
	}

	DynamicArray(DynamicArray&& other) noexcept
		: DynamicArray{} {
		moveOther(std::move(other));
	}

	DynamicArray& operator=(const DynamicArray& other) {
		if (this != &other) {
			DynamicArray copy{ other };
			moveOther(std::move(copy));
		}
		return *this;
	}

	DynamicArray& operator=(DynamicArray&& other) noexcept {
		if (this != &other) {
			moveOther(std::move(other));
		}
		return *this;
	}

public:
	size_t size() const noexcept {
		return arraySize;
	}

	size_t capacity() const noexcept {
		return arrayCapacity;
	}

	const Element* data() const noexcept {
		return array;
	}

	bool isEmpty() const noexcept {
		return arraySize == 0;
	}

	bool isFull() const noexcept {
		return arraySize == arrayCapacity;
	}

	Element& operator[](size_t index) {
		if (index < arraySize) {
			return array[index];
		}
		throw std::out_of_range{ "invalid index" };
	}

	const Element& operator[](size_t index) const {
		return const_cast<DynamicArray* const>(this)->operator[](index);
	}

	void extend(size_t grow) {
		if (grow > 0) {
			DynamicArray extended{ arrayCapacity + grow };
			extended.copyOther(*this);
			moveOther(std::move(extended));
		}
	}

	void push(const Element& element) {
		if (isFull()) {
			extend( arraySize + 2 );
		}
		array[arraySize] = element;
		++arraySize;
	}

	void pop() {
		if (isEmpty()) {
			throw std::logic_error{ "pop-ing empty array" };
		}
		--arraySize;
	}

private:
	size_t arraySize;

	size_t arrayCapacity;

	Element* array;
};


class String {
private:
	using Data = DynamicArray<char>;

public:
	String()
		: data{ 1 } {
		data.push('\0');
	}

	~String() noexcept = default;

	String(const char* content)
		: data{} {
		if (content == nullptr) {
			throw std::invalid_argument{ "nullptr is invalid string" };
		}
		const size_t count = std::strlen(content) + 1;
		data = Data{ count };
		for (size_t index = 0; index < count; ++index) {
			data.push(content[index]);
		}
	}

	String(const String& other) = default;

	String(String&& other) noexcept = default;

	String& operator=(const String& other) = default;

	String& operator=(String&& other) noexcept = default;

public:
	size_t length() const noexcept {
		return data.size() - 1;
	}

	char& operator[](size_t index) {
		return data[index];
	}

	char operator[](size_t index) const {
		return data[index];
	}

	const char* cString() const noexcept {
		return data.data();
	}

	bool operator==(const String& other) const noexcept {
		return std::strcmp(cString(), other.cString()) == 0;
	}

	bool operator!=(const String& other) const noexcept {
		return !operator==(other);
	}

	void getLineFrom(std::istream& input) {
		Data buffer{ 10 };
		char symbol;
		while(true) {
			symbol = input.get();
			if ((symbol == '\n') || input.eof()) {
				buffer.push('\0');
				operator=({ buffer.data() });
				return;
			}
			buffer.push(symbol);
		}
	}

private:
	Data data;
};

std::ostream& operator<<(std::ostream& out, const String& string) {
	return out << string.cString();
}

class KeyValuePair {
public:
	KeyValuePair()
		: key{}, value{} { }

	~KeyValuePair() noexcept = default;

	KeyValuePair(const char* key, const char* value)
		: key{key}, value{value} { }

	KeyValuePair(const String& key, const String& value)
		: key{key}, value{value} { }

	KeyValuePair(String&& key, String&& value)
		: key{ std::move(key) }, value{ std::move(value) } { }

	KeyValuePair(const KeyValuePair& other) = default;

	KeyValuePair(KeyValuePair&& other) noexcept = default;

	KeyValuePair& operator=(const KeyValuePair& other) = default;

	KeyValuePair& operator=(KeyValuePair&& other) noexcept = default;

public:
	const String& getKey() const noexcept {
		return key;
	}

	const String& getValue() const noexcept {
		return value;
	}

	void setKey(const char* newKey) {
		key = { newKey };
	}

	void setKey(const String& newKey) {
		key = newKey;
	}

	void setKey(String&& newKey) {
		key = std::move(newKey);
	}

	void setValue(const char* newValue) {
		value = { newValue };
	}

	void setValue(const String& newValue) {
		value = newValue;
	}

	void setValue(String&& newValue) {
		value = std::move(newValue);
	}

	bool isKeyEqual(const String& otherKey) const noexcept {
		return key == otherKey;
	}

	bool operator==(const KeyValuePair& other) const noexcept {
		return isKeyEqual(other.getKey()) && (value == other.getValue());
	}

	bool operator!=(const KeyValuePair& other) const noexcept {
		return !operator==(other);
	}

private:
	String key;

	String value;
};

std::istream& operator>>(std::istream& input, KeyValuePair& pair) {
	String key;
	String value;
	key.getLineFrom(input);
	value.getLineFrom(input);
	pair = { std::move(key), std::move(value) };
	return input;
}

std::ostream& operator<<(std::ostream& output, const KeyValuePair& pair) {
	return output << pair.getKey() << std::endl << pair.getValue();
}

class Dictionary {
private:
	using Data = DynamicArray<KeyValuePair>;

	friend std::ostream& operator<<(std::ostream& output, const Dictionary& dictionary);

public:
	Dictionary() noexcept = default;

	~Dictionary() noexcept = default;

	Dictionary(const Dictionary& other) = default;

	Dictionary(Dictionary&& other) noexcept = default;

	Dictionary& operator=(const Dictionary& other) = default;

	Dictionary& operator=(Dictionary&& other) noexcept = default;

public:
	KeyValuePair* operator[](const String& key) noexcept {
		if (data.isEmpty()) {
			return nullptr;
		}
		const size_t size = data.size();
		for (size_t index = 0; index < size; ++index) {
			KeyValuePair& entry = data[index];
			if (entry.isKeyEqual(key)) {
				return &entry;
			}
		}
		return nullptr;
	}

	const KeyValuePair* operator[](const String& key) const noexcept {
		return const_cast<Dictionary* const>(this)->operator[](key);
	}

	Dictionary& operator+=(const KeyValuePair& newEntry) {
		data.push(newEntry);
		return *this;
	}

	Dictionary operator+(const KeyValuePair& newEntry) {
		Dictionary copy{ *this };
		copy += newEntry;
		return copy;
	}

	size_t recordsCount() const noexcept {
		return data.size();
	}

private:
	Data data;
};

std::istream& operator >> (std::istream& input, Dictionary& dictionary) {
	KeyValuePair pair;
	while (true) {
		input >> pair;
		dictionary += pair;
		if (!input.good()) {
			return input;
		}
	}
	return input;
}

std::ostream& operator<<(std::ostream& output, const Dictionary& dictionary) {
	const size_t count = dictionary.recordsCount();
	const size_t lastIndex = count - 1;
	for (size_t index = 0; index < count; ++index) {
		output << dictionary.data[index];
		if (index != lastIndex) {
			output << std::endl;
		}
	}
	return output;
}

#include <fstream>

// Dictionary IO format: each KeyValuePair is represented by two lines one for the key and one for the value

int main() {
	Dictionary dictionary;

	try {
		std::ifstream input{ "dic_in.txt" };
		if (!input.good()) {
			std::cerr << "cannot open dic_in.txt" << std::endl;
			return EXIT_FAILURE;
		}
		input >> dictionary;
		std::ofstream output{ "dic_out.txt" };
		if (!output.good()) {
			std::cerr << "cannot open dic_out.txt" << std::endl;
			return EXIT_FAILURE;
		}
		output << dictionary;
		output.close();
	}
	catch (const std::bad_alloc& error) {
		std::cerr << "not enogh moemory :)" << std::endl;
		return EXIT_FAILURE;
	}

    return 0;
}

