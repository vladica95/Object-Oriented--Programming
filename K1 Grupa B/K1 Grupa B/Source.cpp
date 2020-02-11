#include"Header.h"





Materijal::Materijal() {
	tezina = 0;
	rok_trajanja = " ";
	naziv = " ";
}
Materijal::Materijal(string s1, string s2, int a) {
	naziv = s1;
	rok_trajanja = s2;
	tezina = a;
}
Materijal::Materijal(Materijal& m) {
	naziv = m.naziv;
	rok_trajanja = m.rok_trajanja;
	tezina = m.tezina;
}
Materijal::~Materijal() {

}
Praskasti::Praskasti() :Materijal() {

}
Praskasti::Praskasti(string s1,string s2,int a) : Materijal(s1,s2,a) {

}
Praskasti::Praskasti(Praskasti& p) {
	naziv = p.naziv;
	rok_trajanja = p.rok_trajanja;
	tezina = p.tezina;
}
void Praskasti::ispisi() {
	cout << "Praskasti : " << endl << "Ime: " << naziv << endl << "rok trajanja: " << rok_trajanja
	 	<< endl << "tezina: " << tezina << endl;
}
Tecni::Tecni() :Materijal() {

}
Tecni::Tecni(string s1, string s2, int a, int b) : Materijal(s1, s2,0) {
	zapremina = a;
	spec_masa = b;
	tezina = rac_masu();
}
Tecni::Tecni(Tecni& t) {
	naziv = t.naziv;
	rok_trajanja = t.rok_trajanja;
	zapremina = t.zapremina;
	spec_masa = t.spec_masa;

}
float Tecni::rac_masu() {
	float t;
	t = zapremina*spec_masa;
	return t;
}

void Tecni::ispisi() {
	cout << "Tecni : " << endl << "Ime: " << naziv << endl << "rok trajanja: " << rok_trajanja << endl
	     << "tezina: " << tezina << endl;
}

