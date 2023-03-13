#include <iostream>
#include <string>

std::string convert_pos(int d);
std::string convert_neg(int d);
void reverse(std::string str);

int main()
{
	int d_num;
	std::cout << "Enter a decimal number: ";
	std::cin >> d_num;
	if (d_num > 0) reverse(convert_pos(d_num));
	else if (d_num < 0) reverse(convert_neg(d_num));
	return 0;
}

std::string convert_pos(int d)
{
	std::string b_str = "";
	int i = 0;
	while (d > 0)
	{
		if (d % 2 == 1) b_str += '1';
		else b_str += '0';
		d /= 2;
		i++;
	}
	while (i < 32)
	{
		b_str += '0';
		i++;
	}
	return b_str;
}

std::string convert_neg(int d)
{
	d = -d;
	std::string b_str = "";
	short flag = 1;
	int i = 0;
	while (d > 0)
	{
		if (d % 2 == 1)
		{
			if (flag == 1)
			{
				b_str += "1";
				flag = 0;
			}
			else b_str += "0";
		}
		else 
		{
			if (flag == 1) b_str += "0";
			else b_str += "1";
		}
		d /= 2;
		i++;
	}
	while (i < 32)
	{
		b_str += '1';
		i++;
	}
	return b_str;
}
void reverse(std::string str)
{
	std::cout << "Binary number (32 bits): ";
	for (int i = str.length() - 1; i >= 0; i--)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
}
