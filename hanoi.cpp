#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//从源柱移动到目标柱
void move(char src, char dest)
{
	cout << src << "->" << dest << endl;
}
//递归实现汉诺塔问题
void hanoi(int n, char src, char mid, char dest)
{
	if (1 == n)
	{
		move(src, dest);
	}
	else
	{
		hanoi(n - 1, src, dest, mid);
		move(src, dest);
		hanoi(n - 1, mid, src, dest);
	}

}

int main()
{
	int n = 5;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
