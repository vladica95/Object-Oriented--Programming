#include "Header.h"
#include <iostream>
using namespace std;



void main()
{
	try
	{



		Luka <Kontejner, 30> L1;
		Luka <Kontejner, 30> L2;
		Kontejner k1(56);Kontejner k4(56);
		Kontejner k2(32);Kontejner k5(56);
		Kontejner k3(33);
		L1.Istovari(k1);
        L1.Istovari(k2);
		L1.Istovari(k1);
		L1.Istovari(k3);
		L1.Istovari(k4);
		L1.Utovari(2);
		L1.Utovari(4);
		L1.Istovari(k5);
		L1.Istovari(k4);
		L1.urediRast();
		//L1.ispisi();
		L1.urediOpad();
		//L1.ispisi();
		L1.stanje(k2);
		L1.opasnost("Skladiste.txt");
    	L1.proslaOpasnost("Skladiste.txt");
		//L1.upisiBin("Bin.dat");
		//L2.ucitajBin("Bin.dat");
		//L1.ispisi();
		L1.ispisi();
	}
	catch (char* x)
	{
		cout << "Upozorenje glavnom menadzeru:   " << x << endl;

	}
}