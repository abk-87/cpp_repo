#include <iostream>

int get_coefficient(int x);
int concatenate(int a, int b, int k);

int main ()
{
	int a, b;
	std::cout << "Enter two numbers: ";
	std::cin >> a >> b;
	std::cout << concatenate(a, b, get_coefficient(b)) << std::endl;
	return 0;
}

int get_coefficient(int x)
{
	int k = 1;
	do
	{
		x /= 10;
		k *= 10;
	} while (x > 0);
	return k;
}

int concatenate(int a, int b, int k)
{
	return a * k + b;
}
