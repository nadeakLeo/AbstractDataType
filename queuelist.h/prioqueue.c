/* NIM				: 13515041 */
/* Nama				: Leo Lambarita Nadeak */
/* Tanggal			: 06 November 2016 */
/* Topik Praktikum	: QueueList */
/* Deskripsi		: Implikasi dari prioqueue.h */

/* ****LIBRARY**** */
#include<stdio.h>
#include "prioqueue.h"

/* Prototype manajemen memori */
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

boolean IsEmpty (PrioQueue Q)
{
	return (Head(Q) == Nil);
};

int NbElmt(PrioQueue Q)
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
};

void CreateEmpty(PrioQueue * Q)
{
	Head(*Q) = Nil;
};

void Add (PrioQueue * Q, infotype X)
{
	address P;
	
	Alokasi(&P,X);
	
	if (P != Nil) {
		if (IsEmpty(*Q)) {
			Head(*Q) = P;
		}
		else {
			Next(Tail(*Q)) = P;
			Tail(*Q) = P;
		}
	}
};

void Del(PrioQueue * Q, infotype * X)
{
	
};