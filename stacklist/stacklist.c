/*	Nama				: Leo Lambarita Nadeak */
/*	NIM					: 13515041 */
/*	Tanggal				: 1 November 2016 */
/*	Topik Praktikum		: Stack List */
/* 	Isi					: Implikasi dari stacklist.h */

#include<stdio.h>
#include "stacklist.h"

void Alokasi (address *P, infotype X)
{
	*P = (address) malloc (sizeof(ElmtStack));
	
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

void Dealokasi (address P)
{
	free(P);
};

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S)
{
	return (Top(S) == Nil);
};

void CreateEmpty (Stack * S)
{
	Top(*S) = Nil;
};

void Push (Stack * S, infotype X)
{
	address P;
	
	Alokasi(&P,X);
	if (P != Nil)
	{
		Next(P) = Top(*S);
		Top(*S) = P;
	};
};

void Pop (Stack * S, infotype * X)
{
	address P;
	
	P = Top(*S);
	*X = Info(P);
	Top(*S) = Next(P);
	Next(P) = Nil;
	Dealokasi(P);
};
