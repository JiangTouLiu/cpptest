#include <iostream>
using namespace std;
template <class T>
class Array
{
        public:
                Array(int s);
                Array(Array<T>& a);
                ~Array();
                Array<T>& operator =(const Array& a);
                T& operator [](int n);
                const T& operator [](int n) const;
                operator T*();
                operator const T*() const;
                int getSize() const;
                void resetSize(int s);
        private:
                T* list;
                int size;
};


int main()
{
        Array<int> a(10);
        for (int i=0;i<10;i++)
        {
                a[i] = i;
        }
        for (int i=0;i<10;i++)
        {
                cout << a[i] << " ";
        }
        cout << endl;
        Array<double> d(10);
        for (int i=0;i<10;i++)
        {
                d[i] = 1.1 + i;
        }
        for (int i=0;i<10;i++)
        {
                cout << d[i] << " ";
        }
        cout << endl;
}

template <class T>
Array<T>::Array(int s)
{
        if (s>0)
        {
                size = s;
                list = new T[size];
        }
}

template <class T>
Array<T>::Array(Array& a)
{
        size = a.size;
        list = new T[size];
        for (int i=0;i<size;i++)
        {
                list[i] = a.list[i];
        }
}
/*
template <class T>
Array<T>::Array(Array& a)
{
        if (list == a.list)
        {
                return;
        }
        if (size == a.size)
        {
                for (int i=0;i<size;i++)
                {
                        list[i] = a.list[i];
                }
                return;
        }
        else
        {
                int n = (size > a.size) ? size : a.size;
                T* tmp = new T[n];
                for (int i=0;i<a.size;i++)
                {
                        tmp[i] = a.list[i];
                }
                delete [] list;
                list = tmp;
        }
}
*/

template <class T>
Array<T>::~Array()
{
        delete [] list;
        cout << "call the Array destruction" << endl;
}

template <class T>
Array<T>& Array<T>::operator =(const Array& a)
{
        if (&a != this)
        {
                if (size != a.size)
                {
                        size = a.size;
                        delete [] list;
                        list = new T[size];
                }
                for (int i=0;i<size;i++)
                {
                        list[i] = a.list[i];
                }
        }
        return *this;
}

template <class T>
T& Array<T>::operator [](int n)
{
        assert(n >= 0 && n < size);
        return list[n];
}

template <class T>
const T& Array<T>::operator [](int n) const
{
        assert(n >= 0 && n < size);
        return list[n];
}

template <class T>
Array<T>::operator T*()
{
        return list;
}

template <class T>
int Array<T>::getSize() const
{
        return size;
}

template <class T>
void Array<T>::resetSize(int s)
{
        assert(s >= 0);
        if (size != s)
        {
                T* tmp = new T[s];
                int n = (size < s)? size:s;
                for (int i=0;i<n;i++)
                {
                        tmp[i] = list[i];
                }
                delete [] list;
                list = tmp;
                size = s;
        }

}
