/*Prime numbers
Input a number and check if it is a prime number. Print the answer.
    3.1 Input number N and print all prime numbers in the range 1-N*/

#include <iostream>
#include <math.h>

bool is_digit(std::string num);
bool is_simple(int n);
void print(int n);
void sim_nums_until_N(int n);

int main()
{
	std::string num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	while (!is_digit(num))
	{
		std::cout << "Enter a number: ";
		std::cin >> num;
	}
	int N = std::stoi(num);
	print(N);
	sim_nums_until_N(N);
	return 0;
}

bool is_digit(std::string num)
{
	for (int i = 0; i < num.length(); i++)
	{
		if (!std::isdigit(num[i])) return false;
	}
	return true;
}

bool is_simple(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

void print(int n)
{
	if (n > 1 && is_simple(n))
	{
		std::cout << n << " is simple" << std::endl;
	}
	else
	{
		std::cout << n << " is not simple" << std::endl;
	}
}

void sim_nums_until_N(int n)
{
	std::cout << "All prime numbers in the range 1-" << n << ": ";
	for (int num = 2; num <= n; num++)
	{
		if (is_simple(num))
		{
			std::cout << num << " ";
		}
	}
	std::cout << std::endl;
}
