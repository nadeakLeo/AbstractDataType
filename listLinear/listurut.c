/*	Nama			: Leo Lambarita Nadeak */
/*	NIM				: 13515041 */
/*	Tanggal			: 28 Oktober 2016 */
/*	Topik Praktikum	: List Double Pointer dan List Sirkuler */
/*	Deskripsi		: Realisasi dari listdp.h */

#include<stdio.h>
#include "listdp.h"

/* ******DEKLARASI FUNGSI DAN PROSEDUR****** */
address SearchPrec (List L, infotype X);
/* Mengirimkan address elemen sebelum elemen yang nilainya>=X */
/* Mencari apakah ada elemen list dengan Info(P)>=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)>=X pertama. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */

void InsertUrut (List *L, infotype X);
/* Menambahkan elemen pada list L tanpa mengganggu keterurutan L.
Manfaatkan fungsi SearchPrec. */
/* I.S. X terdefinisi. L terdefinisi, mungkin kosong.
Jika tidak kosong, L terurut membesar. */
/* F.S. X dialokasi. Jika alokasi berhasil, maka X dimasukkan sebagai salah
satu elemen L tanpa mengganggu keterurutan L. Insert elemen baru
dapat dilakukan di awal, di tengah, maupun di akhir.
Jika alokasi gagal, L tetap. */

infotype Max (List L);
/* Menghasilkan nilai terbesar dari elemen list L. L tidak kosong. */

infotype Min (List L);
/* Menghasilkan nilai terkecil dari elemen list L. L tidak kosong. */

float Average (List L);
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */


/* *******PROGRAM UTAMA******* */
int main()
{
	/* KAMUS */
	List L;
	infotype input;
	
	/* ALGORITMA */
	CreateEmpty(&L);
	do
	{
		scanf("%d",&input);
		if (input != -9999)	//Input hanya jika tidak -9999
		{
			InsertUrut(&L,input);
		};
	}
	while (input != -9999);
	
	//yang ditampilkan ke layar
	if (!IsEmpty(L))
	{
		printf("%d\n",Max(L));
		printf("%d\n",Min(L));
		printf("%.2f\n",Average(L));
		PrintForward(L);printf("\n");
		PrintBackward(L);printf("\n");
	}
	else
	{
		printf("[]\n");
	}
	
	
	return 0;
}
/* **********FUNGSI DAN PROSEDUR*********** */
address SearchPrec (List L, infotype X)
{
	address P, Prec;
	
	P = First(L);
	Prec = Nil;
	
	while (P != Nil && Info(P) < X)
	{
		Prec = P;
		P = Next(P);
	}
	
	return Prec;
};


void InsertUrut (List *L, infotype X)
{
	if(IsEmpty(*L))
	{
		InsVFirst(L,X);
	}
	else
	{
		if (SearchPrec(*L,X) != Nil)
		{
			if (SearchPrec(*L,X) == Last(*L))
			{
				InsVLast(L,X);
			}
			else
			{
				if (Alokasi(X) != Nil)
				{
					InsertAfter(L,Alokasi(X),SearchPrec(*L,X));
				}
			}
		}
	};
};

infotype Max (List L)
{
	return Info(Last(L));
};

infotype Min (List L)
{
	return Info(First(L));
};

float Average (List L)
{
	int count = 0;
	float sum = 0;
	address temp;
		temp = First(L);
				
		while(temp != Nil)
		{
			sum += Info(temp);
			count++;
			temp = Next(temp);
		}
		return (sum/count);
};