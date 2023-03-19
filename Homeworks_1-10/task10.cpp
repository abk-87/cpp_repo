/*Guess a number
Write a program that calculates a random number 1 through 100. The program then asks the user to guess the number. If the user guesses too high or too low then the program should output "too high" or "too low" accordingly.
The program must let the user continue to guess until the user correctly guesses the number. Output how many guesses it took the user to correctly guess the right number.*/

#include <iostream>
#include <time.h>

void guess(int n);
int rnd();

int main()
{
	guess(rnd());
	return 0;
}

void guess(int n)
{
	int a_num;
	int count = 0;
	std::cout << "Enter a number: ";
	std::cin >> a_num;
	while (a_num != n)
	{
		if (a_num > n)
		{
			if (a_num <= n + 10) std::cout << "High" << std::endl;
			else std::cout << "Too high" << std::endl;
		}
		else
		{
			if (a_num >= n - 10) std::cout << "Low" << std::endl;
			else std::cout << "Too low" << std::endl;
		}
		std::cout << "Enter a number: ";
		std::cin >> a_num;
		count ++;
	}
	std::cout << "Yes, it's " << n << "! You guessed the number in " << count << " tries." << std::endl;
}

int rnd()
{	
	srand(time(NULL));
	int n = 1 + rand()% 100;
	return n;
}
