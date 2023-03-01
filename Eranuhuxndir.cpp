#include <iostream>

int main()
{
	std::cout << "Enter the size of the array: ";
	int n;
	std::cin >> n;
	int arr[n] = {};
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
	
	int max = arr[0];
	int max_i = 0;
	
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
	}
	
	if (max_i == n - 1)
	{
		arr[max_i] = arr[max_i - 1];
	}
	else
	{
		for (int i = max_i; i < n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	
	std::cout << std::endl;
	
	return 0;
}
