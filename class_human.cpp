#include <iostream>
#include <string>

class Human
{
	std::string name;
	int age;
public:
	Human()
	{
		name = "";
		age = 0;
	}
	Human(std::string str, int n)
	{
		name = str;
		age = n;
	}
	std::string get_name()
	{
		return name;
	}
	int get_age()
	{
		return age;
	}

	bool operator>(const Human& object)
	{
		return this->age > object.age;
	}
	
	std::ostream& operator<<(std::ostream& out, const Human& object)
	{
		out << object.name << " " << object.age;
		return out;
	}
};

void print(Human arr[], int size);
void sort(Human arr[], int size);


int main()
{
	Human h1("Armen", 30);
	Human h2("Karen", 33);
	Human h3("Suren", 25);
	Human h4("Vazgen", 41);
	Human h5("Gurgen", 36);
	Human arr[5]{h1, h2, h3, h4, h5};
	sort(arr, 5);
	print(arr, 5);
	return 0;
}

void print(Human arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

void sort(Human arr[], int size)
{
	Human tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}	
}
