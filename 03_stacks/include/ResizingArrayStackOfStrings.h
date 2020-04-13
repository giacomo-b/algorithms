#pragma once

#include <string>
#include <vector>
#include <iostream>

class ResizingArrayStackOfStrings
{
public:
	ResizingArrayStackOfStrings()
	{
		s.resize(1);
	}

	bool isEmpty() const
	{
		return N == 0;
	}

	void push(std::string& item)
	{
		if (N == s.capacity())
			resize(2 * s.capacity());
		
		s[N++] = item;
	}

	std::string pop()
	{
		if (isEmpty()) {
			std::cerr << "\nArray underflow.\nProgram terminated.\n" << std::endl;
			exit(EXIT_FAILURE);
		}

		if (N == s.capacity() / 4)
			resize(s.capacity() / 2);

		std::string item = s[--N];

		return item;
	}

private:
	std::vector<std::string> s;

	// Index of next open position
	int N{ 0 };

	void resize(int capacity)
	{
		std::vector<std::string> copy(capacity);
		for (auto i = 0; i < N; i++)
			copy[i] = s[i];
		s = copy;
	}
};
