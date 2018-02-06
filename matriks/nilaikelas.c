/* Nama File	: nilaikelas.c */
/* Isi			: Realisasi dari matriks.c */

#include<stdio.h>
#include"matriks.h"


void TulisNilaiX(MATRIKS M, indeks j, ElType X)
{
	int i, count = 0;
	
	printf("[");
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		if(X == Elmt(M,i,j))
		{
				count++;
				if(count == CountXKol(M,j,X))
				{
					printf("%d",i);
				}
				else
				{
					printf("%d,",i);
				};
		};
		
	};
	printf("]");
};

void TulisStatistikMhs(MATRIKS M, indeks i)
{
	int max, min;
	MaxMinBrs(M,i,&max,&min);
	printf("[%d] %.2f %d %d",i,RataBrs(M,i),max,min);
};

void TulisStatistikMK(MATRIKS M,indeks j)
{
	int max, min;
	
	MaxMinKol(M,j,&max,&min);
	printf("[%d] %.2f [%d %d ",j,RataKol(M,j),max,CountXKol(M,j,max));
	TulisNilaiX(M,j,max);
	printf("] [%d %d ",min,CountXKol(M,j,min));
	TulisNilaiX(M,j,min);
	printf("]");
};

int main()
{
	/* kamus */
	int n, m;		// n:banyak mahasiswa, m:banyak mata kuliah
	MATRIKS M;
	int i,j;
	
	/* Algoritma */
	scanf("%d",&n);
	scanf("%d",&m);
	
	BacaMATRIKS(&M,n,m);
	printf("STATISTIK PER MAHASISWA\n");
	for(i = GetFirstIdxBrs(M); i<= GetLastIdxBrs(M); i++)
	{
		TulisStatistikMhs(M,i);
		printf("\n");
	};
	printf("STATISTIK PER MATA KULIAH\n");
	for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
	{
		TulisStatistikMK(M,j);
		printf("\n");
	};
	
	return 0;
};