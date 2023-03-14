#include <iostream>

struct point
{
	int x;
	int y;
};

int main()
{
	point a, b, c;
	std::cout << "Enter the coordinates of the point a" << std::endl;
	std::cout << "x: ";
	std::cin >> a.x;
	std::cout << "y: ";
	std::cin >> a.y;
	std::cout << "Enter the coordinates of the point b" << std::endl;
	std::cout << "x: ";
	std::cin >> b.x;
	std::cout << "y: ";
	std::cin >> b.y;
	std::cout << "Enter the coordinates of the point c" << std::endl;
	std::cout << "x: ";
	std::cin >> c.x;
	std::cout << "y: ";
	std::cin >> c.y;
	if ((c.x - a.x) / (b.x - a.x) != (c.y - a.y) / (b.y - a.y))
	{
		std::cout << "It is possible to form a triangle with the points with the specified coordinates" << std::endl;
	}
	else std::cout << "It is not possible to form a triangle with the points with the specified coordinates" << std::endl;
	return 0;
}
