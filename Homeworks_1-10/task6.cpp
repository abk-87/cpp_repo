/*Power of 2
Input a number and check if it is a power of 2.*/

#include <iostream>

bool is_power(int n);
void print(int n);

int main()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	print(num);
	return 0;
}

bool is_power(int n)
{
	while (n > 2)
	{
		if (n % 2 == 1)
		{
			return false;
		}
		n /= 2;
	}
	return true;
}

void print(int n)
{
	if (is_power(n))
	{
		std::cout << n << " is power of 2" << std::endl;
	}
	else
	{
		std::cout << n << " is not power of 2" << std::endl;
	}
}
