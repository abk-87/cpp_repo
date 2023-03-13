#include <iostream>

int main()
{
	int arr[10]{};
	int num;
	std::cout << "Enter a number between 1 and 10: ";
	std::cin >> num;
	while (num != -1)
	{
		arr[num - 1]++;
		std::cout << "Enter a number between 1 and 10: ";
		std::cin >> num;
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ": " << arr[i] << std::endl;
	}
	return 0;
}
