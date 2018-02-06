/* File : jam.c */
/* Deskripsi : Operasi terhadap titik yang terdapat pada sumbu kartesius */
/* Isi : realisasi / kode program dari semua prototype yang didefenisikan dalam point.h */

#include<stdio.h>
#include<math.h>
#include "jam.h"

boolean IsJAMValid (int H, int M, int S)
{
	boolean cek;
	
	if((H >= 1) && (H <= 23))
	{
		if((M >= 0) && (M <= 59))
		{
			if((S >=0) && (S <= 59))
			{
				cek = 1;
			}
			else
			{
				cek = 0;
			};
		}
		else
		{
			cek = 0;
		};
	}
	else
	{
		cek = 0;
	};
	
	return(cek);
};

JAM MakeJAM (int HH, int MM, int SS)
{
	JAM J;
	
	Hour(J) = HH;
	Minute(J) = MM;
	Second(J) = SS;
	
	return(J);
};

void BacaJAM (JAM * J)
{
	int a,b,c;
	do
	{
		scanf(" %d %d %d",&a,&b,&c);
		if(!IsJAMValid(a,b,c))
		{
			printf("Jam tidak valid\n");
		};
	}
	while(!IsJAMValid(a,b,c));	
	*J = MakeJAM(a,b,c);
	
};

void TulisJAM (JAM J)
{
	printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
};

long JAMToDetik (JAM J)
{
	long s;//jumlah detik
	
	s = 3600*Hour(J) + 60*Minute(J) + Second(J);
	
	return(s);
};

JAM DetikToJAM (long N)
{
	JAM hasil;
	long sisa;
	N = N % 86400;
	Hour(hasil) = N / 3600;
	sisa = N % 3600;
	Minute(hasil) = sisa / 60;
	Second(hasil) = sisa % 60;
	return (hasil);
};

boolean JEQ (JAM J1, JAM J2)
{
	/*Kamus Lokal*/
	boolean cek;
	
	if(Hour(J1) == Hour(J2))
	{
		if (Minute(J1) == Minute(J2))
		{
			if (Second(J1) == Second(J2))
			{
				cek = 1;
			}
			else
			{
				cek = 0;
			};
		}
		else
		{
			cek = 0;
		};
	}
	else //J1 != J2
	{
		cek = 0;
	};
	return(cek);
};

boolean JNEQ (JAM J1, JAM J2)
{
	/*Kamus Lokal*/
	boolean cek;
	
	if(!JEQ(J1,J2))
	{
		cek = 1;
	}
	else //J1 = J2
	{
		cek = 0;
	};
	return(cek);
};

boolean JLT (JAM J1, JAM J2)
{
	/*Kamus Lokal*/
	boolean cek;
	
	/*Algoritma*/
	if(Hour(J1) < Hour(J2))
	{
		cek = 1;
	}
	else if(Hour(J1) > Hour(J2))
	{
		cek = 0;
	}
	else //J1.hh = J2.hh
	{
		if(Minute(J1) < Minute(J2))
		{
			cek = 1;
		}
		else if(Minute(J1) > Minute(J2))
		{
			cek = 0;
		}
		else //J1.mm = J2.mm
		{
			if(Second(J1) <= Second(J2))
			{
				cek = 1;
			}
			else if(Second(J1) > Second(J2))
			{
				cek = 0;
			}
		};
	};
	return (cek);
};

boolean JGT (JAM J1, JAM J2)
{
	/*Kamus Lokal*/
	boolean cek;
	if(!JLT(J1,J2))
	{
		cek = 1;
	}
	else //J1<J2
	{
		cek =0;
	};
	return(cek);
};

JAM NextDetik (JAM J)
{
	/*Kamus Lokal*/
	long s; //penampung jumlah detik
	JAM hasil;
	
	/*Algorima*/
	s = JAMToDetik(J);
	s = s + 1;
	hasil = DetikToJAM(s);
	return(hasil);
};

JAM NextNDetik (JAM J, int N)
{
	/*Kamus Lokal*/
	long s; //penampung jumlah detik
	JAM hasil;
	
	/*Algorima*/
	s = JAMToDetik(J);
	s = s + N;
	hasil = DetikToJAM(s);
	return(hasil);
};

JAM PrevDetik (JAM J)
{
	/*Kamus Lokal*/
	long s; //penampung jumlah detik
	JAM hasil;
	
	/*Algorima*/
	s = JAMToDetik(J);
	s = s - 1;
	hasil = DetikToJAM(s);
	return(hasil);
};

JAM PrevNDetik (JAM J, int N)
{
	/*Kamus Lokal*/
	long s; //penampung jumlah detik
	JAM hasil;
	
	/*Algorima*/
	s = JAMToDetik(J);
	s = s - N;
	hasil = DetikToJAM(s);
	return(hasil);
};
	
long Durasi (JAM JAw, JAM JAkh)
{
	/*Kamus Lokal*/
	long sw, skh, hasil;
	
	/*Algorita*/
	sw = JAMToDetik(JAw);
	skh = JAMToDetik(JAkh);
	
	if(JGT(JAw,JAkh))
	{
		skh = skh + 86400;
	};
	
	hasil = skh - sw;
	return(hasil);
};

 