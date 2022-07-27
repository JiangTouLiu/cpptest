#define _CRT_SECURE_NO_WARNINGS 1
#include "PointClass.h"


int main()
{
	ArrayOfPoint a(5);
	for (int i = 0; i < 5; i++)
	{
		a.element(i).move(i, i);
	}
	for (int i = 0; i < 5; i++)
	{
		cout << a.element(i).getX() << "," << a.element(i).getY() << endl;
	}
	return 0;
}

