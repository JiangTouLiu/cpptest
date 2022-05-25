#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Clock
{
	public:
		Clock(int initHour, int initMin, int initSec);
		Clock();
		void ShowTime();
		void SetTime(int newHour, int newMin, int newSec);
	private:
		int hour;
		int min;
		int sec;

};

//类Clock的构造函数，设置3个初始值
Clock::Clock(int initHour, int initMin, int initSec) :hour(initHour), min(initMin), sec(initSec) 
{

}

//类Clock的默认构造函数，设置3个初始值为0
Clock::Clock() : hour(0), min(0), sec(0)
{

}

//定义SetTime函数，用来给类对象初始化
void Clock::SetTime(int newHour, int newMin, int newSec)
{
	hour = newHour;
	min = newMin;
	sec = newSec;
}

//定义ShowTime函数，用来显示当前对象的时间
inline void Clock::ShowTime()
{
	cout << hour << ":" << min << ":" << sec << endl;
}



int main()
{
	Clock c1(2,2,2);
	Clock c2;
	c1.ShowTime();
	c1.SetTime(22, 37, 50);
	c1.ShowTime();
	c2.ShowTime();
	c2.SetTime(22, 41, 30);
	c2.ShowTime();
	return 0;
}
