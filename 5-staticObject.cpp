#include "PointClass.h"



int main()
{
	Point::ShowCount();
	Point a(10, 10);
	
	cout << "a.x is " << a.getX() << endl;
	cout << "a.y is " << a.getY() << endl;
	a.ShowCount();
	Point::ShowCount();
	Point b(a);
	
	cout << "b.y is " << b.getY() << endl;
	cout << "b.y is " << b.getY() << endl;
	b.ShowCount();
	Point::ShowCount();
	Point c;
	cout << "c.y is " << c.getY() << endl;
	cout << "c.y is " << c.getY() << endl;
	c.ShowCount();
	Point::ShowCount();
}
