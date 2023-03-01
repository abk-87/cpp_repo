#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::getline(std::cin, str);

	std::string str_word = "", str_max = "", str_min = "";
	int len_word = 0, len_max = 0, len_min = 0;

	for (int i = 0; ; i++)
	{
		if (str[i] != ' ' && str[i] != '\0')
		{
			str_word += str[i];
			len_word += 1;
		}
		else if (str_word != "")
		{
			if (len_word > len_max)
			{
				str_max = str_word;
				len_max = len_word;
				if (len_min == 0)
				{
					str_min = str_word;
					len_min = len_word;
				}
			}
			else if (len_word < len_min)
			{
				str_min = str_word;
				len_min = len_word;
			}
			str_word = "";
                	len_word = 0;
		}
		if (str[i] == '\0')
		{
			break;
		}
	}

	std::cout << str_max << " " << str_min << std::endl;

	for (int i = 0; str_min[i] != '\0'; i++)
	{
		for (int j = 0; str_max[j] != '\0'; j++)
		{
			if (str_min[i] == str_max[j])
			{
				std::cout << str_min[i] << " ";
			}
		}
	}
	std::cout << std::endl;

	return 0;
}
