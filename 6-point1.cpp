#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int* pa = &a;
	cout << "*pa = " << * pa << endl;
	cout << "pa = " << pa << endl;
	*pa = 5;
	cout << *pa << endl;
	cout << "-------------------------------------------------------";
	int b = 20;
	const int* pb = &b;
	//*pb = 30;
	cout << "*pb = " << *pb << endl;
	cout << "pb = " << pb << endl;
	pb = pa;
	cout << "pb = " << pb << endl;
	int c = 30;
	pb = &c;
	cout << "pb = " << pb << endl;
	cout << "-------------------------------------------------------";
	int* const pc = &c;
	//pc = pb;
	*pc = *pb;
	cout << "*pc = " << *pc << endl;
	cout << "pc= " << pc << endl;
	return 0;
}
