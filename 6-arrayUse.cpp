#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int RES_NUM = 5;


int main()
{
	int ques = 0;
	int count = 0;
	char c = 0;
	char key[RES_NUM] = { 'a', 'b', 'a', 'c', 'd' };
	cout << "please input " << RES_NUM << " answer " << endl;
	while (cin.get(c))
	{
		if (c != '\n')
		{
			if (c == key[ques])
			{
				cout << c;
				count++;
			}
			else
			{
				cout << " ";
			}
			ques++;
		}
		else
		{
			cout << " score is " << count * 100 / ques << "%" << endl;
			ques = 0;
			count = 0;
			
		}
		
	}
	return 0;
}
