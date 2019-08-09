#include <bits/stdc++.h>
using namespace std;

int menu,mhs_max ,jum_mhs,a = 0,b = 0;
string nama_file = "Data Pendaftar.txt",by_daftar,ext = "Banyak ";
char balik;

struct nilai{
	int ma,fi,ki,bi,t_poin;
};

struct bio{
	string nama,sekolah;
	nilai mapel,poin;
}biodata[100], temp;

ofstream file;
ifstream files;

void ambil_file();
void sorting_nama();
void sorting_poin();
void sorting_ma();
void sorting_fi();
void sorting_ki();
void sorting_bi();

int main()
{
	do
	{
		cout<<"Menu :\n1. Input\n2. Output\n3. Hasil\n4. Lolos\nPilih (1..4) = "; cin>>menu;
		by_daftar = ext.append(nama_file);
		switch (menu)
		{
			case 1:
				cout<<"==================== Menu Input ====================\n\n";
				cout<<"\nMasukkan jumlah mahasiswa yang ingin diterima : "; cin>>mhs_max;
				cout<<"Masukkan jumlah pendaftar : "; cin>>jum_mhs;
				

				file.open(nama_file.c_str(),ios::app);
				for (int i = 0; i < jum_mhs; i++)
				{
					cin.ignore();
					cout<<i+1<<".";
					
					cout<<"\tNama\t\t: ";
					getline(cin,biodata[i].nama);
					file<<biodata[i].nama<<endl;
					
					cout<<"\tAsal Sekolah\t: ";
					getline(cin,biodata[i].sekolah);
					file<<biodata[i].sekolah<<endl;
					
					cout<<"\tNilai\t\t: \n";

					cout<<"\t\tMatematika\t: ";
					cin>>biodata[i].mapel.ma;
					file<<biodata[i].mapel.ma<<endl;
					
					cout<<"\t\tFisika\t\t: ";
					cin>>biodata[i].mapel.fi;
					file<<biodata[i].mapel.fi<<endl;

					cout<<"\t\tKimia\t\t: ";
					cin>>biodata[i].mapel.ki;
					file<<biodata[i].mapel.ki<<endl;

					cout<<"\t\tBiologi\t\t: ";
					cin>>biodata[i].mapel.bi;
					file<<biodata[i].mapel.bi<<endl;
						
				}
				file.close();

				files.open(by_daftar.c_str());
				files>>a;
				files.close();

				file.open(by_daftar.c_str());
				a+=jum_mhs;
				file<<a;
				file.close();

				files.open("Max Diterima.txt");
				files>>b;
				files.close();

				file.open("Max Diterima.txt");
				b+=mhs_max;
				file<<b;
				file.close();
				break;

			case 2:	
				ambil_file();

				files.open(nama_file.c_str());
				for (int i = 0; i < a; ++i)
				{
					getline(files,biodata[i].nama);
					getline(files,biodata[i].sekolah);
					files>>biodata[i].mapel.ma;
					files>>biodata[i].mapel.fi;
					files>>biodata[i].mapel.ki;
					files>>biodata[i].mapel.bi;
					files.ignore();
				}
				files.close();
				sorting_nama();

				for (int i = 0; i < a; ++i)
				{
					cout<<i+1<<".";
					cout<<"\tNama\t\t: "<<biodata[i].nama<<endl;
					cout<<"\tAsal Sekolah\t: "<<biodata[i].sekolah<<endl;
					cout<<"\tNilai\t\t: \n";
					cout<<"\t\tMatematika\t: "<<biodata[i].mapel.ma<<endl;					
					cout<<"\t\tFisika\t\t: "<<biodata[i].mapel.fi<<endl;
					cout<<"\t\tKimia\t\t: "<<biodata[i].mapel.ki<<endl;
					cout<<"\t\tBiologi\t\t: "<<biodata[i].mapel.bi<<endl;
				}
				break;

			case 3:
				sorting_ma();
				sorting_fi();
				sorting_ki();
				sorting_bi();
				ambil_file();
				sorting_nama();
				for (int i = 0; i < a; ++i)
				{
					cout<<i+1<<".";
					cout<<"\tNama\t\t: "<<biodata[i].nama<<endl;
					cout<<"\tAsal Sekolah\t: "<<biodata[i].sekolah<<endl;
					cout<<"\tNilai\t\t: \n";
					cout<<"\t\tMatematika\t: "<<biodata[i].poin.ma<<endl;					
					cout<<"\t\tFisika\t\t: "<<biodata[i].poin.fi<<endl;
					cout<<"\t\tKimia\t\t: "<<biodata[i].poin.ki<<endl;
					cout<<"\t\tBiologi\t\t: "<<biodata[i].poin.bi<<endl;
				}
				break;

			case 4:
				ambil_file();
				for (int i = 0; i < a; ++i)
				{
					biodata[i].poin.t_poin = biodata[i].poin.ma + biodata[i].poin.fi + biodata[i].poin.ki + biodata[i].poin.bi;
				}
				sorting_poin();
				for (int i = 0; i < b; ++i)
				{
					cout<<i+1<<".";
					cout<<"\tNama\t\t: "<<biodata[i].nama<<endl;
					cout<<"\tAsal Sekolah\t: "<<biodata[i].sekolah<<endl;
					cout<<"\tNilai\t\t: \n";
					cout<<"\t\tMatematika\t: "<<biodata[i].mapel.ma<<endl;					
					cout<<"\t\tFisika\t\t: "<<biodata[i].mapel.fi<<endl;
					cout<<"\t\tKimia\t\t: "<<biodata[i].mapel.ki<<endl;
					cout<<"\t\tBiologi\t\t: "<<biodata[i].mapel.bi<<endl;
				}
				break;

			default:
				cout<<"\nMohon membaca aturan dengan benar\n";
				break;
		}

		cout<<"Kembali ke menu (y/n)? ";cin>>balik;

		if (balik == 'y')
		{
			system("cls");
		}
		else if(balik == 'n')
		{
			cout<<"Terima Kasih..."<<endl;
			system("pause");
			exit(0);
		}
	}while(balik=='y');
}

void ambil_file()
{
	files.open(by_daftar.c_str());
	files>>a;
	files.close();

	files.open("Max Diterima.txt");
	files>>b;
	files.close();
}

void sorting_nama()
{
	int l,m;
	for(l=0; l<a-1; l++)
	{
		for(m=0; m<a-1-l; m++)
		{
			if(biodata[m].nama > biodata[m+1].nama)
			{
				temp = biodata[m];
				biodata[m] = biodata[m+1];
				biodata[m+1] = temp;
			}
		}
	}
}

void sorting_poin()
{
	int l,m;
	for(l=0; l<a-1; l++)
	{
		for(m=0; m<a-1-l; m++)
		{
			if(biodata[m].poin.t_poin < biodata[m+1].poin.t_poin)
			{
				temp = biodata[m];
				biodata[m] = biodata[m+1];
				biodata[m+1] = temp;
			}
		}
	}
}

void sorting_ma()
{
	ambil_file();
	int l,m;
	for(l=0; l<a-1; l++)
	{
		for(m=0; m<a-1-l; m++)
		{
			if(biodata[m].mapel.ma < biodata[m+1].mapel.ma)
			{
				temp = biodata[m];
				biodata[m] = biodata[m+1];
				biodata[m+1] = temp;
			}
		}
	}

	biodata[0].poin.ma = b;

	for (int i = 0; i < a; ++i)
	{
		if (biodata[i].mapel.ma == biodata[i+1].mapel.ma)
		{
			biodata[i+1].poin.ma = b;
		}

		else if (biodata[i].mapel.ma != biodata[i+1].mapel.ma)
		{
			biodata[i+1].poin.ma = b-1;
			b--;
		}
	}
}

void sorting_fi()
{
	ambil_file();
	int l,m;
	for(l=0; l<a-1; l++)
	{
		for(m=0; m<a-1-l; m++)
		{
			if(biodata[m].mapel.fi < biodata[m+1].mapel.fi)
			{
				temp = biodata[m];
				biodata[m] = biodata[m+1];
				biodata[m+1] = temp;
			}
		}
	}

	biodata[0].poin.fi = b;

	for (int i = 0; i < a; ++i)
	{
		if (biodata[i].mapel.fi == biodata[i+1].mapel.fi)
		{
			biodata[i+1].poin.fi = b;
		}

		else if (biodata[i].mapel.fi != biodata[i+1].mapel.fi)
		{
			biodata[i+1].poin.fi = b-1;
			b--;
		}
	}
}

void sorting_ki()
{
	ambil_file();
	int l,m;
	for(l=0; l<a-1; l++)
	{
		for(m=0; m<a-1-l; m++)
		{
			if(biodata[m].mapel.ki < biodata[m+1].mapel.ki)
			{
				temp = biodata[m];
				biodata[m] = biodata[m+1];
				biodata[m+1] = temp;
			}
		}
	}

	biodata[0].poin.ki = b;

	for (int i = 0; i < a; ++i)
	{
		if (biodata[i].mapel.ki == biodata[i+1].mapel.ki)
		{
			biodata[i+1].poin.ki = b;
		}

		else if (biodata[i].mapel.ki != biodata[i+1].mapel.ki)
		{
			biodata[i+1].poin.ki = b-1;
			b--;
		}
	}
}

void sorting_bi()
{
	ambil_file();
	int l,m;
	for(l=0; l<a-1; l++)
	{
		for(m=0; m<a-1-l; m++)
		{
			if(biodata[m].mapel.bi < biodata[m+1].mapel.bi)
			{
				temp = biodata[m];
				biodata[m] = biodata[m+1];
				biodata[m+1] = temp;
			}
		}
	}

	biodata[0].poin.bi = b;

	for (int i = 0; i < a; ++i)
	{
		if (biodata[i].mapel.bi == biodata[i+1].mapel.bi)
		{
			biodata[i+1].poin.bi = b;
		}

		else if (biodata[i].mapel.bi != biodata[i+1].mapel.bi)
		{
			biodata[i+1].poin.bi = b-1;
			b--;
		}
	}
}