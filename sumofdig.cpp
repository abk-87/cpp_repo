#include <iostream>

int main()
{
	long n;
	std::cout << "Enter a number: ";
	std::cin >> n;
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	std::cout << sum << std::endl;
	return 0;
}
