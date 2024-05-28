class Entity
{
private:
	int m_X;
	int m_Y;
public:
	Entity() : m_X(0), m_Y(0) {}
	Entity(int x, int y) : m_X(x), m_Y(y) {}

	int GetX() const
	{
		return m_X;
	}

	int GetY() const
	{
		return m_Y;
	}
};