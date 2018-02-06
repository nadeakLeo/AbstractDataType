/* NIM              : 13515041 */
/* Nama             : Leo Lambarita Nadeak */
/* Tanggal          : 29 September 2016 */
/* Topik Praktikum  : Stackt */
/* Deskripsi        : Operasi data dengan Struktur Data Stack*/

/* Nama File    : bigint.c */
/* Isi          : Realisasi dari stackt.c */

#include <stdio.h>
#include"stackt.h"

int main()
{
    /* Kamus Lokal */
    char input1[100], input2[100];
    Stack S1, S2, Splus;
    address i = 0;
    infotype sum, temp, X1, X2;
    
    /* Algoritma */
    scanf("%s",&input1);
    scanf("%s",&input2);
    
    //kosongkan stack
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&Splus);
	
    //isi Stack
    while (input1[i] != '#')
    {
        switch (input1[i])
        {
            case '0' : temp = 0; break;
            case '1' : temp = 1; break;
            case '2' : temp = 2; break;
            case '3' : temp = 3; break;
            case '4' : temp = 4; break;
            case '5' : temp = 5; break;
            case '6' : temp = 6; break;
            case '7' : temp = 7; break;
            case '8' : temp = 8; break;
			default : temp = 9 ; break;
        };
        Push(&S1,temp);
        i++;
    };
    
    //isi Stack 2
    i = 0;
    while (input2[i] != '#')
    {
        switch (input2[i])
        {
            case '0' : temp = 0; break;
            case '1' : temp = 1; break;
            case '2' : temp = 2; break;
            case '3' : temp = 3; break;
            case '4' : temp = 4; break;
            case '5' : temp = 5; break;
            case '6' : temp = 6; break;
            case '7' : temp = 7; break;
            case '8' : temp = 8; break;
            default : temp = 9 ; break;
        };
        Push(&S2,temp);
        i++;
    };
    
    //Penjumlahan
    temp =0;
    while((!IsEmpty(S1) || !IsEmpty(S2) || (temp != 0)) && !IsFull(Splus))
    {
        if (IsEmpty(S1))
        {
            X1 = 0;
        }
        else
        {
            Pop(&S1,&X1);
        };
        
        if(IsEmpty(S2))
        {
            X2 = 0;
        }
        else
        {
            Pop(&S2,&X2);
        };
        sum = X1 + X2 + temp;	
			if(sum >= 10)
			{
				temp = sum / 10;
				sum = sum % 10;
			}
			else
			{
				temp = 0;
			};
		Push(&Splus,sum);
    };

    while(!IsEmpty(Splus))
    {
		printf("%d",InfoTop(Splus));
        Pop(&Splus,&temp);
    };
	printf("\n");
    return 0;
};