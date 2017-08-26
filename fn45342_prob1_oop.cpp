// fn45342_prob1_oop.cpp : Defines the entry point for the console application.
//

#include <iostream>
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
		if (prev != nullptr) {
			other->prev = prev;
			prev->next = other;
		}
		other->next = this;
		prev = other;
	}

	void SetNext(Railcar* other) noexcept {
		if (other == nullptr) {
			if (next != nullptr) {
				next->prev = nullptr;
				next = nullptr;
			}
			return;
		}
		if (next != nullptr) {
			other->next = next;
			next->prev = other;
		}
		other->prev = this;
		next = other;
	}

	const Railcar* GetPrev() const noexcept {
		return prev;
	}

	const Railcar* GetNext() const noexcept {
		return next;
	}

	double GetMaxLoad() const noexcept {
		return maxLoad;
	}

	bool operator<(const Railcar& other) const noexcept {
		for(const Railcar* iter = next; iter != nullptr; iter = iter->next) {
			if (iter == &other) {
				return true;
			}
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
			Railcar* next;
			for (size_t i = 1; i < size; ++i) {
				next = new Railcar{ values[i] };
				iter->SetNext(next);
				iter = next;
			}
		}
	}

public:
	double GetMaxLoad() const noexcept {
		double result = 0;
		for(const Railcar* iter = head; iter != nullptr; iter = iter->GetNext()) {
			result += iter->GetMaxLoad();
		}
		return result;
	}

private:
	void clean() noexcept {
		const Railcar* iter = head;
		const Railcar* tmp;
		while (iter != nullptr) {
			tmp = iter;
			iter = iter->GetNext();
			delete tmp;
		}
		head = nullptr;
	}

	void copy(const Composition& other) {
		Railcar* newHead = new Railcar{ *other.head };
		const Railcar* iter = other.head->GetNext();
		Railcar* newIter = newHead;
		Railcar* next;
		while (iter != nullptr) {
			next = new Railcar{ *iter };
			newIter->SetNext(next);
			newIter = next;
			iter = iter->GetNext();
		}
		clean();
		head = newHead;
	}

private:
	Railcar* head;
};

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

