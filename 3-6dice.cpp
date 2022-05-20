#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>
using namespace std;

const int firstRoundW1 = 7;
const int firstRoundW2 = 11;

const int firstRoundL1 = 2;
const int firstRoundL2 = 3;
const int firstRoundL3 = 12;

int dice()
{
	
	int ret1 = 1 + rand() % 6;
	int ret2 = 1 + rand() % 6;
	cout << ret1 << "+" << ret2 << "=" << ret1 + ret2 << endl;
	return ret1 + ret2;
}

enum stauts
{
	LOSE,
	PLAYING,
	WIN
};

int main()
{
	unsigned int seed = 0;
	int sum;
	int myNum = 0;
	enum stauts staut = PLAYING;
	cout << "请输入一个随机数种子:";
	cin >> seed;
	srand(seed);
	sum = dice();
	switch (sum)
	{
		case firstRoundW1:
		case firstRoundW2:
			staut = WIN;
			break;
		case firstRoundL1:
		case firstRoundL2:
		case firstRoundL3:
			staut = LOSE;
			break;
		default:
			myNum = sum;
			cout << "myNum is " << myNum << endl;
			break;
	}
	while (PLAYING == staut)
	{
		myNum = sum;
		sum = dice();
		if (sum == 7)
		{
			staut = LOSE;
		}
		else if (sum == myNum)
		{
			staut = WIN;
		}
	}
	if (WIN == staut)
	{
		cout << "恭喜你赢了！" << endl;
	}
	else
	{
		cout << "很遗憾，你输了" << endl;
	}

	return 0;
}
