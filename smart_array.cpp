#include <iostream>
#include <time.h>

class SmartArray
{
	int* array;
	int Size;
public:
	SmartArray()
	{
		Size = 0;
		array = new int[Size];
	}
	SmartArray(int size)
	{
		Size = size;
		array = new int[Size]{};
	}
	
	int size()
	{
		return Size;
	}
	int at(int index)
	{
		return array[index];
	}
	void insert(int index, int num)
	{
		if (Size <= index)
		{
			int tmp_Size = Size;
			Size = index + 1;
			int* tmp_array = new int[Size]{};
			for (int i = 0; i < tmp_Size; i++)
			{
				tmp_array[i] = array[i];
			}
			delete[] array;
			array = tmp_array;
		}
		array[index] = num;
	}

	~SmartArray()
	{
		delete[] array;
	}
};

void fill_array(SmartArray &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		arr.insert(i, rand()% 100);
	}
}

void print_array(SmartArray &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr.at(i) << " ";
	}
	std::cout << std::endl;
}
int main()
{
	srand(time(NULL));
	SmartArray arr(5);
	fill_array(arr);
	std::cout << arr.size() << std::endl;
	print_array(arr);
	arr.insert(10, 111);
	std::cout << arr.size() << std::endl;
	print_array(arr);
	return 0;
}
