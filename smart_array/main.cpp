#include <iostream>
#include "smart_array.hpp"

int main()
{
	SmartArray arr;
	arr.pop_back();
	arr.push_back(10);
	arr.push_back(40);
	arr.push_back(20);
	arr.push_back(30);
	print_array(arr);
	arr.insert(2, 111);
	arr.push_back(5);
	print_array(arr);
	arr.pop_back();
	print_array(arr);
	std::cout << arr[10] << std::endl;
	std::cout << arr[4] << std::endl;
	return 0;
}
