#include <iostream>
#include <string>
using namespace std;

class Fruit
{
private:
	string name;
	string color;

public:
	Fruit()
	{
	}

	Fruit(string color)
	{
		this->color = color;
	}

	void setColor(string color)
	{
		this->color = color;
	}

	string getColor()
	{
		return color;
	}

	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}


};

class Apple : public Fruit
{
	Fruit apple;
public:
	Apple()
	{
	}

	Apple(string color) : Fruit(color)
	{		
	}
	
	string getName() 
	{
		apple.setName("apple");
		string temp = apple.getName();
		return temp;
	}
};

class GrannySmith : public Apple
{
	Fruit apple;
public:
	GrannySmith() : Apple("Green")
	{
	}

	string getName()
	{
		apple.setName("Granny Smith apple");
		string temp = apple.getName();
		return temp;
	}
};

class Banana : public Fruit
{
	Fruit banana;
public:

	Banana() : Fruit("yellow")
	{

	}

	string getName()
	{
		banana.setName("banana");
		string temp = banana.getName();
		return temp;
	}
};


int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}