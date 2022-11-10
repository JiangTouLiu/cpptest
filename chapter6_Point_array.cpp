#define _CRT_SECURE_NO_WARNINGS 1
#include "Point.h"

//定义一个点类对象的数组类
class PointArray
{
public:
	PointArray(int s)
	{
		size = s;
		point = new Point[size];
		cout << "call the construction" << endl;
	}
	~PointArray()
	{
		delete[] point;
		cout << "call the destruction " << endl;
	}
	Point& element(int index)
	{
		return point[index];
	}
	Point* getPoint()
	{
		return point;
	}
private:
	int size;
	Point* point;
};


int main()
{
	//从键盘输入数组元素个数，动态创建数组
	int count = 0;
	cout << "请输入元素个数" << endl;
	cin >> count;
	PointArray pa(count);
	//打印数组元素
	for (int i = 0; i < count; i++)
	{
		cout << "(" << pa.element(i).getX() << "," << pa.element(i).getY() << ")" << endl;
	}
	//移动数组元素
	for (int i = 0; i < count; i++)
	{
		pa.element(i).move(i + 2, i + 3);
	}
	//移动后再次打印数组元素
	for (int i = 0; i < count; i++)
	{
		cout << "(" << pa.element(i).getX() << "," << pa.element(i).getY() << ")" << endl;
	}
	
	return 0;
}
