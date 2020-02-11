#include "Header.h"


void main() {

	Polje p1(5);
	Ajkula a1, a2, a3, a4;
	Marsovac m1, m2, m3, m4;
	Ruza r1, r2, r3, r4;
	p1.dodaj(a1, 0, 0); p1.dodaj(a2, 1, 3); p1.dodaj(a3, 2, 3); p1.dodaj(a4, 3, 3);
	p1.dodaj(m1, 1, 2); p1.dodaj(m2, 2, 1); p1.dodaj(m3, 2, 2); p1.dodaj(m4, 1, 1);
	p1.dodaj(r1, 1, 0); p1.dodaj(r2, 3, 1); p1.dodaj(r3, 3, 2); p1.dodaj(r4, 4, 4);
	p1.stampaj();
	p1.good();
	p1.stampaj();
	//p1.bad();
	//p1.stampaj();
	p1.bad();
	p1.stampaj();
//	p1.good();
//	p1.stampaj();
}