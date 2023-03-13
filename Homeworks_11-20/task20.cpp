#include <iostream>
#include <time.h>

void complete_the_arr(int a[], int size);
void add_count_of_digs(int a1[], int a2[], int size1, int size2);
void count_of_max_rep_dig(int a[], int size);

int main()
{
	srand(time(NULL));
	int n;
	std::cout << "Enter the array size: ";
	std::cin >> n;
	int arr[n]{};
	int arr2[10]{};
	complete_the_arr(arr, n);
	add_count_of_digs(arr, arr2, n, 10);
	count_of_max_rep_dig(arr2, 10);
	return 0;
}

void complete_the_arr(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand()% 1000;
		std::cout << a[i] << " ";	
	}
	std::cout << std::endl;
}

void add_count_of_digs(int a1[], int a2[], int size1, int size2)
{
	int el;
	int dig;
	for (int i = 0; i < size1; i++)
	{
		el = a1[i];
		while (el > 0)
		{
			dig = el % 10;
			a2[dig]++; 
			el /= 10;
		}		
	}
}

void count_of_max_rep_dig(int a[], int size)
{
	int max = a[0];
	int i_max = 0;
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
		{       
			max = a[i];
			i_max = i;
		}
	}
	std::cout << "Maximum repeating digit: " << i_max << std::endl;
	std::cout << "Count of maximum repeating digit: " << max << std::endl;
}
