// fn45342_prob1_oop.cpp : Defines the entry point for the console application.
//


#include <cstddef>

class Railcar {
public:
	Railcar() noexcept
		: Railcar{ defaultMaxLoad } { }

	~Railcar() noexcept {
		prev = nullptr;
		next = nullptr;
	}

	Railcar(double maxLoad) noexcept
		: maxLoad{ maxLoad }, prev{ nullptr }, next{ nullptr } { }

	Railcar(const Railcar& other) noexcept
		: Railcar{ other.maxLoad } { }

	Railcar& operator=(const Railcar& other) noexcept {
		if (this != &other) {
			maxLoad = other.maxLoad;
			prev = nullptr;
			next = nullptr;
		}
		return *this;
	}

public:
	void SetPrev(Railcar* other) noexcept {
		if (other == nullptr) {
			if (prev != nullptr) {
				prev->next = nullptr;
				prev = nullptr;
			}
			return;
		}
		if (prev == nullptr) {
			prev = other;
			other->next = this;
		}
		else {
			other->next = this;
			other->prev = prev;
			prev->next = other;
			prev = other;
		}
	}

	void SetNext(Railcar* other) noexcept {
		if (other == nullptr) {
			if (next != nullptr) {
				next->prev = nullptr;
				next = nullptr;
			}
			return;
		}
		if (next == nullptr) {
			next = other;
			other->prev = this;
		}
		else {
			other->prev = this;
			other->next = next;
			next->prev = other;
			next = other;
		}
	}

	Railcar* GetPrev() const noexcept {
		return prev;
	}

	Railcar* GetNext() const noexcept {
		return next;
	}

	double GetMaxLoad() const noexcept {
		return maxLoad;
	}

	bool operator<(const Railcar& other) const noexcept {
		const Railcar* iter = next;
		while (iter != nullptr) {
			if (iter == &other) {
				return true;
			}
			iter = iter->next;
		}
		return false;
	}

private:
	static const double defaultMaxLoad;

private:
	double maxLoad;

	Railcar* prev;

	Railcar* next;
};

const double Railcar::defaultMaxLoad = 100.00;

class Composition {
public:
	Composition() noexcept
		: head{nullptr} { }

	~Composition() noexcept {
		clean();
	}

	Composition(const Composition& other)
		: Composition{}  {
		copy(other);
	}

	Composition& operator=(const Composition& other) {
		if (this != &other) {
			copy(other);
		}
		return *this;
	}

	Composition(double* values, size_t size) {
		if (size > 0) {
			head = new Railcar{ values[0] };
			Railcar* iter = head;
			for (size_t i = 1; i < size; ++i) {
				iter->SetNext(new Railcar{ values[i] });
				iter = iter->GetNext();
			}
		}
	}

public:
	double GetMaxLoad() const noexcept {
		double result = 0;
		Railcar* iter = head;
		while (iter != nullptr)
		{
			result += iter->GetMaxLoad();
			iter = iter->GetNext();
		}
		return result;
	}

private:
	void clean() noexcept {
		Railcar* iter = head;
		Railcar* tmp;
		while (iter != nullptr)
		{
			tmp = iter;
			iter = iter->GetNext();
			tmp->SetNext(nullptr);
			delete tmp;
		}
		head = nullptr;
	}

	void copy(const Composition& other) {
		Railcar* newHead = new Railcar{ *other.head };
		Railcar* iter = other.head->GetNext();
		while (iter != nullptr) {
			newHead->SetNext(new Railcar{ *iter });
			iter = iter->GetNext();
		}
		clean();
		head = newHead;
	}

private:
	Railcar* head;
};

#include <iostream>

int main() {

	double all[3] = { 1, 2, 3 };

	Composition c{all, 3 };

	Composition copy = c;

	std::cout << c.GetMaxLoad() << std::endl;

	std::cout << copy.GetMaxLoad() << std::endl;

	copy = c;

	std::cout << copy.GetMaxLoad() << std::endl;

    return 0;
}

