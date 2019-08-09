#include <iostream>
using namespace std;

int main ()
{
	int S=0, rumus, tanda, i, deret;
	
	cout<<"Masukkan batas deret : "; cin>>deret;
	cout<<"S = ";
	for (i=1; i<=deret; i++)
	{
		if(i%2==0)
			{tanda=-1;}
		else
			{tanda=1;}
			
		rumus=(2*i-1)*tanda;
		cout<<rumus;
		if(i<deret)
			{cout<<" + ";}
		S=S+rumus;
	}
	cout<<"\nS = "<<S;
}
