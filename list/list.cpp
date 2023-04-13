#include "list.hpp"

//Constructor. Constructs an object (an element of a List object) that has 2 fields: variable with the value 'data' and pointer with the value 'nullptr'.
//Argument:
//data - value to be copied to the element field 'data'.
Node::Node(int data)
{
	this->data = data;
	next = nullptr;
}

//Default constructor. Constructs an empty List object, with no elements.
List::List()
{
	m_first = nullptr;
	m_size = 0;
}

//Copy constructor. Constructs a List object with a copy of each of the elements in lst, in the same order.
//Argument:
//lst - another List object of the same type (with the same class template arguments), whose contents are either copied.
List::List(const List& lst)
{
	m_size = lst.m_size;
	m_first = nullptr;
	if (lst.m_first != nullptr)
	{
		m_first = new Node(lst.m_first->data);
		Node* n = m_first;
		Node* n_arg = lst.m_first->next;
		while (n_arg != nullptr)
		{
			Node* element = new Node(n_arg->data);
			n->next = element;
			n = n->next;
			n_arg = n_arg->next;
		}
	}
}

//Returns the number of elements in the List object.
int List::get_size()
{
	return m_size;
}

//Returns a bool value indicating whether the List object is empty, i.e. whether its size is 0.
bool List::is_empty()
{
	if (m_first == nullptr)
	{
		return true;
	}
	return false;
}

//Adds a new element at the end of the List object, after its current last element, which receives a link to the new element. The List object size increases by the one.
//Argument:
//data - value to be copied to the new element.
void List::push_back(int data)
{
	if (m_first == nullptr)
	{
		m_first = new Node(data);
	}
	else
	{
		Node* element = new Node(data);
		Node* n = m_first;
		while (n->next != nullptr)
		{
			n = n->next;
		}
		n->next = element;
	}
	m_size++;
}

//Extendedes by inserting new element before the element at the specified position, increasing the List object size by one. Тhe element previously at specified position receives a link to the new element, and the new element receives a link to the element referenced by the element previously at specified position.
//Arguments:
//position - position (index) in the List object where the new element is inserted. It must not be less than 0 and greater than the List object current size. Otherwise the function throws exception.
//data - value to be copied to the inserted element.
void List::insert(int position, int data)
{
	assert(position >= 0 && position <= m_size && "Out of range. Incorrect index.");
	Node* element = new Node(data);
	if (position == 0)
	{
		element->next = m_first;
		m_first = element;
	}
	else
	{
		Node* n = m_first;
		for (int i = 0; i < position - 1; i++)
		{
			n = n->next;
		}
		element->next = n->next;
		n->next = element;
	}
	m_size++;
}

//Removes the last element in the List object, reducing the List object size by one. If the List object is empty, the function throws exception.
int List::pop_back()
{
	assert(m_size > 0 && "The list is empty. No element to remove");
	if (m_size > 1)
	{
		Node* n = m_first;
		Node* n_prev;
		while (n->next != nullptr)
		{
			n_prev = n;
			n = n->next;
		}
		int d = n->data;
		delete n;
		n_prev->next = nullptr;
		m_size--;
		return d;
	}
	else if (m_size == 1)
	{
		delete m_first;
		m_first = nullptr;
		m_size--;
	}
	return 0;
}

//Removes from the List object a single element from the specified position, reducing the List object size by one. If the List object is empty, the function throws exception. If the element to be removed is not the first or last element in the list, the element preceding the element to be removed receives a link to the element following the element to be removed․ Тhe function returns the value of the element being removed.
//Argument:
//position - the position (index) of the element to be removed in the List object. It must not be less than 0 and greater or equal to the List object size. Otherwise the function throws exception.
int List::remove_by_index(int position)
{
	assert(m_size > 0 && "The list is empty. No element to remove.");
	assert(position >= 0 && position < m_size && "Out of range. Incorrect index.");
	int d = m_first->data;
	if (m_size == 1)
	{
		delete m_first;
		m_first = nullptr;
	}
	else if (position == 0)
	{
		Node* n = m_first->next;
		delete m_first;
		m_first = n;
	}
	else
	{
		Node* n = m_first;
		Node* n_prev;
		for(int i = 0; i < position; i++)
		{
			n_prev = n;
			n = n->next;
		}
		d = n->data;
		n_prev->next = n->next;
		delete n;
	}
	m_size--;
	return d;
}

//Removes from the List object a single or all the elements that compare equal to 'data'. This reduces the List object size by the number of elements removed. If the List object is empty, the function throws exception. If the element to be removed is not the first or last element in the List object, the element preceding the element to be removed receives a link to the element following the element to be removed․
//Arguments:
//data - value of the elements to be removed.
//flag - determines the number of elements to be removed. if the argument 'flag' is missing or equal to 0, only the first encountered element with the value 'data' is removed. And if you need to delete all the elements with the value 'data', then the function is given an argument 1. If given an argument other than 0 or 1 the function throws exception.
void List::remove_by_value(int data, int flag)
{
	assert(m_size > 0 && "The list is empty. No element to remove.");
	assert(flag == 0 || flag == 1 && "Incorrect flag");
	
	int s = m_size;
	Node* n = m_first->next;	
	if (flag == 0)
	{
		if (m_first->data == data)
		{
			delete m_first;
			m_first = n;
			m_size--;
			return;
		}

		else
		{
			Node* n_prev = m_first; 
			for (int i = 1; i < m_size; i++)
			{
				if (n->data == data)
				{
					n_prev->next = n->next;
					delete n;
					m_size--;
					return;
				}
				else
				{
					n_prev = n;
				       	n = n->next;
				}
			}
		}
	}

	else if (flag == 1)
	{
		while (m_size > 0 && m_first->data == data)
		{
			delete m_first;
			m_first = n;
			m_size--;
			if (m_first != nullptr)
			{
				n = m_first->next;
			}
		}

		if (m_size > 1)
		{
			Node* n_prev = m_first;
			for (int i = 1; i < m_size; i++)
			{
				if (n->data == data)
				{
					n_prev->next = n->next;
					delete n;
					m_size--;
					n_prev = n;
					n = n->next;
				}
			}
		}
	}
	if (s == m_size)
	{
		std::cout << "Element with value " << data << " does not exist in the list" << std::endl;
	}
}

//Outputs the values of the elements of the List object separated by a space.
void List::print()
{
	Node* n = m_first;
	while (n != nullptr)
	{
		std::cout << n->data << " ";
		n = n->next;
	}
	std::cout << std::endl;
}

//Returns a reference to the element at specified position in the List object. Allows to assign a new value to the element.
//Argument:
//position - position of an element in the List object. It must not be less than 0 and greater or equal to the List object size. Otherwise the function throws exception.
int& List::operator[](int position)
{
	assert(position >= 0 && position < m_size && "Out of range. Incorrect index.");
	Node* n = m_first;
	for (int i = 0; i < position; i++)
	{
		n = n->next;
	}
	return n->data;
}

//Destructor. Destroys the List object with all its elements.
List::~List()
{
	Node* n = m_first;
	Node* n_next;
	while (n != nullptr)
	{
		n_next = n->next;
		delete n;
		n = n_next;
	}
}
