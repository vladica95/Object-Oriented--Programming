#pragma once
#include <iostream>
using namespace std;




class Cvet
{
public:
	Cvet();
	Cvet(int a);
	Cvet(Cvet& c);
	virtual ~Cvet();
	virtual void povecaj_t()=0;
	virtual int vratiTip() = 0;
	virtual float vratiTezinu() = 0;
	virtual void smanjiT() = 0;
	virtual void izgubi_tezinu() = 0;
	virtual void ispisi() = 0;
protected:
	float tezina;
	int tip;
};

class Basta
{
public:
	Basta(int a);
	~Basta();
	void dan();
	void noc();
	void zasadi(Cvet& c, int a, int b);
	void stampaj();
	float Tezina();
private:
	Cvet*** mat;
	int dim;
};

class Ruza : public Cvet
{
 
	//int tezina;
public:
	Ruza();
	Ruza(int a);
	Ruza(Ruza& r);
	inline int vratiTip() { return tip; }
	~Ruza();
    void povecaj_t();
	void izgubi_tezinu();
	inline	float vratiTezinu() { return tezina; }
	void smanjiT();
	void ispisi();
	friend ostream& operator<<(ostream& out, Ruza& r);
};
class Cvetojed : public Cvet
{

	//int tezina;
public:
	Cvetojed();
	Cvetojed(int a);
	Cvetojed(Cvetojed& c);
	~Cvetojed();
	inline int vratiTip() { return tip; }
	inline	float vratiTezinu() { return tezina; }
	void izgubi_tezinu();
	void povecaj_t();
	void smanjiT();
	void ispisi();
	friend ostream& operator<<(ostream& out, Cvetojed& c);
};
class Zumbul : public Cvet
{

	//int tezina;
public:
	Zumbul();
	Zumbul(int a);
	Zumbul(Zumbul& z);
	~Zumbul();
	inline	float vratiTezinu() { return tezina; }
	inline int vratiTip() { return tip; }
	void povecaj_t();
	void smanjiT();
	void izgubi_tezinu();
	void ispisi();
	friend ostream& operator<<(ostream& out, Zumbul& z);
};