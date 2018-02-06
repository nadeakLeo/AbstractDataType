/*	NIM			: 13515041 */
/*	Nama		: Leo Lambarita Nadeak */
/*	Tanggal		: 18 Oktober 2016 */
/*	Topik		: List Linier */


#include<stdio.h>
#include<stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
boolean IsEmpty (List L)
{
	return (First(L) == Nil);
};

void CreateEmpty (List *L)
{
	First(*L) = Nil;
};

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

void Dealokasi (address *P)
{
	free(*P);
};

address Search (List L, infotype X)
{
	address P;
	boolean stop;
	
	P = First(L);
	stop = false;
	
	while ((P != Nil) && !(stop))
	{
		if(Info(P) == X)
		{
			stop = true;
		}
		else
		{
			P = Next(P);
		}
	}
	if (stop)
	{
		return P;
	}
	else
	{
		return Nil;
	}
};

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
{
	address P;
	P = Alokasi(X);
	Next(P) = First(*L);
	First(*L) = P;
};

void InsVLast (List *L, infotype X)
{
	address P;
	if (!IsEmpty(*L))
	{
		P = First(*L);
		while (Next(P) != Nil)
		{
			P = Next(P);
		}
		InsertAfter(L,Alokasi(X),P);
	}
	else
	{
		Next(Alokasi(X)) = First(*L);
		First(*L) = Alokasi(X);
	}
};

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
{
	address P;
	
	P =First(*L);
	*X = Info(P);
	First(*L) = Next(P);
	Dealokasi(&P);
};

void DelVLast (List *L, infotype *X)
{
	address P;

  DelLast(L, &P);
  (*X) = Info(P);
  Dealokasi(&P);
	
};

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
	Next(P) = First(*L);
	First(*L) = P;
	
};

void InsertAfter (List *L, address P, address Prec)
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
};

void InsertLast (List *L, address P)
{
	address temp;
	
	if(!IsEmpty(*L))
	{
		temp = First(*L);
		while(Next(temp) != Nil)
		{
			temp = Next(temp);
		}
		Next(P) = Next(temp);
		Next(temp) = P;
	}
	else
	{
		Next(P) = First(*L);
		First(*L) = P;
	}
};

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
	(*P)=First(*L);
	First(*L)=Next(First(*L));
};

void DelP (List *L, infotype X)
{
	address del,temp;
	if(Search(*L,X) != Nil)
	{
		temp = First(*L);
		if (Info(temp) != X)
		{
			while((Info(Next(temp)) != X) && (Next(temp) != Nil))
			{
				temp = Next(temp);
			}
			del = Next(temp);
			Next(temp) = Next(del);
			Dealokasi(&del);
		}
		else{
			DelFirst(L,&temp);
		}
	}
		
};

void DelLast (List *L, address *P)
{
	address temp;
	
	if (Next(First(*L))!=Nil)
	{
		temp=First(*L);
		while (Next(Next(temp))!=Nil)
		{
			temp=Next(temp);
		}
		(*P)=Next(temp);
		Next(temp)=Nil;
	}
	else 
	{
		(*P)=First(*L);
		First(*L)=Nil;
	}
};

void DelAfter (List *L, address *Pdel, address Prec)
{
	(*Pdel)=Next(Prec);
	Next(Prec)=Next(*Pdel);
};

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
{
	address temp;
	if (IsEmpty(L))
	{
		printf("[]");
	}
	else
	{
		temp = First(L);
		printf("[");
		while (Next(temp)!=Nil)
		{
		printf("%d,",Info(temp));
		temp=Next(temp);
		}
		printf("%d]",Info(temp));
	}
};

int NbElmt (List L)
{
	int count = 1;
	address P;
	if(IsEmpty(L))
	{
		return 0;
	}
	else
	{
		P =First(L);
		while(Next(P)!=Nil)
		{
			count++;
			P = Next(P);
		}
		return count;
	};
};

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
{
	infotype maks;
	address P;
	
	P = First(L);
	maks = Info(P);
	
	while (P != Nil)
	{
		if (maks < Info(P))
		{
			maks = Info(P);
		}
		P = Next(P);
	}
	
	return maks;
};

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
{
	address P;

	CreateEmpty(L3);
	if (IsEmpty(*L1))
	{
		First(*L3)=First(*L2);
	}
	else 
	{
		First(*L3)=First(*L1);
		P=First(*L1);
		while (Next(P)!=Nil){
			P=Next(P);
		}
		Next(P)=First(*L2);
	}
	CreateEmpty(L2);
	CreateEmpty(L1);
};