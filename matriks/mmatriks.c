//Nama File : mmatriks.c
//Isi : Realisasi dari matriks.h

#include<stdio.h>
#include"matriks.c"

int main()
{
	MATRIKS M,N;
	
	
	BacaMATRIKS(&M,3,3);
	
	printf("\n");
//	BacaMATRIKS(&N,3,3);
	
	/*printf("M + N : \n");
	TulisMATRIKS(TambahMATRIKS(M,N));
	printf("M - N : \n");
	TulisMATRIKS(KurangMATRIKS(M,N));
	printf("M * N : \n");
	TulisMATRIKS(KaliMATRIKS(M,N));
	printf("M *3 : \n");
	TulisMATRIKS(KaliKons(M,3));
	printf("\n Determinan = %.2f \n", Determinan(M)); */
	Transpose(&M);
	TulisMATRIKS(M);
	
	return 0;
};