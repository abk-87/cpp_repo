/*Given two strings, check if one is a substring of the other (e.g. "cat" is a substring "complicated"*/

#include <iostream>
#include <string>

void find_substr(std::string str1, std::string str2);

int main()
{
	std::string str1;
	std::string str2;
	std::cout << "Enter a string: ";
	getline(std::cin, str1);
	std::cout << "Enter another string: ";
	getline(std::cin, str2);
	find_substr(str1, str2);
	return 0;
}

void find_substr(std::string str1, std::string str2)
{
	if (str1.find(str2) != std::string::npos) std::cout << str2 << " is substring of " << str1 << std::endl;
	else if (str2.find(str1) != std::string::npos) std::cout << str1 << " is substring of " << str2 << std::endl;
	else std::cout << "No string is a substring of another" << std::endl;
}
