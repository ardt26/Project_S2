#include <bits/stdc++.h>
using namespace std;

int rekursi(int a, int b, int c, int d);
int b(int a, int b);
int main()
{
	int bil, naik, pangkat,berhenti = 0,hasil;
	cout<< "bilangan : "; cin>> bil;
	cout<< "naik : "; cin>> naik;
	cout<< "pangkat : "; cin>> pangkat;
	hasil = rekursi(bil,naik,pangkat,berhenti);

	cout<< endl << "hasil : " << hasil;
	return 0;
}

int rekursi(int bil, int naik, int pangkat, int berhenti){
	if (berhenti == pangkat)
	{
		return bil * b(naik, (pangkat-(pangkat-berhenti)));
	}
	else
	{
		return bil * b(naik, (pangkat-(pangkat-berhenti))) + rekursi(bil,naik,pangkat,(berhenti+1));
	}
}

int b(int naik, int b){
	int hasil = 1;
	for (int i = 0; i < b; ++i)
	{
		hasil = hasil * naik;
	}

	return hasil;
}