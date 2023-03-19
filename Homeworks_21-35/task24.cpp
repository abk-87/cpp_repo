/*Insert the number K into sequence of N numbers in the beginning/end. Do the same but insert the element into M-th place.*/

#include <iostream>
#include <time.h>

void complete_array(int a[], int size);
void print_array(int a[], int size);
void add_K(int a[], int a2[], int size, int m, int k);

int main()
{
	srand(time(NULL));
	int N, M, K;
	std::cout << "Enter the count of elements in the sequence: ";
	std::cin >> N;
	int *arr = new int [N];
	int *arr2 = new int [N+1];
	complete_array(arr, N);
	print_array(arr, N);
	std::cout << "Enter the number K: ";
	std::cin >> K;
	add_K(arr, arr2, N, 1, K);
	print_array(arr2, N+1);
	add_K(arr, arr2, N, N+1, K);
	print_array(arr2, N+1);
	std::cout << "Mark the place where to put the number K: ";
	std::cin >> M;
	add_K(arr, arr2, N, M, K);
	print_array(arr2, N+1);

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

void add_K(int a[], int a2[], int size, int m, int k)
{
	for (int i = 0; i < size + 1; i++)
	{
		if (i + 1 < m) a2[i] = a[i]; 
		else if (i + 1 > m) a2[i] = a[i - 1];
		else a2[i] = k;
	}
}
