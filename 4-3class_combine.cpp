#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Point
{
public:
	
	Point(int xx, int yy);
	Point() :Point(0, 0)		//委托构造函数，默认构造函数
	{
		cout << "call default construction " << endl;
	}
	Point(int xx) :Point(xx, 0)
	{
		cout << "call entrust construction " << endl;
	}
	Point(const Point& p);
	~Point();
	int GetX();
	int GetY();
	void SetX(int xx);
	void SetY(int yy);

private:
	int x;
	int y;
};
//构造函数
Point::Point(int xx, int yy) :x(xx), y(yy)
{
	cout << "call 2 param construction function" << endl;
}
//复制构造函数
Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
	cout << "call Point assignment construction" << endl;
}
//析构函数
Point::~Point()
{
	cout << "call destructor" << endl;
}
//获取Point对象的横坐标
int Point::GetX()
{
	return x;
}
//获取Point对象的纵坐标
int Point::GetY()
{
	return y;
}
//设置Point元素的横坐标
void Point::SetX(int xx)
{
	x = xx;
}
//设置Point元素的纵坐标
void Point::SetY(int yy)
{
	y = yy;
}

//定义线段类
class Line
{
public:
	Line(Point pstart, Point pend);
	Line();			//默认构造函数
	Line(const Line& l);
	~Line();
	double GetLenth();
	void ShowLine();
private:
	Point p1;
	Point p2;
	double lenth;
};

//Line类的构造函数
Line::Line(Point pstart, Point pend) :p1(pstart), p2(pend)
{
	lenth = sqrt(pow((p2.GetY() - p1.GetY()), 2) + (pow((p2.GetX() - p1.GetX()), 2)));
}
//Line类的复制构造函数
Line::Line(const Line& l)
{
	p1 = l.p2;
	p2 = l.p1;
	cout << "call Line assingment construction" << endl;
}
//Line类的析构函数
Line::~Line()
{

}
//获取长度
double Line::GetLenth()
{
	return lenth;
}
//显示线段的两个端点
void Line::ShowLine()
{
	cout << "(" << p1.GetX() << "," << p1.GetY() << ")";
	cout << "(" << p2.GetX() << "," << p2.GetY() << ")" << endl;
}

int main()
{
	Point p1(10, 10);
	Point p2(2);
	Point p3;
	Point p4(p1);
	cout << "p1.x: " << p1.GetX() << " p1.y: " << p1.GetY() << endl;
	cout << "p2.x: " << p2.GetX() << " p2.y: " << p2.GetY() << endl;
	cout << "p3.x: " << p3.GetX() << " p3.y: " << p3.GetY() << endl;
	cout << "p4.x: " << p4.GetX() << " p4.y: " << p4.GetY() << endl;
	p4.SetX(15);
	cout << "p4.x: " << p4.GetX() << " p4.y: " << p4.GetY() << endl;
	p4.SetY(15);
	cout << "p4.x: " << p4.GetX() << " p4.y: " << p4.GetY() << endl;
	Point p5(p2);
	cout << "p5.x: " << p5.GetX() << " p5.y: " << p5.GetY() << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Line class call " << endl;
	Line l1(p1, p2);
	Line l2(p3, p4);
	Line l3(l2);
	cout << "the lenth of l1 is: " << l1.GetLenth() << endl;
	cout << "the lenth of l2 is: " << l2.GetLenth() << endl;
	cout << "the lenth of l3 is: " << l3.GetLenth() << endl;
	l2.ShowLine();
	l3.ShowLine();

	return 0;
}
