#include "Header.h"


Skladiste::Skladiste(char* x, int a) {
	now = 0;
	naziv = x;
	kapacitet = a;
	niz = new Materijal*[kapacitet];
	for (int i = 0; i < kapacitet; i++)
	{
		niz[i] = 0;
	}
}
Skladiste::~Skladiste() {
	delete []niz;
	niz = 0;
}
void Skladiste::dodaj(Materijal& m) {
	if (niz[now] == 0 && now < kapacitet) {
		niz[now] = &m;
		now++;
	}
}
void Skladiste::stampaj() {
	cout << naziv << endl;
	for (int i = 0; i < kapacitet; i++)
	{
		if (niz[i] != 0 && niz[i]->vratiT() > 2) {
			niz[i]->ispisi();
			cout << endl;
		}
	}
}
