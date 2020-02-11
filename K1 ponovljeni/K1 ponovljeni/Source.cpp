#include "Header.h"
#include <math.h>
#include <iostream>
#include <fstream>


using namespace std;



Entitet::Entitet() {
	Energija = 0;
}
Entitet::~Entitet() {}

Entitet::Entitet(Entitet& e) {
	tip = e.tip;
	Energija = e.Energija;
}
Ajkula::Ajkula() {
	Energija = 80;
	tip = 1;
}
Ajkula::~Ajkula() {}

Ajkula::Ajkula(Ajkula& a) {
	Energija = a.Energija;
	tip = a.tip;
}
void Ajkula::uvecaj(int a) {
	Energija += a;
}
void Ajkula::smanji() {
	Energija = Energija - 45;
}
void Ajkula::smanji(int a, int b) {
	double p;  double t = (2.7 + a + b) / b;
	p=exp(t);
		Energija = Energija - p;
}
void Ajkula::ispisi() {
	cout << "Ajkula :    " << Energija << endl;
}
Marsovac::Marsovac() : Entitet() {
	tip = 2;
}
Marsovac::Marsovac(Marsovac& m) {
	tip = m.tip;
	Energija = m.Energija;
}
Marsovac::~Marsovac(){}
void Marsovac::postaviE(int a, int b) {
	int c = a*b;
	Energija = exp(c);
}
void Marsovac::uvecaj(int a) {
	Energija += a;
}
void Marsovac::smanji() {
	Energija = Energija - 45;
}
void Marsovac::ispisi() {
	cout << "Marsovac :    " << Energija << endl;
}
Ruza::Ruza() {
	tip = 3;
	Energija = 10;
}
Ruza::~Ruza(){}
Ruza::Ruza(Ruza& r) {
	tip = r.tip;
	Energija = r.Energija;
}
void Ruza::uvecaj(int a) {
	Energija += a;
}
void Ruza::uvecaj(int a, int b) {
	double p=a*(2.7 + b);
	Energija += p;
}
void Ruza::smanji() {
	Energija = Energija - 45;
}
void Ruza::ispisi() {
	cout << "Ruza :    " << Energija << endl;
}
Polje::Polje(int a) {
	dim = a;

	polje = new Entitet**[dim];
	for (int i = 0; i < dim; i++)
	{
		polje[i] = new Entitet*[dim];
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			polje[i][j] = 0;
		}
	}
}
Polje::~Polje() {
	for (int i = 0; i < dim; i++)
	{
		delete[] polje[i];
	}
	delete[] polje;
	polje = 0;
}
void Polje::dodaj(Entitet& e, int a, int b) {
	if (polje[a][b] == 0) {
		polje[a][b] = &e;
		if (polje[a][b]->vratiTip() == 2) {
			polje[a][b]->postaviE(a, b);
		}
	}
	else cout << "Mesto zauzeto." << endl;
}
void Polje::good() {
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (polje[i][j] != 0) {
				if (polje[i][j]->vratiTip() == 1) {
					polje[i][j]->uvecaj(25);
				}
				else if (polje[i][j]->vratiTip() == 2) {
					for (int k = 0; k < dim; k++)
					{
						for (int l = 0; l < dim; l++)
						{
							if (polje[k][l] != 0) {
								if (polje[k][l]->vratiTip() == 3) {
									polje[k][l]->uvecaj(i, j);
								}
							}
						}
					}
				}
				else if (polje[i][j]->vratiTip() == 3) {
					if (polje[i - 1][j] != 0 && i >= 1) {
						
						polje[i - 1][j]->uvecaj(11);
					}
					else if (i < dim - 1 && polje[i + 1][j] != 0) {
						polje[i + 1][j]->uvecaj(11);
					}
					else if (polje[i][j - 1] != 0 && j > 1) {
						polje[i][j - 1]->uvecaj(11);
					}
					else if (polje[i][j + 1] != 0 && j < dim - 1) {
						polje[i][j + 1]->uvecaj(11);
					}
				}
			}
		}
	}
}
					

void Polje::bad() {
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (polje[i][j] != 0) {
				if (polje[i][j]->vratiTip() == 1) {
					if (i > 1 && polje[i - 1][j] != 0){
						polje[i - 1][j]->smanji();
						if (polje[i - 1][j]->vratiE() <= 0)
							polje[i - 1][j] = 0;
					}
					else if (polje[i + 1][j] != 0 && i < dim - 1) {
						polje[i + 1][j]->smanji();
						if (polje[i + 1][j]->vratiE() <= 0)
							polje[i + 1][j] = 0;
					}
					else if (polje[i][j - 1] != 0 && j > 1) {
						polje[i][j - 1]->smanji();
						if (polje[i][j - 1] <= 0)
							polje[i][j - 1] = 0;
					}
					else if (polje[i][j + 1] != 0 && j < dim - 1) {
						polje[i][j + 1]->smanji();
						if (polje[i][j + 1]->vratiE() <= 0)
							polje[i][j + 1] = 0;
					}
				}
				else if (polje[i][j]->vratiTip() == 2) {
					for (int k = 0; k < dim; k++)
					{
						for (int l = 0; l < dim; l++)
						{
							if (polje[k][l] != 0) {
								if (polje[k][l]->vratiTip() == 1) {
									polje[k][l]->smanji(i, j);
									if (polje[k][l]->vratiE() <= 0)
										polje[k][l] = 0;
								}
							}
						}
					}
				}
				else if (polje[i][j]->vratiTip() == 3) {
					polje[i][j]->uvecaj(12);
				}
			}
		}
	}
}
void Polje::stampaj() {
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (polje[i][j] == 0)
				cout << " ";
			else if (polje[i][j]->vratiTip() == 1)
				cout << "A";
			else if (polje[i][j]->vratiTip() == 2)
				cout << "M";
			else if (polje[i][j]->vratiTip() == 3)
				cout << "R";
			}
		cout << endl;
		}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (polje[i][j] != 0)
				polje[i][j]->ispisi();
		}
	}

}
