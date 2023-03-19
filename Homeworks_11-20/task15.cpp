/*Տրված n բնական թվի համար արտածել ֆիբոնաչիի հաջոր-
դականության n-րդ անդամը:*/

#include <iostream>

long fibonacci(int n);

int main()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << fibonacci(n) << std::endl;
	return 0;
}

long fibonacci(int n)
{
	int i = 2;
	int a = 1;
	long fib = 1;
	int tmp;
	if (n == 0) fib = 0;
	while (i < n)
	{
		tmp = fib;
		fib = fib + a;
		a = tmp;
		i++;
	}
	return fib;
}
