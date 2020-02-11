#include "Header.h"



void main()
{
	try
	{
		Hotel<Kutija, 20> H1;
		Kutija k1("dijamant",20);
		Kutija k2("zlato", 10);
		Kutija k3("srebro", 32);

		H1.zatrazi_sef(k1);
		H1.zatrazi_sef(k2);
		H1.zatrazi_sef(k3);
		H1.Preuzmi(0);

		H1.Prikazi();
		cout << "Prosecan rent: " << H1.prosecan_Rent() << endl;
	}

	catch (char* x) {
		cout << "Upozorenje menadzeru hotela: " << x << endl;
	}
}