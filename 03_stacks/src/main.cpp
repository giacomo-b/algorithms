#include <iostream>
#include <fstream>

#include "LinkedStackOfStrings.h"

int main(int argc, char* argv[])
{
	LinkedStackOfStrings stack;
    // ResizingArrayStackOfStrings stack;
    // FixedCapacityStackOfStrings<10> stack;

	std::ifstream stream("input.txt");
	std::string word;
	while (stream >> word) {
		if (!word.compare("-"))
			std::cout << stack.pop() << ' ';
		else
			stack.push(word);
	}
    
	return 0;
}