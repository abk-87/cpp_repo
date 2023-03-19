/*Տրված է սիմվոլների միաչափ զանգված։ Որոշել և արտածել այդ զանգվածում առկա իրար հաջորդող ամենաերկար նույն սիմվոլային հաջորդականությունը։*/

#include <iostream>
#include <string>

char* longest_ident_char_seq(char chr[], int size);

int main()
{
	int size = 100;
	char chr[size]{};
	std::cout << "Enter text: ";
	std::cin.getline(chr, size);
	char* p = longest_ident_char_seq(chr, size);
	std::cout << "longest identical character sequence: " << p << std::endl;
	delete [] p;
	return 0;
}

char* longest_ident_char_seq(char chr[], int size)
{
	std::string tmp;
       	tmp[0] = chr[0];
	char* l_i_c_s = new char[size];
	int max_c = 1;
	int c = 1;
	for (int i = 1; chr[i] != '\0'; i++)
	{
		if (chr[i] == chr[i-1])
		{
			c++;
			tmp += chr[i];
		}
		else
		{
			if (c > max_c)
			{
				tmp.copy(l_i_c_s, size);
				max_c = c;
			}
			tmp = chr[i];
			c = 1;
		}
	}
	return l_i_c_s;
}
