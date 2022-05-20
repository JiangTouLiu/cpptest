#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cmath>
using namespace std;

double mySin(double x)
{
	double g = 0;
	double t = x;
	int n = 1;
	do
	{
		g += t;
		n++;
		t = -t * x * x / (2 * n - 1) / (2 * n - 2);
	} while ((abs(t)) > 1e-10);
	return g;
}

int main()
{
	double r = 0.0;
	double s = 0.0;
	double k = 0.0;
	cout << "请输入r的值：";
	cin >> r;
	cout << "请输入s的值：";
	cin >> s;
	

	if (r * r <= s * s)
	{
		k = sqrt(((mySin(r) * mySin(r)) + (mySin(s) * mySin(s))));
	}
	else
	{
		k = mySin(r * s) * 0.5;
	}
	cout << "k=:" << k << endl;
	return 0;
}
