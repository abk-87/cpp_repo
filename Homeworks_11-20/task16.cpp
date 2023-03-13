#include <iostream>
#include <string>

std::string inverse(std::string num);

int main()
{
	std::string num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	std::cout << inverse(num) << std::endl;
	return 0;
}

std::string inverse(std::string num)
{
	std::string inverse_num = "";
	for (int i = num.length() - 1; i >= 0; i--)
	{
		inverse_num += num[i];
		inverse_num += '0';
	}
	return inverse_num;
}
