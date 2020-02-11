#include "Header.h"




void main() {

	Skladiste S1("Podrum 1", 20);
	Skladiste *S2;
	S2=new Skladiste ("Podrum 2", 20);

	Praskasti P1("Barut", "neograniceno", 30000);
	Praskasti P2("Secer", "2017", 200);
	Praskasti P3("Brasno", "2020", 200);

	Tecni T1("Rakija", "neograniceno", 20, 3);
	Tecni T2("Vino", "neograniceno", 10, 3);
	Tecni T3("Pivo", "2020", 3, 0.3);

	S1.dodaj(P1);  S2->dodaj(P1);
	S1.dodaj(P2);  S2->dodaj(P2);
	S1.dodaj(P3);  S2->dodaj(P3);

	S1.dodaj(T1);  S2->dodaj(T1);
	S1.dodaj(T2);  S2->dodaj(T2);
	S1.dodaj(T2);  S2->dodaj(T3);

	S1.stampaj();
	S2->stampaj();


}