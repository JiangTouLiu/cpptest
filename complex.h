#pragma once
#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <iostream>
using namespace std;



class Complex
{
public:
	Complex(int r, int i) :real(r), image(i)
	{

	};
	Complex operator +(const Complex& c)
	{
		return Complex(real + c.real, image + c.image);
	};
	Complex operator - (const Complex& c)
	{
		return Complex(real - c.real, image - c.image);
	};
	void display()
	{
		cout << "(" << real << "," << image << ")" << endl;
	}
	friend Complex operator +(int a, const Complex& c);
	friend Complex operator -(int a, const Complex& c);
	friend ostream& operator <<(ostream& out, const Complex& c);
private:
	int real;
	int image;
};


#endif
