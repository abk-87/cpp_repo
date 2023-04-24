#include "stack.hpp"

//Default constructor. Constructs an empty Stack object, with no element.
Stack::Stack()
{
	m_size = 0;
	m_capacity = 1;
	m_stack = new int[m_size];
}

//Returns the number of elements in the Stack object.
int Stack::get_size()
{
	return m_size;
}

//Returns a bool value indicating whether the Stack object is empty, i.e. whether its size is 0.
bool Stack::is_empty()
{
	if (m_size > 0)
	{
                return false;
        }
        return true;
}

//Returns a reference to the top (last added) element in the Stack object. If the Stack object is empty, the function throws exception.
int& Stack::top()
{
	assert(m_size > 0 && "Segmentation fault. The stack is empty.");
	return m_stack[m_size - 1];
}

//Inserts a new element at the top of the Stack object, above its current top element. The content of this new element is initialized to a copy of 'data'. The Stack object size increases by the one.
//Argument:
//data - value to be copied to the new element.
void Stack::push(int data)
{
	m_size++;
	if (m_capacity < m_size)
	{
		m_capacity *= 2;
		int* tmp_stack = new int[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			tmp_stack[i] = m_stack[i];
		}
		delete[] m_stack;
		m_stack = tmp_stack;
	}
	m_stack[m_size - 1] = data;
}

//Removes the element on top of the stack, reducing its size by one. If the Stack object is empty, the function throws exception.
int Stack::pop()
{
	assert(m_size > 0 && "The stack is empty. No element to remove");
	m_size--;
        return m_stack[m_size];
}

//Destructor. Destroys the Stack object with all its elements.
Stack::~Stack()
{
	delete[] m_stack;
}
