/*	Nama				: Leo Lambarita Nadeak */
/*	NIM					: 13515041 */
/*	Tanggal				: 1 November 2016 */
/*	Topik Praktikum		: Stack List */
/* 	Isi					: Implikasi dari stacklist.h */

#include<stdio.h>
#include "queuelist.h"

void Alokasi (address *P, infotype X)
{
	*P = (address) malloc (sizeof(ElmtQueue));
	
	if (P == NULL)		//Jika Alokasi gagal
	{
		return Nil;
	}
	else
	{
		Info(*P) = X;
		Next(*P) = Nil;
	}
};

void Dealokasi (address  P)
{
	free(P);
};

boolean IsEmpty (Queue Q)
{
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
};

int NbElmt(Queue Q)
{
	if (IsEmpty(Q))
	{
		return 0;
	}
	else
	{
		address P;
		int count = 0;
		
		P = Head(Q);
		while (P != Nil)
		{
			count++;
			P = Next(P);
		}
		
		return count;
	}
}

void CreateEmpty(Queue * Q)
{
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
};

void Add (Queue * Q, infotype X)
{
	/* Kamus Lokal */
	address P;

	/* Algoritma */
	Alokasi(&P,X);
	if (P != Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q) = P;
			Tail(*Q) = P;
		} else {
			Next(Tail(*Q)) = P;
			Tail(*Q) = P;
		}
	}
};

void Del(Queue * Q, infotype * X)
{
	address P = Head(*Q);
	*X = InfoHead(*Q);
	Head(*Q) = Next(Head(*Q));
	if (Head(*Q) == Nil)
	{
		Tail(*Q) = Nil;
	}
	Dealokasi(P);
};