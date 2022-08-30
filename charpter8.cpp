#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//ostream& operator <<(ostream& out, const Complex& c)
//{
//	out << "(" << c.real << "," << c.image << ")";
//	return out;
//}

class Base1
{
public:
	virtual void display();
private:
	int i;
};

class Base2 :public Base1
{
public:
	virtual void display();
private:
	int j;
};

class Base3 :public Base2
{
public:
	virtual void display();
private:
	int k;
};

void Base1::display()
{
	cout << "Base1:dispaly" << endl;
}

void Base2::display()
{
	cout << "Base2:dispaly" << endl;
}

void Base3::display()
{
	cout << "Base3:dispaly" << endl;
}

void fun(Base1* b)
{
	b->display();
}


int main()
{
	Base1 b1;
	Base2 b2;
	Base3 b3;
	fun(&b1);
	fun(&b2);
	fun(&b3);
	return 0;
}
