/*	Nama			: Leo Lambarita Nadeak */
/*	NIM				: 13515041 */
/*	Tanggal			: 22 Oktober 2016 */
/*	Topik			: List Linier Double Pointer */
/*	Deskripsi		: Implementasi dari listsirkuler.h */

#include<stdio.h>
#include<stdlib.h>
#include "listsirkuler.h"

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
	return (First(L) == Nil);
};

void CreateEmpty (List *L)
{
	First(*L) = Nil;
};

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	P = (address) malloc (X * sizeof(ElmtList));
	
	if (P == NULL)
	{
		return Nil;
	}
	else
	{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	};
};

void Dealokasi (address P)
{
	free(P);
};

address Search (List L, infotype X)
{
	//Kamus Lokal
	address P;
	
	//Algoritma
	if (IsEmpty(L))
	{
		return Nil;
	}
	else
	{
		P = First(L);
		while ((Next(P) != First(L)) && (Info(P) != X))
		{
			P = Next(P);
		}
		
		if (Info(P) == X)
			return P;
		else
			return Nil;
	}
};

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
{
	address P;
	P = Alokasi(X);
	InsertFirst(L,P);
};

void InsVLast (List *L, infotype X)
{
	address P;
	P = Alokasi(X);
	InsertLast(L,P);
};

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
{
	address P;
	DelFirst(L,&P);
	*X = Info(P);
	Dealokasi(P);
};

void DelVLast (List *L, infotype * X)
{
	address P;
	DelLast(L,&P);
	*X = Info(P);
	Dealokasi(P);
};
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
	address temp;
	
	if(IsEmpty(*L))
	{
		Next(P) = P;
	}
	else{
		temp = First(*L);
		while(Next(temp) != First(*L))
		{
			temp = Next(temp);
		}
		Next(temp) = P;
		Next(P) = First(*L);
	}
	First(*L) = P;
};

void InsertLast (List *L, address P)
{
	address temp;
	
	if(IsEmpty(*L))
	{
		InsertFirst(L,P);
	}
	else
	{
		temp = First(*L);
		while(Next(temp) != First(*L))
		{
			temp = Next(temp);
		}
		Next(temp) = P;
		Next(P) = First(*L);	
	}
};

void InsertAfter (List *L, address P, address Prec)
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
};

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
	address temp;
	
	*P = First(*L);
	if (Next(First(*L)) == First(*L)) 		//satu elemen
	{
		First(*L) = Nil;			//kosongkan list
	}
	else
	{
		temp = First(*L);
		while(Next(temp) != First(*L))
		{
			temp = Next(temp);
		}
		Next(temp) = Next(First(*L));
		First(*L) = Next(First(*L));
	}
	//Next(*P) = Nil;
};

void DelLast (List *L, address *P)
{
	address temp, prectemp;
	
	if (Next(First(*L)) == First(*L)) 		//satu elemen
	{
		*P = First(*L);
		First(*L) = Nil;			//kosongkan list
	}
	else
	{
		temp = First(*L);
		while(Next(temp) != First(*L))
		{
			prectemp = temp;
			temp = Next(temp);
		}
		*P = temp;
		Next(prectemp) = First(*L);
	}
	//Next(*P) = Nil;
};

void DelAfter (List *L, address *Pdel, address Prec)
{
	(*Pdel)=Next(Prec);
	Next(Prec)=Next(*Pdel);
	Next(*Pdel) = Nil;
};

void DelP (List *L, infotype X)
{
	address del,temp;
	if(Search(*L,X) != Nil)
	{
		temp = First(*L);
		if (Info(temp) != X)
		{
			while((Info(Next(temp)) != X) && (Next(temp) != First(*L)))
			{
				temp = Next(temp);
			}
			del = Next(temp);
			Next(temp) = Next(del);
			Dealokasi(del);
		}
		else{
			DelFirst(L,&temp);
		}
	}
};

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
{
	if(IsEmpty(L))
	{
		printf("[]");
	}
	else{
		address temp = First(L);
		printf("[");
		while(Next(temp) != First(L))
		{
			printf("%d,",Info(temp));
			temp = Next(temp);
		}
		printf("%d]",Info(temp));
	}
};