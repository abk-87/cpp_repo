/*  
    Նկարագրել ֆունկցիա, որն արգումենտում ստանում է n և k բնական թվերը և 
    ա) վերադարձնում է true, եթե n-ը հանդիսանում է k-ի որևէ ամբողջ աստիճան, և վերադարձնում է false՝ հակառակ դեպքում,
    բ) արտածում է n թվի ներկայացումը k-ական համակարգում (k<10):
*/

#include <iostream>
#include <string>
#include <fstream>

std::ifstream fin;
std::ofstream fout;

bool is_digit(std::string s);
unsigned int string_to_int_1(std::string s);
unsigned int string_to_int_2(std::string s);
bool is_power(unsigned int n, unsigned int k);
std::string conversion(unsigned int n, unsigned int k);
std::string print_true_false(unsigned int n, unsigned int k);

int main(int argc, char *argv[])
{
	std::string s1, s2, f = "-t";
	unsigned int n, k;	

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
	
		while (i < 10)	
		{
			getline(fin, s1);
			n = string_to_int_2(s1);
			getline(fin, s2);
			k = string_to_int_2(s2);

			fout << n << " is any integer power of " << k << ": " << print_true_false(n, k) << std::endl;
			if (k > 1 && k < 10) 
			{
				fout << "Representation of " << n << " in " << k << "-system: " << conversion(n, k) << std::endl;
			}
			i++;
		}
		fin.close();
		fout.close();
	}
	else	
	{
		std::cout << "Enter natural number 'n': ";
		getline(std::cin, s1);
		n = string_to_int_1(s1);
	
		std::cout << "Enter natural number 'k': ";
		getline(std::cin, s2);
		k = string_to_int_1(s2);
	
		std::cout << n << " is any integer power of " << k << ": " << print_true_false(n, k) << std::endl;
		if (k > 1 && k < 10) 
		{
			std::cout << "Representation of " << n << " in " << k << "-system: " << conversion(n, k) << std::endl;
		}
	}

	return 0;
}

unsigned int string_to_int_1(std::string s)
{
	while (true)
	{
		while (!is_digit(s))
		{
			std::cout << "You entered a non-natural number. Enter again: ";
			getline(std::cin, s);
			continue;
		}
		if (s.length() > 10 || std::stol(s) > 4294967295)
		{
			std::cout << "Entered natural number should not exceed 4294967295. Enter again: ";
			getline(std::cin, s);
		}
		else
		{
			break;
		}
	}
	return std::stol(s);
}

unsigned int string_to_int_2(std::string s)
{
	while (true)
	{
		while (!is_digit(s))
		{
			getline(fin, s);
			continue;
		}
		if (s.length() > 10 || std::stol(s) > 4294967295)
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

bool is_power(unsigned int n, unsigned int k)
{
	if (n == k || n == 1) 
	{
		return true;
	}
	if (k < 2) 
	{
		return false;
	}
	while (n > k)
	{
		if (n % k != 0) 
		{
			return false;
		}
		n /= k;
	}
	if (n == k) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

std::string conversion(unsigned int n, unsigned int k)
{
	std::string k_num = "", tmp = "";
	int i = 0;
	while (n > 0)
	{
		tmp += std::to_string(n % k);
		n /= k;
		i++;
	}
	for (int i = tmp.length() - 1; i >= 0; i--)
	{
		k_num += tmp[i];
	}
	return k_num;
}


std::string print_true_false(unsigned int n, unsigned int k)
{
	if (is_power(n, k)) 
	{
		return "true";
	}
	else 
	{
		return "false";
	}
}
