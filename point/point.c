/* File : point.c */
/* Deskripsi : Operasi terhadap titik yang terdapat pada sumbu kartesius */
/* Isi : realisasi / kode program dari semua prototype yang didefenisikan dalam point.h */

#include<stdio.h>
#include<math.h>
#include "point.h"

POINT MakePOINT (float X, float Y)
{
	/* Kamus Lokal */
	POINT P;
	
	Absis(P) = X;
	Ordinat(P) = Y;
	return (P);
};

void BacaPOINT (POINT *P)
{
	float a,b;//penampung sementara point
	
	scanf("%f%f", &a, &b);
	*P = MakePOINT(a,b);
	
}; 

void TulisPOINT (POINT P)
{
	printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
};


boolean EQ (POINT P1, POINT P2)
{

	/* Algoritma */
	return((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
	
};

boolean NEQ (POINT P1, POINT P2)
{
	return(!((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))));
};

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
{
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
};

boolean IsOnSbX (POINT P)
{
	return (Ordinat(P) == 0);
};

boolean IsOnSbY (POINT P)
{
	return (Absis(P) == 0);
};

int Kuadran (POINT P)
{
	/* Kamus Lokal */
	int letak;
	
	/* Prekondisi : P bukan titik origin, */
    /*              dan P tidak terletak di salah satu sumbu */
	
	if (Absis(P) > 0)
	{
		if (Ordinat(P) > 0) 
		{
			letak = 1;
		}
		else //P.y negatif
		{
			letak = 4;
		};
	}
	else //P.X negatif
	{
		if (Ordinat(P) > 0) 
		{
			letak = 2;
		}
		else //P.y negatif
		{
			letak = 3;
		};
	};
	return(letak);
};

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
{
	/* Kamus Lokal */
	POINT Q;
	
	/* Algoritma */
	Ordinat(Q) = Ordinat(P);
	Absis(Q) = Absis(P) + 1.00;
	return (Q);
};

POINT NextY (POINT P)
{
	/* Kamus Lokal */
	POINT Q;
	
	/* Algoritma */
	Ordinat(Q) = Ordinat(P) + 1.00;
	Absis(Q) = Absis(P) ;
	return (Q);
};

POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
	/* Kamus Lokal */
	POINT Q;
	
	/* Algoritma */
	Absis(Q) = Absis(P) + deltaX;
	Ordinat(Q) = Ordinat(P) + deltaY;
	
	return(Q);
};

POINT MirrorOf (POINT P, boolean SbX)
{
	/* Kamus Lokal */
	POINT Q;
	
	/* Algoritma */
	Q = P;
	if(SbX)
	{
		Ordinat(Q) = Ordinat(P) * (-1);
		Absis(Q)= Absis(P);
	}
	else //SbX bernilai False
	{
		Ordinat(Q) = Ordinat(P);
		Absis(Q)= Absis(P) * (-1);
	};
	return(Q);
};

float Jarak0 (POINT P)
{
	/* Kamus Lokal */
	float s;
	
	/* algoritma */
	s = sqrt((Absis(P) * Absis(P)) + (Ordinat(P) * Ordinat(P)));
	return(s);
};

float Panjang (POINT P1, POINT P2)
{
	/* Kamus Lokal */
	float s;
	
	/* algoritma */
	s = sqrt(((Absis(P2)-Absis(P1)) * (Absis(P2)-Absis(P1))) + ((Ordinat(P2)-Ordinat(P1)) * (Ordinat(P2)-Ordinat(P1))));
	return(s);
};

void Geser (POINT *P, float deltaX, float deltaY)
{
	POINT titik;
	Absis(titik)=Absis(*P);
	Ordinat(titik)=Ordinat(*P);
	*P = PlusDelta(titik,deltaX,deltaY);
	
	
};

void GeserKeSbX (POINT *P)
{
	Ordinat(*P) = 0;
};

void GeserKeSbY (POINT *P)
{
	Absis(*P) = 0;
};

void Mirror (POINT *P, boolean SbX)
{
	*P = MirrorOf(*P,SbX);
};

void Putar (POINT *P, float Sudut)
{
	float a;
	
	a = (Sudut/180) * (22/7);
	Absis(*P) = (Absis(*P) * cos(a)) - (Ordinat(*P) * sin(a));
	Ordinat(*P) = (Absis(*P) * sin(a)) + (Ordinat(*P) * cos(a));
};
