#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
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

//类模板

template <class T>
class Store
{
public:
	Store();
	void putElement(const T& t);
	T& getElement();
private:
	T item;
	bool haveValue;
};

template <class T>
Store <T>::Store()
{
	haveValue = false;
}

template <class T>
void Store<T>::putElement(const T& t)
{
	item = t;
	haveValue = true;
}

template <class T>
T& Store<T>::getElement()
{
	if (haveValue)
	{
		return item;
	}
	else
	{
		cout << "there is nothing" << endl;
	}
	
}

template <class T>
class Array
{
public:
	Array(int sz);
	Array();
	Array(const Array<T>& a);
	~Array();
	Array<T>& operator =(const Array<T>& a);
	T& operator [](int i);
	int getSize();
	void resetSize(int sz);
	operator T *();
private:
	T* arr;
	int size;
};

template <class T>
Array<T>::Array(int sz)
{
	assert(sz > 0);
	size = sz;
	arr = new T[size];
}

template <class T>
Array<T>::Array()
{
	size = 50;
	arr = new T[size];
}

template <class T>
Array<T>::Array(const Array<T>& a)
{
	size = a.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a.arr[i];
	}
}

template <class T>
Array<T>::~Array()
{
	delete [] arr;
}

template <class T>
T& Array<T>::operator [](int i)
{
	assert(i >= 0 && i < size);
	return arr[i];
}

template <class T>
Array<T>& Array<T>:: operator =(const Array<T>& a)
{
	if (&a == this)
	{
		return;
	}
	if (a.size != size)
	{
		size = a.size;
		delete[] arr;
		arr = new T[size];
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = a.arr[i];
	}
	return *this;
}

template <class T>
Array<T>::operator T *()
{
	return arr;
}

template <class T>
void Array<T>::resetSize(int sz)
{
	assert(sz > 0);
	if (sz == size)
	{
		return;
	}
	T* newarr = new T[sz];
	int n = (sz < size) ? sz : size;
	for (int i = 0; i < n; i++)
	{
		newarr[i] = arr[i];
	}
	delete[] arr;
	arr = newarr;
	newarr = NULL;
	size = sz;
}

template <class T>
int Array <T>::getSize()
{
	return size;
}


int main()
{
	/*Point p(10, 10);
	ComplexNum c(20, 20);
	show(p);
	show(c);*/
	/*Store <int> s1;
	s1.putElement(5);
	cout << s1.getElement() << endl;
	Store <double> s2;
	s2.putElement(3.14);
	cout << s2.getElement() << endl;
	Store <Point> s3;
	Point p(10, 20);
	s3.putElement(p);
	cout << s3.getElement() << endl;
	Store <Point> s4;
	cout << s4.getElement() <<endl;*/

	Array <int> ai;
	for (int i = 0; i < ai.getSize(); i++)
	{
		ai[i] = i;
	}
	for (int i = 0; i < ai.getSize(); i++)
	{
		cout << ai[i] << endl;
	}
	return 0;
}
