#define _CRT_SECURE_NO_WARNINGS 1
#include "Point.h"
#include <iostream>
using namespace std;

//定义一个对4列的二维数组的每行求和的函数
void RowSum(int a[][4], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			a[i][0] += a[i][j];
		}
	}
}

//定义4个对两个整型变量进行计算的函数
int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a > b ? b : a;
}

int add(int a, int b)
{
	return a + b;
}

int minus1(int a, int b)
{
	return a - b;
}

//定义一个对两个整型变量进行计算的函数，其中的计算方法通过传函数指针传进去，从而实现不同的计算
int compute(int a, int b, int (*func)(int, int))
{
	return func(a, b);
}

//从键盘读入一个浮点数，然后输出整数部分和小数部分
void spiltNum(double num, int* n, double* d)
{
	*n = static_cast<int> (num);
	*d = num - *n;
}

int main()
{
	/*double num, d;
	int n;
	cin >> num;
	spiltNum(num, &n, &d);
	cout << "数字" << num << endl;
	cout << "整数部分是： " << n << endl;
	cout << "小数部分是：" << d << endl;*/

	//动态申请内存空间创建对象
	/*Point* p1 = new Point();
	cout << p1->getX();
	delete p1;
	p1 = new Point(1, 2);
	cout << p1->getX();
	delete p1;*/

	

	

	/*int line1[] = {1,2,3,4};
	int line2[] = {5,6,7,8};
	int line3[] = {9,10,11,12};*/
	
	//补充：变量名没有括号的，应该是指针数组，也就是说这个变量是一个数组，数组的每一项都是一个指针
	// 变量名有括号的，应该是数组指针，也就是说这个变量是一个指针，指针指向的是一个数组，此时如果对指针进行加1，则跳过整个数组的大小
	//一维数组的理解好像简单一点，就是数组里面的每一项都是一个指向整型对象的指针，赋值的时候把每个数组的首地址赋给数组里面的每一个指针，然后用地址加一的方法可以遍历每一项
	//int *pl[3] = {line1, line2, line3};
	//多维数组不太好理解，大致可以理解为每一个指针指向的是一个3行4列的整型数组，指针加1时跳过3行4列，指向下一个3行4列，所以也可以用地址加一的方法进行遍历
	//指向三维数组的指针
	/*int a[2][3][4] =
	{
		{
			{0,1,2,3}, {4,5,6,7}, {8,9,10,11}
		},
		{
			{12,13,14,15}, {16,17,18,19}, {20,21,22,23}
		}
	};*/
	//int(*paa)[3][4] = a;//数组名代表数组首地址，这里三维数组的首地址就是第一层的地址，也就是第一个3行4列的二维数组的地址所以可以这样赋值

	/*for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cout << paa[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/

	int (*pa)[3][4] = new int[2][3][4];

	for (int i = 0; i < 2; i++)
	{
		for (int j=0;j<3;j++)
			for (int k = 0; k < 4; k++)
			{
				*(*(* (pa + i) + j) + k) = 100 * i + 10 * j + k;
			}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				cout << pa[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	delete[] pa;


	/*int a = 10, b = 20;
	cout << "max of a and b is " << compute(a, b, max) << endl;
	cout << "min of a and b is " << compute(a, b, min) << endl;
	cout << "add of a and b is " << compute(a, b, add) << endl;
	cout << "minus of a and b is " << compute(a, b, minus1) << endl;*/

	

	/*int a[] = { 1,2,3,4,5,6,7 };
	int* pa = &a[0];
	for (int i = 0; i < 7; i++)
	{
		cout << pa[i] << endl;
	}*/

	/*
	Point p1 = Point(1, 1);
	cout << "p1: (" << p1.getX() << "," << p1.getY() << ")" << endl;
	p1.move(10, 10);
	*/

	/*int a[3][4] = {{1,2,3,4}, {2,3,4,5}, {3,4,5,6}};
	RowSum(a, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << "sum of row " << i+1 << " is " << a[i][0] << endl;
	}*/

	/*Point a[2];
	for (int i = 0;i<2;i++)
	{
		cout << "(" << a[i].getX() << "," << a[i].getY() << ")" << endl;
		a[i].move(i + 10, i + 20);
		cout << "(" << a[i].getX() << "," << a[i].getY() << ")" << endl;
	}*/


	//int a = 10;
	//int b = 30;
	//const int* const pa = &a;
	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;
	//cout << "pa: " << * pa << endl;
	//a = 5;
	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;
	//cout << "pa: " << *pa << endl;
	//pa = &b;
	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;
	//cout << "pa: " << *pa << endl;
	//b = 60;
	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;
	//cout << "pa: " << *pa << endl;
	//
	return 0;
}
