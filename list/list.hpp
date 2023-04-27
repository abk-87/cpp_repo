#include <iostream>
#include <cassert>
#include <string>

template <typename T>
class Node
{
public:
	T data;      //Keeps the value of the Node object.
	Node* next;  //A pointer to the next Node object (element of the List object).
	Node* prev;  //A pointer to the previous Node object (element of the List object).

	//Constructor. Constructs an object (an element of a List object) that has 3 fields: variable with the value 'data' and 2 pointers with the value 'nullptr'.
	//Argument:
	//data - value to be copied to the element field 'data'.
	Node(T data)
	{
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
};

template <typename T>
class List
{
private:
	Node<T>* m_front;  //The first element of the List object.
	Node<T>* m_back;   //The last element of the List object.
	int m_size;        //Number of elements in the List object.
public:
	//Default constructor. Constructs an empty List object, with no elements.
	List()
	{
		m_front = nullptr;
		m_back = nullptr;
		m_size = 0;
	}
	
	//Returns the number of elements in the List object.
	int get_size()
	{
		return m_size;
	}
	
	//Returns a bool value indicating whether the List object is empty, i.e. whether its size is 0.
	bool is_empty()
	{
		if (m_size == 0)
		{
			return true;
		}
		return false;
	}
	
	//Returns a reference to the first element in the List object.
	T& front()
	{
		return m_front->data;
	}

	//Returns a reference to the last element in the List object.
	T& back()
	{
		return m_back->data;
	}

	//Adds a new element at the beginning of the List object, before its current first element. The current first element and the new element receive links to each other. The List object size increases by one.
	//Argument:
	//data - value to be copied to the new element.
	void push_front(T data)
	{
		if (m_size == 0)
		{
			m_front = new Node(data);
			m_back = m_front;
		}
		else
		{
			Node<T>* element = new Node(data);
			m_front->prev = element;
			element->next = m_front;
			m_front = element;
		}
		m_size++;
	}
	
	//Adds a new element at the end of the List object, after its current last element. The current last element and the new element receive links to each other. The List object size increases by one.
	//Argument:
	//data - value to be copied to the new element.
	void push_back(T data)
	{
		if (m_size == 0)
		{
			m_back = new Node(data);
			m_front = m_back;
		}
		else
		{
			Node<T>* element = new Node(data);
			m_back->next = element;
			element->prev = m_back;
			m_back = element;
		}
		m_size++;
	}
	
	//Removes the first element in the List object, reducing the List object size by one. If the List object is empty, the function throws exception.
	T pop_front()
	{
		assert(m_size > 0 && "The list is empty. No element to remove");
		T front_value = m_front->data;
		if (m_size > 1)
		{
			Node<T>* n = m_front;
			m_front = m_front->next;
			m_front->prev = nullptr;
			delete n;
		}
		else if (m_size == 1)
		{
			delete m_front;
			m_front = nullptr;
			m_back = m_front;
		}
		m_size--;
		return front_value;
	}
	
	//Removes the last element in the List object, reducing the List object size by one. If the List object is empty, the function throws exception.
	T pop_back()
	{
		assert(m_size > 0 && "The list is empty. No element to remove");
		T back_value = m_back->data;
		if (m_size > 1)
		{
			Node<T>* n = m_back;
			m_back = m_back->prev;
			m_back->next = nullptr;
			delete n;
		}
		else if (m_size == 1)
		{
			delete m_back;
			m_back = nullptr;
			m_front = m_back;
		}
		m_size--;
		return back_value;
	}

	//Extendedes by inserting new element before the element at the specified position, increasing the List object size by one. Тhe element previously at specified position receives a link to the new element, and the new element receives a link to the element referenced by the element previously at specified position.
	//Arguments:
	//position - position (index) in the List object where the new element is inserted. It must not be less than 0 and greater than the List object current size. Otherwise the function throws exception.
	//data - value to be copied to the inserted element.
	void insert(int position, T data)
	{
		assert(position >= 0 && position <= m_size && "Out of range. Incorrect index.");
		if (position == 0)
		{
			push_front(data);
		}
		else if (position == m_size)
		{
			push_back(data);
		}
		else
		{
			Node<T>* element = new Node(data);
                        Node<T>* n = nullptr;
			if (position <= m_size / 2)
			{
				n = m_front;
				for (int i = 1; i < position; i++)
				{
					n = n->next;
				}
			}
			else
			{
				n = m_back;
				for (int i = m_size - 1; i >= position; i--)
				{
					n = n->prev;
				}
			}	
			element->prev = n;
			element->next = n->next;
			n->next->prev = element;
			n->next = element;
			m_size++;
		}
	}

	//Reverses the order of the elements in the List object.
	void reverse()
	{
		T tmp;
		Node<T>* n1 = m_front;
		Node<T>* n2 = m_back;
		for (int i = 0; i < m_size / 2; i++)
		{
			tmp = n1->data;
			n1->data = n2->data;
			n2->data = tmp;
			n1 = n1->next;
			n2 = n2->prev;
		}
	}

	//Outputs the values of the elements of the List object separated by a space.
	void print()
	{
		Node<T>* n = m_front;
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
	T& operator[](int position)
	{
		assert(position >= 0 && position < m_size && "Out of range. Incorrect index.");
		Node<T>* n;
		if (position <= m_size / 2)
		{
			n = m_front;
			for (int i = 0; i < position; i++)
			{
				n = n->next;
			}
		}
		else
		{
			n = m_back;
			for (int i = m_size - 1; i > position; i--)
			{
				n = n->prev;
			}
		}
		return n->data;
	}
	
	//Destructor. Destroys the List object with all its elements.
	~List()
	{
		Node<T>* n = m_front;
		Node<T>* n_next;
		while (n != nullptr)
		{
			n_next = n->next;
			delete n;
			m_size--;
			n = n_next;
		}
		assert(m_size == 0);
	}
};
