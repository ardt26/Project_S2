#include <bits/stdc++.h>
using namespace std;

int main()
{
	int banyak;

	cout<<"Masukkan banyaknya angka : "; cin>>banyak;

	int angka[banyak],pilih,temp;
	int l,m;

	int *pointer;

	pointer = angka;

	for (int i = 0; i < banyak; ++i)
	{
		cout<<"Angka "<<i+1<<" = "; cin>>angka[i];
	}

	cout<<"\n1. Min\n2. Max\n\tPilih (1/2) : "; cin>>pilih;

	switch(pilih)
	{
		case 1:
			for(l=0; l<banyak-1; l++)
			{
				for(m=0; m<banyak-1-l; m++)
				{
					if(angka[m] > angka[m+1])
					{
						temp = angka[m];
						angka[m] = angka[m+1];
						angka[m+1] = temp;
					}
				}
			}
			cout<<"Nilai Minimum = "<< *(pointer);
			break;

		case 2:
			for(l=0; l<banyak-1; l++)
			{
				for(m=0; m<banyak-1-l; m++)
				{
					if(angka[m] < angka[m+1])
					{
						temp = angka[m];
						angka[m] = angka[m+1];
						angka[m+1] = temp;
					}
				}
			}
			cout<<"Nilai Maximum = "<< *(pointer);
			break;
	}
}