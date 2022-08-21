#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Animal
{
public:
	int age;
};

class Dog :public Animal
{
public:
	int getAge()
	{
		return age;
	};
	int setAge(int a)
	{
		age = a;
		return age;
	};
};

class BaseClass
{
public:
	BaseClass()
	{
		cout << "BaseClass default construction is called" << endl;
	}
	~BaseClass()
	{
		cout << "BaseClass destruction is called" << endl;
	}
	int Number;
};

class DeriveClass :public BaseClass
{
public:
	DeriveClass()
	{
		Number = 0;
		Number++;
		cout << "DeriveClass default construction is called" << "Number = " << Number << endl;
	}
	~DeriveClass()
	{
		Number--;
		cout << "DeriveClass destruction is called" << "Number = " << Number << endl;
	}
};

class vehicle
{
public:
	double getMaxSpeed()
	{
		return MaxSpeed;
	}
	double getWeight()
	{
		return Weight;
	}
	void Run()
	{
		cout << "the vehicle is running" << endl;
	};
	void Stop()
	{
		cout << "the vehicle is stopped" << endl;
	};
private:
	double MaxSpeed;
	double Weight;
};

class Bicycle :virtual public vehicle
{
public:
	double getHight()
	{
		return hight;
	};
private:
	double hight;
};

class Motorcar :virtual public vehicle
{
public:
	int getSeatNum()
	{
		return SeatNum;
	}
private:
	int SeatNum;
};

class MotorCycle :public Bicycle, public Motorcar
{


};



int main()
{
	/*Dog d;
	cout << d.getAge() << endl;
	
	cout << d.setAge(2) << endl;
	
	DeriveClass d;*/
	MotorCycle m1;
	m1.Run();
	m1.Stop();
	cout << m1.getMaxSpeed() << endl;
	cout << m1.getWeight() << endl;
	cout << m1.getHight() << endl;
	cout << m1.getSeatNum() << endl;


	return 0;
}
