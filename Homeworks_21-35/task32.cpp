/*Input a word/string (sequence of symbols) and make all of the letters capital/small.
Input a word/string and check if it is anagram (e.g. "mary" and "army" are anagram, i.e. have the same symbols but in different order).*/

#include <iostream>
#include <string>

std::string upper(std::string str);
std::string lower(std::string str);
bool is_anagram(std::string str, std::string str2);

int main()
{
	std::string str;
	std::string str2;
	std::cout << "Enter a word/string: ";
	getline(std::cin, str);
	std::cout << upper(str) << std::endl;
	std::cout << lower(str) << std::endl;
	std::cout << "Enter another word/string: ";
	getline(std::cin, str2);
	if (is_anagram(str, str2)) std::cout << str << " and " << str2 << " are anagram" << std::endl;
	else std::cout << str << " and " << str2 << " are not anagram" << std::endl;
	return 0;
}

std::string upper(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
	return str;
}

std::string lower(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = std::tolower(str[i]);
	}
	return str;
}

bool is_anagram(std::string str, std::string str2)
{
	if (str.length() == str2.length())
	{
		for (int i = 0; i < str.length(); i++)
		{
			for (int j = 0; j < str2.length(); j++)
			{
				if (str[i] == str2[j])
				{
					str2.erase(j, 1);
					break;
				}
			}
			if (str2.length() != str.length() - i - 1) return false;
		}
	}
	else return false;
	return true;
}
