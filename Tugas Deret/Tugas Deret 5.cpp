#include <iostream>
using namespace std;

int main ()
{
	int tanda, i, deret, a=2, b=3;
	float S=0, rumus;
	
	cout<<"Masukkan batas deret : "; cin>>deret;
	cout<<"S = ";
	
	for (i=1; i<=deret; i++)
	{
		if(i%3==0)
			{tanda=-1;}
		else
			{tanda=1;}
		
		if(i>1)
		{a=a*2; b=b*3;}	
		
		rumus=tanda * (a/(b*1.0));
		cout<<tanda*a<<"/"<<b;
		if(i<deret)
			{cout<<" + ";}
		S=S+rumus;
	}
	cout<<"\nS = "<<S;
	
	
}
