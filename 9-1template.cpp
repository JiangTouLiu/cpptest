#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//函数模板
template <typename T>
T abs1(T t)
{
	return t >0? t:-t;
}

class Point
{
public:
	Point() 
	{
		x = 0;
		y = 0;
	}
	Point(int a, int b) :x(a), y(b) {};
	friend ostream& operator <<(ostream& out, Point& p);
private:
	int x;
	int y;
};

template <class T>
void show(T t)
{
	cout << t << endl;
}

ostream& operator <<(ostream& out, Point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
};

class ComplexNum
{
public:
	ComplexNum(int r, int v) :real(r), vir(v) {};
	friend ostream& operator <<(ostream& out, ComplexNum& c);
private:
	int real;
	int vir;
};

ostream& operator <<(ostream& out, ComplexNum& p)
{
	out << "(" << p.real << "," << p.vir << ")";
	return out;
};


int main()
{
	Point p(10, 10);
	ComplexNum c(20, 20);
	show(p);
	show(c);
	return 0;
}
