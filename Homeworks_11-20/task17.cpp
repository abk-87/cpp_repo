#include <iostream>

float get_sum(int n);

int main()
{
	int N;
	std::cout << "Enter number N: ";
	std::cin >> N;
	std::cout << "1+1/1!+1/2!+1/3!+…+1/N! = " << get_sum(N) << std::endl;
	return 0;
}

float get_sum(int n)
{
	float sum = 1;
	float fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact = i * fact;
		sum += 1 / fact;
	}
	return sum;
}
