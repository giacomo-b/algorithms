#include <iostream>
#include <fstream>

#include "LinkedQueueOfStrings.h"
#include "ResizingQueueOfStrings.h"

int main(int argc, char* argv[])
{
	ResizingQueueOfStrings queue;
	//LinkedQueueOfStrings queue;

	std::ifstream stream("input.txt");
	std::string word;
	while (stream >> word) {
		if (!word.compare("-"))
			std::cout << queue.dequeue() << ' ';
		else
			queue.enqueue(word);
	}

	return 0;
}