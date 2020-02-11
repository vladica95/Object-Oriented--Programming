#pragma once
#include<iostream>
#include <string>
using namespace std;

class Materijal {
protected:
	string naziv;
	string rok_trajanja;
	float tezina;
public:
	Materijal();
	Materijal(string s1, string s2, int a);
	Materijal(Materijal& m);
	~Materijal();
	virtual void ispisi() = 0;
	virtual float vratiT() = 0;

};
class Skladiste {
private:
	char* naziv;
	int kapacitet;
	Materijal** niz;
	int now;
public:
	Skladiste(char* x, int a);
	~Skladiste();
	void stampaj();
	void dodaj(Materijal& m);

};
class Praskasti : public Materijal {
public:
	Praskasti();
	Praskasti(string s1, string s2, int a);
	Praskasti(Praskasti& p);
	void ispisi();
	inline float vratiT() {	return tezina; }

};
class Tecni : public Materijal {
private:
	float zapremina;
	float spec_masa;
public:
	Tecni();
	Tecni(string s1, string s2, int a, int b);
	Tecni(Tecni& t);
	float rac_masu();
	inline float vratiT() { return tezina; }
	void ispisi();

};