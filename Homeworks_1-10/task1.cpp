#include <iostream>

int get_sum_of_digits(int n);

int main()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << get_sum_of_digits(num) << std::endl;
	return 0;
}

int get_sum_of_digits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
