#include <iostream>
#include <string>

class Human
{
public:
	std::string name;
	std::string surname;
	int age;
	Human()
	{
		name = "";
		surname = "";
		age = 0;
	}
	Human(std::string name, std::string surname, int age)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
	}
};

class Employee : public Human
{
public:
	std::string company;
	int experience;
	int salary;
	Employee()
	{
		company = "";
		experience  = 0;
		salary = 0;
	}
	Employee(std::string name, std::string surname, int age, std::string company, int experience, int salary): Human (name, surname, age)
	{
		this->company = company;
		this->experience = experience;
		this->salary = salary;
	}
};

class Staff : public Employee
{
public:
	int level;
	std::string profession;
	Staff()
	{
		level = 0;
		profession = "";
	}	
	Staff(std::string name, std::string surname, int age, std::string company, int experience, int salary, int level, std::string profession): Employee(name, surname, age, company, experience, salary)
	{
		this->level = level;
		this->profession = profession;
	}
	bool operator==(const Staff& object)
	{
		return (this->name == object.name && this->surname == object.surname);
	}
};

class Manager : public Employee
{
public:
	Staff arr[5];
	Staff tmp;
	Manager(std::string name, std::string surname, int age, std::string company, int experience, int salary): Employee(name, surname, age, company, experience, salary)
	{
	}	
	void hire(Staff x)
	{
		for (int i = 0; i < 5; i++)
		{
			if (arr[i].age == 0)
			{
				arr[i] = x;
				break;
			}
		}
	}
	void fire(Staff x)
	{
		for (int i = 0; i < 5; i++)
		{
			if (arr[i] == x) arr[i] = tmp;
		}
	}
	void print()
	{
		for (int i = 0; i < 5; i++)
		{
			if (arr[i].age != 0) std::cout << arr[i].name << " " << arr[i].surname << "\t";
		}
		std::cout << std::endl;
	}
};

int main()
{
	Staff s1("Poghos", "Poghosyan", 35, "A-COMPANY LTD", 4, 100000, 2, "Developer");
	Staff s2("Petros", "Petrosyan", 30, "A-COMPANY LTD", 5, 100000, 2, "Developer");
	Staff s3("Martiros", "Martirosyan", 28, "A-COMPANY", 3, 80000, 3, "Developer");
	Staff s4("Simon", "Simonyan", 30, "A-COMPANY LTD", 6, 150000, 1, "Engineer");
	Staff s5("Grigor", "Grigoryan", 35, "A-COMPANY LTD", 5, 150000, 1, "Developer");
	Staff s6("Hovhannes", "Hovhannisyan", 29, "A-COMPANY LTD", 3, 100000, 3, "Engineer");
	Staff s7("Hakob", "Hakobyan", 32, "A-COMPANY LTD", 5, 100000, 2, "Engineer");
	Manager m1("Manuk", "Manukyan", 40, "A-COMPANY LTD", 10, 300000);
	m1.hire(s1);
	m1.hire(s2);
	m1.hire(s3);
	m1.hire(s4);
	m1.hire(s5);
	m1.print();
	m1.fire(s4);
	m1.print();
	m1.hire(s4);	
	m1.print();	
	m1.fire(s1);
	m1.fire(s2);
	m1.hire(s7);
	m1.print();	
	return 0;
}
