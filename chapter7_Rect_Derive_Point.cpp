#pragma once
#ifndef __POINT_H__
#define __POINT_H__
#include <iostream>
using namespace std;

class Point
{
public:
	Point()
	{
		cout << "call the Point default construction" << endl;
	}
	Point(int a, int b) :x(a), y(b)
	{
		cout << "call the construction" << endl;
	}
	Point(Point& p);
	void move(int a, int b);
	int getX();
	int getY();
private:
	int x;
	int y;
};

void Point::move(int a, int b)
{
	x = a;
	y = b;
	cout << "move to (" << x << "," << y << ")" << endl;
}

Point::Point(Point& p)
{
	x = p.x;
	y = p.y;
	cout << "call the copy construction " << endl;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}


//类Rect继承Point类，新增宽度和高度两个属性
class Rect:public Point
{
public:
	Rect()
	{
		cout << "call the Rect default construction" << endl;
	}
	//带参数的构造函数，通过调用Point的构造函数对继承过来的私有变量x,y坐标进行初始化构造
	Rect(int a, int b, int w, int h) :Point(a, b), wight(w), height(h)
	{
		cout << "call the construction" << endl;
	}
	//Rect(Rect& r);
	//通过move函数移动矩形
	void move(int a, int b, int w, int h);
	//分别或去矩形的顶点x，y坐标，以及矩形的宽度和高度
	int getX();
	int getY();
	int getW();
	int getH();
private:
	int wight;
	int height;
};

void Rect::move(int a, int b, int w, int h)
{
	Point::move(a, b);
	wight = w;
	height = h;
	cout << wight << "," << height << endl;
	cout << "call the copy construction" << endl;
}

int Rect::getX()
{
	return Point::getX();
}

int Rect::getY()
{
	return Point::getY();
}

int Rect::getW()
{
	return wight;
}

int Rect::getH()
{
	return height;
}

int main()
{
	Rect r;
	cout << "the point of rect is (" << r.getX() << "," << r.getY() << ")" << endl;
	cout << "the wight of rect is " << r.getW() << endl;
	cout << "the height of rect is " << r.getH() << endl;
	cout << "=================================================" << endl;
	r.move(0, 0, 10, 20);
	cout << "the point of rect is (" << r.getX() << "," << r.getY() << ")" << endl;
	cout << "the wight of rect is " << r.getW() << endl;
	cout << "the height of rect is " << r.getH() << endl;
	cout << "=================================================" << endl;
	r.move(1, 1, -5, -20);
	cout << "the point of rect is (" << r.getX() << "," << r.getY() << ")" << endl;
	cout << "the wight of rect is " << r.getW() << endl;
	cout << "the height of rect is " << r.getH() << endl;
	return 0;
}



#endif
