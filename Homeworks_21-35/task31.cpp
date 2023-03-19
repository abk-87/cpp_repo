/*Գրել int find(char* str,char* substr) նախատիպով
ֆունկցիա, որը վերադարձնում է str տողում substr տողի
առաջին անգամ հանդիպելու դիրքը և վերադարձնում է –1,
եթե substr տողը չի հանդիպում str տողում:*/

#include <iostream>

int find(char* str,char* substr);

int main()
{
	char str[100]{};
	char substr[100]{};
	std::cout << "Enter str: ";
	std::cin.getline(str, 100);
	std::cout << "Enter substr: ";
	std::cin.getline(substr, 100);
	std::cout << find(str, substr) << std::endl;
	return 0;
}

int find(char* str,char* substr)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == substr[0])
		{
			int j = 1;
			while (substr[j] != '\0')
			{
				if (str[i+j] != substr[j]) break;
				j++;
			}
			if (substr[j] == '\0') return i;
		}
	}
	return -1;
}
