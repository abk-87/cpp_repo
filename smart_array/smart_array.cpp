#include "smart_array.hpp"

//Increases capacity if adding new element(s) makes array size larger than capacity
void SmartArray::change_capacity()
{
	if (m_capacity <= m_size / 2)
	{
		m_capacity = m_size;
		if (m_capacity == 1)
		{
			m_array = new int[m_capacity];
		}
		else
		{
			array_copy();
		}
	}
	else if (m_capacity < m_size)
	{
		m_capacity *= 2;
		array_copy();
	}
}

//Creates a new array with a new capacity and populates it with the elements of the old array in the same order		
void SmartArray::array_copy()
{
	int* tmp_array = new int[m_capacity];
	for (int i = 0; i < m_size; i++)
	{
		tmp_array[i] = m_array[i];
	}
	delete[] m_array;
	m_array = tmp_array;
}

//Default constructor
SmartArray::SmartArray()
{
	m_size = 0;
	m_capacity = 0;
	m_array = new int[m_size];
}

//Constructs an array with 'size' elements. Each element is a copy of 0
SmartArray::SmartArray(int size)
{
	m_size = size;
	m_capacity = size;
	m_array = new int[m_size]{};
}

//Constructs an array with a copy of each of the elements in 'array', in the same order.
SmartArray::SmartArray(const SmartArray& array)
{
	m_size = array.m_size;
	m_capacity = array.m_size;
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
	{
		m_array[i] = array.m_array[i];
	}
}

//Returns the number of elements in the array	
int SmartArray::get_size()
{
	return m_size;
}

//Returns the size of the storage space currently allocated for the array, expressed in terms of elements
int SmartArray::get_capacity()
{
	return m_capacity;
}

//Returns whether the vector is empty
bool SmartArray::empty()
{
	if (m_size > 0)
	{
                return false;
        }
       	else
	{
                return true;
        }
}

//Removes all elements from the vector, leaving the array with a size of 0
void SmartArray::clear()
{
	m_size = 0;
}

//Returns the element at position 'index' in the array
int SmartArray::get_element(int index)
{
	assert(index < m_size && index >= 0 && "Out of range. Incorrect index."); 
	return m_array[index];
}

//Returns the first element in the array	
int SmartArray::get_front()
{
	assert(m_size > 0 && "Segmentation fault. The array is empty.");
	return m_array[0];
}

//Returns the last element in the array
int SmartArray::get_back()
{
	assert(m_size > 0 && "Segmentation fault. The array is empty.");
	return m_array[m_size - 1];
}

//Adds a new element at the end of the array, after its current last element, increasing the array size by one. The content of 'num' is copied to the new element
void SmartArray::push_back(int num)
{
	m_size++;
	change_capacity();
	m_array[m_size - 1] = num;
}

//Removes the last element in the array, reducing the array size by one
void SmartArray::pop_back()
{
	if (m_size > 0) 
        {
               	m_size--;
        }
        else
        {
        	std::cout << "The array is empty. No element to remove." << std::endl;
        }
}
	
//Extendedes by inserting new element 'num' before the element at the specified position 'index', increasing the array size by one
void SmartArray::insert(int index, int num)
{
	//assert(m_size >= index && index >= 0 && "Out of range. Incorrect index.");
	//or
	if (index < 0 || index >= m_size)
	{
		std::cout << "Out of range. Incorrect index." << std::endl;
		exit(1);
	}
	
	m_size++;
	change_capacity();
	for (int i = m_size - 1; i > index; i--)
	{
		m_array[i] = m_array[i - 1];
	}
	m_array[index] = num;
}

//Removes from the array a single element from the specified position 'index', reducing the array size by one.
void SmartArray::erase(int index)
{
	//assert(index < m_size && index >= 0 && "Out of range. Incorrect index.");
	//or
	if (index < 0 || index >= m_size)
	{
		std::cout << "Out of range. Incorrect index." << std::endl;
		exit(1);
	}
	
	for(int i = index; i < m_size; i++)
       	{
        	m_array[i] = m_array[i + 1];
        }
        m_size--;
}

//Resizes the array so that it contains 'size' elements. If 'size' is smaller than the current array size, the content is reduced to its first 'size' elements. If 'size' is greater than the current array size, the content is expanded by inserting at the end as many elements as needed to reach a size of 'size'. If 'value' is specified, the new elements are initialized as copies of 'value', otherwise, they are initialized by 0.
void SmartArray::resize(int size, int value)
{
	assert(size >= 0 && "Segmentation fault");
	if (size < m_size)
	{
		m_size = size;
	}
	else if (size > m_size)
	{
		int tmp = m_size;
		m_size = size;
		change_capacity();
		for (int i = tmp; i < m_size; i++)
		{
			m_array[i] = value;
		}
	}
}

//Assigns new contents to the array, replacing its current contents, and modifying its size accordingly. The new contents are 'size' elements, each initialized to a copy of 'value'.
void SmartArray::assign(int size, int value)
{
	m_size = size;
	if (m_capacity < m_size)
	{
		m_capacity = m_size;
		delete[] m_array;
		m_array = new int[m_capacity]{value};
	}
	else
	{
		for (int i = 0; i < m_size; i++)
		{
			m_array[i] = value;
		}
	}
}

//Assigns new contents to the array, replacing its current contents, and modifying its size accordingly. The new contents are elements constructed from each of the elements in the range between indexes 'start' and 'end' of the 'array', in the same order.
void SmartArray::assign(int start, int end, const SmartArray& array)
{
	m_size = end - start;
	if (m_capacity < m_size)
	{
		m_capacity = m_size;
		delete[] m_array;
		m_array = new int[m_capacity];
	}
	int i = 0;
	for (int j = start; j < end; j++)
	{
		m_array[i] = array.m_array[j];
		i++;
	}
}

//Assigns new contents to the array, replacing its current contents, and modifying its size accordingly. The new contents  are copies of the values passed as initializer list, in the same order.
void SmartArray::assign(const std::initializer_list <int>& list)
{
	m_size = list.size();
	if (m_capacity < m_size)
	{
		m_capacity = m_size;
		delete[] m_array;
		m_array = new int[m_capacity];
	}
	int i = 0;
	for (int element : list)
	{
		m_array[i] = element;
		i++;
	}
}

//Returns the element at position 'index' in the array
int SmartArray::operator[](int index)
{
	//assert(index < m_size && index >= 0 && "Out of range. Incorrect index.");
	
	//or
	
	if (index < 0 || index >= m_size)
	{
		std::cout << "Out of range. Incorrect index." << std::endl;
		exit(1);
	}
	
	return m_array[index];
}

//Destructor. Destroys the SmartArray object
SmartArray::~SmartArray()
{
	delete[] m_array;
}

//?utputs the elements of the array sequentially
void print_array(SmartArray &arr)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		std::cout << arr.get_element(i) << " ";
	}
	std::cout << std::endl;
}
