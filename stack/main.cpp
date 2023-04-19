#include "stack.hpp"

int main()
{
	Stack stack;
	
	stack.push(10);
	assert(stack.get_size() == 1 && stack.top() == 10 && stack.is_empty() == 0);	
	
	stack.push(30);
	assert(stack.get_size() == 2 && stack.top() == 30);	
	
	stack.push(40);
	stack.top() = 60;
	assert(stack.top() == 60);
	
	stack.push(20);
	stack.push(50);
	assert(stack.get_size() == 5 && stack.top() == 50);	
	
	stack.pop();
	int a = stack.pop();
	assert(stack.get_size() == 3 && stack.top() == 60 && a == 20);	
	
	stack.pop();
	stack.pop();
	stack.pop();
	assert(stack.get_size() == 0 && stack.is_empty() == 1);	
}
