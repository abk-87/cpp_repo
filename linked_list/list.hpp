#include <iostream>
#include <cassert>

class Node
{
public:
	int data; //Keeps the value of the Node object.
	Node* next; //A pointer to another (next) Node object.

	//Constructor. Constructs an object (an element of a List object) that has 2 fields: variable with the value 'data' and pointer with the value 'nullptr'.
	//Argument:
	//data - value to be copied to the element field 'data'.
	Node(int data);
};

//List is a singly-linked list, linear collection of data elements whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. Each node contains: data, and a link to the next node in the sequence.
class List
{
private:
	Node* m_first; //The first element of the List object.
	int m_size; //Number of elements in the List object.
public:
	//Default constructor. Constructs an empty List object, with no elements.
	List();
	
	//Copy constructor. Constructs a List object with a copy of each of the elements in lst, in the same order.
	//Argument:
	//lst - another List object of the same type (with the same class template arguments), whose contents are either copied.
	List(const List& lst);
	
	//Returns the number of elements in the List object.
	int get_size();
	
	//Returns a bool value indicating whether the List object is empty, i.e. whether its size is 0.
	bool is_empty();
	
	//Adds a new element at the end of the List object, after its current last element, which receives a link to the new element. The List object size increases by the one.
	//Argument:
	//data - value to be copied to the new element.
	void push_back(int data);
	
	//Extendedes by inserting new element before the element at the specified position, increasing the List object size by one. Тhe element previously at specified position receives a link to the new element, and the new element receives a link to the element referenced by the element previously at specified position.
	//Arguments:
	//position - position (index) in the List object where the new element is inserted. It must not be less than 0 and greater than the List object current size. Otherwise the function throws exception.
	//data - value to be copied to the inserted element.
	void insert(int position, int data);

	//Removes the last element in the List object, reducing the List object size by one. If the List object is empty, the function throws exception.
	int pop_back();
	
	//Removes from the List object a single element from the specified position, reducing the List object size by one. If the List object is empty, the function throws exception. If the element to be removed is not the first or last element in the list, the element preceding the element to be removed receives a link to the element following the element to be removed․ Тhe function returns the value of the element being removed.
	//Argument:
	//position - the position (index) of the element to be removed in the List object. It must not be less than 0 and greater or equal to the List object size. Otherwise the function throws exception.
	int remove_by_index(int position);
	
	//Removes from the List object a single or all the elements that compare equal to 'data'. This reduces the List object size by the number of elements removed. If the List object is empty, the function throws exception. If the element to be removed is not the first or last element in the List object, the element preceding the element to be removed receives a link to the element following the element to be removed․
	//Arguments:
	//data - value of the elements to be removed.
	//flag - determines the number of elements to be removed. if the argument 'flag' is missing or equal to 0, only the first encountered element with the value 'data' is removed. And if you need to delete all the elements with the value 'data', then the function is given an argument 1. If given an argument other than 0 or 1 the function throws exception.
	void remove_by_value(int data, int flag = 0);

	//Outputs the values of the elements of the List object separated by a space.
	void print();
	
	//Returns a reference to the element at specified position in the List object. Allows to assign a new value to the element.
	//Argument:
	//position - position of an element in the List object. It must not be less than 0 and greater or equal to the List object size. Otherwise the function throws exception.
	int& operator[](int position);
	
	//Returns a Boolean value indicating whether the List object is a copy of another List object.
	bool operator!=(const List& lst);

	//Destructor. Destroys the List object with all its elements.
	~List();
};
