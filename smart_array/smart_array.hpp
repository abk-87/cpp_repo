#include <iostream>
#include <cassert>

class SmartArray
{
private:	
	int* m_array;
	int m_size;
	int m_capacity;
	
	//Increases capacity if adding new element(s) makes array size larger than capacity
	void change_capacity();
	
	//Creates a new array with a new capacity and populates it with the elements of the old array in the same order
	void array_copy();
public:
	//Default constructor
	SmartArray();
	//Constructs an array with 'size' elements. Each element is a copy of 0
	SmartArray(int size);
	//Constructs an array with a copy of each of the elements in 'array', in the same order.
	SmartArray(const SmartArray& array);
	
	//Returns the number of elements in the array
	int get_size();
	
	//Returns the size of the storage space currently allocated for the array, expressed in terms of elements
	int get_capacity();
	
	//Returns whether the vector is empty
	bool empty();
    
    //Removes all elements from the vector, leaving the array with a size of 0
	void clear();

	//Returns the element at position ‘index’ in the array
	int get_element(int index);
    
    //Returns the first element in the array
	int get_front();	
	
	//Returns the last element in the array
	int get_back();

	//Adds a new element at the end of the array, after its current last element, increasing the array size by one. The content of 'num' is copied to the new element
	void push_back(int num);
	
	//Removes the last element in the array, reducing the array size by one
	void pop_back();	
	
	//Extendedes by inserting new element 'num' before the element at the specified position 'index', increasing the array size by one
	void insert(int index, int num);
	
	//Removes from the array a single element from the specified position 'index', reducing the array size by one.
	void erase(int index);
	
	//Resizes the array so that it contains 'size' elements. If 'size' is smaller than the current array size, the content is reduced to its first 'size' elements. If 'size' is greater than the current array size, the content is expanded by inserting at the end as many elements as needed to reach a size of 'size'. If 'value' is specified, the new elements are initialized as copies of 'value', otherwise, they are initialized by 0.
	void resize(int size, int value = 0);

    //Assigns new contents to the array, replacing its current contents, and modifying its size accordingly. The new contents are 'size' elements, each initialized to a copy of 'value'.
	void assign(int size, int value);
	
	//Assigns new contents to the array, replacing its current contents, and modifying its size accordingly. The new contents are elements constructed from each of the elements in the range between indexes 'start' and 'end' of the 'array', in the same order.
	void assign(int start, int end, const SmartArray& array);
	
	//Assigns new contents to the array, replacing its current contents, and modifying its size accordingly. The new contents  are copies of the values passed as initializer list, in the same order.
	void assign(const std::initializer_list <int>& list);
	
	//Returns the element at position 'index' in the array
	int operator[](int index);
    
    //Destructor. Destroys the SmartArray object
	~SmartArray();
};

//Օutputs the elements of the array sequentially
void print_array(SmartArray &arr);
