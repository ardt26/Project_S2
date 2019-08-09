#include <bits/stdc++.h>
using namespace std;

struct data{
	int jam,durasi;
	string jurusan;
	}rapat[100],temp,hasil[100];

int menu,jum_jur,j;
char lagi;

void sort();
void hasil_d();

ofstream simpan;
ifstream ambil;

int main()
{
	do
	{
		cout<<"Menu :\n1. Input\n2. Output\n3. Hasil\n4. Exit\nPilih (1..4) : "; cin>>menu;
		switch(menu)
		{
			case 1:
				cout<<"Jumlah Jurusan lain = "; cin>>jum_jur;
				cout<<endl;
				simpan.open("Data Rapat Jurusan.txt",ios::app);
				simpan<<jum_jur<<endl;
				for (int i = 0; i < jum_jur; i++)
				{
					cin.ignore();
					cout<<"No. "<<i+1<<endl;
					cout<<"Jurusan		: "; getline(cin,rapat[i].jurusan);
					simpan<<rapat[i].jurusan<<endl;
					cout<<"Jam		: ";cin>>rapat[i].jam;
					simpan<<rapat[i].jam<<endl;
					cout<<"Durasi		: ";cin>>rapat[i].durasi;
					simpan<<rapat[i].durasi<<endl;
					cout<<endl;
				}
				simpan.close();
				break;
				
			case 2:
				ambil.open("Data Rapat Jurusan.txt");
				ambil>>jum_jur;
				for (int i = 0; i < jum_jur; i++)
				{
					ambil.ignore();
					getline(ambil,rapat[i].jurusan);
					ambil>>rapat[i].jam;
					ambil>>rapat[i].durasi;
					
				}
				cout<<endl;
				sort();
				for (int i = 0; i < jum_jur; i++)
				{
					cout<<"No. "<<i+1<<endl;
					cout<<"Jurusan		: "<<rapat[i].jurusan<<endl;
					cout<<"Jam		: "<<rapat[i].jam<<endl;
					cout<<"Durasi		: "<<rapat[i].durasi<<" Jam"<<endl;
				}
				break;
				
			case 3:
			
				hasil_d();
				cout<<endl;
				simpan.open("Data Rapat Jurusan FIX.txt");
				simpan<<j<<endl;
				for (int i = 0; i < j; i++)
				{
					cout<<"No. "<<i+1<<endl;
					cout<<"Jurusan		: "<<hasil[i].jurusan<<endl;
					simpan<<hasil[i].jurusan<<endl;
					cout<<"Jam		: "<<hasil[i].jam<<endl;
					simpan<<hasil[i].jam<<endl;
					cout<<"Durasi		: "<<hasil[i].durasi<<" Jam"<<endl;
					simpan<<hasil[i].durasi<<endl;
				}
				cout<<endl<<"IF dapat menjalin kerja sama dengan "<<j<<" jurusan lain"<<endl;
				break;

			case 4:
				cout<<"\t\tTerima Kasih";
				exit(0);
					break;
							
		}
		cout<<"\nKembali ke menu? "; cin>>lagi;
		if (lagi == 'y')
		{
			system("cls");
		}
	}while(lagi == 'y');
}

void sort()
{
	for (int i = 0; i < jum_jur-1; i++)
	{
		for (int j = 0; j < jum_jur-1-i; j++)
		{
			if (rapat[j].jam > rapat[j+1].jam)
			{
				temp = rapat[j];
				rapat[j] = rapat[j+1];
				rapat[j+1] = temp;
			}
		}
	}
}

void hasil_d()
{
	j = 1;
	hasil[0].jurusan = rapat[0].jurusan;
	hasil[0].jam = rapat[0].jam;
	hasil[0].durasi = rapat[0].durasi;
	
	for (int i = 0; i < jum_jur; i++)
	{
		if (rapat[i].jam + rapat[i].durasi <= rapat[i+1].jam)
		{
			hasil[j].jurusan = rapat[i+1].jurusan;
			hasil[j].jam = rapat[i+1].jam;
			hasil[j].durasi = rapat[i+1].durasi;
			j++;
		}
	}
	
}
