/* Nama			: Leo Lambarita Nadeak */
/* NIM			: 16515325 */
/* Nama File	: ekspresi.c */
/* Isi			: Realisasi dari mesintoken.c */

#include<stdio.h>
#include "mesintoken.h"
#include "mesinkar.h"

/* ********PROGRAM UTAMA******** */
int main()
{
	/* Kamus Lokal */
	int count = 0;		//penghitung jumlah token
	/* Algoritma */
	STARTTOKEN();
	while (!EndToken)
	{
		count++;
		if (CToken.tkn == 'b')
		{
			printf("%d\n", CToken.val);
		}
		else
		{
			printf("%c\n", CToken.tkn);
		};
		ADVTOKEN();
	};
	
	if(count == 0)
	{
		printf("Ekspresi Kosong");
	};
	return 0;
};