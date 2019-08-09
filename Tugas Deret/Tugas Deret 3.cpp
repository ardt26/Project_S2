#include <iostream>
using namespace std;

int main ()
{
	int tanda, i;
	float S=0, rumus;
	
	cout<<"S = ";
	for (i=1; i<=100; i++)
	{
		if(i%2==0)
			{tanda=-1;}
		else
			{tanda=1;}
			
		rumus=tanda * 1/(i*1.0);
		cout<<tanda<<"/"<<i;
		if(i<100)
			{cout<<" + ";}
		S=S+rumus;
	}
	cout<<"\n\nS = "<<S;
	
}
