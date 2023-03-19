/*Input a sequence of N whole numbers and print Yes if the numbers in the sequence are sorted in ascending/descending order.*/

#include <iostream>
#include <time.h>

void complete_array(int a[], int size);
void print_array(int a[], int size);
bool asc_comparison(int a[], int size);
bool desc_comparison(int a[], int size);

int main()
{
	srand(time(NULL));
	int N;
	std::cout << "Enter the count of elements in the sequence: ";
	std::cin >> N;
	int *arr = new int [N];
	complete_array(arr, N);
	print_array(arr, N);
	if (asc_comparison(arr, N) || desc_comparison(arr, N)) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	delete [] arr;
	return 0;
}

void complete_array(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand()% 100;
	}
}

void print_array(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

bool asc_comparison(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

bool desc_comparison(int a[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (a[i] < a[i + 1]) return false;
	}
	return true;
}
