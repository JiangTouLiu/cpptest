#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int x = 1;
int y = 2;
void fun();

int main()
{
	cout << "global x is " << x << endl;
	cout << "global y is " << y << endl;

	int x = 10;
	int y = 20;
	cout << "main x is " << x << endl;
	cout << "main y is " << y << endl;
	fun();

	return 0;
}

void fun()
{
	int x = 5;
	cout << "fun x is " << x << endl;
	cout << "fun y is " << y << endl;
}
