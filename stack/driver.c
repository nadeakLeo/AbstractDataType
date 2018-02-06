/* driver.c */

#include<stdio.h>
#include"stackt.h"


int main(){
	Stack S1, S2, S3;
	int i;
	
	for(i = 1; i <= 4; i++)
	{
		S1.T[i] = i;
		S2.T[i] = i * 3;
	};
	S1.TOP = i;
	S2.TOP = i;
	
	S3 = MergeStack(S1,S2);

	for(i = 1; i <= S3.TOP; i++)
	{
		printf("%d",S3.T[i]);
	};
	
	
	return 0;
};