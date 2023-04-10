#include <iostream>
#include <cassert>

class List
{
private:
	class Node
	{
	public:
		int data;
		Node* next;

		Node(int data);
	};

	Node* first;

public:
	List();
	
	int get_size();

	bool is_empty();

	void push_back(int data);

	int pop_back();

	void print();
	
	int& operator[](int position);
};
