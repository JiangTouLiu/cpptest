class Base
{
public:
	virtual void display();	//定义display函数，类内只声明，不实现
};
//类外实现基类的显示函数
void Base::display()
{
	cout << "Base1 display" << endl;
};
class Derive:public Base
{
public:
	virtual void display();//定义display函数，类内只声明，不实现
};
//类外实现基类的显示函数
void Derive::display()
{
	cout << "Derive display" << endl;
};
//定义函数调用类的display函数，以Base类的指针作为形参，实际调用时根据传入的指针类型调用对应类的display函数
void fun(Base* b)
{
	b->display();
};
int main()
{
	Base b;
	Derive d;
	fun(&b);	//由于display是虚函数，所以在运行时根据指针类型去调用对应的类的display函数，b是Base类指针，所以调用Base类的display函数
	fun(&d);	//由于display是虚函数，所以在运行时根据指针类型去调用对应的类的display函数，d是Derive类指针，所以调用Derive类的display函数
	return 0;
}

class Base
{
public:
	~Base();	//不是虚函数
};
Base::~Base()
{
	cout << "Base destruction function" << endl;
};
class Derive :public Base
{
public:
	~Derive();	//不是虚函数
private:
	int* p;
};
Derive::~Derive()
{
	delete p;
	cout << "Derive destruction function" << endl;
};

void fun(Base* b)
{
	delete b;
};

int main()
{
	Base* d = new Derive();
	fun(d);	//析构函数没有被声明为虚析构函数，此时执行fun函数只调用了Base类的析构函数，造成内存泄漏
	return 0;
}
