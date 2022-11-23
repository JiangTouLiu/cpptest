#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Complex_num
{
public:
	Complex_num();
	Complex_num(int i, int j);
	Complex_num(Complex_num& c);
	~Complex_num();
	void show();
	Complex_num operator +(const Complex_num& c1);
	Complex_num operator +(int a);
	//非成员函数方式重载整型和复数的加法运算，使用friend声明为友元函数，从而在外部可以直接访问私有成员
	friend Complex_num operator +(int i, const Complex_num& c);
	//非成员函数方式重载复数和复数的减法运算，使用friend声明为友元函数，从而在外部可以直接访问私有成员
	friend Complex_num operator -(const Complex_num& c1, const Complex_num& c2);
	//非成员函数方式重载输出运算符，使用friend声明为友元函数，从而在外部可以直接访问私有成员
	friend ostream& operator <<(ostream& out, const Complex_num& c);
private:
	int x;
	int y;
};

Complex_num::Complex_num()
{
	cout << "call the defalut ruction" << endl;
}

Complex_num::Complex_num(const int i, const int j) :x(i), y(j)
{
	cout << "call the ruction" << endl;
}

Complex_num::Complex_num(Complex_num& c)
{
	x = c.x;
	y = c.y;
	cout << "call teh copy ruction" << endl;
}

Complex_num::~Complex_num()
{
	cout << "call the destruction" << endl;
}

void Complex_num::show()
{
	cout << "(" << x << "," << y << ")" << endl;
}

Complex_num Complex_num::operator +(const Complex_num& c1)
{
	int a = x + c1.x;
	int b = y + c1.y;
	Complex_num c(a, b);
	return c;
}

Complex_num Complex_num::operator +(int a)
{
	int x1 = x + a;
	Complex_num c(x1, y);
	return c;
}

//实现加法重载，由于是非类内的成员函数（全局函数），所以不用类名进行限定
Complex_num operator +(int i, const Complex_num& c)
{
	Complex_num b(i + c.x, c.y);
	return b;
}

//实现加法重载，由于是非类内的成员函数（全局函数），所以不用类名进行限定
Complex_num operator -(const Complex_num& c1, const Complex_num& c2)
{
	Complex_num c(c1.x + c2.x, c1.y + c2.y);
	return c;
}

//实现加法重载，由于是非类内的成员函数（全局函数），所以不用类名进行限定
ostream& operator <<(ostream& out, const Complex_num& c)
{
	out << "(" << c.x << "," << c.y << ")";
	return out;
}

int main()
{
	Complex_num c1(10, 10);     //call the construction
	Complex_num c2(20, 20);     //call the construction
	c1.show();                  //(10,10)
	c2.show();                  //(20,20)
	Complex_num c3;             //call the defalut ruction
	c3 = c1 + c2;               //call the construction
                              //call the copy construction
                              //call the destruction
                              //call the destruction
	c3.show();                  //(30,30)
	c3 = c3 + 10;               //call the construction
                              //call the copy construction
                              //call the destruction
                              //call the destruction 
	c3.show();                  //(40,30)
                              //call the destruction
                              //call the destruction     

	Complex_num c4(10, 10);
	Complex_num c5(5, 5);
	cout << "c4:" << c1 << endl;
	cout << "c5:" << c2 << endl;
	Complex_num c6(0, 0);
	c6 = c4 - c5;
	cout << "c4 - c5" << c6 << endl;
	int i = 20;
	c6 = i + c4;
	cout << "i + c4 " << c6 << endl;
	return 0;
}
