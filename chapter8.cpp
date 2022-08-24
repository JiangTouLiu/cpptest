#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "Complex.h"
#include "Clock.h"

ostream& operator <<(ostream& out, const Complex& c)
{
	out << "(" << c.real << "," << c.image << ")";
	return out;
}


int main()
{
	Complex c = Complex(5, 6);
	Complex c2 = Complex(3, 10);
	Complex c3 = 1 - c2;
	Complex c4 = 2 + c2;
	cout << c3 << endl;
	cout << c4 << endl;

	/*Clock c1(12, 25, 26);
	Clock c2(23, 59, 59);
	Clock& c3 = ++c1;
	c3.show();
	c1.show();
	cout << &c3 << endl;
	cout << &c1 << endl;*/
	return 0;
}
