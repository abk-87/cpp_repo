#include <iostream>
#include <cassert>
#include <string>

template <typename T1, typename T2>
class Node
{
public:
	T1 key;       //Key values that are used to sort and uniquely identify elements.
	T2 value;     //Values that store the content associated with the key.   
	Node* left;   //Pointer to the root element of the left subtree.
	Node* right;  //Pointer to the root element of the right subtree.

	//Constructor. Constructs an object (an element of a Map object) by assigning fields 'key' and 'value' the values of the corresponding arguments.
	Node(T1 key, T2 value)
	{
		this->key = key;
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
};

template <typename T1, typename T2>
class Map
{
private:
	Node<T1, T2>* m_root;  //The root element of the Map object.
	int m_size;            //The number of elements in the Map object.

	//Inserts a new element in the Map object if its key is unique. The insertion only takes place if no other element in the object has a key equivalent to the one being emplaced. If inserted, this increases the object size by one. Internally, map containers keep all their elements sorted by their key. The element is always inserted in its respective position following this ordering.
	void emplace(T1 key, T2 value, Node<T1, T2>* n)
	{
		if (m_size == 0)
		{
			m_root = new Node<T1, T2>(key, value);
			m_size++;
		}
		else if (key < n->key)
		{
			if (n->left == nullptr)
			{
				Node<T1, T2>* element = new Node<T1, T2>(key, value);
				n->left = element;
				m_size++;
			}
			else
			{				
				emplace(key, value, n->left);
			}
		}
		else if (key > n->key)
		{
			if (n->right == nullptr)
			{
				Node<T1, T2>* element = new Node<T1, T2>(key, value);
				n->right = element;
				m_size++;
			}
			else
			{				
				emplace(key, value, n->right);
			}
		}
	}

	//Iterates the Map object recursively and outputs the keys and values of its elements line by line.
	void print(Node<T1, T2>* n)
	{
		if(n)
		{
			print(n->left);
			std::cout << n->key << " " << n->value << std::endl;
			print(n->right);
		}
	}
	
	//Iterates the Map object recursively and removes its elements.
	void clear(Node<T1, T2>* n)
	{
	       	if (n)
		{
			clear(n->left);
			clear(n->right);
			delete n;
			m_size--;
		}
	}
public:
	//Default constructor. Constructs an empty Map object, with no elements.
	Map()
	{
		m_root = nullptr;
		m_size = 0;
	}
	
	//Returns the number of elements in the Map object.	
	int get_size()
	{
		return m_size;
	}
	
	//Emplace() function overload to call it from main().
	void emplace(T1 key, T2 value)
	{
		emplace(key, value, m_root);
	}

	//Print() function overload to call it from main().
	void print()
	{
		print(m_root);
	}

	//Clear() function overload to call it from main().
	void clear()
	{
		clear(m_root);
	}

	//Destructor. Destroys the Map object with all its elements using the function clear().
	~Map()
	{
		clear();
		assert(m_size == 0);
	}
};
