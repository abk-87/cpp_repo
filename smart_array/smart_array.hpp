#include <iostream>
#include <cassert>

class SmartArray
{
	int* array;
	int Size;
	int capacity;
	
	void change_capacity();
public:
	SmartArray();
	SmartArray(int size);
		
	int size();	
	int at(int index);	
	void push_back(int num);	
	void insert(int index, int num);
	
	~SmartArray();
};

void print_array(SmartArray &arr);
