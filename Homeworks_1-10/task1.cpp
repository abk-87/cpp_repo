/*Calculate sum of the digits
Write a program which will input an integer number and will print the sum of the digits of the number. 
    E.g. Input 123 - Output 6 (which is 1 + 2 + 3)*/

#include <iostream>
#include <string>

bool is_digit(std::string num);
int get_sum_of_digits(std::string num);

int main()
{
	std::string num;
	std::cout << "Enter an integer number: ";
	std::cin >> num;
	while (!is_digit(num))
	{
		std::cout << "Enter an integer number: ";
		std::cin >> num;
	}
	std::cout << get_sum_of_digits(num) << std::endl;
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

int get_sum_of_digits(std::string num)
{
	int sum = 0;
	for (int i = 0; i < num.length(); i++)
	{
		sum += (num[i] - '0');
	}
	return sum;
}
