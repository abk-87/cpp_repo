/*Նկարագրել ֆունկցիա, որն արգումենտում ստանում է նույն
երկարության երկու բնական թվերի զանգված և կառուցում է նույն երկարության երրորդ զանգված, որի
տարրերը հավասար են առաջին երկու զանգվածների համապատասխան տարրերի ամենամեծ ընդհանուր բաժանարարներին:*/

#include <iostream>
#include <time.h>

void complete_array(int a1[], int a2[], int size);
void print_array(int a[], int size);
int get_gr_com_div(int a, int b);
void foo(int a1[], int a2[], int a[], int size);

int main()
{
	srand(time(NULL));
	int size;
	std::cout << "Enter the size of arrays: ";
	std::cin >> size;
	int *arr1 = new int [size];
	int *arr2 = new int [size];
	int *arr = new int [size];
	complete_array(arr1, arr2, size);
	print_array(arr1, size);
	print_array(arr2, size);
	foo(arr1, arr2, arr, size);
	print_array(arr, size);
	delete [] arr1;
	delete [] arr2;
	delete [] arr;
	return 0;
}

void complete_array(int a1[], int a2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a1[i] = rand()% 1000;
		a2[i] = rand()% 1000;
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

int get_gr_com_div(int a, int b)
{
	int limit;
	int gr_com_div = 1;
	if (a > b) limit = b;
        else limit = a;	
	for (int i = 2; i <= limit; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gr_com_div = i;	
		}
	}
	return gr_com_div;
}

void foo(int a1[], int a2[], int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = get_gr_com_div(a1[i], a2[i]);
	}
}
