/*Input a sequence of N numbers and sort the sequence in ascending/descending order.*/

#include <iostream>
#include <time.h>


void complete_array(int a[], int size);
void print_array(int a[], int size);
void asc_sort(int a[], int size);
void desc_sort(int a[], int size);

int main()
{
	srand(time(NULL));
	int N;
	std::cout << "Enter the count of elements in the sequence: ";
	std::cin >> N;
	int *arr = new int [N];
	complete_array(arr, N);
	print_array(arr, N);
	asc_sort(arr, N);
	std::cout << "Sequence in ascending order: ";
	print_array(arr, N);
	desc_sort(arr, N);
	std::cout << "Sequence in descending order: ";
	print_array(arr, N);
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

void asc_sort(int a[], int size)
{
	int i = 0;
	int tmp;
	while (i < size)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
		i++;
	}
}

void desc_sort(int a[], int size)
{
	int tmp;
	for (int i = 0; i < size/2; i++)
	{
		tmp = a[i];
		a[i] = a[size - i - 1];
		a[size - i - 1] = tmp;
	}
}
