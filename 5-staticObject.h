#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class Point
{
public:
	Point(int x, int y);
	Point(int x) : Point(x, 0) {};
	Point();
	Point(const Point& p);
	~Point();
	int getX();
	int getY();
	static void ShowCount();
private:
	int x;
	int y;
	static int count;
	
};

int Point::count = 0;

Point::Point(int a, int b) : x(a), y(b)
{
	count++;
}

Point::Point()
{
	count++;
}

Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
	count++;
}

Point::~Point()
{
	count--;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void Point::ShowCount()
{
	cout << "the number of object is " << count << endl;
}
