/* Nama File : mesinkata.c */
/* Isi		 : Implementasi dari mesinkata.h */

#include<stdio.h>
#include"mesinkata.h"


boolean EndKata;
Kata CKata;

void IgnoreBlank()
{
	while((CC == BLANK) && (CC != MARK))
	{
		ADV();
	};
};

void STARTKATA()
{
	START();
	IgnoreBlank();
	if (CC == MARK) 
	{
		EndKata = true;
		CKata.Length = 0;
	}
	else // CC != MARK
	{
		EndKata = false;
		SalinKata();
	};
};

void ADVKATA()
{
	IgnoreBlank();
	if (CC == MARK) 
	{
		EndKata = true;
	}
	else // CC != MARK
	{
		SalinKata();
		IgnoreBlank();
	};
};

void SalinKata()
{
	/* Kamus Lokal */
	   int i=1;
	   
	  /* Agoritma */
        
        while ((CC != BLANK) && (CC != MARK) && (i <= NMax) ){
        CKata.TabKata[i] = CC ;
        i++;
        ADV();
        }
		i -= 1;
        if (i > NMax){
            CKata.Length=NMax;
        }

        else{
            CKata.Length=i;
        };
};