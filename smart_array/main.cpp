#include <iostream>
#include "smart_array.hpp"

int main()
{
	SmartArray arr;
	arr.pop_back();
	//std::cout << arr.get_front();
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
	std::cout << arr[1] << std::endl;
	std::cout << arr[3] << std::endl;
	SmartArray arr2(arr);
	print_array(arr2);
	arr.resize(15);
	print_array(arr);
	arr.resize(20, 33);
	print_array(arr);
	arr.resize(12);
	print_array(arr);
	arr.resize(5);
	print_array(arr);
	arr.assign(4, 15);
	print_array(arr);
	arr.assign(1, 4, arr2);
	print_array(arr);
	arr.assign({5, 4, 3, 2, 1});
	print_array(arr);
	return 0;
}
