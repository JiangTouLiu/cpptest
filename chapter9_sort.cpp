#include <iostream>
using namespace std;

class Point
{
        public:
                Point():x(0),y(0){};
                Point(int a, int b):x(a), y(b){};
                void show();
                int getX();
                int getY();
                bool operator <(const Point& p);  //重载小于判断
                bool operator >(const Point& p);  //重载大于判断
                bool operator ==(const Point& p); //重载相等判断
        private:
                int x;
                int y;
};

void Point::show()
{
        cout << "(" << x << "," << y << ") ";
}

int Point::getX()
{
        return x;
}

int Point::getY()
{
        return y;
}

bool Point::operator <(const Point& p)
{
        if (x < p.x)
        {
                return true;
        }
        else
        {
                return false;
        }
}

bool Point::operator >(const Point& p)
{
        if (x > p.x)
        {
                return true;
        }
        else
        {
                return false;
        }
}

bool Point::operator ==(const Point& p)
{
        if (x == p.x)
        {
                return true;
        }
        else
        {
                return false;
        }
}

//插入排序，使用这个函数是，实际的类型T需要重载过>运算符
template <class T>
void insertSort(T a[], int n)
{
        for (int i = 1;i < n;i++)
        {
                int j = i;
                T tmp = a[i];
                while (j > 0 && a[j-1] > tmp)
                {
                        a[j] = a[j-1];
                        j--;
                }
                a[j] = tmp;
        }
}

int main()
{
        int a[] = {5,2,6,1,9};
        for (int i = 0; i<5;i++)
        {
                cout << a[i] << "  ";
        }
        insertSort(a, 5);
        cout << endl << "============================================" << endl;
        for (int i = 0; i<5;i++)
        {
                cout << a[i] << "  ";
        }
        cout << endl;
        cout << "=======================================================" << endl;
        Point p1(3,5), p2(7,10), p6(2,7), p3(5,9), p4(1,8), p5(6,7);
        Point pa[] = {p1, p2, p3, p4, p5};
        for (int i =0;i<5;i++)
        {
                pa[i].show();   //输出显示排序前pa数组的每一项
        }
        cout << endl;
        insertSort(pa, 5);
        cout << "=========================================================" << endl;
        for (int i=0;i<5;i++)
        {
                pa[i].show();   //输出显示排序后pa数组的每一项
        }
        cout << endl;
        return 0;
}
