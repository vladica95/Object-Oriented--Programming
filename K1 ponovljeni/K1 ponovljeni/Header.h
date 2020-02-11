#pragma once






class Entitet
{
protected:
	double Energija;
	int tip;

public:
	Entitet();
	Entitet(Entitet& e);
	virtual ~Entitet();
	virtual void uvecaj(int a) = 0;
	virtual void uvecaj(int a, int b) {}
	virtual void smanji() = 0;
	virtual void smanji(int a, int b) {}
	virtual void postaviE(int a, int b) {}
	virtual void ispisi() = 0;
	virtual double vratiE() = 0;
	virtual int vratiTip() = 0;



};

class Polje 
{
	int dim;
	Entitet*** polje;

public:
	Polje(int a);
	~Polje();
	void dodaj(Entitet& e, int a, int b);
	void good();
	void bad();
	void stampaj();
	//void UcitajIZTXT(char* ime);


};

class Ajkula : public Entitet
{
public:
	Ajkula();
	Ajkula(Ajkula& a);
	~Ajkula();
	void uvecaj(int a);
	void smanji();
	void smanji(int a, int b);
	void ispisi();
	inline double vratiE() {  return Energija;  }
	inline int vratiTip() {  return tip;	}
};

class Marsovac : public Entitet
{
public:
	Marsovac();
	Marsovac(Marsovac& m);
	~Marsovac();
	void postaviE(int a, int b);
	void uvecaj(int a);
	void smanji();
	void ispisi();
	inline double vratiE() { return Energija; }
	inline int vratiTip() { return tip; }
};

class Ruza : public Entitet
{
public:
	Ruza();
	Ruza(Ruza& r);
	~Ruza();
	void uvecaj(int a);
	void uvecaj(int a, int b);
	void smanji();
	void ispisi();
	inline double vratiE() { return Energija; }
	inline int vratiTip() { return tip; }
};