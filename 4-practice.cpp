#define _CRT_SECURE_NO_WARNINGS 1
#include "4-practice.h"


int main()
{
	/*CPU c1(CPU_Rank::P2, 100, 5.0);
	CPU c2(CPU_Rank::P5, 20, 1.2);
	CPU c3(CPU_Rank::P7, 70, 10.5);
	c1.Run();
	c1.Stop();
	c1.Show();
	c2.Show();
	c3.Show();
	c1.SetRank(CPU_Rank::P1);
	c1.SetFrq(200);
	c1.SetVol(3.14);
	c1.Show();
	c2.Show();
	c3.Show();
	RAM ra1(100, RAM_Type::DDR1, 2.5);
	CDROM cro1(INTERFACE_TYPE::SATA, ASSEMBLE_TYPE::BULIT_IN, 128);
	ra1.Show();
	cro1.Show();*/
	CPU c1(CPU_Rank::P2, 2000, 2.5);
	RAM r1(128, RAM_Type::DDR4, 2.8);
	CDROM cr1(INTERFACE_TYPE::SATA, ASSEMBLE_TYPE::EXTERNAL, 512);
	COMPUTER pc1("surface", c1, r1, cr1);
	pc1.Run();
	pc1.Stop();

	return 0;
}
