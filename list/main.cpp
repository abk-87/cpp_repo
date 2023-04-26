#include "list.hpp"

int main()
{
	//int
	List<int> list;

	list.push_back(10);
	assert(list.get_size() == 1 && list.front() == 10 && list.back() == 10);
	
	list.push_back(20);
	assert(list.is_empty() == 0 && list.front() == 10 && list.back() == 20);

	list.push_front(30);
	assert(list.get_size() == 3 && list.front() == 30 && list.back() == 20);
	
	list.pop_front();
	assert(list.get_size() == 2 && list.front() == 10 && list.back() == 20);

	list.pop_back();
	assert(list.get_size() == 1 && list.front() == 10 && list.back() == 10);

	list.pop_front();
	assert(list.is_empty() == 1);

	//string
	List<std::string> list2;

	list2.push_front("aaa");
	assert(list2.get_size() == 1 && list2.front() == "aaa" && list2.back() == "aaa");
	
	list2.push_front("bbb");
	list2.push_back("ccc");
	list2.push_front("ddd");
	list2.push_back("eee");
	list2.push_front("fff");
	list2.push_back("ggg");
	//fff ddd bbb aaa ccc eee ggg
	list2.print();

	list2.pop_front();
	list2.pop_back();
	assert(list2.get_size() == 5 && list2.front() == "ddd" && list2.back() == "eee");

	list2.front() = "first";
	list2.back() = "last";
	//first bbb aaa ccc last
	list2.print();

	//char
	List<char> list3;
	list3.push_front('o');
	list3.push_front('l');
	list3.push_front('l');
	list3.push_front('e');
	list3.push_front('H');
	list3.push_back(' ');
	list3.push_back('w');
	list3.push_back('o');
	list3.push_back('r');
	list3.push_back('l');
	list3.push_back('d');
	list3.push_back('!');
	list3.print();
	return 0;
}
