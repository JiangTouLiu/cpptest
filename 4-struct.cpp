#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>
using namespace std;


class ExamInfo
{
public:
	ExamInfo(string sname, string cname, int per);
	ExamInfo(string sname, string cname, bool pas);
	ExamInfo(string sname, string cname, char re);
	~ExamInfo();
	void ShowInfo();
	
private:
	string stuName;
	string course;
	enum class MarkType:int
	{
		PERCENT,
		PASS,
		GRADE
	}mode;
	union
	{
		int percent;
		bool pass;
		char grade;
	};
	
};
//percent格式的成绩构造函数
ExamInfo::ExamInfo(string sname, string cname, int per):stuName(sname), course(cname), mode(MarkType::PERCENT),  percent(per)
{
	
}
//pass格式的成绩构造函数
ExamInfo::ExamInfo(string sname, string cname, bool b):stuName(sname), course(cname), mode(MarkType::PASS), pass(b)
{

}
//grade格式的成绩构造函数
ExamInfo::ExamInfo(string sname, string cname, char gra):stuName(sname), course(cname), mode(MarkType::GRADE), grade(gra)
{

}

//析构函数
ExamInfo::~ExamInfo()
{


}

void ExamInfo::ShowInfo()
{
	switch (mode)
	{
		case MarkType::PERCENT:
			cout << "the " << course << " mark of " << stuName << " is: " << percent << endl;
			break;
		case MarkType::PASS:
			cout << "the " << course << " mark of " << stuName << " is: " << pass << endl;
			break;
		case MarkType:: GRADE:
			cout << "the " << course << " mark of " << stuName << " is: " << grade << endl;

	}
	

}

//创建结构体
struct Student
{
	int age;
	char name[25];
	int stuNum;
	char address[50];
	void Show();
	void Set(int aa, int stuno);
};

void Student::Show()
{
	cout << "age is : " << age << endl;
	cout << "stuNum is : " << stuNum << endl;
	cout << "name is " << name << endl;
	cout << "adderss is: " << address << endl;
}

void Student::Set(int aa, int stuno)
{
	age = aa;
	stuNum = stuno;
}
//声明联合体
union Result
{
	int percent;
	char grade;
	bool pass;
};

int main()
{
	ExamInfo e1("zhangsan", "math", 86);
	ExamInfo e2("lisi", "english", 'B');
	ExamInfo e3("wangwu", "python", false);
	Student s1 = { 23, "zhangsan", 1001, "guangdongshen" };
	s1.Show();
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	s1.Set(25, 2002);
	s1.Show();
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------" << endl;
	e1.ShowInfo();
	e2.ShowInfo();
	e3.ShowInfo();

	return 0;
}
