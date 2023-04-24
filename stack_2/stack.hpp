#include <iostream>
#include <cassert>

class Stack 
{
private:	
	int* m_stack;    //An array-based Stack object.
	int m_size;      //Number of elements in the Stack object.
	int m_capacity;  //The size of the storage space currently allocated for the Stack object.
public:
	//Default constructor. Constructs an empty Stack object, with no element.
	Stack();
	
	//Returns the number of elements in the Stack object.
	int get_size();
	
	//Returns a bool value indicating whether the Stack object is empty, i.e. whether its size is 0.
	bool is_empty();
   	
	//Returns a reference to the top (last added) element in the Stack object. If the Stack object is empty, the function throws exception.
	int& top();
	
	//Inserts a new element at the top of the Stack object, above its current top element. The content of this new element is initialized to a copy of 'data'. The Stack object size increases by the one.
	//Argument:
	//data - value to be copied to the new element.
	void push(int data);
	
	//Removes the element on top of the stack, reducing its size by one. If the Stack object is empty, the function throws exception.
	int pop();	
    	
	//Destructor. Destroys the Stack object with all its elements.
	~Stack();
};
