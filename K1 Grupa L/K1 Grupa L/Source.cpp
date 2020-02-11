#include"Header.h"



Cvet::Cvet() {
	tezina = 0;
	tip = 0;
}
Cvet::Cvet(int a) {
	tezina = a;
}
Cvet::~Cvet() {

}
Cvet::Cvet(Cvet& c) {
	tezina = c.tezina;
}
void Cvet::povecaj_t() {
	float a = tezina*5.77;
	tezina += a;
}
Ruza::Ruza() :Cvet() {

}
Ruza::Ruza(int a) : Cvet(a) {
	tip = 1;
}
Ruza::Ruza(Ruza& r) {
	tezina = r.tezina;
	tip = r.tip;
}
Ruza::~Ruza() {

}
void Ruza::izgubi_tezinu() {
	float a = tezina*0.14/100;
	tezina = tezina - a;
	
}
void Ruza::povecaj_t() {
	float a = tezina*5.77/100;
	tezina += a;
}
void Ruza::smanjiT() {
	float a = tezina / 4;
	tezina = tezina - a;
}
void Ruza::ispisi() {
	cout << "Tezina ruze je: " << tezina << endl;
}
ostream& operator<<(ostream& out, Ruza& r) {
	out << "Tezina ruze je: " << r.tezina << endl;
	return out;
}
Zumbul::Zumbul() : Cvet() {

}
Zumbul::Zumbul(int a) : Cvet(a) {
	tip = 2;
}
Zumbul::Zumbul(Zumbul& z) {
	tezina = z.tezina;
	tip = z.tip;
}
Zumbul::~Zumbul() {

}
void Zumbul::povecaj_t() {
	float a = tezina*5.77/100;
	tezina += a;
}
void Zumbul::smanjiT() {
	float a = tezina / 4;
	tezina = tezina - a;
}
void Zumbul::izgubi_tezinu() {
	float a = tezina*2.35/100;
	tezina -= a;
}
void Zumbul::ispisi() {
	cout << "Tezina zumbula je: " << tezina << endl;
}

ostream& operator<<(ostream& out, Zumbul& z) {
	out << "Tezina zumbula je: " << z.tezina << endl;
	return out;
}
Cvetojed::Cvetojed() : Cvet() {

}
Cvetojed::Cvetojed(int a) : Cvet(a) {
	tip = 3;
}
Cvetojed::Cvetojed(Cvetojed& c) {
	tezina = c.tezina;
	tip = c.tip;
}
Cvetojed::~Cvetojed() {

}
void Cvetojed::izgubi_tezinu() {
	float a = tezina*8/100;
	tezina -= a;

}
void Cvetojed::povecaj_t() {
	float a = tezina*5.77 / 100;
	tezina += a;
}
void Cvetojed::smanjiT() {

}
void Cvetojed::ispisi() {
	cout << "Tezina cvetojeda je: " << tezina << endl;
}
ostream& operator<<(ostream& out, Cvetojed& c) {
	out << "Tezina cvetojeda je: " << c.tezina << endl;
	return out;
}