#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;





template <class T,int dim>
class Luka
{
	int now;
	int pointer;
	T** lokacije;

public:
	Luka() {
		now = 0;
		pointer = 0;
		lokacije = new T*[dim];
		for (int i = 0; i < dim; i++)
			lokacije[i] = 0;
	}
	~Luka() {
		delete[] lokacije;
		lokacije = 0;
	}
	void Istovari(T& t) {
		if (now < dim) {
				
				for (int i = dim; i > -1; i--)
				{
					if (lokacije[i] == 0) {
						pointer = i;
					}
				}
				lokacije[pointer] = &t;
				now++;
				
			}
			else
			{
				throw "Luka je popunjena.";
		}
	}

	void Utovari(int a) {
		if (lokacije[a] != 0)
		{
			lokacije[a] = 0;
			now--;
			cout << "Kontejner je utovaren." << endl;
		}
		else throw "Lokacija je pogresna.";
	}

	void stanje(T& t) {
		int q;
		q = 0;
		for (int i = 0; i < dim; i++)
		{
			if (lokacije[i] == &t) {
			 q = 1;
				
			}
		}
		if (q == 1) {
			cout << "Kontejner je smesten." << endl;
		}
		else throw "Kontejner nije smesten.";
	}

	void urediRast() {
		T* pom;
		cout << "Rastuce sortiranje. " << endl;
		for (int i = 0; i < now-1; i++)
		{
			for (int j = i+1; j < now; j++)
			{
				if (lokacije[i]->vratiID() > lokacije[j]->vratiID()) {
					pom = lokacije[i];
					lokacije[i] = lokacije[j];
					lokacije[j] = pom;
				}
			}
		}
	}

	void urediOpad() {
		T* pom;
		cout << "Opadajuce sortiranje. " << endl;
		for (int i = 0; i < now - 1; i++)
		{
			for (int j = i+1; j < now; j++)
			{
				if (lokacije[i]->vratiT() < lokacije[j]->vratiT()) {
					pom = lokacije[i];
					lokacije[i] = lokacije[j];
					lokacije[j] = pom;
				}
			}
		}
	}

	void ispisi() {
		for (int i = 0; i < now; i++)
		{
			if (lokacije[i] != 0) {
				cout << *lokacije[i];
			}
		}
	}
	void opasnost(char* ime) {
		ofstream f2(ime);
		if (!f2.good())
			throw "Neispravno smestanje u skladistu.";
		f2 << now << endl;
		for (int i = 0; i < now; i++)
		{
		f2 <<*lokacije[i];
		}
		f2.close();
	}

	void proslaOpasnost (char* ime) {
		ifstream ulaz(ime);
		if (!ulaz.is_open())
			throw "Vracanje kontejnera je neuspesno.";
		delete[] lokacije;
		lokacije = 0;
		ulaz >> now;
		if (!ulaz.good())
			throw "Vracanje kontejnera je neuspesno.";
		lokacije = new T*[now];
		for (int i = 0; i < now; i++)
		{
			lokacije[i] = 0;
		}
		T pom;
		for (int i = 0; i<now; i++)
		{
			ulaz >> pom;
			lokacije[i] = new T(pom);
			if (!ulaz.good())
				throw "Vracanje kontejnera je neuspesno.";
		}
		ulaz.close();
	}
	void upisiBin(char* naziv) {
		ofstream izlaz(naziv, ios::out | ios::binary);
		izlaz.write((char*)&now, sizeof(int));
		for (int i = 0; i<now; i++)
			izlaz.write((char*)&lokacije[i], sizeof(int));
		izlaz.close();
	}

	void ucitajBin(char* naziv)
	{
		ifstream ulaz(naziv, ios::in | ios::binary);
		if (!ulaz.is_open())
			throw "Binrna datoteka za citanje nije otvorena.";
		if (now != 0)
			delete[] lokacije;
		ulaz.read((char*)&now, sizeof(int));
		if (!ulaz.good())
			throw "Citanje iz binarne datoteke nije uspelo.";
		lokacije = new T*[now];
		for (int i = 0; i<now; i++)
		{
			ulaz.read((char*)&lokacije[i], sizeof(int));
			if (!ulaz.good())
				throw "Citanje iz binarne datoteke nije uspelo.";
		}
		ulaz.close();
	}
};


class Kontejner
{
public:
	Kontejner();
	Kontejner(Kontejner& k);
	Kontejner(int a);
	~Kontejner();
	inline int	vratiID() { return ID; }
	inline int  vratiT() { return tezina; }
	friend ostream& operator<<(ostream& out, Kontejner& k);
	friend istream& operator>>(istream& in, Kontejner& k);
	//friend ifstream& operator >> (ifstream& ulaz, Kontejner& k);

private:
	int ID;
	int tezina;
	
};

Kontejner::Kontejner()
{
	ID = 0;
}
Kontejner::Kontejner(int a) {
	tezina = a;
	ID = rand();
}
Kontejner::Kontejner(Kontejner& k) {
	tezina = k.tezina;
	ID = k.ID;
}

Kontejner::~Kontejner()
{
}

ostream& operator<<(ostream& out, Kontejner& k) {
	out << "Kontejner: " << k.ID << " " << k.tezina << endl;
	return out;
}
istream& operator >> (istream& in, Kontejner& k) {
	string pom;
	in >> pom >> k.ID >> k.tezina;
	return in;
}
//ifstream& operator >> (ifstream& ulaz, Kontejner& k) {
//	string pom;
//	ulaz  >> k.ID >> k.tezina;
//	return ulaz;
//}