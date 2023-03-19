/*Տրված տողի համար կառուցել և արտածել մի նոր տող, որտեղ բոլոր իրար հաջորդող միևնույն սիմվոլների փոխարեն թողնված է դրանցից մեկը միայն:*/

#include <iostream>
#include <string>

std::string del_ident_symb(std::string str1, std::string str2);

int main()
{
	std::string str1;
	std::string str2 = "";
	std::cout << "Enter a string: ";
	getline(std::cin, str1);
	std::cout << del_ident_symb(str1, str2) << std::endl;
	return 0;
}

std::string del_ident_symb(std::string str1, std::string str2)
{
	str2 += str1[0];
	for (int i = 1; i < str1.length(); i++)
	{
		if (str1[i] == str1[i - 1]) 
		{
			continue;
		}
		else str2 += str1[i];
	}
	return str2;
}
