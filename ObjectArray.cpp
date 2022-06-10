#define _CRT_SECURE_NO_WARNINGS 1
#include "PointClass.h"

int main()
{
	Point p[2];
	for (int i = 0; i < 2; i++)
	{
		cout << p[i].getX() << "," << p[i].getY() << endl;
	}
	for (int i = 0; i < 2; i++)
	{
		p[i].move(i + 10, i + 20);
	}
	for (int i = 0; i < 2; i++)
	{
		cout << p[i].getX() << "," << p[i].getY() << endl;
	}

	return 0;
}
