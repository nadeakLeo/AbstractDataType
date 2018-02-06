//driver

#include<stdio.h>
#include "listdp.h"

int main()
{
	List L;
	address input, before = Alokasi(10);
	CreateEmpty(&L);
	
	/*if (IsEmpty(L))
	{
		printf("kosong");
	}
	else
	{
		printf("tidak kosong");
	}*/
	InsVFirst(&L,10);
	InsVLast(&L,32);
	InsVFirst(&L,8);
	//InsertAfter(&L,Alokasi(13),before);
	
	
	//rintForward(L);
	//DelP(&L,8);
	//PrintInfo(L);
	printf("\n%d",Search(L,10));
	return 0;
};