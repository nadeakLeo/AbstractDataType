/* File : garis.c */
/* Deskripsi : Operasi terhadap titik yang terdapat pada sumbu kartesius */
/* Isi : realisasi / kode program dari semua prototype yang didefenisikan dalam garis.h */

#include<stdio.h>
#include<math.h>
#include "garis.h"

void MakeGARIS (POINT P1, POINT P2, GARIS * L)
{
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
};

void BacaGARIS (GARIS * L)
{
	POINT p, q;
	GARIS l;
	do
	{
		//Baca point
		BacaPOINT(&p);
		BacaPOINT(&q);
		if(EQ(p,q))
		{
			printf("Garis tidak valid\n");
		};
	}
	while (NEQ(p,q));
	
		//Bentuk garis
		MakeGARIS(p,q,&l);
		*L = l;
};

void TulisGARIS (GARIS L)
{
	printf("((%.2f,%.2f),(%.2f,%.2f))", Absis(PAwal(L)), Ordinat(PAwal(L)), Absis(PAkhir(L)), Ordinat(PAkhir(L)));
};


float PanjangGARIS (GARIS L)
{
	return(sqrt(((Ordinat(PAkhir(L)) - Ordinat(PAwal(L)))*(Ordinat(PAkhir(L)) - Ordinat(PAwal(L)))) + ((Absis(PAkhir(L)) - Absis(PAwal(L)))*(Absis(PAkhir(L)) - Absis(PAwal(L))))));
}; 

float Gradien (GARIS L)
{
	/* Prekondisi : x1 != x2 */
	
	return((Ordinat(PAkhir(L)) - Ordinat(PAwal(L)))/(Absis(PAkhir(L)) - Absis(PAwal(L))));
}; 

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
	Geser(&PAwal(*L),deltaX,deltaY);
	Geser(&PAkhir(*L),deltaX,deltaY);
};

boolean IsTegakLurus (GARIS L1, GARIS L2)
{
	return((Gradien(L1)*Gradien(L2)) == -1.00 ) ;
};

boolean IsSejajar (GARIS L1, GARIS L2)
{
	return(Gradien(L1) == Gradien(L2)); 
};

