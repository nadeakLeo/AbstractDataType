/* Nama			: Leo Lambarita Nadeak */
/* NIM			: 1351515041 */
/* Nama File	: telegram.c */
/* Isi			: Realisasi dari mesin.c */

#include<stdio.h>
#include"mesinkar.h"
#include"mesinkata.h"

/* ********Deklarasi Fungsi********* */
boolean IsKataSama(Kata K1, Kata K2);

/* *********PROGRAM UTAMA********* */
int main()
{
	/* Kamus */
	Kata koma,titik;
	int i, countTotalKata = 0, countKataReguler = 0, countKataPanjang = 0;
	float harga;
	
	/* Algoritma */
	//Membentuk kata koma
	koma.TabKata[1] = 'K';
	koma.TabKata[2] = 'O';
	koma.TabKata[3] = 'M';
	koma.TabKata[4] = 'A';
	koma.Length = 4;
	
	//Membentuk kata titik
	titik.TabKata[1] = 'T';
	titik.TabKata[2] = 'I';
	titik.TabKata[3] = 'T';
	titik.TabKata[4] = 'I';
	titik.TabKata[5] = 'K';
	titik.Length = 5;
	
	STARTKATA();
	while(!EndKata)
	{
		countTotalKata++;
		if(IsKataSama(CKata,koma))
		{
			printf(",");
		}
		else if(IsKataSama(CKata,titik))
		{
			printf(".");
		}
		else
		{
			if (countTotalKata != 1)
			{
				printf(" ");
			};
			for (i = 1;i <= CKata.Length;i++)
			{
				printf("%c",CKata.TabKata[i]);
			};
			//penghitungan biasa berdasarkan kategori
			if (CKata.Length >= 10)
			{
				countKataPanjang++;
			}
			else
			{
				countKataReguler++;
			};
		};
		ADVKATA();
	};
	printf("\n");
	harga = (countKataPanjang * 1500) + (countKataReguler * 1000);
	if(countTotalKata > 10)
	{
		harga = harga - (harga * 0.1);
	}
	else
	{
	};
	
	//tampilan kelayar
	printf("%d\n",countKataReguler);
	printf("%d\n",countKataPanjang);
	printf("%.0f\n",harga);
	return 0;
};

/* *******IMPLIKASI FUNGSI******* */
boolean IsKataSama(Kata K1, Kata K2)
{
	/* Kamus Lokal */
	boolean cek = true;
	int i = 1;
	
	/* Algoritma */
	if (K1.Length == K2.Length)
	{
		while ((cek == true) && (i <= K1.Length))
		{
			if(K1.TabKata[i] != K2.TabKata[i])
			{
				cek = false;
			};
			i++;
		};
	}
	else	// panjang kata tidak sama
	{
		cek = false;
	};
	
	return cek;
};