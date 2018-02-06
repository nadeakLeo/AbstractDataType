#include<stdio.h>
#include"listrek.h"



int main()
{
	List L1, L2, L3;
	L1 = Nil;
	L1 = Konso(-2,L1);
	L1 = Konso(4,L1);
	L1 = Konso(-12,L1);
	L1 = Konso(13,L1);
	PrintList(L1);printf("\n");

	SplitOnX(L1,10,&L2,&L3);
	PrintList(L2);printf("\n");
	PrintList(L3);printf("\n");
	return 0;
}
