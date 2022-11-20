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
private:
	int x;
	int y;
};

Complex_num::Complex_num()
{
	cout << "call the defalut construction" << endl;
}

Complex_num::Complex_num(const int i, const int j) :x(i), y(j)
{
	cout << "call the construction" << endl;
}

Complex_num::Complex_num(Complex_num& c)
{
	x = c.x;
	y = c.y;
	cout << "call teh copy construction" << endl;
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
	return 0;
}

