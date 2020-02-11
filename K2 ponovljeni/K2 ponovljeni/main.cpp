#include "Header.h"



void main() {


	Kontejner<PP, 3> k1,k2,k3;
	Kontejner<int, 6> t1, t2, t3;
	PP p1(3, 4, 3, 4), p2(1, 2, 3, 4), p3(3, 4, 5, 6);
	k1.dodaj(p1); k2.dodaj(p3);
	k1.dodaj(p2); k2.dodaj(p2);
	k1.dodaj(p3); k2.dodaj(p1);
	k3.posebnaf(k1, k2);
	//k1.uredi();
	//cout <<"Prosek je: "<< k1.prosek() << endl;
	//t1.unesi();

	//t1.uredi();
	//cout <<"Prosek je: "<< t1.prosek() << endl;
	//t1.stampaj();
	//k1.unesi();
	//k1.stampaj();
	k3.stampaj();
}
