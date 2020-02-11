#include "Header.h"





void main()
{
	Basta B1(5);
	Ruza r1(5),r2(20),r3(30),r4(33);
	Zumbul z1(8),z2(40),z3(90);
	Cvetojed c1(20), c2(30), c3(1000);
	
	B1.zasadi(r1, 1, 1);
	B1.zasadi(r4, 4, 4);
	B1.zasadi(r3, 3, 3);
	B1.zasadi(z1, 1, 2);
	B1.zasadi(c1, 2, 1);
	B1.zasadi(r2, 2, 2);
	B1.zasadi(z2, 0, 0);
	B1.zasadi(z3, 4, 1);
	B1.zasadi(c2, 1, 3);
	B1.zasadi(c3, 3, 2);

	B1.dan();
	B1.noc();
	B1.dan();
	B1.noc();
	B1.dan();
	B1.noc();
	B1.stampaj();
	cout << "Ukupna tezina biljaka u basti je :" << B1.Tezina() << endl;
}