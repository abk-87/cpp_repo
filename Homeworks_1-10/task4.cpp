#include <iostream>

int inverse(int n);
void is_palindrome(int n, int inverse_n);

int main()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	is_palindrome(num, inverse(num));
	return 0;
}

int inverse(int n)
{
	int inverse_n = 0;
	while (n > 0)
	{
		inverse_n = (inverse_n * 10) + (n % 10);
		n /= 10;
	}
	return inverse_n;
}

void is_palindrome(int n, int inverse_n)
{
	if (n == inverse_n)
	{
		std::cout << n << " is palindrome" << std::endl;
	}
	else
	{	
		std::cout << n << " is not palindrome" << std::endl;
	}
}
