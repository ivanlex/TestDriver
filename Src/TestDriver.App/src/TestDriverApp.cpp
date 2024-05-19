#include <iostream>

int MultiplyR(int a, int b);

class Entity
{
protected:
	float X;
	float Y;

public:
	void Move(float x, float y)
	{
		X = x;
		Y = y;
	}

	virtual std::string GetName()
	{
		return "Entity";
	}

	virtual int GetNumber() = 0;
};

class Player : public Entity
{
public:
	std::string m_Name;
	int m_Number;

	Player(const std::string& name, const int number) : 
		m_Name(name),
		m_Number(number) 
	{
	}

	std::string GetName() override
	{
		return m_Name;
	}

	int GetNumber() override
	{
		return m_Number;
	}
};


int main()
{
	std::string myName("123");
	Player* player = new Player(myName, 456);
	Entity* e = player;
	std::cout << e->GetName() << std::endl;
	std::cout << e->GetNumber() << std::endl;

	int myItems[10];
	int* p_myItems = myItems;

	myItems[2] = 2;
	*(p_myItems + 2) = 2;
	*((char*)p_myItems + 8) = 2;

	return 0;
}