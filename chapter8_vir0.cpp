#include <iostream>
#include <string>
using namespace std;

class Abstract
{
        public:
                virtual void display() const =0;
        private:
                int i;
};

class Real1:virtual public Abstract
{
        public:
                virtual void display() const;
        private:
                string type();
};


class Real2:virtual public Real1
{
        public:
                virtual void display() const;
        private:
                string type();
};

void func(Abstract* a)
{
        a->display();
}

int main()
{
        //由于Abstract类是抽象类，所以不能创建实例对象，下面的这行语句是错误的
        //抽象类不能实例化对象，一般用于定义一类类对象共有的抽象方法，可以用来创建指针对象，抽象类类型的指针可以接受派生类的地址（指针）从而实现动态绑定，在运行时判断指针实际指向的派生类，从而调用该类的具体实现方法。实际的逻辑由虚表来实现
        //Abstract* a = new Abstract();
        Real1 r1;
        Real2 r2;
        func(&r1);
        func(&r2);
        return 0;
}

void Real1::display() const
{
        cout << "call the Real1 func" << endl;
}

void Real2::display() const
{
        cout << "call the Real2 func" << endl;
}
