#include <iostream>

int is_simple_1(int num) //is the number simple or not?
{
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int is_simple_2(int num) //the nearest simple number greater than the 'num'
{
	num++;
	while (true)
	{
		if (is_simple_1(num))
		{
			return num;
		}
		num++;	
	}
}

int is_simple_3(int num) //the nearest simple number les than the 'num'
{
	num--;
	while (num > 1)
	{
		if (is_simple_1(num))
		{
			return num;
		}
		num--;	
	}
	return -1;
}

int main()
{
	std::cout << "Enter a number: ";
	int num;
	std::cin >> num;
	
	if (num > 1 && is_simple_1(num))
	{
		std::cout << num << " is a simple number" << std::endl;
	}
	else
	{
		std::cout << num << " is not a simple number" << std::endl;	
	}
	
	int big = is_simple_2(num);
	int small = is_simple_3(num);

	std::cout << "The nearest simple number greater than " << num << " is " << big << std::endl;

	if (big - num < num - small)
	{
		std::cout << "The nearest simple number to " << num << " is " << big << std::endl;
	}
	else if (big - num > num - small)
	{
		std::cout << "The nearest simple number to " << num << " is " << small << std::endl;
	}
	else
	{
		std::cout << "The nearest simple numbers to " << num << " are " << small << " and " << big << std::endl;	
	}
	return 0;
}
