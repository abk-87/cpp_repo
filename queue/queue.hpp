#include <iostream>
#include <cassert>

class Node
{
public:
	int data; //Keeps the value of the Node object.
	Node* link; //A pointer to another (next) Node object.

	//Constructor. Constructs an object (an element of a Queue object) that has 2 fields: variable with the value 'data' and pointer with the value 'nullptr'.
	//Argument:
	//data - value to be copied to the element field 'data'.
	Node(int data);
};

class Queue
{
private:
	Node* m_front; //The first element of the Queue object.
	Node* m_back; //The last element of the Queue object.
	int m_size; //Number of elements in the Queue object.
public:
	//Default constructor. Constructs an empty Queue object, with no element.
	Queue();
	
	//Returns the number of elements in the Queue object.
	int get_size();
	
	//Returns a reference to the first element in the Queue object which is removed when the function pop() is called. If the Queue object is empty, the function throws exception.
	int& front();

	//Returns a reference to the last element in the Queue object. If the Queue object is empty, the function throws exception.
	int& back();

	//Returns a bool value indicating whether the Queue object is empty, i.e. whether its size is 0.
	bool is_empty();
	
	//Inserts a new element at the end of the Queue object, after its last element. The content of this new element is initialized to a copy of 'data'. The Queue object size increases by one.
	//Argument:
	//data - value to be copied to the new element.
	void push(int data);

	//Removes the first element in the Queue object, reducing its size by one. If the Queue object is empty, the function throws exception.
	int pop();
	
	//Destructor. Destroys the Queue object with all its elements.
	~Queue();
};
