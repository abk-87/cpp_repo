#include <iostream>

void get_triangle_1(int n);
void get_triangle_2(int n);

int main()
{
	int N;
	std::cout << "Enter a number: ";
	std::cin >> N;
	get_triangle_1(N);
	get_triangle_2(N);
	return 0;
}

void get_triangle_1(int n)
{
	for (int i = 0; i < n / 2 + 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < n / 2 - i || j > n / 2 + i)
			{
				std::cout << ' ';
			}
			else
			{
				std::cout << '*';
			}
		}
		std::cout << std::endl;
	}
}

void get_triangle_2(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + i ; j++)
		{
			if (j < n - i - 1 || j > n + i - 1)
			{
				std::cout << ' ';
			}
			else
			{
				std::cout << '*';
			}
		}
		std::cout << std::endl;
	}
}
