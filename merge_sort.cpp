#include <iostream>

#include <time.h>



void complete_array(int a[], int size);

void print_array(int a[], int size);

void fragmentation(int a[], int size);

void merge(int a[], int l_a[], int r_a[], int l_size, int r_size);



int main()

{
	
	srand(time(NULL));

	int n;
	std::cin >> n;
	int* arr = new int [n];
	
	complete_array(arr, n);
	print_array(arr, n);
	fragmentation(arr, n);
	print_array(arr, n);
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



void fragmentation(int a[], int size)

{

	if (size / 2 == 0) return;

	int* l_arr = new int [size / 2];

	int* r_arr = new int [size - size / 2];
	
	for (int i = 0; i < size / 2; i++)

	{

		l_arr[i] = a[i];

	}

	for (int i = 0; i < size - size / 2; i++)

	{

		r_arr[i] = a[i + size / 2];

	}



	fragmentation(l_arr, size / 2);
	
	fragmentation(r_arr, size - size / 2);

	merge(a, l_arr, r_arr, size / 2, size - size / 2);

}



void merge(int a[], int l_a[], int r_a[], int l_size, int r_size)

{

	int i = 0, j = 0, k = 0;

	while (j < l_size && k < r_size)

	{

		if (l_a[j] < r_a[k])

		{

			a[i] = l_a[j];

			i++;

			j++;

		}

		else

		{

			a[i] = r_a[k];

			i++;

			k++;

		}

	}



	for (int ll = j; ll < l_size; ll++)
	{

		a[i] = l_a[ll];

		i++;

	}

	for (int rr = k; rr < r_size; rr++)

	{
		a[i] = r_a[rr];

		i++;

	}


}