#include <iostream>

class Vector3D;

//if we use friend class, we can describe our class Vector3D first. 
//But if we use friend method, we need to describe class Point3D firstly,
//bcs variables of class Vector3D must be in the visibility zone

class Point3D
{
private:
	double m_x, m_y, m_z;

public:
	Point3D(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	void print()
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector(const Vector3D& v);
	/*{
		this->m_x += v.m_x;
		this->m_y += v.m_y;		for variant with friend class
		this->m_z += v.m_z;
	}*/

};

class Vector3D
{
	//friend Point3D;		for variant with friend class
	friend void Point3D::moveByVector(const Vector3D& v);
private:
	double m_x, m_y, m_z;

public:
	Vector3D(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	void print()
	{
		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}
	
};

int main()
{
	Point3D p(3.0, 4.0, 5.0);
	Vector3D v(3.0, 3.0, -2.0);

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}

void Point3D::moveByVector(const Vector3D& v)
{
	this->m_x += v.m_x;
	this->m_y += v.m_y;
	this->m_z += v.m_z;
}
