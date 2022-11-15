#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//定义一个基类
class Base0
{
public:
	Base0()
	{
		cout << "call the Base0 class default construction" << endl;
	}
	Base0(int i, int j) :a(i),b(j)
	{
		cout << "call the Base0 class construction" << endl;
	}
	int getA();
	void setA(int i);
	void func();
private:
	int a;
	int b;
};

int Base0::getA()
{
	return a;
}

void Base0::func()
{
	cout << "Base0 func" << endl;
}

void Base0::setA(int i)
{
	a = i;
}
//定义一个派生类，继承Base0，同时写一个同名变量和函数
class Base1 :public Base0
{
public:
	Base1()
	{
		cout << "call the Base1 class default construction" << endl;
	}
	Base1(int i, int j, int k) :Base0(i, j), c(k)
	{
		cout << "call the Base1 class construction" << endl;
	}
	int getA();
	void setA(int i);
	void func();
private:
	int a;
	int b;
	int c;
};

int Base1::getA()
{
	return a;
}

void Base1::setA(int i)
{
	a = i;
}

void Base1::func()
{
	cout << "Base1 func" << endl;
}


int main()
{
	Base1 b1(5, 10, 20);
	cout << "Base0 a is :" << b1.Base0::getA() << endl;	//Base1继承了Base0，Base1里面的getA()覆盖了Base0里面的getA()函数，如果想要调用Base0的getA()，则调用时使用Base0::进行限定getA()函数，表示使用Base0的getA()函数
	cout << "Base1 a is :" << b1.getA() << endl;	//Base1继承了Base0，Base1里面的getA()覆盖了Base0里面的getA()函数，如果直接调用，则调用Base1的getA()函数。
	cout << "===============================================================" << endl;

	b1.setA(10);	//Base1继承了Base0，Base1里面的setA()覆盖了Base0里面的setA()函数，如果直接调用，则调用Base1的setA()函数。
	b1.Base0::setA(15);	//Base1继承了Base0，Base1里面的setA()覆盖了Base0里面的setA()函数，如果想要调用Base0的setA()，则调用时使用Base0::进行限定setA()函数，表示使用Base0的setA()函数
	cout << "Base0 a is :" << b1.Base0::getA() << endl;
	cout << "Base1 a is :" << b1.Base1::getA() << endl;

	cout << "==============================================================" << endl;
	b1.func();	//输出Base1 func
	b1.Base0::func();	//输出Base0 func

	return 0;
}
