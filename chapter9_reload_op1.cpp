class Clock
{
	public:
		Clock();
		Clock(int h, int m, int s);
		void display();
		int getHour();
		int getMin();
		int getSec();
		Clock* operator ++(int);
	private:
		unsigned int hour;
		unsigned int min;
		unsigned int sec;
};

#include <iostream>
using namespace std;

int main()
{
	Clock c;
	c.display();
	int count = 0;
	while (c.getHour() < 24)
	{
		c++;
		c.display();
		if ( c.getHour() == 23 && c.getMin() == 59 && c.getSec() == 59)
		{
			break;
		}
		count++;
	};
	cout << count << endl;
	return 0;
}

Clock::Clock():hour(0), min(0), sec(0)
{
	cout << "call the Clock default construction " << endl;
}

Clock::Clock(int h, int m, int s)
{
	if (h <=24 && m <=60 && s <=60 )
	{
		hour = h;
		min = m;
		sec = s;
	}
	else 
	{
		hour = 0;
		min = 0;
		sec = 0;
	}
	cout << "call the Clock construction " << endl;
}

void Clock::display()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

int Clock::getHour()
{
	return hour;
}

int Clock::getMin()
{
	return min;
}

int Clock::getSec()
{
	return sec;
}

//重载后置++运算符
Clock* Clock::operator ++(int)
{
	sec++;
	if (sec >= 60)
	{
		sec %= 60;
		min++;
		if (min >=60)
		{
			min %=60;
			hour++;
			if (hour >= 24)
			{
				hour %= 24;
			}
		}
	}
	return this;
}
