#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Point
{
public:
	Point(int a, int b) :x(a), y(b) {}
	int getX();
	int getY();
private:
	int x;
	int y;
};

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}


int main()
{
	Point a(5, 2);
	Point* pa = &a;
	cout << pa->getX() << endl;
	cout << pa->getY() << endl;
	return 0;
}
