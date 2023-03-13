#include <iostream>
#include <cmath>

int convertation(int b, int d);

int main()
{
	int b_num;
	int d_num = 0;
	std::cout << "Enter a binary number: ";
	std::cin >> b_num;
	std::cout << "Decimal number: " << convertation(b_num, d_num) << std::endl;
	return 0;
}

int convertation(int b, int d)
{
	int i = 0;
	int dig;
	while (b != 0)
	{
		dig = b % 10;
		d += dig * pow(2, i);
		b /= 10;
		i++;
	}
	return d;
}
