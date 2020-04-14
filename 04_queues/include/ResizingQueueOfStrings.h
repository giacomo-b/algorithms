#pragma once

#include <string>
#include <vector>
#include <iostream>

class ResizingQueueOfStrings
{
public:
	ResizingQueueOfStrings()
	{
		q.resize(1);
	}

	bool isEmpty() const
	{
		return head == tail;
	}

	void enqueue(std::string& item)
	{
		if (tail == q.capacity()) {
			if (head == 0)
				resize(2 * q.capacity());
			else
				resetPositions();
		}

		q[tail++] = item;
	}

	std::string dequeue()
	{
		if (isEmpty()) {
			std::cerr << "\nEmpty queue.\nProgram terminated.\n" << std::endl;
			exit(EXIT_FAILURE);
		}

		if ((tail - head) == q.capacity() / 4)
			resize(q.capacity() / 2);

		std::string item = q[head++];

		return item;
	}

private:
	std::vector<std::string> q;

	// Index of next open position
	int tail{ 0 };

	// Index of least recent item
	int head{ 0 };

	void resize(int capacity)
	{
		std::vector<std::string> copy(capacity);
		for (auto i = 0; i < (tail - head); i++)
			copy[i] = q[i + head];
		q = copy;

		tail -= head;
		head = 0;
	}

	void resetPositions()
	{
		for (auto i = 0; i < q.capacity() - head; i++)
			q[i] = q[i + head];

		tail -= head;
		head = 0;
	}
};
