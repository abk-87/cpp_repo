#include "list.hpp"

int main()
{
	List list;
	list.print();
	list.push_back(10);
	list.push_back(30);
	list.push_back(40);
	list.push_back(20);
	std::cout << list.get_size() << std::endl;
	list.print();
	std::cout << list[2] << std::endl;
	list[2] = 50;
	list.print();
	std::cout << list.pop_back() << std::endl;
	std::cout << list[1] << std::endl;
	std::cout << list.get_size() << std::endl;
	list.print();
	list.push_back(40);
	list.push_back(60);
	list.print();
	std::cout << list.get_size() << std::endl;
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.print();
	std::cout << list.get_size() << std::endl;
	list.pop_back();
	list.pop_back();
	list.push_back(11);
	list.push_back(22);
	list.push_back(33);
	std::cout << list[2] << " " << list[1] << " " << list[0] << std::endl;
	list[0] = list[2];
	list.print();
	std::cout << list.get_size() << std::endl;
	return 0;
}
