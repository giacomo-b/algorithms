#include "LinkedStackOfStrings.h"

#include <iostream>

LinkedStackOfStrings::LinkedStackOfStrings()
{

}

void LinkedStackOfStrings::push(std::string item)
{
	// Save a link to the list
	Node* old_first = first;

	// Create new node for the beginning of the stack
	first = new Node;

	// Set the instance variables of the new node
	first->setItem(item);
	first->setNext(old_first);
}

std::string LinkedStackOfStrings::pop()
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

bool LinkedStackOfStrings::isEmpty() const
{
	return first == nullptr;
}