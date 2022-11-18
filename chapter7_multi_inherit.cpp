#include <iostream>
using namespace std;

class Base
{
public :
Base();
Base(int i, int j);
Base(Base& ba);
int getA();
~Base();
private:
int a;
int b;
};

class Derive_1_1:virtual public Base //第一层第一个继承
{
public:
Derive_1_1();
Derive_1_1(int i, int j, int k);
Derive_1_1(Derive_1_1& d11);
~Derive_1_1();
private:
int c;
};

class Derive_1_2 :virtual public Base //第一层第二个继承
{
public:
Derive_1_2();
Derive_1_2(int i, int j, int k);
Derive_1_2(Derive_1_2& d11);
~Derive_1_2();
private:
int d;
};

class Derive_2 :public Derive_1_1, public Derive_1_2 //第二层的继承
{
public:
Derive_2();
Derive_2(int i, int j, int k);
Derive_2(Derive_2& d11);
~Derive_2();
private:
int e;
};

Base::Base():a(0), b(0)
{
cout << "call the Base default construction" << endl;
}

Base::Base(int i, int j) :a(i), b(j)
{
cout << "call the Base construction" << endl;
}

Base::Base(Base& ba)
{
a = ba.a;
b = ba.b;
}

Base::~Base()
{
cout << "call the Base destruciton" << endl;
}

int Base::getA()
{
return a;
}

Derive_1_1::Derive_1_1():c(0)
{
cout << "call the Derive_1_1 default construction" << endl;
}

Derive_1_1::Derive_1_1(int i, int j, int k) :Base(i, j)
{
c = k;
cout << "call the Derive_1_1 construction" << endl;
}

Derive_1_1::Derive_1_1(Derive_1_1& d11) :Base(d11)
{
c = d11.c;
cout << "call the Derive_1_1 copy construction" << endl;
}

Derive_1_1::~Derive_1_1()
{
cout << "call the Derive_1_1 destruction" << endl;
}

Derive_1_2::Derive_1_2():d(0)
{
cout << "call the Derive_1_2 default construction" << endl;
}

Derive_1_2::Derive_1_2(int i, int j, int k) :Base(i, j)
{
d = k;
cout << "call the Derive_1_2 construction" << endl;
}

Derive_1_2::Derive_1_2(Derive_1_2& d11) :Base(d11)
{
d = d11.d;
cout << "call the Derive_1_2 copy construction" << endl;
}

Derive_1_2::~Derive_1_2()
{
cout << "call the Derive_1_2 destruction" << endl;
}

Derive_2::Derive_2() :e(0)
{
cout << "call the Derive_2 default construction" << endl;
}

Derive_2::Derive_2(int i, int j, int k) :Base(i, j), Derive_1_1(i, j, k), Derive_1_2(k, j, i)
{
e = k;
cout << "call the Derive_2 construction" << endl;
}

Derive_2::Derive_2(Derive_2& d2) :Derive_1_1(d2), Derive_1_2(d2)
{
e = d2.e;
cout << "call the Derive_2 copy construction" << endl;
}

Derive_2::~Derive_2()
{
cout << "call the Derive_2 destruction" << endl;
}

int main()
{
// Derive_2 d;
/*
执行之后的显示结果
call the Base default construction 先进入Derive_1_1 d的默认构造函数，然后这个默认构造函数调用了Base的默认构造函数，所以第一个执行的是Derive_1_1 调用的Base类的默认构造函数
call the Derive_1_1 default construction 先进入Derive_1_1 d的默认构造函数，然后这个默认构造函数调用了Base的默认构造函数，所以第一个执行的是Derive_1_1 调用的Base类的默认构造函数，其次执行Derive_1_1 的默认构造函数
call the Base default construction 与Derive_1_1 的同理
call the Derive_1_2 default construction 与Derive_1_1 的同理
call the Derive_2 default construction 最后调用Derive_2的构造函数
call the Derive_2 destruction 析构顺序正好相反
call the Derive_1_2 destruction
call the Base destruciton
call the Derive_1_1 destruction
call the Base destruciton
*/
//Derive_1_1 d11(1, 3, 5);
//Derive_1_2 d12(1, 3, 5);
Derive_2 d2(1, 3, 5);
cout << d2.getA() << endl; //报错，d2是Derive_2类的对象，Derive_2继承了Derive_1_1和Derive_1_2，Derive_1_1和Derive_1_2都继承了Base，所以在Derive_2中有两个a，b，一个是继承自Derive_1_1，一个是继承于Derive_1_2
//使用虚继承，可以解决这个问题，使用虚继承时，由最后的那个派生类调用第一层基类构造函数，中间的派生类的调用都不生效，如果最后的派生类没有显示调用第一层基类的构造函数，则调用第一层基类的默认构造函数
//使用虚基类可以避免多继承时的二义性和冗余问题
return 0;
