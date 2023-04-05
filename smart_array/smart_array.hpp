#include <iostream>
#include <cassert>

class SmartArray
{
private:	
	int* m_array;
	int m_size;
	int m_capacity;
	
	//Doubles the capacity of the array
	void change_capacity();
public:
	SmartArray();
	SmartArray(int size);
	
	//Returns the size of the array
	int get_size();	
		
	//Returns the element at position ‘index’
	int get_value(int index);	
	
	//Adds element at the end of the array
	void push_back(int num);
	
	//Deletes last element of the array
	void pop_back();	
	
	//Inserts new element at the specified position
	void insert(int index, int num);
	

	int operator[](int index);

	~SmartArray();
};

void print_array(SmartArray &arr);
