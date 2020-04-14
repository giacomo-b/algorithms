#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class LinkedStackOfStrings
{
public:
	// Create an empty stack
	LinkedStackOfStrings() {}

	// Insert a new string onto stack
	void push(std::string item)
    {
        // Save a link to the list
        Node* old_first = first;

        // Create new node for the beginning of the stack
        first = new Node;

        // Set the instance variables of the new node
        first->setItem(item);
        first->setNext(old_first);
    }

	// Remove and return the most recently added string
	std::string pop()
    {
        if (isEmpty()) {
            std::cerr << "\nUnderflow.\nProgram terminated.\n" << std::endl;
            exit(EXIT_FAILURE);
        }

        // Save item to be returned
        std::string item = first->getItem();

        // Delete the first node
        first = first->getNext();

        return item;
    }

	// Is the stack empty?
	bool isEmpty() const
    {
        return first == nullptr;
    }

private:
	Node *first = nullptr;
};
