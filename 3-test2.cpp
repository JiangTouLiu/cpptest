#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;

//max1函数，返回两个整型变量中较大值
int max1(int x, int y)
{
	if (x >= y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

//重载max1函数，返回三个整型变量中最大的值
int max1(int x, int y, int z)
{
	return max1(max1(x, y), z);
}

//重载max1函数，返回两个double型变量的最大值
double max1(double x, double y)
{
	if (abs(x - y) < 1e-10)
	{
		return x;
	}
	else if (x >= y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
//重载max1函数，返回三个double型变量的最大值
double max1(double x, double y, double z)
{
	return max1(max1(x, y), z);
}

int main()
{
	int a, b, c, d;
	double m, n, l, k;
	cout << "please input value of a:";
	cin >> a;
	cout << "please input value of b:";
	cin >> b;
	cout << "please input value of c:";
	cin >> c;
	d = max1(a, b);
	cout << "the max of " << a << " and " << b << " is " << d << endl;
	d = max1(a, b, c);
	cout << "the max of " << a << " and " << b << " and " << c << " is " << d << endl;
	cout << "please input value of m:";
	cin >> m;
	cout << "please input value of n:";
	cin >> n;
	cout << "please input value of l:";
	cin >> l;
	k = max1(m, n);
	cout << "the max of " << m << " and " << n << " is " << k << endl;
	k = max1(m, n, l);
	cout << "the max of " << m << " and " << n << " and " << l << " is " << k << endl;
	k = pow(m, n);
	cout << m << " de " << n << " ci fang is " << k << endl;
	return 0;
}
