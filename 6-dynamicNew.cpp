#define _CRT_SECURE_NO_WARNINGS 1
#include "PointClass.h"

int main()
{
	int* p = new int[10];
	if (p == NULL)
	{
		cout << "开辟空间失败" << endl;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			p[i] = i;
		}
		for (int i = 0; i < 10; i++)
		{
			cout << p[i];
		}
		delete[] p;
		p = NULL;
	}
	
	Point* p = new Point[2];
	if (p == NULL)
	{
		cout << "开辟空间失败" << endl;
	}
	else
	{
		cout << "p1:" << p[0].getX() << "," << p[0].getY() << endl;
		cout << "p2:" << p[1].getX() << "," << p[1].getY() << endl;
		p[0].move(10, 20);
		p[1].move(20, 30);
		cout << "p1:" << p[0].getX() << "," << p[0].getY() << endl;
		cout << "p2:" << p[1].getX() << "," << p[1].getY() << endl;
		delete[] p;
		p = NULL;
	}

	return 0;
}
