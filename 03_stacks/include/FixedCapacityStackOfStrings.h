#pragma once

#include <string>

template <int CAPACITY>
class FixedCapacityStackOfStrings
{
public:
	bool isEmpty() const
	{
		return N == 0;
	}

	bool isFull() const
	{
		return N == CAPACITY;
	}

	void push(std::string& item)
	{
		if (isFull()) {
			std::cerr << "\nArray overflow.\nProgram terminated.\n" << std::endl;
			exit(EXIT_FAILURE);
		}
		s[N++] = new std::string(item);
	}

	std::string pop()
	{
		if (isEmpty()) {
			std::cerr << "\nArray underflow.\nProgram terminated.\n" << std::endl;
			exit(EXIT_FAILURE);
		}

		std::string item = *s[--N];

		s[N] = nullptr;

		return item;
	}

private:
	std::string* s[CAPACITY];

	// Both size of the stack and index of next open position
	int N{ 0 };
};

