#include <bits/stdc++.h>
using namespace std;

int main()
{
	int menu,b = 0,awal,akhir;
	char kalimat[100],hide,*poin,lagi,search;
	poin = kalimat;
	bool ada = false;
	do
	{
		cout<<"Menu :\n1. Input\n2. Output\n3. Hasil\n4. Exit\nPilih (1..4) : "; cin>>menu;
		switch(menu)
		{
			case 1:
				cin.ignore();
				cout<<"Kalimat 		: "; cin.getline(kalimat,100);
				cout<<"Sembunyikan huruf	: ";cin>>hide;
				break;
				
			case 2:
				cout<<"Kalimat 		: ";
				for (unsigned int i = 0; i < strlen(kalimat); i++)
				{
					if (kalimat[i] == hide)
					{
						*(poin+i) = '*';
						cout<<kalimat[i];
					}
					else
					{
					cout<<kalimat[i];
					}
				}
				for (unsigned int i = 0; i < strlen(kalimat); i++)
				{
					if (kalimat[i] == '*')
					{
						kalimat[i] = hide;
					}
				}
				break;
			case 3:
				int j;
				cout<<"Cari 	: ";cin>>search;
				awal = 0;
				for (unsigned j = 0; j < strlen(kalimat); j++)
				{	
					if (kalimat[j] == ' ')
					{

						akhir = j;
					
						for (int k = awal; k < akhir; ++k)
						{
							if (*(poin+k)== search)
							{
								ada = true;
							}
						}
						if (ada)
						{
							for (int l = awal; l < akhir; ++l)
							{
								
								cout<<kalimat[l];
							}
							cout<<",";
							b++;
						}
						awal = j + 1;
					}
					ada = false;
				}
				for (unsigned k = awal; k < strlen(kalimat); k++)
				{
					if (*(poin+k)== search)
					{
						ada = true;	
					}
					akhir = k;
				}
				if (ada)
				{
					for (int l = awal; l < akhir+1; ++l)
					{
						cout<<kalimat[l];
					}
					b++;
				}
				cout<<endl<<"Terdapat "<<b<<" kata yang memiliki huruf "<<search;
				break;

			case 4:
				cout<<"\t\tTerima Kasih";
				exit(0);
		}
		
		cout<<"\n\nKembali ke menu? "; cin>>lagi;
		if (lagi == 'y')
		{
			system("cls");
		}
	}while(lagi == 'y');	
}
