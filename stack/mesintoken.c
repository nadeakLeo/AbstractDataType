/* Nama				: Leo Lambarita Nadeak */
/* NIM				: 13515041 */
/* Nama File		: mesihtoken.c */
/* Isi				: Implikasi dari mesintoken.h */

#include"mesinkar.h"
#include"mesintoken.h"
#include<stdio.h>

/* *****KAMUS GLOBAL***** */
boolean EndToken;
Token CToken;

void IgnoreBlank()
{
	while((CC == BLANK) && (CC != MARK))
	{
		ADV();
	};
};

void STARTTOKEN()
{
	START();
	IgnoreBlank();
	if (CC == MARK)
	{
		EndToken = true;
	}
	else
	{
		EndToken = false;
		SalinToken();
	};
};

void ADVTOKEN()
{
	IgnoreBlank();
	if(CC == MARK)
	{
		EndToken = true;
	}
	else
	{
		SalinToken();
		IgnoreBlank();
	};
};

void SalinToken()
{
	/* Kamus Lokal */
	int temp;
	/* Algoritma */
	CToken.val = 0;
	while ((CC != MARK) && (CC != BLANK))
	{
		if ((CC == '+') || (CC == '-') || (CC == '*') || (CC == '/') || (CC == '^'))
		{
			CToken.tkn = CC;
			CToken.val = -1;
		}
		else //CC bukan operator
		{
			switch (CC){
				case '0' : temp = 0; break;
				case '1' : temp = 1; break;
				case '2' : temp = 2; break;
				case '3' : temp = 3; break;
				case '4' : temp = 4; break;
				case '5' : temp = 5; break;
				case '6' : temp = 6; break;
				case '7' : temp = 7; break;
				case '8' : temp = 8; break;
				case '9' : temp = 9; break;
			};
			CToken.val = (CToken.val * 10) + temp;
			CToken.tkn = 'b';
		};
		ADV();
	};
};