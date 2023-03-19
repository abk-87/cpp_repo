/*Նկարագրել ֆունկցիա, որն արգումենտում ստանում է n և k
    բնական թվերը և
    ա) վերադարձնում է true, եթե n-ը հանդիսանում է k-ի որևէ
    ամբողջ աստիճան, և վերադարձնում է false՝ հակառակ
    դեպքում,
    բ) արտածում է n թվի ներկայացումը k-ական համակար-
    գում (k<10):*/

#include <iostream>

bool is_power(int n, int k);
int conversion(int n, int k);

int main()
{
	int n, k;
	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "Enter k: ";
	std::cin >> k;
	std::cout << "Is n any integer power of k?: " << is_power(n, k) << std::endl;
	if (k < 10) std::cout << "Representation of the number n in k-system: " << conversion(n, k) << std::endl;
	return 0;
}

bool is_power(int n, int k)
{
	while (n > k)
	{
		if (n % k != 0) return false;
		n /= k;
	}
	if (n == k) return true;
	else return false;
}

int conversion(int n, int k)
{
	int k_num = 0;
	int k_coef = 1;
	while (n > 0)
	{
		k_num = (n % k) * k_coef + k_num;
		n /= k;
		k_coef *= 10;
	}
	return k_num;
}
