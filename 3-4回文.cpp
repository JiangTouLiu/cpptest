#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//写一个函数判断是否是回文数
bool palindromeNum(int x)
{
	int tmp = x;
	int ret = 0;
	do
	{
		ret = ret * 10 + x % 10;
	} while (x /= 10);
	return ret == tmp;
	
}

int main()
{
	int i = 0;
	for (i = 10; i < 9999; i++)
	{
		if (palindromeNum(i) && palindromeNum(i*i) && palindromeNum(i*i*i))
		{
			cout << i << endl;
			cout << i * i << endl;
			cout << i * i * i << endl;
		}
	}
	return 0;
}
