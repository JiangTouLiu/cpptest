#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int compute(int x, int y, int (*func)(int, int))
{
	return func(x, y);
}

int max1(int m, int n)
{
	return m>n ? m:n;
}

int min1(int m, int n)
{
	return m<n ? m  : n;
}

int plus1(int m, int n)
{
	return m + n;
}

int minus1(int m, int n)
{
	return m - n;
}

int main()
{
	int a, b;
	cout << "please input two numbers : " << endl;
	cin >> a;
	cin >> b;
	cout << "the max of a and b is " << compute(a, b, max1) << endl;
	cout << "the min of a and b is " << compute(a, b, min1) << endl;
	cout << "a + b is " << compute(a, b, plus1) << endl;
	cout << "a - b is " << compute(a, b, minus1) << endl;


	return 0;
}
