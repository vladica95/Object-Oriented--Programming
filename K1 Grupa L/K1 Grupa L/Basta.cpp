#include "Header.h"

Basta::Basta(int a) {
	dim = a;
	mat = new Cvet**[dim];
	for (int i = 0; i < dim; i++)
	{
		mat[i] = new Cvet*[dim];
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			mat[i][j] = 0;
		}
	}
}
Basta::~Basta() {
	for (int i = 0;i < dim;i++)
		delete[] mat[i];
	delete[] mat;
	mat = 0;
}
void Basta::dan() {
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (mat[i][j] != 0) {
				mat[i][j]->povecaj_t();
			}
		}
	}
}
void Basta::noc() {
	int q=0;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (mat[i][j] != 0) {
				if (mat[i][j]->vratiTip() == 3) {
					if (mat[i - 1][j] != 0) {
						mat[i - 1][j]->smanjiT();
						q = 1;
					}
					if (mat[i + 1][j] != 0) {
						mat[i + 1][j]->smanjiT();
						q = 1;
					}
					if (mat[i][j - 1] != 0) {
						mat[i][j - 1]->smanjiT();
						q = 1;
					}
					if (mat[i][j + 1] != 0) {
						mat[i][j + 1]->smanjiT();
						q = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (mat[i][j] != 0) {
				if (q = 0) {
					mat[i][j]->izgubi_tezinu();
				}
				else if (q == 1) {
					if (mat[i][j]->vratiTip() != 3) {
						mat[i][j]->izgubi_tezinu();
					}
				}
			}
		}
	}
}
void Basta::zasadi(Cvet& c, int a, int b) {
			if (mat[a][b] == 0) {
				mat[a][b] = &c;
			}
		}
void Basta::stampaj() {
	cout << "Basta :" << endl;
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j<dim; j++)
		{
			if (mat[i][j] == 0)
			{
				cout << " ";
			}
			else if (mat[i][j]->vratiTip() == 1)
			{
				cout << "R";
			}
			else if (mat[i][j]->vratiTip() == 2)
			{
				cout << "Z";
			}
			else
				if (mat[i][j]->vratiTip() == 3)
					cout << "C";
		}
		cout << endl << endl;
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (mat[i][j] != 0) {
				mat[i][j]->ispisi();
			}
		}
	}
}
float Basta::Tezina() {
	float t = 0;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (mat[i][j] != 0) {
				t += mat[i][j]->vratiTezinu();
			}
		}
	}
	return t;
}