/*Guess a number
Write a program that calculates a random number 1 through 100. The program then asks the user to guess the number. If the user guesses too high or too low then the program should output "too high" or "too low" accordingly.
The program must let the user continue to guess until the user correctly guesses the number. Output how many guesses it took the user to correctly guess the right number.*/

#include <iostream>
#include <time.h>
#include <string>

bool is_digit(std::string str);
int checking(std::string str);
void guess(int n);
int get_random_number();

int main()
{
	guess(get_random_number());
	return 0;
}

bool is_digit(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i])) return false;
	}
	return true;
}

int checking(std::string str)
{
	if (!is_digit(str) || str.size() > 3 || std::stoi(str) > 100)
	{
		throw "wrong number";
		return 0;
	}
	return std::stoi(str);
}

void guess(int n)
{
	int count = 0;
	std::string s_num;
	std::cout << "Enter a number: ";
	std::cin >> s_num;
	int a_num = 0;
        while (true)
	{
		while (true)
              	{
	                try
        	        {
	                        a_num = checking(s_num);
	                }
	                catch (const char* text)
	                {
	                        std::cout << "You entered a wrong number. Enter a number between 1-100: ";
	                        std::cin >> s_num;
	                        continue;
	                }
			count++;
	                break;
	        }
		
		if (a_num == n)
		{
			std::cout << "Yes, it's " << n << "! You guessed the number in " << count << " tries." << std::endl;
			break;
		}
		else if (a_num > n)
		{
			//if the user's guess is greater than the memorized number by more than 10, the program prints "too high", 
			//otherwise it prints "high"
			if (a_num <= n + 10) std::cout << "High" << std::endl;
			else std::cout << "Too high" << std::endl;
		}
		else
		{
			//if the user's guess is less than the memorized number by more than 10, the program prints "too low", 
			//otherwise it prints "low"
			if (a_num >= n - 10) std::cout << "Low" << std::endl;
			else std::cout << "Too low" << std::endl;
		}
		std::cout << "Enter a number: ";
		std::cin >> s_num;
	}
}

int get_random_number()
{	
	srand(time(NULL));
	int m_num = 1 + rand()% 100;
	std::cout << "I memorized the number between 1-100. Try to guess it" << std::endl;
	return m_num;
}
