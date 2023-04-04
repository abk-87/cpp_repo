#include "smart_array.hpp"

//doubles capacity if adding a new element makes the array size equal to capacity
void SmartArray::change_capacity()
{
	if (capacity == 0)
	{
		capacity++;
	}
	else
	{
		capacity *= 2;
		int* tmp_array = new int[capacity];
		for (int i = 0; i < Size; i++)
		{
			tmp_array[i] = array[i];
		}
		delete[] array;
		array = tmp_array;
	}
}

SmartArray::SmartArray()
{
	Size = 0;
	capacity = 0;
	array = new int[Size];
}
SmartArray::SmartArray(int size)
{
	Size = size;
	capacity = size;
	array = new int[Size]{};
}
	
//Returns the number of elements	
int SmartArray::size()
{
	return Size;
}

//Returns the element at position ‘index’
int SmartArray::at(int index)
{
	assert(index < Size && index >= 0); 
	return array[index];
}
	
//Adds the element 'num' from the back
void SmartArray::push_back(int num)
{
	Size++;
	if (Size >= capacity)
	{
		change_capacity();
	}
	array[Size - 1] = num;
}
	
//Inserts new element 'num' before the element at the specified position
void SmartArray::insert(int index, int num)
{
	assert(Size >= index);
	Size++;
	if (Size > capacity)
	{
		change_capacity();
	}
	for (int i = Size - 1; i > index; i--)
	{
		array[i] = array[i - 1];
	}
	array[index] = num;
}

SmartArray::~SmartArray()
{
	delete[] array;
}

void print_array(SmartArray &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr.at(i) << " ";
	}
	std::cout << std::endl;
}
