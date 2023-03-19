/*Guess a number (roles changed)
Write a program which asks the user to think a of random number from 1 to 100 and try to guess the number. The user must tell the computer whether the guessed number is too high or too low. 
Modify the program so that no matter what number the user thinks of (1-100) the computer can guess it in 7 or less guesses.*/

#include <iostream>
#include <string>
#include <time.h>

void guess(int n);

int main()
{
	int num;
	std::cout << "Enter" << std::endl;
	std::cout << "'h' - if the number the computer guessed is less than the number you memorized by" << std::endl;
	std::cout << "'l' - if the number the computer guessed is greater than the number you memorized by" << std::endl;
	std::cout << "Enter a number in the range 1-100: ";
	std::cin >> num;
	guess(num);
	return 0;
}

void guess(int n)
{
	int count = 1;
	int a_num = 100 / 2;
	int l = 1, h = 100;
	std::string prompt = "";
	std::cout << a_num << std::endl;
	while (a_num != n)
	{
		std::cin >> prompt;
		if (prompt == "h")
		{
			h = a_num;
			a_num = (h + l) / 2;
			std::cout << a_num << std::endl;
		}
		else if (prompt == "l")
		{
			l = a_num + 1;
			a_num = (h + l) / 2;
			std::cout << a_num << std::endl;
		}
		count ++;
	}
	std::cout << "Yes, it's " << n << "! The computer guessed the number in " << count << " tries." << std::endl;
}
