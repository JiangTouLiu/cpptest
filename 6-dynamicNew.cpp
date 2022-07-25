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

	return 0;
}
