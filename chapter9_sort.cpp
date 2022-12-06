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

//交换函数，交换两个变量的值
template <class T>
void my_swap(T& a, T& b)
{
        T tmp = a;
        a = b;
        b = tmp;
}

//选择排序
template <class T>
void select_sort(T a[], int n)
{
        for (int i =0 ;i< n-1;i++)
        {
                int min = i;
                min = i;
                for (int j=i+1;j<n;j++)
                {
                        if (a[j] < a[min])
                        {
                                min = j;
                        }
                }
                my_swap(a[i], a[min]);
        }
}

//冒泡排序
template <class T>
void bubble_sort(T a[], int n)
{
        int i = n-1;
        while (i > 0)   //当最后一次交换的位置为0时，说明已经有序
        {
                int lastch = 0;
                for (int j=0;j<i;j++)
                {
                        if (a[j] > a[j+1])
                        {
                                my_swap(a[j], a[j+1]);
                                lastch = j;     //记录最后一次交换的位置，说明后面的数据已经都有序了
                        }
                }
                i = lastch;     //将最后一次交换的位置赋值给i，从而控制循环次数
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
        
        //使用选择排序对整型和Point类数组进行排序
        int arr[5] = {8,3,9,2,6};
        for (int i = 0;i<5;i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl << "====================================" << endl;

        select_sort(arr, 5);
        for (int i = 0;i<5;i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
        Point p1(3,5), p2(7,10), p3(6,13), p4(9,12), p5(15, 20), p6(20, 30); 
        Point pa[] = {p1, p2, p3, p4, p5, p6};
        for (int i =0;i<6;i++)
        {
                pa[i].show();
        }
        cout << endl << "==============================================" << endl;
        select_sort(pa, 6);
        for (int i =0;i<6;i++)
        {
                pa[i].show();
        }
        cout << endl;
        return 0;
        return 0;
}
