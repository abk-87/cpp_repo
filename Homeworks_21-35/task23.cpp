/*Delete the M-th element in the sequence of N numbers (e.g. delete the 3rd element from the [1,4,5,6,3] sequence and end up with [1,4,6,3] sequence).*/

#include <iostream>
#include <time.h>

void complete_array(int a[], int size);
void print_array(int a[], int size);
void delete_el(int a[], int a2[], int size, int m);

int main()
{
	srand(time(NULL));
	int N, M;
	std::cout << "Enter the count of elements in the sequence: ";
	std::cin >> N;
	int *arr = new int [N];
	int *arr2 = new int [N-1];
	complete_array(arr, N);
	print_array(arr, N);
	std::cout << "Specify the element number to delete: ";
	std::cin >> M;
	delete_el(arr, arr2, N, M);
	print_array(arr2, N-1);

	delete [] arr;
	delete [] arr2;
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

void delete_el(int a[], int a2[], int size, int m)
{
	for (int i = 0; i < size; i++)
	{
		if (i + 1 < m) a2[i] = a[i]; 
		else if (i + 1 > m) a2[i - 1] = a[i];
	}
}
