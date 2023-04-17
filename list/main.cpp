#include "list.hpp"

int main()
{
	List list;
	
	list.push_back(10);
	list.push_back(30);
	list.push_back(40);
	list.push_back(20);
	//10 30 40 20
	assert(list.get_size() == 4 && list[0] == 10 && list[1] == 30 && list[2] == 40 && list[3] == 20);	

	list[2] = 50;
	//10 30 50 20
	assert(list[2] == 50);
	
	int a = list.pop_back();
	//10 30 50
	assert(list.get_size() == 3 && a == 20);
	
	list.push_back(40);
	list.push_back(60);
	//10 30 50 40 60
	assert(list.get_size() == 5 && list[3] == 40 && list[4] == 60);	
	
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	list.pop_back();
	assert(list.is_empty() == 1);	
	
	list.push_back(11);
	list.push_back(22);
	list.push_back(33);
	//11 22 33
	list[0] = list[2];
	//33 22 33
	assert(list.get_size() == 3 && list[0] == 33 && list[1] == 22 && list[2] == 33);	
	
	list.insert(2, 55);
	list.insert(0, 44);
	list.insert(3, 77);
	list.insert(6, 66);
	//44 33 22 77 55 33 66
	assert(list.get_size() == 7 && list[4] == 55 && list[0] == 44 && list[3] == 77 && list[6] == 66);	
	
	list.remove_by_index(0);
	//33 22 77 55 33 66
	assert(list.get_size() == 6 && list[0] == 33);
	
	list.remove_by_index(5);
	//33 22 77 55 33
	assert(list.get_size() == 5);
	
	list.remove_by_index(2);
	//33 22 55 33
	assert(list.get_size() == 4 && list[0] == 33 && list[1] == 22 && list[2] == 55 && list[3] == 33);	
	
	list.insert(1, 33);
	list.insert(1, 33);
	//33 33 33 22 55 33
	assert(list.get_size() == 6 && list[0] == 33 && list[1] == 33 && list[2] == 33 && list[3] == 22 && list[4] == 55 && list[5] == 33);	
	
	list.remove_by_value(22);
	list.remove_by_value(33);
	//33 33 55 33
	assert(list.get_size() == 4 && list[0] == 33 && list[1] == 33 && list[2] == 55 && list[3] == 33);
	
	list.remove_by_value(33, 1);
	//55
	assert(list.get_size() == 1 && list[0] == 55);
	
	list.remove_by_value(33, 1); //cout: 'Element with value 33 does not exist in the list'
	
	list.push_back(66);
	list.push_back(77);
	list.push_back(88);
	list.push_back(99);
	//55 66 77 88 99
	
	List list2(list);
	//55 66 77 88 99
	assert(list2.get_size() == 5 && list[0] == 55 && list[1] == 66 && list[2] == 77 && list[3] == 88 && list[4] == 99);

	list2.insert(0, 44);
	list.print();
	list2.print();
	return 0;
}
