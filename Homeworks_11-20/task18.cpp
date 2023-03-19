/*n թվանշան ունեցող բնական թիվը կոչվում է Արմսթրոնգի
թիվ, եթե նրա թվանշանների n աստիճանների գումարը հա-
վասար է այդ թվին (օրինակ՝ 153=1^3 +5^3 +3^3 ): Արտածել բոլոր
երկնիշ, եռանիշ և քառանիշ Արմսթրոնգի թվերը:*/

#include <iostream>
#include <cmath>

void is_armstrong();

int main()
{
	std::cout << "Armstrong numbers between 10 and 9999: ";
	is_armstrong();
	return 0;
}

void is_armstrong()
{
	for (int n = 10; n < 10000; n++)
	{
		if (n < 100)
		{
			if (pow((n / 10), 2) + pow((n % 10), 2) == n) std::cout << n << " ";
		}
		else if (n >= 100 && n < 1000)
		{
			if (pow((n / 100), 3) + pow(((n / 10) % 10), 3) + pow((n % 10), 3) == n) std::cout << n << " ";
		}
		else
		{	
			if (pow((n / 1000), 4) + pow(((n / 100) % 10), 4) + pow(((n / 10) % 10), 4) + pow((n % 10), 4) == n) std::cout << n << " ";
		}
	}
	std::cout << std::endl;
}
