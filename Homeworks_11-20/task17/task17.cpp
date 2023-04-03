/*
 Տրված է N բնական թիվը: Օգտագործելով մեկ ցիկլ՝ հաշվել հետևյալ գումարը. 1+1/1!+1/2!+1/3!+…+1/N! (ստացված թիվը e հաստատունի մոտավոր արժեքն է):
*/

#include <iostream>
#include <string>
#include <fstream>

std::ifstream fin;
std::ofstream fout;

float get_sum(int n);
int string_to_int_1(std::string s);
int string_to_int_2(std::string s);
bool is_digit(std::string s);

int main(int argc, char *argv[])
{
	std::string s, f = "-t";
	int N;

	if (argc > 2 || (argc == 2 && argv[1] != f))
	{
		std::cout << "You can give the program only one argument: -t" << std::endl;
		return 0;
	}
	
	if (argc == 2)
	{
		int i = 0;
		fin.open("in.txt");
		fout.open("out.txt", std::ofstream::app);
		if (!fin.is_open() || !fout.is_open())
		{
			std::cout << "File opening error" << std::endl;
		}
		else
		{
			while (i < 10)
			{
				getline(fin, s);
				N = string_to_int_2(s);
				fout << get_sum(N) << std::endl;
				i++;
			}
		}
	}
	else
	{
		std::cout << "Enter natural number N: ";
		getline(std::cin, s);
		N = string_to_int_1(s);
		std::cout << "1+1/1!+1/2!+1/3!+…+1/N! = " << get_sum(N) << std::endl;
	}
	return 0;
}

int string_to_int_1(std::string s)
{
	while (true)
	{
		while (!is_digit(s))
		{
			std::cout << "You entered a non-natural number. Enter again: ";
			getline(std::cin, s);
			continue;
		}
		if (s.length() > 10 || std::stoi(s) > 1000000000)
		{
			std::cout << "Entered natural number should not exceed 1000000000. Enter again: ";
			getline(std::cin, s);
		}
		else
		{
			break;
		}
	}
	return std::stoi(s);
}

int string_to_int_2(std::string s)
{
	while (true)
	{
		while (!is_digit(s))
		{
			getline(fin, s);
			continue;
		}
		if (s.length() > 10 || std::stol(s) > 1000000000)
		{
			getline(fin, s);
		}
		else
		{
			break;
		}
	}
	return std::stol(s);
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

float get_sum(int n)
{
	float sum = 1;
	float fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact = i * fact;
		sum += 1 / fact;
	}
	return sum;
}
