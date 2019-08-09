#include <bits/stdc++.h>
using namespace std;

int rekursi(int a, int b);

int main()
{
	int bilangan,mod,hasil;
	cout<<"Bilangan	: "; cin>>bilangan;
	cout<<"Mod		: "; cin>>mod;
	cout<<"Hasil = ";
	hasil = rekursi(bilangan,mod);
	cout<<" = "<<hasil;
}

int rekursi(int a, int b)
{
	if(b == 0)
	{ 
		cout<<a%(b+1);
		return 0;
	}
	else
	{	
		if (b > 1)
		{
			cout<<a%b<<" + ";
		}
		return (a%b + rekursi(a/b,b-1));
	}
}
