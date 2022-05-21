#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int square(int x)
{
	return x * x;
}
//函数AddSquare调用Square函数，实现函数的嵌套调用
int AddSquare(int x, int y)
{
	return square(x) + square(y);
}
//阶乘函数，递归调用
int Fac(int x)
{
	if (0 == x)
		return 1;
	else
	{
		return x * Fac(x - 1);
	}
}
//计算组合数
int Combin(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else
	{
		return (Combin(n, k - 1) * (n - k + 1) / k);
	}
}

//计算组合数2
int Combina(int n, int k)
{
	if (0 == k || n == k)
	{
		return 1;
	}
	else
	{
		return Combina(n - 1, k - 1) + Combina(n - 1, k);
	}
}

int main()
{
	int a = 10, b = 5;
	int n = 0, k = 0 ;
	int c = AddSquare(a, b);
	int con = 0;
	int fac = 0;
	cout << "c = " << c << endl;
	cout << "请输入总数：";
	cin >> n;
	cout << "请输入要选去的个数：";
	cin >> k;
	fac = Fac(n);
	cout << n << "的阶乘是:" << fac << endl;
	
	con = Combina(n, k);
	cout << n << "的" << k << "组合数是：" << con << endl;
	return 0;
}
