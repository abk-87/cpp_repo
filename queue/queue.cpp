#include "queue.hpp"

//Constructor. Constructs an object (an element of a Queue object) that has 2 fields: variable with the value 'data' and pointer with the value 'nullptr'.
//Argument:
//data - value to be copied to the element field 'data'.
Node::Node(int data)
{
	this->data = data;
	link = nullptr;
}

//Default constructor. Constructs an empty Queue object, with no element.
Queue::Queue()
{
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;
}

//Returns the number of elements in the Queue object.
int Queue::get_size()
{
	return m_size;
}

//Returns a reference to the first element in the Queue object which is removed when the function pop() is called. If the Queue object is empty, the function throws exception.
int& Queue::front()
{
	assert(m_size != 0 && "Segmentation fault");
	return m_front->data;
}

//Returns a reference to the last element in the Queue object. If the Queue object is empty, the function throws exception.
int& Queue::back()
{
	assert(m_size != 0 && "Segmentation fault");
	return m_back->data;	
}

//Returns a bool value indicating whether the Queue object is empty, i.e. whether its size is 0.
bool Queue::is_empty()
{
	if (m_front == nullptr)
	{
		return true;
	}
	return false;
}

//Inserts a new element at the end of the Queue object, after its last element. The content of this new element is initialized to a copy of 'data'. The Queue object size increases by one.
//Argument:
//data - value to be copied to the new element.
void Queue::push(int data)
{
	if (m_front == nullptr)
	{
		m_front = new Node(data);
		m_back = m_front;
	}
	else
	{
		Node* element = new Node(data);
		m_back->link = element;
		m_back = element;
	}
	m_size++;
}

//Removes the first element in the Queue object, reducing its size by one. If the Queue object is empty, the function throws exception.
int Queue::pop()
{
	assert(m_size > 0 && "The queue is empty. No element to remove");
	if (m_size > 1)
	{
				
		int d = m_front->data;
		Node* n = m_front;
		m_front = m_front->link;
		delete n;
		m_size--;
		return d;
	}
	else if (m_size == 1)
	{
		delete m_front;
		m_front = nullptr;
		m_back = nullptr;
		m_size--;
	}
	return 0;
}

//Destructor. Destroys the Queue object with all its elements.
Queue::~Queue()
{
	Node* n = m_front;
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
