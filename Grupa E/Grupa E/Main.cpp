#include "Header.h"





void main(){

	try {
		Traka<Cokolada, 20> T1;

		Cokolada c1;
		//cin >> c1;
		Cokolada c2;
		//cin >> c2;
		Cokolada c3;
		//cin >> c3;
		Cokolada c4;
		//cin >> c4;
		T1.dodaj(c1);
		T1.dodaj(c2);
		T1.dodaj(c3);
		T1.dodaj(c4);
		cout << T1.stanje() << endl;
		T1.trazi_Def();
		T1.pisi_na_ekran();

	}
	catch(char* x){
		cout << "Upozorenje: " << x << endl;
	}
}



