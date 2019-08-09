#include <bits/stdc++.h>
using namespace std;

struct isi{
	string tanggal, nama, nim, jurusan, keperluan;
	}info[100],temp;
string nama_file,ext,by_file,cari_file,sort_file,sorted_file,cari,n_file[100],null;
int z, j, a, b, b_data;
bool found;
ifstream bydata;
ifstream x;
ifstream files1;
ofstream files;
ofstream bydata1;

void buat_file();
void buat_file_baru();
void ambil_file();
void sorting_file();
void hasil_sorting();
	void bubble_tanggal();
	void bubble_nama();
	void bubble_nim();
	void bubble_jurusan();
	void bubble_keperluan();
void selection_tanggal();
void selection_nama();
void selection_nim();
void selection_jurusan();
void selection_keperluan();
	void insertion_tanggal();
	void insertion_nama();
	void insertion_nim();
	void insertion_jurusan();
	void insertion_keperluan();
void shell_tanggal();
void shell_nama();
void shell_nim();
void shell_jurusan();
void shell_keperluan();
	void mergeSort_tanggal(int l, int r);
		void merge_tanggal(int l, int m, int r);
	void mergeSort_nama(int l, int r);
		void merge_nama(int l, int m, int r);
	void mergeSort_nim(int l, int r);
		void merge_nim(int l, int m, int r);
	void mergeSort_jurusan(int l, int r);
		void merge_jurusan(int l, int m, int r);
	void mergeSort_keperluan(int l, int r);
		void merge_keperluan(int l, int m, int r);
void quick_tanggal(int first, int last);
void quick_nama(int first, int last);
void quick_nim(int first, int last);
void quick_jurusan(int first, int last);
void quick_keperluan(int first, int last);
	void bin_tanggal();
	void bin_nama();
	void bin_nim();
	void bin_jurusan();
	void bin_keperluan();
void trans_merge_sambung();
void trans_spliting();


int main()
{
	int menu, m_search, m_sort, m_trans, m_src, m_srt,m_file;
	char balik;
	found = false;
	z = 0, j = 1, a = 0, b = 0, b_data = 0;
	do
	{
		ofstream file;
		cout<<"Selamat Datang di Perpustakaan Fakultas Teknik Industri\n";
		cout<<"Menu :\n1. Input\n2. Searching\n3. Transaksi\n4. Exit\nMenu yang dipilih adalah menu ke-";cin>>menu;
		cout<<endl;
		switch (menu)
		{
			case 1:
			cout<<"1. File Lama\n2. File Baru\nPilihan anda adalah "; cin>>m_file;
			if (m_file == 1)
			{
				cout<<"Nama-nama file yang tersedia : \n";
				files.open("Nama-nama File.txt",ios::app);
				files.close();
				files1.open("Nama-nama File.txt");
				for (int i = 0; !files1.eof(); i++)
				{
					files1>>n_file[i];
					cout<<n_file[i]<<endl;
				}
				files1.close();
				cout << "Silahkan pilih file yang tersedia untuk menambahkan isi file (Dengan format): ";
				cin.ignore();
				buat_file();
			}
			else if (m_file == 2)
			{
				cout << "Silahkan Masukkan nama file untuk menyimpan data baru (Dengan format): ";
				cin.ignore();
				buat_file_baru();
			}
			cout<<"==================== Menu Input ====================\n\n";
			cout<<"Masukkan banyaknya data\t: ";cin>>b_data;
			cin.ignore();
			
			file.open(nama_file.c_str(),ios::app);
			for (int i = 0; i < b_data; i++)
			{
				cout<<i+1<<".";
				
				cout<<"\tTanggal \t: ";
				getline(cin,info[i].tanggal);
				file<<info[i].tanggal<<endl;
				
				cout<<"\tNama \t\t: ";
				getline(cin,info[i].nama);
				file<<info[i].nama<<endl;
				
				cout<<"\tNIM\t\t: \n\tContoh : 123180056\n\t";
				getline(cin,info[i].nim);
				file<<info[i].nim<<endl;
				
				cout<<"\tJurusan\t\t: \n\tContoh : IF, SI, TI, Tekim\n\t";
				getline(cin,info[i].jurusan);
				file<<info[i].jurusan<<endl;

				cout<<"\tKeperluan\t: ";
				getline(cin,info[i].keperluan);
				file<<info[i].keperluan<<endl;	
			}
			file.close();

			
			cout<<"Nama file adalah "<<nama_file<<endl;
			ext = "banyak ";
			by_file = ext.append(nama_file);

			x.open(by_file.c_str());
			x>>a;
			x.close();

			bydata1.open(by_file.c_str());
			a+=b_data;
			bydata1<<a;
			bydata1.close();

			cout<<"Kembali ke menu (y/n)? ";cin>>balik;
			break;
			
			case 2:
			cout<<"==================== Menu Searching ====================\n\n";
			cout<<"Menu :\n1. Sequential Search\n2. Binary Search\n3. Kembali ke Menu Utama\nMenu yang dipilih adalah menu ke-";cin>>m_search;
			cout<<endl;
			
			if (m_search == 1)
			{
				cout<<"******************** Sequential Search ********************\n\n";
				cout<<"1. Tanggal\n2. Nama\n3. NIM\n4. Jurusan\n5. Keperluan\nSearch data berdasarkan : ";cin>>m_src;
				
				cout<<"\nNama-nama file yang tersedia : \n";
				files.open("Nama-nama File.txt",ios::app);
				files.close();
				files1.open("Nama-nama File.txt");
				for (int i = 0; !files1.eof(); i++)
				{
					files1>>n_file[i];
					cout<<n_file[i]<<endl;
				}
				files1.close();

				if (m_src == 1)
				{
					ambil_file();
					cout<<"Masukkan tanggal yang ingin dicari : ";cin>>cari;
					for (int i = 0; i < b; i++)
					{
						if (info[i].tanggal == cari)
						{
							cout<<"No."<<j<<" :\n";
							cout<<"Tanggal\t\t: "<<info[i].tanggal<<endl;
							cout<<"Nama\t\t: "<<info[i].nama<<endl;
							cout<<"NIM\t\t: "<<info[i].nim<<endl;
							cout<<"Jurusan\t\t: "<<info[i].jurusan<<endl;
							cout<<"Keperluan\t: "<<info[i].keperluan<<endl<<endl;
							found = true;
							j++;
						}
					}
					
				}
				
				else if (m_src == 2)
				{
					ambil_file();
					cout<<"Masukkan nama yang ingin dicari : ";cin>>cari;
					for (int i = 0; i < b; i++)
					{
						if (info[i].nama == cari)
						{
							cout<<"No."<<j<<" :\n";
							cout<<"Tanggal\t\t: "<<info[i].tanggal<<endl;
							cout<<"Nama\t\t: "<<info[i].nama<<endl;
							cout<<"NIM\t\t: "<<info[i].nim<<endl;
							cout<<"Jurusan\t\t: "<<info[i].jurusan<<endl;
							cout<<"Keperluan\t: "<<info[i].keperluan<<endl<<endl;
							found = true;
							j++;
						}
					}
					
				}
				
				else if (m_src == 3)
				{
					ambil_file();
					cout<<"Masukkan tanggal yang ingin dicari : ";cin>>cari;
					for (int i = 0; i < b; i++)
					{
						if (info[i].nim == cari)
						{
							cout<<"No."<<j<<" :\n";
							cout<<"Tanggal\t\t: "<<info[i].tanggal<<endl;
							cout<<"Nama\t\t: "<<info[i].nama<<endl;
							cout<<"NIM\t\t: "<<info[i].nim<<endl;
							cout<<"Jurusan\t\t: "<<info[i].jurusan<<endl;
							cout<<"Keperluan\t: "<<info[i].keperluan<<endl<<endl;
							found = true;
							j++;
						}
					}
					
				}
				
				else if (m_src == 4)
				{
					ambil_file();
					cout<<"Masukkan tanggal yang ingin dicari : ";cin>>cari;
					for (int i = 0; i < b; i++)
					{
						if (info[i].jurusan == cari)
						{
							cout<<"No."<<j<<" :\n";
							cout<<"Tanggal\t\t: "<<info[i].tanggal<<endl;
							cout<<"Nama\t\t: "<<info[i].nama<<endl;
							cout<<"NIM\t\t: "<<info[i].nim<<endl;
							cout<<"Jurusan\t\t: "<<info[i].jurusan<<endl;
							cout<<"Keperluan\t: "<<info[i].keperluan<<endl<<endl;
							found = true;
							j++;
						}
					}
					
				}
				
				else if (m_src == 5)
				{
					ambil_file();
					cout<<"Masukkan tanggal yang ingin dicari : ";cin>>cari;
					for (int i = 0; i < b; i++)
					{
						if (info[i].keperluan == cari)
						{
							cout<<"No."<<j<<" :\n";
							cout<<"Tanggal\t\t: "<<info[i].tanggal<<endl;
							cout<<"Nama\t\t: "<<info[i].nama<<endl;
							cout<<"NIM\t\t: "<<info[i].nim<<endl;
							cout<<"Jurusan\t\t: "<<info[i].jurusan<<endl;
							cout<<"Keperluan\t: "<<info[i].keperluan<<endl<<endl;
							found = true;
							j++;
						}
					}
					
				}
				
				else
				{
					cout<<"\nMohon membaca aturan dengan benar\n";
				}

				if (found == false)
				{
					cout<<"Data tidak ditemukan\n";
				}

				cout<<"Kembali ke menu (y/n)? ";cin>>balik;
				
			}
			
			else if (m_search == 2)
			{
				cout<<"==================== Menu Sorting ====================\n\n";
				cout<<"Sorting dilakukan terlebih dahulu sebelum melakukan binary search\n";
				cout<<"Menu :\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Shell Sort\n5. Merge Sort\n6. Quick Sort\nMenu yang dipilih adalah menu ke-";cin>>m_sort;
				cout<<endl;
				cout<<"1. Tanggal\n2. Nama\n3. NIM\n4. Jurusan\n5. Keperluan\nSort data berdasarkan : ";cin>>m_srt;
				
				cout<<"Nama-nama file yang tersedia : \n";
				files1.open("Nama-nama File.txt");
				for (int i = 0; !files1.eof(); i++)
				{
					files1>>n_file[i];
					cout<<n_file[i]<<endl;
				}
				files1.close();

				ambil_file();
				ext = "sort ";
				sorted_file = ext.append(cari_file);
				
				if (m_sort == 1)
				{
					if (m_srt == 1)
					{
						bubble_tanggal();
						hasil_sorting();
						bin_tanggal();
					}

					else if (m_srt == 2)
					{
						bubble_nama();
						hasil_sorting();
						bin_nama();
					}

					else if (m_srt == 3)
					{
						bubble_nim();
						hasil_sorting();
						bin_nim();
					}

					else if (m_srt == 4)
					{
						bubble_jurusan();
						hasil_sorting();
						bin_jurusan();
					}

					else if (m_srt == 5)
					{
						bubble_keperluan();
						hasil_sorting();
						bin_keperluan();
					}
				}
				
				else if (m_sort == 2)
				{
					if (m_srt == 1)
					{
						selection_tanggal();
						hasil_sorting();
						bin_tanggal();
					}

					else if (m_srt == 2)
					{
						selection_nama();
						hasil_sorting();
						bin_nama();
					}

					else if (m_srt == 3)
					{
						selection_nim();
						hasil_sorting();
						bin_nim();
					}

					else if (m_srt == 4)
					{
						selection_jurusan();
						hasil_sorting();
						bin_jurusan();
					}

					else if (m_srt == 5)
					{
						selection_keperluan();
						hasil_sorting();
						bin_keperluan();
					}
				}
				
				else if (m_sort == 3)
				{
					if (m_srt == 1)
					{
						insertion_tanggal();
						hasil_sorting();
						bin_tanggal();
					}

					else if (m_srt == 2)
					{
						insertion_nama();
						hasil_sorting();
						bin_nama();
					}

					else if (m_srt == 3)
					{
						insertion_nim();
						hasil_sorting();
						bin_nim();
					}

					else if (m_srt == 4)
					{
						insertion_jurusan();
						hasil_sorting();
						bin_jurusan();
					}

					else if (m_srt == 5)
					{
						insertion_keperluan();
						hasil_sorting();
						bin_keperluan();
					}
				}
				
				else if (m_sort == 4)
				{
					if (m_srt == 1)
					{
						shell_tanggal();
						hasil_sorting();
						bin_tanggal();
					}

					else if (m_srt == 2)
					{
						shell_nama();
						hasil_sorting();
						bin_nama();
					}

					else if (m_srt == 3)
					{
						shell_nim();
						hasil_sorting();
						bin_nim();
					}

					else if (m_srt == 4)
					{
						shell_jurusan();
						hasil_sorting();
						bin_jurusan();
					}

					else if (m_srt == 5)
					{
						shell_keperluan();
						hasil_sorting();
						bin_keperluan();
					}
				}
				
				else if (m_sort == 5)
				{
					if (m_srt == 1)
					{
						mergeSort_tanggal(0,b-1);
						hasil_sorting();
						bin_tanggal();
					}

					else if (m_srt == 2)
					{
						mergeSort_nama(0,b-1);
						hasil_sorting();
						bin_nama();
					}

					else if (m_srt == 3)
					{
						mergeSort_nim(0,b-1);
						hasil_sorting();
						bin_nim();
					}

					else if (m_srt == 4)
					{
						mergeSort_jurusan(0,b-1);
						hasil_sorting();
						bin_jurusan();
					}

					else if (m_srt == 5)
					{
						mergeSort_keperluan(0,b-1);
						hasil_sorting();
						bin_keperluan();
					}
				}
				
				else if (m_sort == 6)
				{
					if (m_srt == 1)
					{
						quick_tanggal(0,b-1);
						hasil_sorting();
						bin_tanggal();
					}

					else if (m_srt == 2)
					{
						quick_nama(0,b-1);
						hasil_sorting();
						bin_nama();
					}

					else if (m_srt == 3)
					{
						quick_nim(0,b-1);
						hasil_sorting();
						bin_nim();
					}

					else if (m_srt == 4)
					{
						quick_jurusan(0,b-1);
						hasil_sorting();
						bin_jurusan();
					}

					else if (m_srt == 5)
					{
						quick_keperluan(0,b-1);
						hasil_sorting();
						bin_keperluan();
					}
				}
				

				cout<<"Kembali ke menu (y/n)? ";cin>>balik;	
			}
			
			else if (m_search == 3)
			{
				balik = 'y';
			}
			break;
			
			case 3:
			cout<<"==================== Menu Transaksi ====================\n\n";
			cout<<"Menu :\n1. Merge Sambung\n2. Spliting\nMenu yang dipilih adalah menu ke-";cin>>m_trans;
			cout<<endl;
			
			if (m_trans == 1)
			{
				trans_merge_sambung();
			}
			else if (m_trans == 2)
			{
				trans_spliting();
			}
			else
			{
				cout<<"\nMohon membaca aturan dengan benar\n";
			}

			cout<<"Kembali ke menu (y/n)? ";cin>>balik;
			break;
			
			case 4:
			cout<<"Terima Kasih...";
			exit(0);
			
			default:
			cout<<"\nMohon membaca aturan dengan benar\n";
			break;
			
		}


		if (balik == 'y')
		{
			found = false;
			j = 1,z = 0,a = 0;
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

void buat_file()
{
	dua :
	files.open("Nama-nama File.txt",ios::app);
	getline(cin, nama_file); // dengan format
	bydata.open(nama_file.c_str());
	if (!bydata.good())
	{
		cout<< nama_file << " tidak ada di dalam direktori" << endl;
		bydata.close();
		goto dua;
	}
	cout << "Nama file adalah " << nama_file << endl;
	files.close();
}

void buat_file_baru()
{
	files.open("Nama-nama File.txt",ios::app);
	getline(cin, nama_file); // dengan format
	cout << "Nama file adalah " << nama_file << endl;
	files<<nama_file<<endl;
	files.close();
}

void ambil_file()
{
	cout<<"Nama File? ";cin>>cari_file;			
	ext = "banyak ";
	by_file = ext.append(cari_file);
	bydata.open(by_file.c_str());
	bydata>>b;
	bydata.close();

	bydata.open(cari_file.c_str());
	for (int i = 0; i < b; ++i)
	{
		bydata>>info[i].tanggal;
		bydata.ignore();
		getline(bydata,info[i].nama);
		bydata>>info[i].nim;
		bydata>>info[i].jurusan;
		bydata.ignore();
		getline(bydata,info[i].keperluan);
	}
	bydata.close();
}

void sorting_file()
{
	bydata1.open(sorted_file.c_str());

	for (int i = 0; i < b; ++i)
	{
		bydata1<<info[i].tanggal<<endl;
		bydata1<<info[i].nama<<endl;
		bydata1<<info[i].nim<<endl;
		bydata1<<info[i].jurusan<<endl;
		bydata1<<info[i].keperluan<<endl;
	}
	bydata1.close();
}

void hasil_sorting()
{
	sorting_file();
	for (int l = 0; l < b; l++)
	{
		cout<<"No."<<l+1<<" :\n";
		cout<<"Tanggal\t\t: "<<info[l].tanggal<<endl;
		cout<<"Nama\t\t: "<<info[l].nama<<endl;
		cout<<"NIM\t\t: "<<info[l].nim<<endl;
		cout<<"Jurusan\t\t: "<<info[l].jurusan<<endl;
		cout<<"Keperluan\t: "<<info[l].keperluan<<endl<<endl;
	}
	
	cout<<"******************** Binary Search ********************\n\n";
}

void bubble_tanggal()
{
	int l,m;
	for(l=0; l<b-1; l++)
	{
		for(m=0; m<b-1-l; m++)
		{
			if(info[m].tanggal > info[m+1].tanggal)
			{
				temp = info[m];
				info[m] = info[m+1];
				info[m+1] = temp;
			}
		}
	}
}

void bubble_nama()
{
	int l,m;
	for(l=0; l<b-1; l++)
	{
		for(m=0; m<b-1-l; m++)
		{
			if(info[m].nama > info[m+1].nama)
			{
				temp = info[m];
				info[m] = info[m+1];
				info[m+1] = temp;
			}
		}
	}
}

void bubble_nim()
{
	int l,m;
	for(l=0; l<b-1; l++)
	{
		for(m=0; m<b-1-l; m++)
		{
			if(info[m].nim > info[m+1].nim)
			{
				temp = info[m];
				info[m] = info[m+1];
				info[m+1] = temp;
			}
		}
	}
}

void bubble_jurusan()
{
	int l,m;
	for(l=0; l<b-1; l++)
	{
		for(m=0; m<b-1-l; m++)
		{
			if(info[m].jurusan > info[m+1].jurusan)
			{
				temp = info[m];
				info[m] = info[m+1];
				info[m+1] = temp;
			}
		}
	}
}

void bubble_keperluan()
{
	int l,m;
	for(l=0; l<b-1; l++)
	{
		for(m=0; m<b-1-l; m++)
		{
			if(info[m].keperluan > info[m+1].keperluan)
			{
				temp = info[m];
				info[m] = info[m+1];
				info[m+1] = temp;
			}
		}
	}
}

void selection_tanggal()
{
	int l, m;
	string t_tgl;
	for(l=1; l<b; l++) 
	{
		t_tgl = info[l].tanggal;
		temp = info[l];
		m = l - 1;
		while((t_tgl < info[m].tanggal) && (m >= 0))
		{
			info[m+1] = info[m];
			m--;
			info[m+1] = temp; 
		}
	}
}

void selection_nama()
{
	int l, m;
	string t_nama;
	for(l=1; l<b; l++) 
	{
		t_nama = info[l].nama;
		temp = info[l];
		m = l - 1;
		while((t_nama < info[m].nama) && (m >= 0))
		{
			info[m+1] = info[m];
			m--;
			info[m+1] = temp; 
		}
	}
}

void selection_nim()
{
	int l, m;
	string t_nim;
	for(l=1; l<b; l++) 
	{
		t_nim = info[l].nim;
		temp = info[l];
		m = l - 1;
		while((t_nim < info[m].nim) && (m >= 0))
		{
			info[m+1] = info[m];
			m--;
			info[m+1] = temp; 
		}
	}
}

void selection_jurusan()
{
	int l, m;
	string t_jurusan;
	for(l=1; l<b; l++) 
	{
		t_jurusan = info[l].jurusan;
		temp = info[l];
		m = l - 1;
		while((t_jurusan < info[m].jurusan) && (m >= 0))
		{
			info[m+1] = info[m];
			m--;
			info[m+1] = temp; 
		}
	}
}

void selection_keperluan()
{
	int l, m;
	string t_keperluan;
	for(l=1; l<b; l++) 
	{
		t_keperluan = info[l].keperluan;
		temp = info[l];
		m = l - 1;
		while((t_keperluan < info[m].keperluan) && (m >= 0))
		{
			info[m+1] = info[m];
			m--;
			info[m+1] = temp; 
		}
	}
}

void insertion_tanggal()
{
	int l, m;
	for(l=0; l<b; l++)
	{
		for(m=l+1; m<b; m++)
		{
			if(info[l].tanggal > info[m].tanggal)
			{
				temp = info[l];
				info[l] = info[m];
				info[m] = temp;
			}
		}
	}
}

void insertion_nama()
{
	int l, m;
	for(l=0; l<b; l++)
	{
		for(m=l+1; m<b; m++)
		{
			if(info[l].nama > info[m].nama)
			{
				temp = info[l];
				info[l] = info[m];
				info[m] = temp;
			}
		}
	}
}

void insertion_nim()
{
	int l, m;
	for(l=0; l<b; l++)
	{
		for(m=l+1; m<b; m++)
		{
			if(info[l].nim > info[m].nim)
			{
				temp = info[l];
				info[l] = info[m];
				info[m] = temp;
			}
		}
	}
}

void insertion_jurusan()
{
	int l, m;
	for(l=0; l<b; l++)
	{
		for(m=l+1; m<b; m++)
		{
			if(info[l].jurusan > info[m].jurusan)
			{
				temp = info[l];
				info[l] = info[m];
				info[m] = temp;
			}
		}
	}
}

void insertion_keperluan()
{
	int l, m;
	for(l=0; l<b; l++)
	{
		for(m=l+1; m<b; m++)
		{
			if(info[l].keperluan > info[m].keperluan)
			{
				temp = info[l];
				info[l] = info[m];
				info[m] = temp;
			}
		}
	}
}

void shell_tanggal()
{
	int k,l,m;
	for(m=b/2; m>0; m/=2)
	{
		for(l=m; l<b; l++)
		{
			for(k = l-m; k >= 0; k -= m)
			{
				if(info[k + m].tanggal >= info[k].tanggal)
				{
					break;
				}
				
				else
				{
					temp = info[k];
					info[k] = info[k + m];
					info[k + m] = temp;
				}
			}
		}
	}
}

void shell_nama()
{
	int k,l,m;
	for(m=b/2; m>0; m/=2)
	{
		for(l=m; l<b; l++)
		{
			for(k = l-m; k >= 0; k -= m)
			{
				if(info[k + m].nama >= info[k].nama)
				{
					break;
				}
				
				else
				{
					temp = info[k];
					info[k] = info[k + m];
					info[k + m] = temp;
				}
			}
		}
	}
}

void shell_nim()
{
	int k,l,m;
	for(m=b/2; m>0; m/=2)
	{
		for(l=m; l<b; l++)
		{
			for(k = l-m; k >= 0; k -= m)
			{
				if(info[k + m].nim >= info[k].nim)
				{
					break;
				}
				
				else
				{
					temp = info[k];
					info[k] = info[k + m];
					info[k + m] = temp;
				}
			}
		}
	}
}

void shell_jurusan()
{
	int k,l,m;
	for(m=b/2; m>0; m/=2)
	{
		for(l=m; l<b; l++)
		{
			for(k = l-m; k >= 0; k -= m)
			{
				if(info[k + m].jurusan >= info[k].jurusan)
				{
					break;
				}
				
				else
				{
					temp = info[k];
					info[k] = info[k + m];
					info[k + m] = temp;
				}
			}
		}
	}
}

void shell_keperluan()
{
	int k,l,m;
	for(m=b/2; m>0; m/=2)
	{
		for(l=m; l<b; l++)
		{
			for(k = l-m; k >= 0; k -= m)
			{
				if(info[k + m].keperluan >= info[k].keperluan)
				{
					break;
				}
				
				else
				{
					temp = info[k];
					info[k] = info[k + m];
					info[k + m] = temp;
				}
			}
		}
	}
}

void mergeSort_tanggal(int l, int r)
{
	if (l < r) 
	{
		int m = l+(r-l)/2;  
		mergeSort_tanggal(l, m); 
		mergeSort_tanggal(m+1, r); 
		merge_tanggal(l, m, r); 
	}
}

	void merge_tanggal(int l, int m, int r)
	{
		int i, j, k; 
		int n1 = m - l + 1; 
		int n2 =  r - m; 
	  	
		isi L[n1], R[n2]; 
	  	
		for (i = 0; i < n1; i++) 
			L[i] = info[l + i]; 
		for (j = 0; j < n2; j++) 
			R[j] = info[m + 1+ j]; 

		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2) 
		{ 
			if (L[i].tanggal <= R[j].tanggal) 
			{ 
				info[k] = L[i]; 
				i++; 
			} 
			else
			{ 
				info[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 
		while (i < n1) 
		{ 
			info[k] = L[i]; 
			i++; 
			k++; 
		} 
		while (j < n2) 
		{ 
			info[k] = R[j]; 
			j++; 
			k++; 
		} 
	}

void mergeSort_nama(int l, int r)
{
	if (l < r) 
	{
		int m = l+(r-l)/2;  
		mergeSort_nama(l, m); 
		mergeSort_nama(m+1, r); 
		merge_nama(l, m, r); 
	}
}

	void merge_nama(int l, int m, int r)
	{
		int i, j, k; 
		int n1 = m - l + 1; 
		int n2 =  r - m; 
	  	
		isi L[n1], R[n2]; 
	  	
		for (i = 0; i < n1; i++) 
			L[i] = info[l + i]; 
		for (j = 0; j < n2; j++) 
			R[j] = info[m + 1+ j]; 

		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2) 
		{ 
			if (L[i].nama <= R[j].nama) 
			{ 
				info[k] = L[i]; 
				i++; 
			} 
			else
			{ 
				info[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 
		while (i < n1) 
		{ 
			info[k] = L[i]; 
			i++; 
			k++; 
		} 
		while (j < n2) 
		{ 
			info[k] = R[j]; 
			j++; 
			k++; 
		} 
	}

void mergeSort_nim(int l, int r)
{
	if (l < r) 
	{
		int m = l+(r-l)/2;  
		mergeSort_nim(l, m); 
		mergeSort_nim(m+1, r); 
		merge_nim(l, m, r); 
	}
}

	void merge_nim(int l, int m, int r)
	{
		int i, j, k; 
		int n1 = m - l + 1; 
		int n2 =  r - m; 
	  	
		isi L[n1], R[n2]; 
	  	
		for (i = 0; i < n1; i++) 
			L[i] = info[l + i]; 
		for (j = 0; j < n2; j++) 
			R[j] = info[m + 1+ j]; 

		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2) 
		{ 
			if (L[i].nim <= R[j].nim) 
			{ 
				info[k] = L[i]; 
				i++; 
			} 
			else
			{ 
				info[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 
		while (i < n1) 
		{ 
			info[k] = L[i]; 
			i++; 
			k++; 
		} 
		while (j < n2) 
		{ 
			info[k] = R[j]; 
			j++; 
			k++; 
		} 
	}

void mergeSort_jurusan(int l, int r)
{
	if (l < r) 
	{
		int m = l+(r-l)/2;  
		mergeSort_jurusan(l, m); 
		mergeSort_jurusan(m+1, r); 
		merge_jurusan(l, m, r); 
	}
}

	void merge_jurusan(int l, int m, int r)
	{
		int i, j, k; 
		int n1 = m - l + 1; 
		int n2 =  r - m; 
	  	
		isi L[n1], R[n2]; 
	  	
		for (i = 0; i < n1; i++) 
			L[i] = info[l + i]; 
		for (j = 0; j < n2; j++) 
			R[j] = info[m + 1+ j]; 

		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2) 
		{ 
			if (L[i].jurusan <= R[j].jurusan) 
			{ 
				info[k] = L[i]; 
				i++; 
			} 
			else
			{ 
				info[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 
		while (i < n1) 
		{ 
			info[k] = L[i]; 
			i++; 
			k++; 
		} 
		while (j < n2) 
		{ 
			info[k] = R[j]; 
			j++; 
			k++; 
		} 
	}

void mergeSort_keperluan(int l, int r)
{
	if (l < r) 
	{
		int m = l+(r-l)/2;  
		mergeSort_keperluan(l, m); 
		mergeSort_keperluan(m+1, r); 
		merge_keperluan(l, m, r); 
	}
}

	void merge_keperluan(int l, int m, int r)
	{
		int i, j, k; 
		int n1 = m - l + 1; 
		int n2 =  r - m; 
	  	
		isi L[n1], R[n2]; 
	  	
		for (i = 0; i < n1; i++) 
			L[i] = info[l + i]; 
		for (j = 0; j < n2; j++) 
			R[j] = info[m + 1+ j]; 

		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2) 
		{ 
			if (L[i].keperluan <= R[j].keperluan) 
			{ 
				info[k] = L[i]; 
				i++; 
			} 
			else
			{ 
				info[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 
		while (i < n1) 
		{ 
			info[k] = L[i]; 
			i++; 
			k++; 
		} 
		while (j < n2) 
		{ 
			info[k] = R[j]; 
			j++; 
			k++; 
		} 
	}

void quick_tanggal(int first, int last)
{
	int low, high;
	string list_separator;

   	low = first;
   	high = last;
   	list_separator = info[(first + last) / 2].tanggal;

   	do {
      	while(info[low].tanggal < list_separator)
         	low++;
      	while(info[high].tanggal > list_separator)
         	high--;

      	if(low <= high)
      	{
         	temp = info[low];
         	info[low++] = info[high];
         	info[high--] = temp;
 		}
   	} while(low <= high);

   	if(first < high) quick_tanggal(first, high);
   	if(low < last) quick_tanggal(low, last);
}

void quick_nama(int first, int last)
{
	int low, high;
	string list_separator;

   	low = first;
   	high = last;
   	list_separator = info[(first + last) / 2].nama;

   	do {
      	while(info[low].nama < list_separator)
         	low++;
      	while(info[high].nama > list_separator)
         	high--;

      	if(low <= high)
      	{
         	temp = info[low];
         	info[low++] = info[high];
         	info[high--] = temp;
 		}
   	} while(low <= high);

   	if(first < high) quick_nama(first, high);
   	if(low < last) quick_nama(low, last);
}

void quick_nim(int first, int last)
{
	int low, high;
	string list_separator;

   	low = first;
   	high = last;
   	list_separator = info[(first + last) / 2].nim;

   	do {
      	while(info[low].nim < list_separator)
         	low++;
      	while(info[high].nim > list_separator)
         	high--;

      	if(low <= high)
      	{
         	temp = info[low];
         	info[low++] = info[high];
         	info[high--] = temp;
 		}
   	} while(low <= high);

   	if(first < high) quick_nim(first, high);
   	if(low < last) quick_nim(low, last);
}

void quick_jurusan(int first, int last)
{
	int low, high;
	string list_separator;

   	low = first;
   	high = last;
   	list_separator = info[(first + last) / 2].jurusan;

   	do {
      	while(info[low].jurusan < list_separator)
         	low++;
      	while(info[high].jurusan > list_separator)
         	high--;

      	if(low <= high)
      	{
         	temp = info[low];
         	info[low++] = info[high];
         	info[high--] = temp;
 		}
   	} while(low <= high);

   	if(first < high) quick_jurusan(first, high);
   	if(low < last) quick_jurusan(low, last);
}

void quick_keperluan(int first, int last)
{
	int low, high;
	string list_separator;

   	low = first;
   	high = last;
   	list_separator = info[(first + last) / 2].keperluan;

   	do {
      	while(info[low].keperluan < list_separator)
         	low++;
      	while(info[high].keperluan > list_separator)
         	high--;

      	if(low <= high)
      	{
         	temp = info[low];
         	info[low++] = info[high];
         	info[high--] = temp;
 		}
   	} while(low <= high);

   	if(first < high) quick_keperluan(first, high);
   	if(low < last) quick_keperluan(low, last);
}

void bin_tanggal()
{
	int i,j,k;
	cout<< "Tanggal yang dicari : "; cin.ignore(); getline(cin,cari);
	i = 0;
	j = b;
	while((!found) & (i <= j)){
		k = (i + j) / 2;
	    if(cari == info[k].tanggal)
	        found = true;
	    else
	    {
	        if(cari < info[k].tanggal)
	    	    j = k - 1;
	        else
	        	i = k + 1;
	    }
	}
	cout<< endl;
	if(found)
	{
		cout<<"Tanggal\t\t: "<<info[k].tanggal<<endl;
		cout<<"Nama\t\t: "<<info[k].nama<<endl;
		cout<<"NIM\t\t: "<<info[k].nim<<endl;
		cout<<"Jurusan\t\t: "<<info[k].jurusan<<endl;
		cout<<"Keperluan\t: "<<info[k].keperluan<<endl<<endl;
	}
	else
	    cout << cari << " tidak ada di dalam " << cari_file << endl;
}

void bin_nama()
{
	int i,j,k;
	cout<< "Nama yang dicari : "; cin.ignore(); getline(cin,cari);
	i = 0;
	j = b;
	while((!found) & (i <= j)){
		k = (i + j) / 2;
	    if(cari == info[k].nama)
	        found = true;
	    else
	    {
	        if(cari < info[k].nama)
	    	    j = k - 1;
	        else
	        	i = k + 1;
	    }
	}
	cout<< endl;
	if(found)
	{
		cout<<"Tanggal\t\t: "<<info[k].tanggal<<endl;
		cout<<"Nama\t\t: "<<info[k].nama<<endl;
		cout<<"NIM\t\t: "<<info[k].nim<<endl;
		cout<<"Jurusan\t\t: "<<info[k].jurusan<<endl;
		cout<<"Keperluan\t: "<<info[k].keperluan<<endl<<endl;
	}
	else
	    cout << cari << " tidak ada di dalam " << cari_file << endl;
}

void bin_nim()
{
	int i,j,k;
	cout<< "NIM yang dicari : "; cin.ignore(); getline(cin,cari);
	i = 0;
	j = b;
	while((!found) & (i <= j)){
		k = (i + j) / 2;
	    if(cari == info[k].nim)
	        found = true;
	    else
	    {
	        if(cari < info[k].nim)
	    	    j = k - 1;
	        else
	        	i = k + 1;
	    }
	}
	cout<< endl;
	if(found)
	{
	    cout<<"Tanggal\t\t: "<<info[k].tanggal<<endl;
		cout<<"Nama\t\t: "<<info[k].nama<<endl;
		cout<<"NIM\t\t: "<<info[k].nim<<endl;
		cout<<"Jurusan\t\t: "<<info[k].jurusan<<endl;
		cout<<"Keperluan\t: "<<info[k].keperluan<<endl<<endl;
	}
	else
	    cout << cari << " tidak ada di dalam " << cari_file << endl;
}

void bin_jurusan()
{
	int i,j,k;
	cout<< "Jurusan yang dicari : "; cin.ignore(); getline(cin,cari);
	i = 0;
	j = b;
	while((!found) & (i <= j)){
		k = (i + j) / 2;
	    if(cari == info[k].jurusan)
	        found = true;
	    else
	    {
	        if(cari < info[k].jurusan)
	    	    j = k - 1;
	        else
	        	i = k + 1;
	    }
	}
	cout<< endl;
	if(found)
	{
	    cout<<"Tanggal\t\t: "<<info[k].tanggal<<endl;
		cout<<"Nama\t\t: "<<info[k].nama<<endl;
		cout<<"NIM\t\t: "<<info[k].nim<<endl;
		cout<<"Jurusan\t\t: "<<info[k].jurusan<<endl;
		cout<<"Keperluan\t: "<<info[k].keperluan<<endl<<endl;
	}
	else
	    cout << cari << " tidak ada di dalam " << cari_file << endl;
}

void bin_keperluan()
{
	int i,j,k;
	cout<< "Keperluan yang dicari : "; cin.ignore(); getline(cin,cari);
	i = 0;
	j = b;
	while((!found) & (i <= j)){
		k = (i + j) / 2;
	    if(cari == info[k].keperluan)
	        found = true;
	    else
	    {
	        if(cari < info[k].keperluan)
	    	    j = k - 1;
	        else
	        	i = k + 1;
	    }
	}
	cout<< endl;
	if(found)
	{
	    cout<<"Tanggal\t\t: "<<info[k].tanggal<<endl;
		cout<<"Nama\t\t: "<<info[k].nama<<endl;
		cout<<"NIM\t\t: "<<info[k].nim<<endl;
		cout<<"Jurusan\t\t: "<<info[k].jurusan<<endl;
		cout<<"Keperluan\t: "<<info[k].keperluan<<endl<<endl;
	}
	else
	    cout << cari << " tidak ada di dalam " << cari_file << endl;
}

void trans_merge_sambung()
{
	string file1,file2;
	int k = 0;
	ext = "banyak ";
	cout<<"Nama-nama file yang tersedia : \n";
	files1.open("Nama-nama File.txt");
	for (int i = 0; !files1.eof(); i++)
	{
		files1>>n_file[i];
		cout<<n_file[i]<<endl;
	}
	files1.close();
	cout<<"Masukkan nama file pertama (dengan format): "; cin>>file1;

	by_file = ext.append(file1);
	bydata.open(by_file.c_str());
	bydata>>b;
	bydata.close();
	bydata.open(file1.c_str());
	for (int i = 0; i < b; ++i)
	{
		bydata>>info[k].tanggal;
		bydata.ignore();
		getline(bydata,info[k].nama);
		bydata>>info[k].nim;
		bydata>>info[k].jurusan;
		bydata.ignore();
		getline(bydata,info[k].keperluan);
		k++;
	}
	bydata.close();

	cout<<"Masukkan nama file kedua (dengan format): "; cin>>file2;

	by_file = ext.append(file2);
	bydata.open(by_file.c_str());
	bydata>>b;
	bydata.close();
	bydata.open(file2.c_str());
	for (int i = 0; i < b; ++i)
	{
		bydata>>info[k].tanggal;
		bydata.ignore();
		getline(bydata,info[k].nama);
		bydata>>info[k].nim;
		bydata>>info[k].jurusan;
		bydata.ignore();
		getline(bydata,info[k].keperluan);
		k++;
	}
	bydata.close();
	cout<<"Masukkan nama file untuk menyimpan hasil transaksi : ";
	cin.ignore();
	buat_file_baru();

	ext = "banyak ";
	by_file = ext.append(nama_file);
	bydata1.open(by_file.c_str());
	bydata1<<k;
	bydata1.close();

	files.open(nama_file.c_str(),ios::app);
	for (int j = 0; j < k; ++j)
	{
		files<<info[j].tanggal<<endl;
		files<<info[j].nama<<endl;
		files<<info[j].nim<<endl;
		files<<info[j].jurusan<<endl;
		files<<info[j].keperluan<<endl;
	}
	files.close();
}

void trans_spliting()
{
	string file1,file2,file3,file4;
	int k = 0;
	cout<<"Nama-nama file yang tersedia : \n";
	files1.open("Nama-nama File.txt");
	for (int i = 0; !files1.eof(); i++)
	{
		files1>>n_file[i];
		cout<<n_file[i]<<endl;
	}
	files1.close();
	ambil_file();

	cout<<"Masukkan nama file untuk jurusan IF (dengan format): ";
	cin.ignore();
	buat_file_baru();
	files.open(nama_file.c_str(),ios::app);
	for (int j = 0; j < b; j++)
	{
		if (info[j].jurusan == "IF")
		{
			files<<info[j].tanggal<<endl;
			files<<info[j].nama<<endl;
			files<<info[j].nim<<endl;
			files<<info[j].jurusan<<endl;
			files<<info[j].keperluan<<endl;
			k++;
		}
	}
	files.close();

	ext = "banyak ";
	by_file = ext.append(nama_file);
	bydata1.open(by_file.c_str());
	bydata1<<k;
	bydata1.close();
	k = 0;

	cout<<"Masukkan nama file untuk jurusan TI (dengan format): ";
	buat_file_baru();
	files.open(nama_file.c_str(),ios::app);
	for (int j = 0; j < b; j++)
	{
		if (info[j].jurusan == "TI")
		{
			files<<info[j].tanggal<<endl;
			files<<info[j].nama<<endl;
			files<<info[j].nim<<endl;
			files<<info[j].jurusan<<endl;
			files<<info[j].keperluan<<endl;
			k++;
		}
	}
	files.close();

	ext = "banyak ";
	by_file = ext.append(nama_file);
	bydata1.open(by_file.c_str());
	bydata1<<k;
	bydata1.close();
	k = 0;

	cout<<"Masukkan nama file untuk jurusan SI (dengan format): ";
	buat_file_baru();
	files.open(nama_file.c_str(),ios::app);
	for (int j = 0; j < b; j++)
	{
		if (info[j].jurusan == "SI")
		{
			files<<info[j].tanggal<<endl;
			files<<info[j].nama<<endl;
			files<<info[j].nim<<endl;
			files<<info[j].jurusan<<endl;
			files<<info[j].keperluan<<endl;
			k++;
		}
	}
	files.close();

	ext = "banyak ";
	by_file = ext.append(nama_file);
	bydata1.open(by_file.c_str());
	bydata1<<k;
	bydata1.close();
	k = 0;

	cout<<"Masukkan nama file untuk jurusan Tekim (dengan format): ";
	buat_file_baru();
	files.open(nama_file.c_str(),ios::app);
	for (int j = 0; j < b; j++)
	{
		if (info[j].jurusan == "Tekim")
		{
			files<<info[j].tanggal<<endl;
			files<<info[j].nama<<endl;
			files<<info[j].nim<<endl;
			files<<info[j].jurusan<<endl;
			files<<info[j].keperluan<<endl;
			k++;
		}
	}
	files.close();

	ext = "banyak ";
	by_file = ext.append(nama_file);
	bydata1.open(by_file.c_str());
	bydata1<<k;
	bydata1.close();
	k = 0;
}