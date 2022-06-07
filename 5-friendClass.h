#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __FRIENDCLASS__
#define __FRIENDCLASS__
#endif
#include <iostream>
using namespace std;
class A
{
	//友元类声明
	friend class B;
	//友元函数声明
	friend int Minus(A& s);
public:
	A(int x, int y);
	~A()
	{
		count--;
	}
	int geta();
	int getb();
private:
	int a;
	int b;
	static int count;
};

//友元类定义
class B
{
public:
	B(A& x, A& y);
	~B()
	{
		count--;
	}
	int add();
private:
	A a1;
	A a2;
	static int count;
};
