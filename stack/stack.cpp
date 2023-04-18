#include "stack.hpp"

//Constructor. Constructs an object (an element of a Stack object) that has 2 fields: variable with the value 'data' and pointer with the value 'nullptr'.
//Argument:
//data - value to be copied to the element field 'data'.
Node::Node(int data)
{
	this->data = data;
	link = nullptr;
}

//Default constructor. Constructs an empty Stack object, with no element.
Stack::Stack()
{
	m_top = nullptr;
	m_size = 0;
}

//Returns the number of elements in the Stack object.
int Stack::get_size()
{
	return m_size;
}

//Returns a reference to the top (last added) element in the Stack object. If the Stack object is empty, the function throws exception.
int& Stack::top()
{
	assert(m_size != 0 && "Segmentation fault");
	return m_top->data;
}

//Returns a bool value indicating whether the Stack object is empty, i.e. whether its size is 0.
bool Stack::is_empty()
{
	if (m_top == nullptr)
	{
		return true;
	}
	return false;
}

//Inserts a new element at the top of the Stack object, above its current top element. The content of this new element is initialized to a copy of 'data'. The Stack object size increases by one.
//Argument:
//data - value to be copied to the new element.
void Stack::push(int data)
{
	if (m_top == nullptr)
	{
		m_top = new Node(data);
	}
	else
	{
		Node* element = new Node(data);
		element->link = m_top;
		m_top = element;
	}
	m_size++;
}

//Removes the element on top of the stack, reducing its size by one. If the Stack object is empty, the function throws exception.
int Stack::pop()
{
	assert(m_size > 0 && "The stack is empty. No element to remove");
	if (m_size > 1)
	{
				
		int d = m_top->data;
		Node* n = m_top;
		m_top = m_top->link;
		delete n;
		m_size--;
		return d;
	}
	else if (m_size == 1)
	{
		delete m_top;
		m_top = nullptr;
		m_size--;
	}
	return 0;
}

//Destructor. Destroys the Stack object with all its elements.
Stack::~Stack()
{
	Node* n = m_top;
	Node* n_link;
	while (n != nullptr)
	{
		n_link = n->link;
		delete n;
		m_size--;
		n = n_link;
	}
	assert(m_size == 0);
}
