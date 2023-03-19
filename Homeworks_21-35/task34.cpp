/*Տրված տողի համար կառուցել և արտածել մի նոր տող,որտեղ բոլոր a տառերը փոխարինված են ab-ով:*/

#include <iostream>
#include <string>

std::string replace_a_to_ab(std::string str1, std::string str2);

int main()
{
	std::string str1;
	std::string str2 = "";
	std::cout << "Enter a string: ";
	getline(std::cin, str1);
	std::cout << replace_a_to_ab(str1, str2) << std::endl;
	return 0;
}

std::string replace_a_to_ab(std::string str1, std::string str2)
{
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] == 'a') 
		{
			str2 += "ab";
		}
		else str2 += str1[i];
	}
	return str2;
}
