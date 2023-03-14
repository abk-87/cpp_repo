#include <iostream>
#include <string>

struct human
{
	std::string name;
	int age;
};

int main()
{
	human *arr = new human [5];
	human oldest = {"", 0};
	std::cout << "Enter name and age of 5 people" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> arr[i].name;
		std::cin >> arr[i].age;
		if (arr[i].age > oldest.age) oldest = arr[i];
	}
	std::cout << "The oldest person is "<< oldest.name << ". He/she is " << oldest.age << " years old." << std::endl;
	delete [] arr;
	return 0;
}
