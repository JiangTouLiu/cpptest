#define _CRT_SECURE_NO_WARNINGS 1
#include "friendClass.h"

int A::count = 0;

A::A(int x, int y) :a(x), b(y)
{
	count++;
}

int A::geta()
{
	return a;
}

int A::getb()
{
	return b;
}
//友元函数定义
int Minus(A& s)
{
	return s.a - s.b;
}


int B::count = 0;

B::B(A& x, A& y):a1(x), a2(y)
{
	count++;
}


int B::add()
{
	return a1.a + a1.b + a2.a + a2.b;
}
