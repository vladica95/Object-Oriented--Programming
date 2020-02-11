#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;




template <class T,int dim>
class Analizator {

	string naziv;
	T** rek;
	int now;
	int brEL;

public:
	Analizator() {
		now = 0;
		brEL = dim;
		cout << "Unesi ime analizatora: " << endl;
		cin >> naziv;
		rek = new T*[dim];
		for (int i = 0; i < dim; i++)
		{
			rek[i] = 0;
		}
	}
	~Analizator() {
		delete[] rek;
		rek = 0;
	}
	void postavi_BK() {
		for (int i = 0; i < dim-1; i++)
		{
			for (int j = i + 1; j < dim; j++) 
			{
				if (rek[i]->vrati_Ime() == rek[j]->vrati_Ime()) {
					rek[j]->podesi_BK(vrati(i));
				}
			}
		}
	}
	void dodaj(T& t) {
		if (rek[now] == 0 && now < dim) {
			rek[now] = &t;
			now++;
		}
		else 
		{
			throw "Nepravilno dodavanje epruveta.";
		}
	}
	T vrati(int a) {
		if (rek[a] != 0) {
			return *rek[a];
		}
		else throw "Nepravilna lokacija.";
	}
	void izbaci(int a) {
		if (rek[a] != 0) {
			rek[a] = 0;
			for (int i = a; i < dim-1; i++)
			{
				rek[i] = rek[i+1];

			}
			rek[dim-1] = 0;
			now--;
		}
	}
	int vrati(T& t) {
		for (int i = 0; i < dim; i++)
		{
			if (rek[i] == &t) {
				return i;
			}
		}
	}
	void uredi() {
		T* pom;
		for (int i = 0;i<dim;i++) {
			for (int j = i + 1;j<dim;j++) {
				if (rek[i]>rek[j]) {
					pom = rek[i];
					rek[i] = rek[j];
					rek[j] = pom;
				}
			}
		}
	}
	
	void ispisi() {
		cout << naziv<<"  :" << endl;
		for (int i = 0; i < dim; i++)
		{
			if (rek[i] != 0) {
				cout << *rek[i];
			}
		}
	}
	void Upisi_UTXT(char* ime) {
		ofstream izlaz(ime);
		izlaz << "Broj epruveta: " << brEL << endl;
		for (int i = 0; i < dim; i++)
		{
			izlaz << *rek[i] << endl;
		}
		izlaz.close();
	}
	void Upisi_IzTXT(char* ime) {
		ifstream ulaz(ime);
		if (!ulaz.is_open())
			throw "Lose otvaranje.";
		delete[]rek;
		rek = 0;
		ulaz >> brEL;
		if (!ulaz.good())
			throw "Lose otvaranje.";
		rek = new T*[dim];
		T pom;                    //dodato 
		for (int i = 0; i < dim; i++)
		{
			ulaz >> pom;          //bilo je rek[i];
			rek[i] = new T(pom);  //dodato
			if (!ulaz.good())
				throw "Lose otvaranje.";
		}
		ulaz.close();
	}

	/*friend istream& operator >> (istream& in, Analizator& a) {
		in >> brEL;
		return in;
	}
*/
};

class Epruveta {
	
	int barKod[7];
	string Ime_pacijenta;
	string vreme;
	string test;
public:
	Epruveta() {
		for (int i = 0; i < 7; i++)
		{
			barKod[i] = 0;
		}
		vreme = "--:--";
		test = " ";
	}
	Epruveta(string s1, string s2, string s3) {
		//srand(time(NULL));
		for (int i = 0; i < 6; i++)
		{
			barKod[i] = rand() % 10;
		}
		barKod[6] = 0;
		Ime_pacijenta = s1;
		vreme = s2;
		test = s3;

	}
	~Epruveta() {
	}
	string vrati_Ime() {

		return Ime_pacijenta;
	}
	void podesi_BK(Epruveta& e) {
		for (int i = 0;i < 7;i++) {
			barKod[i] = e.barKod[i];
		}
			barKod[6] += 1;
	}
	int vrati_BK(int a) {
		return barKod[a]; 
	}
	int operator>(Epruveta& d) {
		if (barKod>d.barKod)
			return 1;
		else return 0;
	}
	friend ostream& operator<<(ostream& out, Epruveta& e) {
		out << "Epruveta:  " << e.Ime_pacijenta << "  " << e.vreme << "  " << e.test << "  ";
		for (int i = 0; i < 7; i++)
		{
			out << e.barKod[i];
		}
		cout << endl;
		return out;
	}
	friend istream& operator >> (istream& in, Epruveta& e) {
		in >> e.Ime_pacijenta >> e.vreme >> e.test;
		for (int i = 0; i < 7; i++)
		{
			in >> e.barKod[i];
		}
		return in;
	}
};
