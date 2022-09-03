#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Point
{
public:
	Point();
	Point(int a, int b):x(a), y(b) {};
	Point& operator ++();
	Point operator ++(int);
	Point& operator --();
	Point operator --(int);
	void show();
	friend ostream& operator <<(ostream& out, Point& p);
private:
	int x;
	int y;
};

Point::Point()
{
	x = 0;
	y = 0;
};

Point& Point::operator ++()
{
	++this->x;
	++this->y;
	return *this;
};

Point Point::operator ++(int)
{
	Point tem = *this;
	++*this;
	return tem;
};

Point& Point::operator --()
{
	--this->x;
	--this->y;
	return *this;
};

Point Point::operator --(int)
{
	Point tem = *this;
	--* this;
	return tem;
};

ostream& operator << (ostream& out, Point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
};

class Vehicle
{
public:
	virtual void run();
	virtual void stop();
private:
	string style;
};

void Vehicle::run()
{
	cout << "Vehicle is running" << endl;
};

void Vehicle::stop()
{
	cout << "Vehicle is stopping" << endl;
};

class Bicycle :virtual public Vehicle
{
public:
	virtual void run();
	virtual void stop();
private:
	int height;
};

void Bicycle::run()
{
	cout << "Bicycle is running" << endl;
};

void Bicycle::stop()
{
	cout << "Bicycle is stopping" << endl;
};

class Motocycle :virtual public Vehicle
{
public:
	virtual void run();
	virtual void stop();
private:
	int height;
};

void Motocycle::run()
{
	cout << "Motocycle is running" << endl;
};

void Motocycle::stop()
{
	cout << "Motocycle is stopping" << endl;
};

void start(Vehicle* v)
{
	v->run();
};




int main()
{
	Vehicle v;
	Bicycle b;
	Motocycle m;
	Vehicle* vp = &v;
	vp->run();
	vp->stop();
	vp = &b;
	vp->run();
	vp->stop();
	vp = &m;
	vp->run();
	vp->stop();
	/*Point p1;
	cout << p1++ << endl;
	cout << p1 << endl;
	cout << ++p1 << endl;
	cout << p1-- << endl;
	cout << --p1 << endl;*/
	return 0;
}
