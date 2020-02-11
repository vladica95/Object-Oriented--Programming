#pragma once
#include <iostream>
using namespace std;



template <class T, int dim>
class Kontejner
{
	T** niz;
	int now;
	int broj;

public:
	Kontejner() {
		now = 0;
		broj = dim;
		niz = new T*[dim];
		for (int i = 0; i < dim; i++)
		{
			niz[i] = 0;
		}
	}
	~Kontejner() {
		delete[] niz;
		niz = 0;

	}
	void dodaj(T& t) {
		if (niz[now] == 0)
			niz[now] = &t;
		now++;
	}
	void unesi() {
		T pom;
		for (int i = 0;i < dim;i++) {
			cin >> pom;
			niz[i] = new T(pom);
		}
	}
	void stampaj() {
		cout << "Kontejner :" << endl;
		for (int i = 0; i < broj; i++)
		{
			if (niz[i] != 0)
				cout << *niz[i];
		}
		cout << endl;
	}
	float prosek() {
		T pom;
		pom = 0;
		float p = 0; float t = 0;
		for (int i = 0; i < dim; i++)
		{
			if (niz[i] != 0) {
				pom =pom + *niz[i];
				t++;
			}
		}
		p = pom / t;
		return p;
	}
	void uredi() {
		T *pom;
		for (int i = 0; i < dim - 1; i++)
		{
			for (int j = i + 1; j < dim; j++)
			{
				if (*niz[i] > *niz[j]) {
					pom = niz[i];
					niz[i] = niz[j];
					niz[j] = pom;
				}
			}
		}
	}
	Kontejner& posebnaf(Kontejner& t1, Kontejner& t2) {
		T**pom;
		int p;
		p = t1.broj + t2.broj;
		broj = p;
		pom = new T*[p];
		for (int i = 0; i < p; i++)
		{
			pom[i] = 0;
		}
		for (int i = 0; i < t1.broj; i++)
		{
			pom[i] = t1.niz[i];
		}
		for (int i = t1.broj; i < p; i++)
		{
			pom[i] = t2.niz[i - t1.broj];
		}
		delete[]niz;
		niz = pom;
		pom = 0;
		return *this;
	}

};
class PP {
	int masa, duzina, sirina, visina, g_mat;

public:
	PP(int a, int b, int c, int d) {
		duzina = a; sirina = b; visina = c; g_mat = d;
		masa = a*b*c*d;
	}
	PP() {
		masa = 0;
		duzina = 0;
		sirina = 0;
		visina = 0;
		g_mat = 0;
	}
	~PP() {}
	int vratiV() {
		return sirina*visina*duzina*g_mat;
	}
	friend ostream& operator<<(ostream& out, PP& p) {
		out << "Paralelopiped :  " << "duzina :  " << p.duzina << "   " << "sirina :   " << p.sirina
			<< "   " << "visina :  " << p.visina << "   " << "gustina materijala :  " << p.g_mat
			<< "   " << "masa : " << p.duzina*p.sirina*p.visina*p.g_mat;
		cout << endl;
		return out;
	}
	friend istream& operator >> (istream& in, PP& p) {
		in >> p.duzina >> p.sirina >> p.visina >> p.g_mat;
		return in;
	}
	PP& operator+(PP&p) {
		int pom;
		pom = masa + p.vratiV();
		masa = pom;
		return *this;
	}
	int operator>(PP&p) {
		if (vratiV() > p.vratiV())
			return 1;
		else return 0;
	}
	float operator/(int a) {
		float p;
		p = masa / a;
			return p;
	}
	PP& operator=(PP& p) {
		masa = p.masa;
	//	duzina = p.duzina;
	//	sirina = p.sirina;
	//	visina = p.visina;
		return *this;
	}
	PP& operator=(int x) {
		masa = x;
		return *this;
	}
};