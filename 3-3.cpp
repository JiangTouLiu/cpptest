#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//写函数计算arctan的值，arctan的近似值为 x - x^3/3 + x^5/5 - x^7/7 ...
double arctan(double x)
{
	double sqr = x * x;
	double e = x;
	double r = 0;
	int i = 1;
	while (e / i > 1e-15)
	{
		double f = e / i;
		r = (i % 4 == 1) ? r + f : r - f;
		e = e * sqr;
		i += 2;
	}
	return r;
}

//写函数计算x的n次方
double power(double x, int n)
{
	double ret = 1;
	while (n--)
	{
		ret *= x;
		
	}
	return ret;
}

//用函数实现二进制转换成10进制


int main()
{
	double pi = 16 * arctan(1 / 5.0) - 4 * arctan(1 / 239.0);
	cout << pi << endl;
	double y = power(2.0, 4);
	cout << y << endl;

	//从键盘输入一个8位二进制数，转化成十进制输出
	int ret = 0;
	int i = 0;
	cout << "请输入一个二进制数：";
	for (i = 8; i > 0; i--)
	{
		char ch;
		cin >> ch;
		cout << "请输入一个二进制数：";
		if (ch == '1')
		{
			ret += static_cast<int>(power(2, i-1));
		}
	}
	cout << ret << endl;

	return 0;
}
