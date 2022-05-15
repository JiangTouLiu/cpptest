#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS 1
#define PI 3.14
#include <iostream>
using namespace std;

//定义枚举变量，枚举所有可能的形状
enum shape
{
	CIRCLE,
	RECTANGLE,
	SQUARE
};


//计算圆形的面积
void AreaOfCircle()
{
	unsigned int r = 0;
	cout << "请输入圆的半径：" << endl;
	cin >> r;
	cout << "半径为" << r << "的圆的面积是：" << PI * r * r << endl;
}

//计算长方形的面积
void AreaOfRectangle()
{
	unsigned int length = 0;
	unsigned int width = 0;
	cout << "请输入长方形的长：" << endl;
	cin >> length;
	cout << "请输入长方形的宽：" << endl;
	cin >> width;
	cout << "长方形的面积是：" << length * width << endl;
}

//计算正方形的面积
void AreaOfSquare()
{
	unsigned int side_of_length = 0;
	cout << "请输入正方形的边长： " << endl;
	cin >> side_of_length;
	cout << "边长为" << side_of_length << "的正方形的面积是：" << side_of_length * side_of_length << endl;
}



int main()
{
	//使用sizeof操作符，计算常见类型的大小
	cout << "the size of int is:" << sizeof(int) << endl;
	cout << "the size of short is:" << sizeof(short) << endl;
	cout << "the size of long int is :" << sizeof(long int) << endl;
	cout << "the size of long long int is:" << sizeof(long long int) << endl;
	cout << "the size of char is:" << sizeof(char) << endl;
	cout << "the size of float is:" << sizeof(float) << endl;
	cout << "the size of double is:" << sizeof(double) << endl;
	cout << "the size of long double is:" << sizeof(long double) << endl;
	cout << "the size of bool is:" << sizeof(bool) << endl;

	//给出两个数，计算差值
	unsigned int a = 50;
	unsigned int b = 100;
	int c = 0;
	c = b - a;
	cout << "the result of b - a is:" << c << endl;
	c = a - b;
	cout << "the result of a - b is:" << c << endl;

	//计算两个数的差的绝对值
	int x = 0;
	int y = 0;
	int z = 0;
	cout << "请输入x的值" << endl;
	cin >> x;
	cout << "请输入y的值" << endl;
	cin >> y;
	z = x > y ? (x - y) : (y - x);
	cout << "the diferent of x and y is:" << z << endl;
	
	
	//计算不同形状的面积
	int s = 0;
	cout << "plese select shape:" << endl;
	cout << "---------------   0: circle  ------------------------" << endl;
	cout << "---------------   1: rectangle  ------------------------" << endl;
	cout << "---------------   2: square  ------------------------" << endl;
	cin >> s;
	switch (s)
	{
		case CIRCLE:
			AreaOfCircle();
			break;
		case RECTANGLE:
			AreaOfRectangle();
			break;
		case SQUARE:
			AreaOfSquare();
			break;
		default:
			cout << "选择错误，请重新选择" << endl;
			break;
	}
	
	
	return 0;
}
