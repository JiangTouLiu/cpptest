#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//使用函数把华氏温度转化成摄氏度
float Convert(float tem)
{
	return (tem - 32) * 5 / 9;
}

//使用函数计算斐波那契数列的第n项
int Fib(int n)
{
	cout << "process Fib (" << n << ")";
	if (n < 3)
	{
		cout << "return 1" << endl;
		return 1;
	}
	else
	{
		cout << "call Fib (" << n - 1 << ") and Fib (" << n - 2 << ")" << endl;
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main()
{
	float f;
	float s;
	int n = 0;
	int answer;
	/*cout << "plese input tem:" << endl;
	cin >> f;
	s = Convert(f);
	cout << f << "convert to s is:" << s << endl;*/
	cout << "plese input num";
	cin >> n;
	answer = Fib(n);
	cout << answer << " is the fib of " << n << endl;

	return 0;
}
