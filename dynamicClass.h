#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x, int y):a(x), b(y)
	{
		cout << "call the construction function " << endl;
	}
	Point()
	{
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
	~ArrayOfPoint();
	Point& element(int index);
private:
	Point* p;
	int size;
};
