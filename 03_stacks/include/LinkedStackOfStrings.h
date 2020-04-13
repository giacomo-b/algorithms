#pragma once

#include <string>
#include "Node.h"

class LinkedStackOfStrings
{
public:
	// Create an empty stack
	LinkedStackOfStrings();

	// Insert a new string onto stack
	void push(std::string item);

	// Remove and return the most recently added string
	std::string pop();

	// Is the stack empty?
	bool isEmpty() const;

private:
	Node *first = nullptr;
};
