#include "Header.h"



void main() 
{
	try

	{

		Analizator<Epruveta, 5> A1;
		Epruveta e1("Vladica Vucic", "02:20", "analiza krvi");
		Epruveta e2("Vladica Vucic", "07:50", "analiza krvi");
		Epruveta e4("Petar", "22:34", "analiza krvi");
		Epruveta e3("Petar", "04:30", "analiza krvi");
		Epruveta e5("Milos","13:23","analiza krvi");
		A1.dodaj(e1); A1.dodaj(e2); A1.dodaj(e5);
		A1.vrati(0);
		A1.izbaci(2);
		A1.dodaj(e4);  A1.dodaj(e3);  A1.dodaj(e5);
		A1.ispisi();
		A1.postavi_BK();
		A1.ispisi();
		A1.uredi();
		A1.ispisi();
		A1.Upisi_UTXT("TestKrvi.txt");
		A1.Upisi_IzTXT("TestKrvi.txt");
		A1.ispisi();
		cout << "Pozicija epruvete:" << A1.vrati(e2) << endl;
	}
	catch (char* x) {
		cout << "Upozorenje:  " << x << endl;
	}
}