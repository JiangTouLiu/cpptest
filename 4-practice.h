#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

enum class CPU_Rank :int
{
	P1 = 1,
	P2,
	P3,
	P4,
	P5,
	P6,
	P7
};

class CPU
{
public:
	CPU(CPU_Rank r, int f, double v);
	CPU(const CPU &c);
	CPU() = default;
	~CPU();
	void Run();
	void Stop();
	void SetRank(CPU_Rank newr);
	void SetFrq(int newf);
	void SetVol(double vol);
	void Show();
private:
	CPU_Rank rank;
	int frequency;
	double voltage;
};



//构造函数
CPU::CPU(CPU_Rank r, int f, double v):rank(r), frequency(f), voltage(v)
{
	cout << "构造一个CPU" << endl;
}

CPU::CPU(const CPU& c)
{
	rank = c.rank;
	frequency = c.frequency;
	voltage = c.voltage;
	cout << "复制构造一个CPU" << endl;
}
//析构函数
CPU::~CPU()
{
	cout << "析构一个CPU" << endl;
}
void CPU::Run()
{
	cout << "CPU start run" << endl;
}
void CPU::Stop()
{
	cout << "CPU stop run" << endl;
}

void CPU::SetRank(CPU_Rank newr)
{
	rank = newr;
}

void CPU::SetFrq(int newf)
{
	frequency = newf;
}

void CPU::SetVol(double vol)
{
	voltage = vol;
}

void CPU::Show()
{
	cout << "the frequency of cpu is " << int(rank) << endl;
	cout << "the frequency of cpu is " << frequency << endl;
	cout << "the voltage of cpu is " << voltage << endl;
}



enum class RAM_Type:int
{
	DDR4,
	DDR3,
	DDR2,
	DDR1
};

class RAM
{
public :
	RAM() = default;
	RAM(int cap, RAM_Type tp, double dominF);
	RAM(const RAM &r);
	~RAM();
	void Show();
	void Run();
	void Stop();
private:
	int capacity;
	RAM_Type type;
	double dominFrequency;
};
//构造函数
RAM::RAM(int cap, RAM_Type tp, double dominF):capacity(cap), type(tp), dominFrequency(dominF)
{
	cout << "构造一个RAM " << endl;
}
RAM::RAM(const RAM& r)
{
	capacity = r.capacity;
	type = r.type;
	dominFrequency = r.dominFrequency;
	cout << "复制构造一个RAM " << endl;
}
//析构函数
RAM::~RAM()
{
	cout << "析构一个RAM " << endl;
}

void RAM::Show()
{
	cout << "the capacity of RAM is " << capacity << endl;
	cout << "the type of RAM is " << int(type) << endl;
	cout << "the dominFrequency of RAM is " << dominFrequency << endl;
}

void RAM::Run()
{
	cout << "RAM start Run " << endl;
}

void RAM::Stop()
{
	cout << "RAM Stop Run " << endl;
}

enum class INTERFACE_TYPE :int
{
	SATA,
	USB,
	IDE,
	SCSI,
	SAS
};

enum class ASSEMBLE_TYPE :int
{
	EXTERNAL,
	BULIT_IN
};

class CDROM
{
public:
	CDROM() = default;
	CDROM(INTERFACE_TYPE it, ASSEMBLE_TYPE at, double cC);
	CDROM(const CDROM& cr);
	~CDROM();
	void Show();
	void Run();
	void Stop();
private:
	INTERFACE_TYPE interType;
	ASSEMBLE_TYPE assType;
	double cacheCapacity;
};
//构造函数
CDROM::CDROM(INTERFACE_TYPE it, ASSEMBLE_TYPE at, double cC):interType(it), assType(at), cacheCapacity(cC)
{
	cout << "构造一个CDROM " << endl;
}
//复制构造函数
CDROM::CDROM(const CDROM& cr)
{
	interType = cr.interType;
	assType = cr.assType;
	cacheCapacity = cr.cacheCapacity;
	cout << "复制构造一个CDROM " << endl;
}
//析构函数
CDROM::~CDROM()
{
	cout << "析构一个CDROM " << endl;
}

void CDROM::Show()
{
	cout << "the interType of CDROM is " << int(interType) << endl;
	cout << "the assType of CDROM is " << int(assType) << endl;
	cout << "the cacheCapacity of CDROM is " << cacheCapacity << endl;
}

void CDROM::Run()
{
	cout << "CDROM start Run " << endl;
}

void CDROM::Stop()
{
	cout << "CDROM stop Run " << endl;
}

class COMPUTER
{
public:
	COMPUTER();
	COMPUTER(string name, CPU c, RAM r, CDROM cr);
	COMPUTER(const COMPUTER& pc);
	~COMPUTER();
	void SetName(string n);
	void SetCpu(CPU c);
	void SetRam(RAM r);
	void SetCR(CDROM cr);
	void Run();
	void Stop();
private:
	string myName;
	CPU myCpu;
	RAM myRam;
	CDROM myCdRom;
};
//构造函数
COMPUTER::COMPUTER(string name, CPU c, RAM r, CDROM cr) :myName(name), myCpu(c), myRam(r), myCdRom(cr)
{
	cout << "构造一个COMPUTER " << endl;
}
//复制构造函数
COMPUTER::COMPUTER(const COMPUTER& pc)
{
	myName = pc.myName;
	myCpu = pc.myCpu;
	myRam = pc.myRam;
	myCdRom = pc.myCdRom;
	cout << "复制构造一个COMPUTER " << endl;
}
//析构函数
COMPUTER::~COMPUTER()
{
	cout << "析构一个COMPUTER " << endl;
}

void COMPUTER::Run()
{
	myCpu.Run();
	myRam.Run();
	myCdRom.Run();
	cout << "COMPUTER start Run " << endl;
}

void COMPUTER::Stop()
{
	myCpu.Stop();
	myRam.Stop();
	myCdRom.Stop();
	cout << "COMPUTER Stop Run " << endl;
}

