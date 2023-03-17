#include <iostream>

void complete_array(int arr[], int size);
void print_array(int arr[], int size);
void sort(int arr[], int size);
int get_index(int arr[], int size, int num);

int main()
{
	int size;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	int* arr = new int [size];
	complete_array(arr, size);
	sort(arr, size);
	print_array(arr, size);
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << get_index(arr, size, num) << std::endl;
	return 0;
}

void complete_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()% 100;
	}
}

void print_array(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void sort(int arr[], int size)
{
	int tmp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}	
	}
}

int get_index(int arr[], int size, int num)
{
	int m = size / 2;
	while (arr[m] != num)
	{
		if (arr[m] > num)
		{
			size = m - 1;
			m /= 2;
		}
		else
		{
			m = (m + size) / 2;
		}
	}	
	return m;
}
