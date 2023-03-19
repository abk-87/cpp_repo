/*արտածել տրված ամբողջ թվերի հաջորդականությունը ցիկ-
լիկ տեղաշարժված դեպի աջ 4 տարրով:*/

#include <iostream>
#include <time.h>

void complete_array(int a[], int size);
void print_array(int a[], int size);
void el_movement(int a[], int size);

int main()
{
	srand(time(NULL));
	int N;
	std::cout << "Enter the count of elements in the sequence: ";
	std::cin >> N;
	int *arr = new int [N];
	complete_array(arr, N);
	print_array(arr, N);
	el_movement(arr, N);
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

void el_movement(int a[], int size)
{
	int tmp1 = a[0], tmp2, i = 4;
	for (int j = 0; j < size; j++)
	{
		tmp2 = a[i];
		a[i] = tmp1;
		tmp1 = tmp2;
		i = i + 4;
		if (i >= size) i = i - size;
		if (i == 4) 
		{
			i = 5;
			tmp1 = a[1];
		}
		else if (size % 2 == 0 && size % 4 == 0 && i == 5)
		{
			i = 6;
			tmp1 = a[2];
		}
		else if (size % 2 == 0 && size % 4 == 0 && i == 6)
		{
			i = 7;
			tmp1 = a[3];
		}
	}
}
