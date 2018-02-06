/* Driver dari queue.c */

#include<stdio.h>
#include"queue.h"

void ProcessPR(Queue *Q, infotype T);

int main()
{
	int i,X;
	Queue Q;
	
	CreateEmpty(&Q,10);
	for (i = 1; i<=5; i++)
	{
		Add(&Q,(i+4));
	}
	
	ProcessPR(&Q,2);
	for (i = 1; i<=Tail(Q); i++)
	{
		Del(&Q,&X);
		printf("%d\n",X);
	}
	return 0;
};

void ProcessPR(Queue *Q, infotype T)
{
	infotype X;
	if (InfoHead(*Q) <= T)
	{
		printf("%d telah selesai diproses.\n", Head(*Q));
		Del(Q,&X);
	}
	else
	{
		Del(Q,&X);
		X = X - T;
		Add(Q,X);
	}
}