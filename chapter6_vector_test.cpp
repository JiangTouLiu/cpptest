#define _CRT_SECURE_NO_WARNINGS 1
#include "Point.h"
#include <vector>   //导入vector头文件






int main()
{
	unsigned int n = 0;
	cout << "请输入整型数组元素个数" << endl;
	cin >> n;
	//使用vector构造一个整型数组，赋值并输出
	vector<int> arr(n);
	//1.使用循环下标循环
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
	cout << "====================================================" << endl;
	//2.使用迭代器循环
	for (auto i = arr.begin(); i < arr.end(); i++)
	{
		*i = *i+1;
		cout << *i << endl;
	}
	cout << "====================================================" << endl;
	//3.使用基于范围的for循环;使用基于范围的for循环时，每执行一次循环都是对该次循环的数组元素进行一个临时拷贝，e是临时拷贝，对e进行修改不会对arr数组产生影响
	for (int e : arr)
	{
		e = ++e;
		cout << e << endl; //这里打印的比上2.使用迭代器循环的值分别大1
	}
	cout << "====================================================" << endl;
	for (auto e : arr)
	{
		cout << e << endl; //这里打印的比上2.使用迭代器循环的值相同
	}
	cout << "====================================================" << endl;
	//使用vector创建一个Point类数组
	cout << "请输入点类数组元素个数" << endl;
	cin >> n;
	vector<Point> pa(n);
	//1.使用循环下标循环
	for (int i = 0; i < pa.size(); i++)
	{
		cout << "pa[" << i << "]: (" << pa[i].getX() << "," << pa[i].getY() << ")" << endl;
	}
	for (int i = 0; i < pa.size(); i++)
	{
		pa[i].move(i, 2 * i);
	}
	for (int i = 0; i < pa.size(); i++)
	{
		cout << "pa[" << i << "]: (" << pa[i].getX() << "," << pa[i].getY() << ")" << endl;
	}
	cout << "====================================================" << endl;
	//2.使用迭代器循环
	for (auto p = pa.begin(); p < pa.end(); p++)
	{
		static int i = 0;
		p->move(i, i + 5);
		cout << "pa[" << i << "]: (" << p->getX() << "," << p->getY() << ")" << endl;
		i++;
	}
	cout << "====================================================" << endl;
	//3.使用基于范围的for循环
	for (Point e : pa)
	{
		static int j = 0;
		cout << "pa[" << j << "]: (" << e.getX() << "," << e.getY() << ")" << endl;
		j++;
	}

	return 0;
}
