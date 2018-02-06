/*  NIM             : 13515041 */
/*  Nama            : Leo Lambarita Nadeak */
/*  Tanggal         : 03 November 2016 */
/*  Topik Praktikum : StackList dan Queque List */
/*  Deskripsi       : Realisasi stacklist.c */

#include<stdio.h>
#include "stacklist.h"

/* *********PROGRAM UTAMA *********** */
int main()
{
    /* KAMUS */
    char input[100];
    int i, count1 = 0, count2 = 0;
    infotype X;
    Stack S,Stemp;
    boolean cek;
    
    /* ALGORITMA */
    CreateEmpty(&S);
    
    //Mengisi Stack
    scanf("%s",&input);
    for (i = 0; i <= 100; i++)
    {
        if ((input[i] == '{') || (input[i] == '}'))
        {
            if (input[i] == '{')
            {
                X = 1;
            }
            else
            {
                X = 2;
            }
            Push(&S,X);
        }
    }
    
    
    //Cek apakah berurutan
    CreateEmpty(&Stemp);
    while(!IsEmpty(S))
    {
        Pop(&S,&X);
        if (X == 1)
        {
            count1 = count1 + 1;
        }
        else
        {
            count2 = count2 + 1;
        }
        
        Push(&Stemp,X);
    };
    
    if (count1 != count2)
    {
        cek = false;
    }
    else
    {
        count2 = 0;
    int X;
        while(X != 2)
        {
            Pop(&Stemp,&X);
            count2 = count2 + 1;
        }
        count2 = count2 - 1;
    
        if (count2 == count1)
        {
            cek = true;
        }
        else
        {
                                
        }
    }
    
    if (cek)
    {
        printf("ok\n");
    }
    else
    {
        printf("salah\n");
    };
    return 0;
};

