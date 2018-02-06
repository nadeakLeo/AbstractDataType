//File : main.c
//Isi : test dari realisasi point.c

#include "jam.h"
#include<stdio.h>

int main()
{
	/*Kamus*/
	int N,i;
	JAM J1, J2, jawal, jakhir;
	long lama;
	
	/*Algoritma*/
	scanf(" %d",&N);
	
	jawal = MakeJAM(23,59,59);
	jakhir = MakeJAM(0,0,0);
	for(i=1;i<=N;i++)
	{
		printf("[%d]\n",i);
		BacaJAM(&J1);
		BacaJAM(&J2);
		
		if(JLT(J1,J2))
		{
			lama = Durasi(J1,J2);
			if(JLT(J1,jawal))
			{
				jawal = J1;
			};
			
			if(JGT(J2,jakhir))
			{
				jakhir = J2;
			};
		}
		else
		{
			lama = Durasi(J2,J1);
			if(JLT(J2,jawal))
			{
				jawal = J2;
			};
			
			if(JGT(J1,jakhir))
			{
				jakhir = J1;
			};
		};	
		printf("%ld\n",lama);
	};
	TulisJAM(jawal);printf("\n");
	TulisJAM(jakhir);
	
	return 0;
};