#include <iostream>
#include <string>

class Human
{
	public:
		std::string name;
		int age;
};

void print(Human arr[], int size);
void sort(Human arr[], int size);

int main()
{
	Human h1, h2, h3, h4, h5;
	h1.name = "Armen";
	h1.age = 30;
	h2.name = "Karen";
	h2.age = 33;
	h3.name = "Suren";
	h3.age = 25;
	h4.name = "Vazgen";
	h4.age = 41;
	h5.name = "Gurgen";
	h5.age = 36;
	Human arr[5]{h1, h2, h3, h4, h5};
	sort(arr, 5);
	print(arr, 5);
	return 0;
}

void print(Human arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i].name << " " << arr[i].age << std::endl;
	}
}

void sort(Human arr[], int size)
{
	Human tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j].age > arr[j+1].age)
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}	
}
