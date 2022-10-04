#pragma once
#include <string>

struct Champion
{
	std::string		name;
	int			hp;
	int			mp;
	int			attack;
	int			defense;
};

class Node
{
private:
	Champion data;

	Node* nextNode;

public:
	Node() : nextNode(nullptr) {}
	~Node() {}

	friend class MyLinkedList;
};

class MyLinkedList
{
public:
	MyLinkedList()
	{
		begin = new Node;
		end = new Node;

		begin->nextNode = end;
	}

	~MyLinkedList()
	{
		for (int i = 0; i < index; ++i)
		{
			Node* deleteData = begin->nextNode;
			begin->nextNode = deleteData->nextNode;
			delete deleteData;
		}
		delete begin;
		delete end;
	}

public:
	void push_front(const Champion& data)
	{
		Node* newNode = new Node;
		newNode->data = data;

		if (isEmpty())
		{
			newNode->nextNode = end;
			begin->nextNode = newNode;
		}
		else
		{
			newNode->nextNode = begin->nextNode;
			begin = newNode;
		}

		++index;
	}

	void pop_front()
	{
		if (isEmpty())
		{
			std::cout << "비어있습니다.\n";
		}
		else
		{
			Node* popData = begin->nextNode;

			begin->nextNode = popData->nextNode;

			delete popData;

			--index;
		}
	}

	void printAll()
	{
		if (isEmpty())
		{
			std::cout << "비어있습니다.\n";
		}
		else
		{
			Node* printNode = begin->nextNode;
			for (int i = 0; i < index; ++i)
			{
				std::cout << "Name : " << printNode->data.name << "\n";
				printNode = printNode->nextNode;
			}
		}
	}

private:
	bool isEmpty()
	{
		if (begin->nextNode == end)
			return true;
		else
			return false;
	}

private:
	int		index;

	Node*	begin;
	Node*	end;
};

