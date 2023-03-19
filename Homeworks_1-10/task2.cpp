/*Inverse the number
Write a program which will input an integer number and calculate the inverse of the number. Print the output.
    E.g. Input 163 - Output 361*/

#include <iostream>

int inverse(int n);

int main()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << inverse(num) << std::endl;
	return 0;
}

int inverse(int n)
{
	int inverse_n = 0;
	while (n > 0)
	{
		inverse_n = (inverse_n * 10) + (n % 10);
		n /= 10;
	}
	return inverse_n;
}
