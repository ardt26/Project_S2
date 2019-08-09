#include <bits/stdc++.h>
using namespace std;
struct identitas{
	string nama,ktp;
	char tempt_ddk[3];
};
struct penerbangan
{
	string tgl_brt,bln_brt,thn_brt,bandara[10],bandara_smp;
	char book[6],kode_p[6],asuransi;
	int kelas,total_bagasi, total_pembayaran, biaya_asuransi,by_penumpang,tiket_p,gate;
	identitas bio[100];
}info;
struct pesawat{
	string jam_brt,jam_smp,lama_p,nama_p,kode_bb,kode_bs;
	int harga;
};
pesawat psw[100],temp;
int menu_awal,banyak_p[10],bts_bp,i,asci;
string cari_p[10],cari_book,kodbuk,kodpes,tp_ddk[100];
char lagi,*pntr;
string ext,panggil_file,panggil;

ofstream sim;
ifstream amb;

void list_bandara();
void list_pesawat();
void beli_tiket();
void booking();
void pesan();
int pembayaran();
void tiket();
void g(int a);
void kodepesawat();
void tempatduduk();
void kodebooking();
void invoice();

int main()
{
	ext = "invoice - ";
	do
	{
		cout<<"\t\t\t\t\tWELCOME TO AERLOKA"<<endl;
		cout<<"\tMenu :\n\t\t1. Beli Tiket\n\t\t2. Cetak Tiket\n\tMenu yang dipilih adalah menu ke-";cin>>menu_awal;

		switch (menu_awal)
		{
			case 1:
				beli_tiket();
				break;
			case 2:
				cout<<info.tiket_p;
				cout<<endl<<"\tMasukkan Kode Booking : "; cin>>cari_book;
				panggil = ext.append(cari_book)+".txt";

				amb.open(panggil.c_str());

				amb>>kodbuk;
				amb>>info.tgl_brt;
				amb>>info.bln_brt;
				amb>>info.thn_brt;
				amb.ignore();
				getline(amb,psw[info.tiket_p].nama_p);
				amb>>kodpes;
				amb>>psw[info.tiket_p].jam_brt;
				amb>>psw[info.tiket_p].jam_smp;
				amb>>psw[info.tiket_p].kode_bb;
				amb>>psw[info.tiket_p].kode_bs;
				amb>>info.kelas;
				amb>>info.by_penumpang;
				for(i=0; i<info.by_penumpang; i++){
					amb.ignore();
					getline(amb,info.bio[i].nama);
					amb>>info.bio[i].ktp;
					amb>>tp_ddk[i];
					
				}
				amb>>info.gate;
				amb>>psw[info.tiket_p].harga;
				amb>>info.total_bagasi;
				amb>>info.asuransi;
				amb>>info.biaya_asuransi;
				amb>>info.total_pembayaran;

				amb.close();

				tiket();
		}
		cout<<endl<<"\tKembali ke menu utama? "; cin>>lagi;
		if (lagi == 'y')
		{
			system("cls");
		}
		else
		{
			cout<<endl<<"\t\t\tTERIMA KASIH TELAH MENGGUNAKAN JASA KAMI"<<endl;
		}
	}while(lagi == 'y');
}

void list_bandara()
{
	ifstream b;
	b.open("List Bandara.txt");
	cout<<endl<<"\t\t\tList Bandara Tujuan"<<endl;
	for(i=0; i<10; i++){
		getline(b,info.bandara[i]);
		cout<<"\t"<<i+1<<". "<<info.bandara[i]<<endl;
	}
}

void list_pesawat()
{
	int b=49;
	string ext1,ext2,panggil_file,kosong;
	ext1 = "e tujuan ";
	ext2 = "b tujuan ";
	
	if(info.kelas==1){
		ifstream byk;
		byk.open("Banyak P E.txt");
		for(i=0; i<10; i++){
			getline(byk,cari_p[i]);
			byk>>banyak_p[i];
			getline(byk,kosong);
			if(info.bandara_smp==cari_p[i]){
				bts_bp=banyak_p[i];
			}
		}
		byk.close();
		panggil_file = ext1.append(info.bandara_smp) + ".txt";
		ifstream p;
		p.open(panggil_file.c_str());
		for(i=0; i<bts_bp; i++){
			getline(p,psw[i].nama_p);
			getline(p,psw[i].jam_brt);
			getline(p,psw[i].jam_smp);
			getline(p,psw[i].kode_bb);
			getline(p,psw[i].kode_bs);
			getline(p,psw[i].lama_p);
			p>>psw[i].harga;
			getline(p,kosong);
		}
		for(i=0; i<bts_bp; i++){
			for(int j=i+1; j<bts_bp; j++){
				if(psw[i].harga>psw[j].harga){
					temp = psw[i];
					psw[i] = psw[j];
					psw[j] = temp;
				}
			}
		}
		for(i=0; i<bts_bp; i++){
			cout<<"\tTiket "<<i+1<<endl;
			cout<<"\t"; g(b);
			cout<<setiosflags(ios::left);
			cout<<"\t|  "<<setw(45)<<"Flight"<<"|"<<endl;
			cout<<"\t|  "<<setw(45)<<info.tgl_brt + " " + info.bln_brt + " " + info.thn_brt<<"|"<<endl;
			cout<<"\t|  "<<setw(30)<<psw[i].nama_p<<psw[i].jam_brt<<" - "<<psw[i].jam_smp<<"\t|"<<endl;
			cout<<"\t|  "<<setw(30)<<"Economy - Direct "<<psw[i].kode_bb<<" "<<psw[i].lama_p<<" "<<psw[i].kode_bs<<"\t|"<<endl;
			cout<<"\t|  Rp "<<psw[i].harga<<"\t\t\t\t\t|"<<endl;
			cout<<"\t"; g(b);
		}
		p.close();
	}
	if(info.kelas==2){
		ifstream byk1;
		byk1.open("Banyak P B.txt");
		for(i=0; i<10; i++){
			getline(byk1,cari_p[i]);
			byk1>>banyak_p[i];
			getline(byk1,kosong);
			if(info.bandara_smp==cari_p[i]){
				bts_bp=banyak_p[i];
			}
		}
		byk1.close();
		panggil_file = ext2.append(info.bandara_smp) + ".txt";
		ifstream q;
		q.open(panggil_file.c_str());
		for(i=0; i<bts_bp; i++){
			getline(q,psw[i].nama_p);
			getline(q,psw[i].jam_brt);
			getline(q,psw[i].jam_smp);
			getline(q,psw[i].kode_bb);
			getline(q,psw[i].kode_bs);
			getline(q,psw[i].lama_p);
			q>>psw[i].harga;
			getline(q,kosong);
		}
		for(i=0; i<bts_bp; i++){
			for(int j=i+1; j<bts_bp; j++){
				if(psw[i].harga>psw[j].harga){
					temp = psw[i];
					psw[i] = psw[j];
					psw[j] = temp;
				}
			}
		}
		for(i=0; i<bts_bp; i++){
			cout<<"\tTiket "<<i+1<<endl;
			cout<<"\t"; g(b);
			cout<<setiosflags(ios::left);
			cout<<"\t|  "<<setw(45)<<"Flight"<<"|"<<endl;
			cout<<"\t|  "<<setw(45)<<info.tgl_brt + " " + info.bln_brt + " " + info.thn_brt<<"|"<<endl;
			cout<<"\t|  "<<setw(30)<<psw[i].nama_p<<psw[i].jam_brt<<" - "<<psw[i].jam_smp<<"\t|"<<endl;
			cout<<"\t|  "<<setw(30)<<"Business - Direct "<<psw[i].kode_bb<<" "<<psw[i].lama_p<<" "<<psw[i].kode_bs<<"\t|"<<endl;
			cout<<"\t|  Rp "<<psw[i].harga<<"\t\t\t\t\t|"<<endl;
			cout<<"\t"; g(b);
		}
		q.close();
	}
}

void beli_tiket()
{
	int i;
	list_bandara();
	cout<<endl<<"\t\tKeberangkatan dari Bandara Internasional Soekarno-Hatta"<<endl;
	cout<<"\tMasukkan Kode Bandara Tujuan \t: "<<endl<<"\t\tContoh : JOG"<<endl;
	cout<<"\t\tPilihan \t\t: "; cin>>info.bandara_smp;
	cout<<"\tMasukan Tanggal Keberangkatan \t: "<<endl<<"\t\tContoh : 17(space)AGS(space)19"<<endl;
	cout<<"\t\tTanggal \t\t: "; cin>>info.tgl_brt>>info.bln_brt>>info.thn_brt;
	cout<<"\tBanyaknya penumpang \t\t: ";cin>>info.by_penumpang;
	cout<<"\tPilihan Kelas :\n\t\t1. Economy\n\t\t2. Business\n\tKelas yang Dipilih adalah ";cin>>info.kelas;
	cout<<endl;
	list_pesawat();
	cout<<"\tPilihan Tiket : "; cin>>info.tiket_p;
	info.tiket_p = info.tiket_p - 1;
	booking();
}

void booking ()
{
	int b=49;
	cout<<endl<<"\t\tPilihan tiket anda "<<endl;
	cout<<"\t"; g(b);
	cout<<"\t|  "<<setw(45)<<"Flight"<<"|"<<endl;
	cout<<"\t|  "<<setw(45)<<info.tgl_brt + " " + info.bln_brt + " " + info.thn_brt<<"|"<<endl;
	cout<<"\t|  "<<setw(30)<<psw[info.tiket_p].nama_p<<psw[info.tiket_p].jam_brt<<" - "<<psw[info.tiket_p].jam_smp<<"\t|"<<endl;
	if(info.kelas == 1)
		cout<<"\t|  "<<setw(30)<<"Economy - Direct "<<psw[info.tiket_p].kode_bb<<" "<<psw[info.tiket_p].lama_p<<" "<<psw[info.tiket_p].kode_bs<<"\t|"<<endl;
	else
		cout<<"\t|  "<<setw(30)<<"Business - Direct "<<psw[info.tiket_p].kode_bb<<" "<<psw[info.tiket_p].lama_p<<" "<<psw[info.tiket_p].kode_bs<<"\t|"<<endl;
	cout<<"\t|  Rp "<<psw[info.tiket_p].harga<<"\t\t\t\t\t|"<<endl;
	cout<<"\t"; g(b);
	cout<<endl<<"\tBagasi awal 20kg/orang"<<endl;
	cout<<"\tBagasi Tambahan dalam kg (Rp 100000/kg) : "; cin>>info.total_bagasi;
	pesan();
}

void pesan()
{
	cout<<"\tMasukkan Identitas Penumpang : \n";
	for (int i = 0; i < info.by_penumpang; ++i)
	{
		cout<<"\tNo. "<<i+1<<" :"<<endl;
		cin.ignore();
		cout<<"\t\tNama penumpang	: "; getline(cin,info.bio[i].nama);
		cout<<"\t\tNomor KTP	: "; cin>>info.bio[i].ktp;
		cout<<endl;
	}

	cout<<"\tApakah anda ingin menggunakan jasa asuransi (50.000/orang) : "; cin>>info.asuransi;
	pembayaran();
	kodepesawat();
	tempatduduk();
	kodebooking();
	cout<<endl;
	invoice();
}
void kodepesawat()
{
	pntr = info.kode_p;
	for (int i = 3; i < 6; ++i)
	{
		asci = rand()%10 + 48;
		info.kode_p[i] = (char)asci;
	}
	if(psw[info.tiket_p].nama_p=="All Nippon Airways (ANA)"){
		info.kode_p[0] = 'N';
		info.kode_p[1] = 'H';
		info.kode_p[2] = '-';
	}
	else if(psw[info.tiket_p].nama_p=="Korean Air"){
		info.kode_p[0] = 'K';
		info.kode_p[1] = 'E';
		info.kode_p[2] = '-';
	}
	else if(psw[info.tiket_p].nama_p=="Garuda Indonesia"){
		info.kode_p[0] = 'G';
		info.kode_p[1] = 'A';
		info.kode_p[2] = '-';
	}
	else if(psw[info.tiket_p].nama_p=="Sriwijaya Air"){
		info.kode_p[0] = 'S';
		info.kode_p[1] = 'J';
		info.kode_p[2] = '-';
	}
	else if(psw[info.tiket_p].nama_p=="Citilink"){
		info.kode_p[0] = 'Q';
		info.kode_p[1] = 'G';
		info.kode_p[2] = '-';
	}
	else if(psw[info.tiket_p].nama_p=="Batik Air"){
		info.kode_p[0] = 'I';
		info.kode_p[1] = 'D';
		info.kode_p[2] = '-';
	}

	asci = rand()%10 + 1;
	info.gate = asci;
}
void tempatduduk()
{
	for (int i = 0; i < info.by_penumpang; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if(j == 0)
			{
				asci = rand()%3 + 48;
				info.bio[i].tempt_ddk[j] = (char)asci;
			}

			else if (j == 1)
			{
				asci = rand()%9 + 49;
				info.bio[i].tempt_ddk[j] = (char)asci;
			}

			else if(j == 2)
			{
				asci = rand()%6 + 65;
				info.bio[i].tempt_ddk[j] = (char)asci;
			}
		}
	}

}
void kodebooking()
{
	for (int i = 0; i < 6; ++i)
	{
		if (i%2 == 1)
		{
			asci = rand()%26 + 65;
			info.book[i] = (char)asci;
		}

		else if (i%2 == 0)
		{
			asci = rand()%9 + 49;
			info.book[i] = (char)asci;
		}

		kodbuk = kodbuk + info.book[i];	
	}
}
void invoice()
{
	int b=112;
	g(b);
	cout<<setiosflags(ios::left);
	cout<<"|"<<setw(100)<<" "<<"| AERLOKA |"<<endl;
	cout<<"|  E-Ticket"<<setw(90)<<" "<<"|---------|"<<endl;
	if(info.bln_brt=="JAN")
	{
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(20)<<" JANUARI 20" + info.thn_brt<<setw(35)<<" "<<"|"<<endl;
	}
	else if(info.bln_brt=="FEB")
	{
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(20)<<" FEBRUARI 20" + info.thn_brt<<setw(35)<<" "<<"|"<<endl;
	}
	else if(info.bln_brt=="MAR"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(68)<<" MARET 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="APR"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(68)<<" APRIL 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="MEI"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(69)<<" MEI 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="JUN"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(68)<<" JUNI 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="JUL"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(68)<<" JULI 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="AGS"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(268)<<" AGUSTUS 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="SEP"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(68)<<" SEPTEMBER 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="OKT"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(68)<<" OKTOBER 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="NOV"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(68)<<" NOVEMBER 20" + info.thn_brt<<"|"<<endl;
	}
	else if(info.bln_brt=="DES"){
		cout<<"|"<<setw(40)<<" "<<info.tgl_brt<<setw(68)<<" DESEMBER 20" + info.thn_brt<<"|"<<endl;
	}	
	cout<<"|  "<<setw(38)<<psw[info.tiket_p].nama_p<<setw(7)<<psw[info.tiket_p].jam_brt<<" o "<<setw(47)<<psw[info.tiket_p].kode_bb<<"Booking Code |"<<endl;
	cout<<"|  ";
	for(i=0; i<6; i++){cout<<*(pntr + i);}
	cout<<setw(40)<<" "<<"|"<<setw(51)<<" ";
	for(i=0; i<6; i++){cout<<info.book[i];}
	cout<<setw(4)<<" "<<"|"<<endl;
	if (info.kelas==1)
	{
		cout<<"|  Economy"<<setw(31)<<" "<<setw(7)<<psw[info.tiket_p].jam_smp<<" o "<<setw(60)<<psw[info.tiket_p].kode_bs<<"|"<<endl;
	}
	else
	{
		cout<<"|  Business"<<setw(30)<<" "<<setw(7)<<psw[info.tiket_p].jam_smp<<" o "<<setw(60)<<psw[info.tiket_p].kode_bs<<"|"<<endl;
	}
	cout<<"|"<<setw(110)<<" "<<"|"<<endl;
	g(b);
	cout<<"|"<<setw(110)<<" "<<"|"<<endl;
	cout<<"|  No. "<<setw(15)<<" "<<" Passenger(s) "<<setw(15)<<" "<<" Seat "<<setw(15)<<" "<<" Route "<<setw(16)<<" "<<" Flight Luggage |"<<endl;
	cout<<"|   No. "<<setw(14)<<" "<<"  Nama Penumpang "<<setw(12)<<" "<<"  Tempat Duduk "<<setw(6)<<" "<<"  Rute "<<setw(16)<<" "<<"  Bagasi"<<setw(7)<<" "<<" |"<<endl;
	for(i=0; i<info.by_penumpang; i++)
	{
		cout<<"|   "<<i+1<<setw(19)<<". "<<setw(29)<<info.bio[i].nama;
		for(int j=0; j<3; j++){ cout<<info.bio[i].tempt_ddk[j];}
		cout<<setw(18)<<" "<<psw[info.tiket_p].kode_bb<<"-"<<psw[info.tiket_p].kode_bs<<setw(16)<<" "<<setw(3)<<20<<" kg"<<setw(8)<<" "<<"|"<<endl;
	}
	cout<<"|"<<setw(110)<<" "<<"|"<<endl;
	cout<<"|"<<setw(110)<<" "<<"|"<<endl;
	g(b);
	cout<<"|"<<setw(110)<<" "<<"|"<<endl;
	cout<<"|  Invoice/Pembayaran"<<setw(90)<<" "<<"|"<<endl;
	cout<<"|"<<setw(110)<<" "<<"|"<<endl;
	cout<<"|  No."<<setw(10)<<" "<<" Jenis Barang "<<setw(12)<<" "<<" Jumlah "<<setw(12)<<" "<<"Harga/Satuan"<<setw(16)<<" "<<"Harga Total"<<setw(10)<<" "<<"|"<<endl;
	cout<<"|  "<<1<<setw(12)<<". "<<setw(29)<<" Tiket Pesawat "<<setw(19)<<info.by_penumpang<<setw(27)<<psw[info.tiket_p].harga<<setw(19)<<psw[info.tiket_p].harga*info.by_penumpang<<" |"<<endl;
	cout<<"|  "<<2<<setw(12)<<". "<<setw(29)<<" Bagasi "<<setw(19)<<info.total_bagasi<<setw(27)<<100000<<setw(19)<<100000*info.total_bagasi<<" |"<<endl;
	if(info.asuransi=='y'){
		cout<<"|  "<<3<<setw(12)<<". "<<setw(29)<<" Asuransi "<<setw(19)<<info.by_penumpang<<setw(27)<<info.biaya_asuransi<<setw(19)<<info.biaya_asuransi*info.by_penumpang<<" |"<<endl;
	}
	cout<<"|"<<setw(79)<<" "<<"Admin "<<setw(5)<<" "<<100000<<setw(14)<<" "<<"|"<<endl;
	cout<<"|"<<setw(79)<<" "<<"Total "<<setw(5)<<" "<<setw(20)<<info.total_pembayaran<<"|"<<endl;
	cout<<"|"<<setw(110)<<" "<<"|"<<endl;
	g(b);

	panggil_file = ext.append(kodbuk) + ".txt";
	sim.open(panggil_file.c_str());
	for (int j = 0; j < 6; ++j)
	{
		sim<<info.book[j];
	}
	sim<<endl;
	sim<<info.tgl_brt<<endl;
	sim<<info.bln_brt<<endl;
	sim<<info.thn_brt<<endl;
	sim<<psw[info.tiket_p].nama_p<<endl;
	for (int j = 0; j < 6; ++j)
	{
		sim<<info.kode_p[j];
	}
	sim<<endl;
	sim<<psw[info.tiket_p].jam_brt<<endl;
	sim<<psw[info.tiket_p].jam_smp<<endl;
	sim<<psw[info.tiket_p].kode_bb<<endl;
	sim<<psw[info.tiket_p].kode_bs<<endl;
	sim<<info.kelas<<endl;
	sim<<info.by_penumpang<<endl;
	for(i=0; i<info.by_penumpang; i++){
		sim<<info.bio[i].nama<<endl;
		sim<<info.bio[i].ktp<<endl;
		sim<<info.bio[i].tempt_ddk<<endl;
	}
	sim<<info.gate<<endl;
	sim<<psw[info.tiket_p].harga<<endl;
	sim<<info.total_bagasi<<endl;
	sim<<info.asuransi<<endl;
	sim<<info.biaya_asuransi<<endl;
	sim<<info.total_pembayaran<<endl;
	sim.close();
}

int pembayaran()
{
	if(info.asuransi == 'y')
	{
		info.biaya_asuransi = 50000;
	}
	else
	{
		info.biaya_asuransi = 0;
	}
	
	info.total_pembayaran = (psw[info.tiket_p].harga + info.biaya_asuransi)*info.by_penumpang + (info.total_bagasi*(100000))+100000;
	return (info.total_pembayaran);
}

void tiket()
{
	int b=137;
	cout<<endl;
	for(int i=0; i<info.by_penumpang; i++)
	{
		cout<<"\t"; g(b);
		cout<<setiosflags(ios::left);
		if(info.kelas == 1)
			cout<<"\t|"<<setw(31)<<""<<setw(56)<<"Economy Class"<<setw(3)<<"|"<<setw(45)<<psw[info.tiket_p].nama_p<<"|"<<endl;
		else
			cout<<"\t|"<<setw(31)<<""<<setw(56)<<"Business Class"<<setw(3)<<"|"<<setw(45)<<psw[info.tiket_p].nama_p<<"|"<<endl;
		cout<<"\t"; g(b);
		cout<<"\t|  "<<setw(85)<<""<<"|  Nama/Name"<<setw(36)<<""<<"|"<<endl;
		cout<<"\t|  "<<setw(30)<<"Nama/Name"<<setw(28)<<"Penerbangan/Flight"<<setw(27)<<"Tujuan/Destination"<<setw(3)<<"|"<<setw(45)<<info.bio[i].nama<<"|"<<endl;
		cout<<"\t|  "<<setw(36)<<info.bio[i].nama<<setw(29)<<kodpes<<setw(20)<<psw[info.tiket_p].kode_bs<<setw(48)<<"|"<<"|"<<endl;
		cout<<"\t|  "<<setw(85)<<" "<<setw(27)<<"|  Penerbangan/Flight "<<setw(21)<<"Tanggal/Date"<<"|"<<endl;
		cout<<"\t|  "<<setw(85)<<" "<<setw(3)<<"|"<<setw(27)<<kodpes<<setw(18)<<info.tgl_brt + " " + info.bln_brt + " " + info.thn_brt<<"|"<<endl;
		cout<<"\t|  "<<setw(29)<<"Tanggal/Date "<<setw(28)<<" Tempat Duduk/Seat "<<setw(28)<<" Kode Booking/Booking Code "<<setw(48)<<"|"<<"|"<<endl;
		cout<<"\t|  "<<setw(37)<<info.tgl_brt + " " + info.bln_brt + " " + info.thn_brt<<setw(30)<<tp_ddk[i]<<setw(18)<<kodbuk<<setw(3)<<"|"<<setw(24)<<"Asal/Origin"<<setw(21)<<"Tujuan/Destination"<<"|"<<endl;
		cout<<"\t|  "<<setw(85)<<""<<setw(7)<<"|"<<setw(27)<<"JKT"<<setw(14)<<psw[info.tiket_p].kode_bs<<"|"<<endl;
		cout<<"\t|  "<<setw(85)<<""<<setw(48)<<"|"<<"|"<<endl;
		cout<<"\t|  "<<setw(13)<<""<<setw(72)<<psw[info.tiket_p].nama_p<<setw(3)<<"|"<<setw(24)<<"Pintu/Gate"<<setw(21)<<"Tempat Duduk/Seat"<<"|"<<endl;
		cout<<"\t|  "<<setw(85)<<""<<setw(8)<<"|"<<setw(26)<<info.gate<<setw(14)<<tp_ddk[i]<<"|"<<endl;
		cout<<"\t"; g(b);
		if(info.kelas == 1)
			cout<<"\t|  "<<setw(85)<<"Boarding Pass"<<setw(3)<<"|"<<setw(45)<<"Economy Class"<<"|"<<endl;
		else
			cout<<"\t|  "<<setw(85)<<"Boarding Pass"<<setw(3)<<"|"<<setw(45)<<"Business Class"<<"|"<<endl;
		cout<<"\t"; g(b);
		cout<<endl;
	}
}
void g(int a){
	if(a>1){
		cout<<"-";
		g(a-1);
	}
	else
		cout<<"-"<<endl;
}