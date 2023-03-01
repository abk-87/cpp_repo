#include <iostream>

int main()
{
	int n;
	std::cout << "Enter a three-digit number: ";
	std::cin >> n;
	
	while (n != 0)
	{
		if (n / 100 == n % 10)
		{
			std::cout << n << " is polindrom" << std::endl;
		}
		std::cout << "Enter a three-digit number: ";
		std::cin >> n;
	}
	return 0;
}
