#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;

template <class T,int dim>
class Traka
{

private:
	T** pokretna_traka;
	string ime;
	int now;



public:
	Traka() {
		now = 0;
		cout << "Unesi ime trake: " << endl;
		cin >> ime;
		pokretna_traka = new T*[dim];
			for (int i = 0; i < dim; i++)
			{
				pokretna_traka[i] = 0;
			}
	}
	~Traka() {
		delete[] pokretna_traka;
		pokretna_traka = 0;
	}
	int stanje() {
		return now;
	}
	void dodaj(T& t) {
		if (now < dim)
		{
			if (pokretna_traka[now] == 0) {
				pokretna_traka[now] = &t;
				now++;
				cout << "Proizvod uspesno dodat." << endl;
			}
			else {
				throw "Proizvod neuspesno dodat.";
			}
		}
		else {
				throw "Nema vise mesta na traci.";
			}
		
	}
	void trazi_Def() {
		for (int i = 0; i < now; i++)
		{
			if (pokretna_traka[i]->defektnost() != 1)
			{
				pokretna_traka[i] = 0;
			}
		}
	}



	void pisi_na_ekran() {
		cout << "Pokretna traka " << ime << " : " << endl;
		for (int i = 0; i < now; i++)
		{
			if (pokretna_traka[i] != 0) {
				cout <<*pokretna_traka[i];
			}
		}
	}


};

class Cokolada
{
private:
	string tip;
	int defekt;
	string ime;
	int tezina;
	int barkod[5];
	string vreme_proizvodnje;
public:
    
	Cokolada() {
		srand(time(NULL));
		int x;
		cout << "Unesi da li je defektna cokolada: " << endl;
		cin >> x;
		defekt = x % 2;
		for (int i = 0; i < 5; i++)
		{
			barkod[i] = rand() % 10;
		}
	}
	~Cokolada() {

	}
	int defektnost() { 
		return defekt; 
	}
	
	friend ostream& operator<<(ostream& out, Cokolada& c) {
		out << "Cokolada :" << "Ime: " << c.ime << "  " << "Tip: " << c.tip << "  " << "Tezina: " << c.tezina
			<< "  " << "Vreme proizvodnje: " << c.vreme_proizvodnje << " " << "Bar kod :";
		for (int i = 0; i < 5; i++)
		{
		out  << c.barkod[i];
		}
		cout << endl;
		return out;
	}
	friend istream& operator >> (istream& in, Cokolada& c) {
		cout << "Unesi ime proizvoda: " << endl;
		in >> c.ime;
		cout << "Unesi tip proizvoda: " << endl;
		in >> c.tip;
		cout << "Unesi tezinu proizvoda: " << endl;
		in >> c.tezina;
		cout << "Unesi vreme proizvodnje: " << endl;
		in >> c.vreme_proizvodnje;
		return in;
	}
};
