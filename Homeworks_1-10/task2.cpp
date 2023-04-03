/*Inverse the number
Write a program which will input an integer number and calculate the inverse of the number. Print the output.
    E.g. Input 163 - Output 361*/

#include <iostream>
#include <string>

bool is_digit(std::string num);
std::string inverse(std::string num);

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
	std::cout << std::stol(inverse(num)) << std::endl;
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

std::string inverse(std::string num)
{
	std::string inverse_num = "";
	for (int i = num.length() - 1; i >= 0; i--)
	{
		inverse_num += num[i];
	}
	return inverse_num;
}
