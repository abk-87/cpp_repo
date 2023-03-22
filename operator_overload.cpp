#include <iostream>

class Number
{
	int value;
public:
	Number()
	{
		value = 0;
	}
	Number(int n)
	{
		value = n;
	}
	void set_value(int n)
	{
		value = n;
	}
	int get_value()
	{
		return value;
	}

	Number operator+(const Number &object)
	{
		Number tmp;
		tmp.value = this->value + object.value;
		return tmp;
	}
	Number operator+=(const Number &object)
	{
		this->value = this->value + object.value;
		return *this;
	}
	Number operator++()
	{
		this->value += 1;
		return *this;
	}
	Number operator-(const Number &object)
	{
		Number tmp;
		tmp.value = this->value - object.value;
		return tmp;
	}
	Number operator-=(const Number &object)
	{
		this->value = this->value - object.value;
		return *this;
	}
	Number operator--()
	{
		this->value -= 1;
		return *this;
	}
	Number operator*(const Number &object)
	{
		Number tmp;
		tmp.value = this->value * object.value;
		return tmp;
	}
	Number operator*=(const Number &object)
	{
		this->value = this->value * object.value;
		return *this;
	}
	Number operator/(const Number &object)
	{
		Number tmp;
		if (object.value != 0) tmp.value = this->value / object.value;
		return tmp;
	}
	Number operator/=(const Number &object)
	{
		if (object.value != 0) this->value = this->value / object.value;
		return *this;
	}
	Number operator%(const Number &object)
	{
		Number tmp;
		if (object.value != 0) tmp.value = this->value % object.value;
		return tmp;
	}
	Number operator%=(const Number &object)
	{
		if (object.value != 0) this->value = this->value % object.value;
		return *this;
	}
	bool operator>(const Number& object)
	{
		return this->value > object.value;
	}
	bool operator<(const Number& object)
	{
		return this->value < object.value;
	}
	bool operator>=(const Number& object)
	{
		return this->value >= object.value;
	}
	bool operator<=(const Number& object)
	{
		return this->value <= object.value;
	}
	bool operator==(const Number& object)
	{
		return this->value == object.value;
	}
	bool operator!=(const Number& object)
	{
		return this->value != object.value;
	}

	void print()
	{
		std::cout << this->value << std::endl; 
	}
/*	
	std::ostream& operator<<(std::ostream& out, const Number& object)
	{
		out << object.value;
		return out;
	}


	void operator<<(const Number& object)
	{
		std::cout << object.value;
	}
*/
};

int main()
{
	Number n1(10);
	Number n2(2);
	return 0;
}
