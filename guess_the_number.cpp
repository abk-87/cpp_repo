#include <iostream>
#include <time.h>
#include <cmath>

void guess(int n);
int rnd(int a);
void levels();

int main()
{
	levels();
	return 0;
}

void guess(int n)
{
	int a_num;
	int count = 1;
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

int rnd(int a)
{	
	srand(time(NULL));
	int n = a + rand()% (a * 9);
	return n;
}

void levels()
{
	for (int i = 1; i <= 3; i++)
	{
		std::cout << "Level " << i << ": Guess the " << i+1 << "-digit number" << std::endl;
		guess(rnd(pow(10, i)));
		std::cout << std::endl;
	}
}
