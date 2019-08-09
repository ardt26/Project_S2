#include <iostream>
using namespace std;

int main ()
{
	int tanda, i, deret;
	float S=0, rumus;
	
	cout<<"Masukkan batas deret : "; cin>>deret;
	cout<<"S = ";
	for (i=1; i<=deret; i++)
	{
		if(i%4==0)
			{tanda=1;}
		else
			{tanda=-1;}
			
		rumus=tanda * 1/(i*2.0);
		cout<<tanda<<"/"<<i*2;
		if(i<deret)
			{cout<<" + ";}
		S=S+rumus;
	}
	cout<<"\nS = "<<S;
	
	
}
