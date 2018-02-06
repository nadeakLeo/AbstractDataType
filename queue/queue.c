/*	Nama				: Leo Lambarita Nadeak
	NIM					: 13515041
	Tanggal				: 05 Oktober 2016
	Topik Praktikum		: Queue
	Deskripsi			: Impilkasi dari queue.h */

/* ******************************************************** */
/* ******LIBRARY****** */
#include<stdio.h>
#include "queue.h"
#include<stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
{
	return((Head(Q) == Nil) && (Tail(Q) == Nil));
};

boolean IsFull (Queue Q)
{
	return ((Head(Q) = 1) && (NBElmt(Q) == MaxEl(Q)));
};

int NBElmt (Queue Q)
{
	/* Kamus Lokal */
	int Elmt;
	
	/* algoritma */
	if(IsEmpty(Q))
	{
		Elmt = 0;
	}
	else 	//queue tidak kosong
	{
		Elmt = Tail(Q) - Head(Q) + 1;
	}
	return (Elmt);
};

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
{
	(*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
	if ((*Q).T != NULL)
	{
		MaxEl(*Q) = Max;
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else 	//Alokasi Gagal
	{
		MaxEl(*Q) = Nil;
	}
};

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
{
	MaxEl(*Q) = Nil;
	free((*Q).T);
};

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
{
  if (IsEmpty(*Q))
  {
    Head(*Q)=1;
    Tail(*Q)=1;
  }
  else if (Tail(*Q)==MaxEl(*Q))
  {
    Tail(*Q)=((Tail(*Q)+1)-MaxEl(*Q));
  }
  else
  {
    Tail(*Q)=(Tail(*Q)+1);
  }
  InfoTail(*Q)=X;
};

void Del (Queue * Q, infotype * X)
{
	*X = InfoHead(*Q);
	
	if (Head(*Q) == Tail(*Q)) // set menjadi queue kosong
	{
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else
	{
		Head(*Q)++;
	}
};

