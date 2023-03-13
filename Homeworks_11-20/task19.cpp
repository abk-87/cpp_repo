#include <iostream>
#include <time.h>

void get_count_of_max(int n);

int main()
{
	srand(time(NULL));
	int n;
	std::cout << "Enter the count of elements in sequence: ";
	std::cin >> n;
	get_count_of_max(n);
	return 0;
}

void get_count_of_max(int n)
{
	int el = -10;
	int max = el;
	int max_count = 1;
	for (int i = 0; i < n; i++)
	{
		el = -10 + rand()% 21;
		std::cout << el << " ";
		if (el > max)
		{
			max = el;
			max_count = 1;
		}
		else if (el == max)
		{
			max_count++;
		}
	}
	std::cout << std::endl << "The maximum element is repeated " << max_count << " times" << std::endl;
}
