/* NIM              : 13515041 */
/* Nama             : Leo Lambarita Nadeak */
/* Tanggal          : 29 September 2016 */
/* Topik Praktikum  : Stackt */
/* Deskripsi        : Operasi data dengan Struktur Data Stack*/

/* Nama File    : ekspresi.c */
/* Isi          : Realisasi dari mesintoken.c dan stckt.c */

#include<stdio.h>
#include<math.h>
#include"mesintoken.h"
#include"stackt.h"

int main()
{
    Stack S;
    infotype operan2, operan1, hasil;
    
    CreateEmpty(&S);
    STARTTOKEN();
    while(!EndToken)
    {
        if (CToken.tkn == 'b' && CToken.val != -1)
        {
            printf("%d\n", CToken.val);
            Push(&S,CToken.val);
        }
        else if (CToken.tkn == 'b' && CToken.val == -1)
        {
            printf("Ekspresi kosong");
        }
        else
        {
            Pop(&S,&operan2);
            Pop(&S,&operan1);
            switch (CToken.tkn)
            {
                case '+' : hasil = operan1 + operan2; break;
                case '-' : hasil = operan1 - operan2; break;
                case '*' : hasil = operan1 * operan2; break;
                case '/' : hasil = operan1 / operan2; break;
                case '^' : hasil = pow(operan1,operan2); break;
            };
            printf("%d %c %d\n",operan1,CToken.tkn,operan2);
            printf("%d\n",hasil);
            Push(&S,hasil);
        };
        ADVTOKEN();
    };
    Pop(&S,&hasil);
    printf("Hasil=%d",hasil);
    return 0;
};