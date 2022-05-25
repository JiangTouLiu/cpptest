#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//定义一个Clock类，里面有私有成员hour，min，sec，有共有函数成员：SetTime，ShowTime
class Clock
{
	public:
		void SetTime(int newHour, int newMin, int newSec);
		void ShowTime();
	private:
		int hour;
		int min;
		int sec;
};

//定义SetTime函数，用来给类对象初始化
void Clock::SetTime(int newHour, int newMin, int newSec)
{
	hour = newHour;
	min = newMin;
	sec = newSec;
}

//定义ShowTime函数，用来显示当前对象的时间
void Clock::ShowTime()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

int main()
{
	int newHour;
	int newMin;
	int newSec;
	Clock startime;
	cout << "please input hour:";
	cin >> newHour;
	cout << "please input min:";
	cin >> newMin;
	cout << "please input sec:";
	cin >> newSec;
	startime.SetTime(newHour, newMin, newSec);
	startime.ShowTime();
	return 0;
}
