#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int main()
{
	//使用sizeof操作符，计算常见类型的大小
	cout << "the size of int is:" << sizeof(int) << endl;
	cout << "the size of short is:" << sizeof(short) << endl;
	cout << "the size of long int is :" << sizeof(long int) << endl;
	cout << "the size of long long int is:" << sizeof(long long int) << endl;
	cout << "the size of char is:" << sizeof(char) << endl;
	cout << "the size of float is:" << sizeof(float) << endl;
	cout << "the size of double is:" << sizeof(double) << endl;
	cout << "the size of long double is:" << sizeof(long double) << endl;
	cout << "the size of bool is:" << sizeof(bool) << endl;

	//给出两个数，计算差值
	unsigned int a = 50;
	unsigned int b = 100;
	int c = 0;
	c = b - a;
	cout << "the result of b - a is:" << c << endl;
	c = a - b;
	cout << "the result of a - b is:" << c << endl;

	//计算两个数的差的绝对值
	int x = 0;
	int y = 0;
	int z = 0;
	cout << "请输入x的值" << endl;
	cin >> x;
	cout << "请输入y的值" << endl;
	cin >> y;
	z = x > y ? (x - y) : (y - x);
	cout << "the diferent of x and y is:" << z << endl;
	return 0;
}
