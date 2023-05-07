#include "map.hpp"

int main()
{
	Map<int, std::string> a_map;
	std::cout << "******2002******" << std::endl;
	a_map.emplace(2002, "Brazil");
	a_map.print();
	std::cout << "******1990******" << std::endl;
	a_map.emplace(1990, "Germany");
	a_map.print();
	std::cout << "******2018******" << std::endl;
	a_map.emplace(2018, "France");
	a_map.print();
	std::cout << "******1994******" << std::endl;
	a_map.emplace(1994, "Brazil");
	a_map.print();
	std::cout << "******1986******" << std::endl;
	a_map.emplace(1986, "Argentina");
	a_map.print();
	std::cout << "******1998******" << std::endl;
	a_map.emplace(1998, "France");
	a_map.print();
	std::cout << "******2010******" << std::endl;
	a_map.emplace(2010, "Spain");
	a_map.print();
	std::cout << "******2006******" << std::endl;
	a_map.emplace(2006, "Italy");
	a_map.print();
	std::cout << "******2022******" << std::endl;
	a_map.emplace(2022, "Argentina");
	a_map.print();
	std::cout << "******2014******" << std::endl;
	a_map.emplace(2014, "Germany");
	a_map.print();
	std::cout << "******1982******" << std::endl;
	a_map.emplace(1982, "Italy");
	a_map.print();
	return 0;
}
