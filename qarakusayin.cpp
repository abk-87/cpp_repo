#include <iostream>
#include <math.h>

int main()
{
	float a, b, c;
	std::cin >> a >> b >> c;
	int D = (b * b) - (4 * a * c);
	if (D > 0)
	{
		float x1 = (-b + sqrt(D)) / (2 * a);
		float x2 = (-b - sqrt(D)) / (2 * a);
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x2 << std::endl;
	}
	else if (D == 0)
	{
		float x = -b / (2 * a);
		std::cout << "x = " << x << std::endl;
	}
	else
	{
		std::cout << "Quadratic equation has no roots" << std::endl;
	}
	return 0;
}
