#include "list.hpp"

List::Node::Node(int data)
{
	this->data = data;
	next = nullptr;
}

List::List()
{
	first = nullptr;
}
	
int List::get_size()
{
	int size = 0;
	Node* n = first;
	while (n != nullptr)
	{
		size++;
		n = n->next;
	}
	return size;
}

bool List::is_empty()
{
	if (first == nullptr)
	{
		return true;
	}
	return false;
}

void List::push_back(int data)
{
	if (first == nullptr)
	{
		first = new Node(data);
	}
	else
	{
		Node* element = new Node(data);
		Node* n = first;
		while (n->next != nullptr)
		{
			n = n->next;
		}
		n->next = element;
	}
}

int List::pop_back()
{
	int s = get_size();
	if (s > 1)
	{
		Node* n = first;
		Node* n_prev;
		while (n->next != nullptr)
		{
			n_prev = n;
			n = n->next;
		}
		int d = n->data;
		delete n;
		n_prev->next = nullptr;
		return d;
	}
	else if (s == 1)
	{
		delete first;
		first = nullptr;
	}
	return 0;
}

void List::print()
{
	Node* n = first;
	while (n != nullptr)
	{
		std::cout << n->data << " ";
		n = n->next;
	}
	std::cout << std::endl;
}

int& List::operator[](int position)
{
	Node* n = first;
	for (int i = 0; i < position; i++)
	{
		n = n->next;
	}
	return n->data;
}
