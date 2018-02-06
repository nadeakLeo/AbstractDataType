/*	Nama			: Leo Lambarita Nadeak */
/*	NIM				: 13515041 */
/*	Tanggal			: 22 Oktober 2016 */
/*	Topik			: List Linier Double Pointer */
/*	Deskripsi		: Implementasi dari listdp.h */

#include<stdio.h>
#include"listdp.h"
#include<stdlib.h>

/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
	return ((First(L) == Nil) && (Last(L) == Nil));
};


void CreateEmpty (List *L)
{
	First(*L) = Nil;
	Last(*L) = Nil;
};

address Alokasi (infotype X)
{
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	//Proses Alokasi
	P = (address) malloc (X * sizeof(ElmtList));
	
	//Pengecekan apakah alokasi berhasil
	if (P == NULL)
	{
		return Nil;
	}
	else{
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
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
		while ((Next(P) != Nil) && (Info(P) != X))
		{
			P = Next(P);
		}	//Next(P) = Nil atau Info(P) = X
		
		if (Info(P) == X)
			return P;
		else
			return Nil;
	}
};

void InsVFirst (List *L, infotype X)
{
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	P = Alokasi(X);
	if (P != Nil)
	{
		InsertFirst(L,P);
	}
};

void InsVLast (List *L, infotype X)
{
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	P = Alokasi(X);
	if (P != Nil)
	{
		InsertLast(L,P);
	}
};

void DelVFirst (List *L, infotype *X)
{
	address P;
	
	DelFirst(L,&P);
	*X = Info(P);
	Dealokasi(P);
};

void DelVLast (List *L, infotype *X)
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
	if(!IsEmpty(*L))
	{
		Next(P) = First(*L);
		Prev(First(*L)) = P;
	} else
	{
		Last(*L) = P;
	}
	First(*L) = P;
};

void InsertLast (List *L, address P)
{
	if(!IsEmpty(*L))
	{
		Prev(P) = Last(*L);
		Next(Last(*L)) = P;
		Last(*L) = P;
	} else
	{
		InsertFirst(L,P);
	}
};

void InsertAfter (List *L, address P, address Prec)
{
	if (Last(*L) == Prec)
	{
		InsertLast(L,P);
	} else
	{
		Next(P) = Next(Prec);
		Prev(Next(Prec)) = P;
		Prev(P) = Prec;
		Next(Prec) = P; 
	};
};

void InsertBefore (List *L, address P, address Succ)
{
	if (First(*L) = Succ)
	{
		InsertFirst(L,P);
	} else
	{
		Prev(P) = Prev(Succ);
		Next(Prev(Succ)) = P;
		Next(P) = Succ;
		Prev(Succ) = P;
	};
};

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
	*P = First(*L);
	First(*L) = Next(First(*L));
	if (First(*L) != Nil)
	{
		Prev(First(*L)) = Nil;
	} else
	{
		Last(*L) = Nil;
	}
	//Next(*P) = Nil;
};

void DelLast (List *L, address *P)
{
	*P = Last(*L);
	Last(*L) = Prev(Last(*L));
	if (Last(*L) != Nil)
	{
		Next(Last(*L)) = Nil;
	} else
	{
		First(*L) = Nil;
	}
	//Next(*P) = Nil;
};

void DelP (List *L, infotype X)
{
	if(!IsEmpty(*L))
	{
		address P = Search(*L,X);
		if (P != Nil)
		{
			if (P == First(*L))
			{
				DelFirst(L,&P);
			}
			else
			{
				address Prev = First(*L);
				while(Next(Prev) != P)
				{
					Prev = Next(Prev);
				}
				DelAfter(L,&P,Prev);
			}
			Dealokasi(P);
		}
	}
};

void DelAfter (List *L, address *Pdel, address Prec)
{
	if (Last(*L) == Next(Prec))
	{
		DelLast(L,Pdel);
	}
	else if (Next(Prec) != Nil)
	{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	Prev(Next(*Pdel)) = Prec;
	Prev(*Pdel) = Nil;
	Next(*Pdel) = Nil;
	}
};

void DelBefore (List *L, address *Pdel, address Succ)
{
	if (First(*L) == Prev(Succ))
	{
		DelFirst(L,Pdel);
	} else if (Prev(Succ) != Nil)
	{
	*Pdel = Prev(Succ);
	Prev(Succ) = Prev(Prev(Succ));
	Next(Prev(*Pdel)) = Succ;
	Next(*Pdel) = Nil;
	Prev(*Pdel) = Nil;
	}
};
/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
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
		while (Next(temp)!= Nil)
		{
			printf("%d,",Info(temp));
			temp=Next(temp);
		}	//temp = Last(L)
		printf("%d]",Info(temp));
	}
};

void PrintBackward (List L)
{
	address temp;
	if(IsEmpty(L))
	{
		printf("[]");
	}
	else		//List tidak kosong
	{
		temp = Last(L);
		printf("[");
		while(Prev(temp) != Nil)
		{
			printf("%d,",Info(temp));
			temp = Prev(temp);
		}	// temp = First(L)
		printf("%d]",Info(temp));
	}
};

