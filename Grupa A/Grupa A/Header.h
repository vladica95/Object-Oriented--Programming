#pragma once
#include <iostream>
#include <fstream>
using namespace std;



template <class T,int dim>
class Hotel
{
private:
	T** sefovi;
	int now;
	

public:
	Hotel() {
		now = 0;
		sefovi = new T*[dim];
		for (int i = 0; i < dim; i++)
		{
			sefovi[i] = 0;
		}

	}
	~Hotel() {
		delete[] sefovi;
		sefovi = 0;
	}
	void zatrazi_sef(T& t) {
		if (sefovi[now] == 0) {
			sefovi[now] = &t;
			now++;
			cout << "Redni broj sefa: " << now - 1 << endl << endl;
		}
		else throw "Dodavanje nije moguce. ";
	}

	void Preuzmi(int a) {
		if (sefovi[a] != 0) {
			for (int i = a; i < dim; i++)
			{
				sefovi[i] = sefovi[i + 1];
			}
			now--;
			sefovi[dim - now] = 0;
		}
		else
		{
			throw "Preuzimanje nije moguce. ";
		}
	}

	float prosecan_Rent() {
		int a = 0;
		float b;
		for (int i = 0; i < now; i++)
		{
			if(sefovi[i]!=0)
			a = a + sefovi[i]->vrati_rent();
		}
		b = a / now;
		return b;
	}
	




	void Prikazi() {
		for (int i = 0; i < now; i++)
		{
			if (sefovi[i] != 0) {
				cout << *sefovi[i] << endl;
			}
		}
	}
};
class Kutija
{
	int rent;
	char* ime;

public:
	Kutija() {
		rent = 0;
	}

	Kutija(char* IME,int a) {
		rent = a;
		ime = IME;
	}

	~Kutija() {

	}
	inline int vrati_rent() {
		return rent;
	}

	friend ostream& operator<<(ostream& out, Kutija& k) {
		out << "Kutija:  " << "Nakit: " << k.ime << "  " << "Vreme renta: " << k.rent << " dana. ";
		cout << endl;
		return out;
	}

};




