/*Նկարագրել ֆունկցիա, որն արգումենտում ստանում է n
բնական թիվը և վերադարձնում է այդ թվի
    ա) ամենամեծ թվանշանի կարգահամարը (եթե այդ թվանշա-
    նը թվում հանդիպում է մի քանի անգամ վերադարձնել ա-
    մենաձախի կարգահամարը),
    բ) բոլոր պարզ բաժանարարների քանակը,
    գ) 16-ական ներկայացման մեջ զրոների քանակը,
    դ) հարևան զույգ թվանշանների քանակը:*/

#include <iostream>
#include <math.h>

int index_largest_dig(int n);
int simple_divisors(int n);
int count_of_zero(int n);
int count_of_couple_digs(int n);
bool is_simple(int n);

int index_largest_dig(int n)
{
	int max = 0;
	int i = 0, i_max = 0;
	while (n > 0)
	{
		if (n % 10 >= max) 
		{
			max = n % 10;
			i_max = i;
		}
		n /= 10;
		i++;
	}
	return i - i_max - 1;
}

int simple_divisors(int n)
{
	int count = 0;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			if (is_simple(i)) count++;
		}
	}
	return count;
}

int count_of_zero(int n)
{
	int count = 0;
	while (n > 0)
	{
		if (n % 16 == 0) count++;
		n /= 16;
	}
	return count;
}

int count_of_couple_digs(int n)
{
	int count = 0;
	short flag1 = 0, flag2 = 0;
        while (n > 0)
        {
                if ((n % 10) % 2 == 0)
		{
                        count++;
			if (flag1 == 1) flag2 = 1;
			else flag1 = 1;
                }
		else 
		{
			if (flag1 == 1 && flag2 == 0) count--;
			flag1 = 0;
			flag2 = 0;
		}
                n /= 10;
		if (n == 0 && flag1 == 1 && flag2 == 0) count--;
        }
        return count;
}

bool is_simple(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	int n;
	std::cout << "Enter a natural number: ";
	std::cin >> n;
	std::cout << "The index of the largest digit: " << index_largest_dig(n) << std::endl;
	std::cout << "The count of simple divisors: " << simple_divisors(n) << std::endl;
	std::cout << "The count of zeros in the representation of hexadecimal: " << count_of_zero(n) << std::endl;
	std::cout << "The count of adjacent couple digits: " << count_of_couple_digs(n) << std::endl;
	return 0;
}
