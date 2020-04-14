#pragma once

#include <string>

class Node
{
public:
	std::string getItem() const { return item; }

	Node* getNext() const { return next; }

	void setItem(std::string item)
	{
		this->item = item;
	}

	void setNext(Node *node)
	{
		this->next = node;
	}

private:
	std::string item;
	Node* next = nullptr;
};