#pragma once

#include <iostream>
#include <string>
#include <iostream>
#include "Node.h"

class LinkedQueueOfStrings
{
public:
	// Create an empty queue
	LinkedQueueOfStrings() {}

	// Insert a new string onto queue
	void enqueue(std::string item)
    {
        // Save a link to the last node
        Node* old_last = last;

        // Create new node for the end
        last = new Node;

        // Link the new node to the end of the list
        last->setItem(item);
        last->setNext(nullptr);

        if (isEmpty())
            first = last;
        else
            old_last->setNext(last);
    }

	// Remove and return the string least recently added
	std::string dequeue()
    {
        if (isEmpty()) {
            std::cerr << "\nUnderflow.\nProgram terminated.\n" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Save item to be returned
        std::string item = first->getItem();

        // Delete the first node
        first = first->getNext();

        if (isEmpty())
            last = nullptr;

        return item;
    }

	// Is the queue empty?
	bool isEmpty() const
    {
        return first == nullptr;
    }

private:
	Node* first = nullptr;
	Node* last = nullptr;
};

