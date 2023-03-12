#include <iostream>

void get_rectangle(int n, int m, char symb = '*')
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
			{
				std::cout << symb;
			}
			else
			{
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}

int main()
{
	int N, M;
	char symb;
	std::cout << "Enter two numbers (N and M) and one symbol: ";
	std::cin >> N >> M >> symb;
	get_rectangle(N, M);
	get_rectangle(N, M, symb);
	return 0;
}
