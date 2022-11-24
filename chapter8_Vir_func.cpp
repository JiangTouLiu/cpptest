#include <iostream>
using namespace std;

class Vir_base
{
        public:
                virtual void display();
        private:
                int i;
};

//当基类的函数使用virtual关键词进行修饰声明为虚函数之后，派生类函数与基类该函数同名的函数默认也为虚函数。
//但是建议派生类同样使用virtual关键词进行修饰，可以增加代码的可读性
class Vir_first1:public Vir_base
{
        public:
                virtual void display();
};

class Vir_first2:public Vir_base
{
        public:
                virtual void display();
};

class Vir_second1:public Vir_first1
{
        public:
                virtual void display();
};

class Vir_second2:public Vir_first2
{
        public:
                virtual void display();
};



void func(Vir_base* B);

int main()
{
        Vir_base* vb = new Vir_base();
        Vir_base* vf1 = new Vir_first1();
        Vir_base* vf2 = new Vir_first2();
        Vir_base* vs1 = new Vir_second1();
        Vir_base* vs2 = new Vir_second2();
        //如果基类的display函数没有用virtual声明为虚函数，这样调用func时都是调用Vir_base类的display函数
        //如果基类的display函数使用了virtual关键词声明为虚函数，这样会根据指针实际指向的类型调用对应类的display函数
        func(vb);
        func(vf1);
        func(vf2);
        func(vs1);
        func(vs2);
        return 0;
}

void Vir_base::display()
{
        cout << "call the Vir_base display" << endl;
}

void Vir_first1::display()
{
        cout << "call the Vir_first1 display" << endl;
}


void Vir_first2::display()
{
        cout << "call the Vir_first2 display" << endl;
}


void Vir_second1::display()
{
        cout << "call the Vir_second1 display" << endl;
}


void Vir_second2::display()
{
        cout << "call the Vir_second2 display" << endl;
}

void func(Vir_base* B)
{
        B->display();
}
