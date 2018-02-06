/* File : marray.c*/
/* Isi : realisasi dari array.c */

#include<stdio.h>
#include"array.c"

int main()
{
	TabInt T1, T2, T3;
	IdxType i, X;
	
	BacaIsi(&T1);
	TulisIsi(T1);
	printf("\n");
	BacaIsiTab(&T2);
	
	
	/*MaxSortDesc(&T1);
	TulisIsi(T1);
	printf("\n");
	InsSortAsc(&T1);
	TulisIsi(T1)*/ ;
	TulisIsiTab(T2);
	if(IsLess(T1,T2))
	{
		printf("ya\n");
	}
	else
	{
		printf("tidak\n");
	};
	//Del1Urut(&T1,4);
	//TulisIsi(T1);
	//printf("%d",X);
	return 0;
};
