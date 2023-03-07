#include <iostream>
#include <typeinfo>

int main()
{
	std::string s;
	std::cout << "Enter a number: ";
	std::cin >> s;
	int n;
	int sum= 0;
	while (true)
	{
		try
		{
			n = std::stoi(s);
		}
		catch(...)
		{
			std::cout << "Enter a positive number: ";
                        std::cin >> s;
			continue;
		}
		
		if (n == 0)
		{
			break;
		}
		else if (n > 0)
		{
			sum += n;
			std::cout << "Enter a number: ";
			std::cin >> s;
		}
		else
		{
			std::cout << "Enter a positive number: ";
			std::cin >> s;
		}
	}
	std::cout << "Sum: " << sum <<std::endl;
	return 0;
}
