/*Draw rectangle
Write a program which will input two integer - N and M. The program should "draw" a rectangle of NxM size using "*" and spaces.
    E.g. Input 6 4
    Output
    ******
    *    *
    *    *
    ******
    Enhance the program to input the character to be use for "drawing"
    E.g. Input 6 4 $
    
    $$$$$$
    $    $
    $    $
    $$$$$$
 */

#include <iostream>
#include <string>
#include <fstream>

std::ifstream fin;
std::ofstream fout;

short string_to_int_1(std::string s);
short string_to_int_2(std::string s);
bool is_digit(std::string s);
char is_char_1(std::string s);
char is_char_2(std::string s);
void get_rectangle_1(short n, short m, char symb);
void get_rectangle_2(short n, short m, char symb);

int main(int argc, char *argv[])
{
	std::string s1, s2, s3, f = "-t";
	short N, M;
	char symb;
	
	if (argc > 2 || (argc == 2 && argv[1] != f))
	{
		std::cout << "You can give the program only one argument: -t" << std::endl;
		return 0;
	}
	
	if (argc == 2)
	{
		int i = 0;	
	        fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		try
		{
                        fin.open("in.txt");
                        fout.open("out.txt", std::ofstream::app);
                }
                catch (const std::exception & ex)
                {
                        std::cout << ex.what() << std::endl;
                        std::cout << "File opening error" << std::endl;
                }
				
		while (i < 5)
		{
			getline(fin, s1);
			N = string_to_int_2(s1);
			getline(fin, s2);
			M = string_to_int_2(s2);
			getline(fin, s3);
			symb = is_char_2(s3);
				
			get_rectangle_2(N, M, '*');
			get_rectangle_2(N, M, symb);
			i++;
		}
		fin.close();
		fout.close();
	}
	else
	{
		std::cout << "Enter an integer number (N): ";	
		getline(std::cin, s1);
		N = string_to_int_1(s1);
		std::cout << "Enter another integer number (M): ";
		getline(std::cin, s2);
		M = string_to_int_1(s2);
		std::cout << "Enter one symbol: ";
		getline(std::cin, s3);
		symb = is_char_1(s3);
		
		get_rectangle_1(N, M, '*');
		get_rectangle_1(N, M, symb);
	}
	return 0;
}

short string_to_int_1(std::string s)
{
	while (true)
	{
		while (!is_digit(s))
		{
			std::cout << "You entered a non-integer number. Try again: ";
			getline(std::cin, s);
			continue;
		}
		if (s.length() > 5 || std::stoi(s) > 32767)
		{	
			std::cout << "Entered integer number should not exceed 32767. Enter again: ";
			getline(std::cin, s);
		}
		else
		{
			break;
		}
	}
	return std::stoi(s);
}

short string_to_int_2(std::string s)
{
	while (true)
	{
		while (!is_digit(s))
		{
			getline(fin, s);
			continue;
		}
		if (s.length() > 5 || std::stoi(s) > 32767)
		{
			getline(fin, s);
		}
		else
		{
			break;
		}
	}
	return std::stoi(s);
}

bool is_digit(std::string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i])) 
		{
			return false;
		}
	}
	return true;
}

char is_char_1(std::string s)
{
	while (s.length() > 1)
	{
		std::cout << "Enter one symbol: ";
		getline(std::cin, s);
	}
	return s[0];
}

char is_char_2(std::string s)
{
	while (s.length() > 1)
	{
		getline(fin, s);
	}
	return s[0];
}

void get_rectangle_1(short n, short m, char symb)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
			{	
				std::cout << symb;
			}
			else 
			{
				std::cout << ' ';
			}
		}
		std::cout << '\n';	
	}
}

void get_rectangle_2(short n, short m, char symb)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
			{	
				fout << symb;
			}
			else 
			{
				fout << ' ';
			}
		}
		fout << '\n';	
	}
}
