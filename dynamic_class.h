#define _CRT_SECURE_NO_WARNINGS 1
#include "PointClass.h"
#include <cassert>

void Point::move(int x, int y)
{
	a = x;
	b = y;
}

int Point::getX()
{
	return a;
}

int Point::getY()
{
	return b;
}


ArrayOfPoint::ArrayOfPoint(int size):size(size)
{
	p = new Point[size];
	cout << "call the construction function" << endl;
}

ArrayOfPoint::~ArrayOfPoint()
{
	delete[] p;
	cout << "call the destruction function" << endl;
}

Point& ArrayOfPoint::element(int index)
{
	assert(index >= 0 && index < size);
	return p[index];
}
