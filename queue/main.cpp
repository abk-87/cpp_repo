#include "queue.hpp"

int main()
{
	Queue queue;
	
	queue.push(10);
	assert(queue.get_size() == 1 && queue.front() == 10 && queue.back() == 10 && queue.is_empty() == 0);
	
	queue.push(30);
	assert(queue.get_size() == 2 && queue.front() == 10 && queue.back() == 30);
	
	queue.front() = 20;
	assert(queue.front() == 20);
	
	queue.push(40);
	queue.push(50);
	assert(queue.get_size() == 4 && queue.front() == 20 && queue.back() == 50);
	
	queue.pop();
	assert(queue.get_size() == 3 && queue.front() == 30);
	
	int a = queue.pop();
	assert(queue.get_size() == 2 && a == 30 && queue.back() == 50);	
	
	queue.pop();
	assert(queue.get_size() == 1 && queue.front() == queue.back());
	
	queue.pop();
	assert(queue.get_size() == 0 && queue.is_empty() == 1);
}
