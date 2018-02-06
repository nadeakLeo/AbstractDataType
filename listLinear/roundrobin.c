/*  NIM             : 13515041 */
/*  Nama            : Leo Lambarita Nadeak */
/*  Tanggal         : 27 Oktober 2016 */
/*  Topik Praktikum : List Double Pointer dan List Sirkuler */
/*  Deskripsi       : Realisasi dari listsirkuler.h */

#include<stdio.h>
#include "listsirkuler.h"

/* **********DEKLARASI FUNGSI DAN PROSEDUR********** */
void DeleteRR (List *L, infotype TQ);
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */

float Average (List L);
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */

/* ******PROGRAM UTAMA****** */
int main()
{
    int TQ, TA;
    char command;
    address last;
    List L;
    
    CreateEmpty(&L);
    //input TQ dan validasi
    scanf("%d",&TQ);
	while(TQ <= 0)
	{
		scanf("%d",&TQ);
	};    
	
	//Operasi roundrobin
	do
    {
        scanf(" %c",&command);
        if (command == 'A')
        {
            scanf(" %d",&TA);
            if (TA > 0)
            {
                InsVFirst(&L,TA);
            };
			
        }
        else if (command == 'D')
        {
            DeleteRR(&L,TQ);
        }
		else if (command == 'F')
		{
			if (!IsEmpty(L))
			{
				printf("%.2f\n",Average(L));	
			}
			else
			{
				printf("Proses selesai");
			};
		}
        else 
        {
            printf("Kode salah\n");
        }; 
    }
	while (command != 'F');
		
    return 0;
};

/* ************FUNGSI DAN PRISEDUR********* */
void DeleteRR (List *L, infotype TQ)
{
    address last;
    if (!IsEmpty(*L))
    {
        DelLast(L,&last);
		
		if (Info(last) > TQ)
		{
			InsVFirst(L,(Info(last) - TQ));
			printf("%d\n",TQ);
		}
		else
		{
			printf("%d\n", Info(last));
		}
    }
    else
    {
        printf("List kosong\n");
    };
};

float Average (List L)
{
    address temp;
    temp=First(L);
     
    float sum = 0;
	int count = 0;
    while (Next(temp) != First(L))
    {
        sum += Info(temp);
        count++;
        temp=Next(temp);
    }   //Next temp = First L
    if (temp != Nil)
    {
        count++;
        sum += Info(temp);
    };
    
    if (count!=0)
        return (sum/count);
    else
        return 0.00;
};
