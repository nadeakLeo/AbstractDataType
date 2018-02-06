/* Nama         : Leo Lambarita Nadeak */
/* NIM          : 13515041 */
/* Nama File    : stackt.c */
/* Isi          : Implikasi dari stackt.h */

/* ***HEADER*** */
#include<stdio.h>
#include "stackt.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S)
{
	Top(*S) = Nil;
};

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S)
{
	return(Top(S) == Nil);
};

boolean IsFull (Stack S)
{
	return(Top(S) == MaxEl);
};

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype X)
{
	Top(*S) += 1;
	InfoTop(*S) = X;
};

void Pop (Stack * S, infotype* X)
{
	*X = InfoTop(*S);
	Top(*S) -= 1;
};

void CopyStack(Stack *Sout, Stack Sin)
{
	/* kamus Lokal */
	Stack Stemp;
	infotype X;

	/* Algoritma */
	CreateEmpty(&Stemp);
	while (!(IsEmpty(Sin)))
	{
		Pop(&Sin,&X);
		Push(&Stemp,X);
	};

	while (!(IsEmpty(Stemp)))
	{
		Pop(&Stemp,&X);
		Push(Sout,X);
	}
};

void InverseStack(Stack *S)
{
	/* kamus Lokal */
	Stack Stemp;
	infotype X;

	/* Algoritma */
	CreateEmpty(&Stemp);
	while (!(IsEmpty(*S)))
	{
		Pop(S,&X);
		Push(&Stemp,X);
	};

	CopyStack(S,Stemp);
};

Stack MergeStack(Stack S1, Stack S2)
{
	infotype X;

	InverseStack(&S2);

	while (!(IsEmpty(S2)) && !(IsFull(S1)))
	{
		Pop(&S2,&X);
		Push(&S1,X);
	}

	return S1;
};