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
