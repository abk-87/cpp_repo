#include "smart_array.hpp"

//Doubles capacity if adding a new element makes the array size equal to capacity
void SmartArray::change_capacity()
{
	if (m_capacity == 0)
	{
		m_capacity++;
	}
	else
	{
		m_capacity *= 2;
		int* tmp_array = new int[m_capacity];
		for (int i = 0; i < m_size; i++)
		{
			tmp_array[i] = m_array[i];
		}
		delete[] m_array;
		m_array = tmp_array;
	}
}

SmartArray::SmartArray()
{
	m_size = 0;
	m_capacity = 0;
	m_array = new int[m_size];
}
SmartArray::SmartArray(int size)
{
	m_size = size;
	m_capacity = size;
	m_array = new int[m_size]{};
}
	
//Returns the number of elements in the array	
int SmartArray::get_size()
{
	return m_size;
}

//Returns a reference to the element at position n in the array
int SmartArray::get_value(int index)
{
	assert(index < m_size && index >= 0); 
	return m_array[index];
}
	
//Adds a new element at the end of the array, after its current last element. The content of num is copied (or moved) to the new element.
void SmartArray::push_back(int num)
{
	m_size++;
	if (m_size >= m_capacity)
	{
		change_capacity();
	}
	m_array[m_size - 1] = num;
}

//Removes the last element in the array, effectively reducing the container size by one
void SmartArray::pop_back()
{
	//assert(m_size > 0 && "The array is empty. No element to remove");
	if (m_size > 0) 
        {
              	//m_array[m_size - 1] = 0;
               	m_size--;
        }
        else
        {
        	std::cout << "The array is empty. No element to remove" << std::endl;
        }
}
	
//Extendedes the array by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted
void SmartArray::insert(int index, int num)
{
	assert(m_size >= index);
	m_size++;
	if (m_size > m_capacity)
	{
		change_capacity();
	}
	for (int i = m_size - 1; i > index; i--)
	{
		m_array[i] = m_array[i - 1];
	}
	m_array[index] = num;
}

int SmartArray::operator[](int index)
{
	//assert(index >= 0 && index < m_size && "Segmentation fault");
	if (index < 0 || index >= m_size)
	{
		std::cout << "Segmentation fault" << std::endl;
		exit(1);
	}
	return m_array[index];
}

SmartArray::~SmartArray()
{
	delete[] m_array;
}

void print_array(SmartArray &arr)
{
	for (int i = 0; i < arr.get_size(); i++)
	{
		std::cout << arr.get_value(i) << " ";
	}
	std::cout << std::endl;
}
