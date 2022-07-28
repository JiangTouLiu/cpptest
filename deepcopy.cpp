#define _CRT_SECURE_NO_WARNINGS 1



#include <cassert>
#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x, int y) :a(x), b(y)
	{
		cout << "call the construction function " << endl;
	}
	Point()
	{
		a = 0;
		b = 0;
		cout << "call the default construction function" << endl;
	}
	~Point()
	{
		cout << "call the destruction function" << endl;
	}
	void move(int x, int y);
	int getX();
	int getY();
private:
	int a;
	int b;
};

class ArrayOfPoint
{
public:
	ArrayOfPoint(int size);
	ArrayOfPoint(ArrayOfPoint& aop);
	~ArrayOfPoint();
	Point& element(int index);
private:
	Point* p;
	int size;
};

class intNumer
{
public:

	intNumer(int x);
	intNumer(intNumer& ip);
	~intNumer();
	int getInt();
private:
	int* ptr;
};



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


ArrayOfPoint::ArrayOfPoint(int size) :size(size)
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

//复制构造函数（深层复制）
ArrayOfPoint::ArrayOfPoint(ArrayOfPoint& aop)
{
	size = aop.size;
	p = new Point[size];
	for (int i = 0; i < size; i++)
	{
		p[i] = aop.p[i];
	}
}


intNumer::intNumer(int x = 0)
{
	ptr = new int(x);
	cout << "call the construction function" << endl;
}

intNumer::intNumer(intNumer& ip)
{
	ptr = new int(*ip.ptr);
	cout << "call the copy construction function" << endl;
}

intNumer::~intNumer()
{
	cout << "call the destruction function" << endl;
}

int intNumer::getInt()
{
	return *ptr;
}












//#include "PointClass.h"
//
//
//int main()
//{
//	ArrayOfPoint a(5);
//	for (int i = 0; i < 5; i++)
//	{
//		a.element(i).move(i, i);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << a.element(i).getX() << "," << a.element(i).getY() << endl;
//	}
//	return 0;
//}
//



intNumer copy1()
{
	intNumer a;
	return a;
}

int main()
{
	//ArrayOfPoint a(2);
	//ArrayOfPoint b(a);
	//cout << "(" << a.element(0).getX() << "," << a.element(0).getY() << ")" << endl;
	//cout << "(" << a.element(1).getX() << "," << a.element(1).getY() << ")" << endl;
	//cout << "(" << b.element(0).getX() << "," << b.element(0).getY() << ")" << endl;
	//cout << "(" << b.element(1).getX() << "," << b.element(1).getY() << ")" << endl;
	//a.element(0).move(1, 1);
	////a.element(1).move(2, 2);
	//cout << "(" << a.element(0).getX() << "," << a.element(0).getY() << ")" << endl;
	//cout << "(" << a.element(1).getX() << "," << a.element(1).getY() << ")" << endl;
	//cout << "(" << b.element(0).getX() << "," << b.element(0).getY() << ")" << endl;
	//cout << "(" << b.element(1).getX() << "," << b.element(1).getY() << ")" << endl;

	cout << copy1().getInt() << endl;


	return 0;
}

