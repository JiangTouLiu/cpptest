#pragma once
#ifndef _POINTCLASS_H_
#define _POINTCLASS_H_
#include <iostream>
using namespace std;

class Point
{
public:
	Point(float x, float y):a(x), b(y)
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
	void initPoint(float x, float y)
	{
		a = x;
		b = y;
	}
	void move(float x, float y);
	float getX() const;
	float getY() const;
private:
	float a;
	float b;
};

#endif
#pragma once
#ifndef _RECT_H_
#define _RECT_H_

#include "PointClass.h"
class rect :private Point
{
public:
	rect(float x, float y, float h, float w)
	{
		initPoint(x, y);
		this->h = h;
		this->w = w;
	};
	void initRect(float x, float y, float h, float w)
	{
		initPoint(x, y);
		this->h = h;
		this->w = w;
	};
	float getX() const
	{
		return Point::getX();
	};
	float getY() const
	{
		return Point::getY();
	};
	void move(float x, float y)
	{
		Point::move(x, y);
	}
	float getH() const
	{
		return h;
	};
	float getW() const
	{
		return w;
	};
	
private:
	float h;
	float w;
};


#endif
