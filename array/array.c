//NIM				: 13515041
//Nama				: Leo Lambarita Nadeak
//Tanggal			: 06 September 2016
//Topik Praktikum	: ADT Array
//Deskripsi			: implementasi dari array.h

#include<stdio.h>
#include "array.h"

/* ********** KONSTRUKTOR ********** */
void MakeEmpty (TabInt * T)
{
	Neff(*T) = 0;
};

/* ********** SELEKTOR (TAMBAHAN) ********** */
int NbElmt (TabInt T)
{
	return(Neff(T));
};

int MaxNbEl (TabInt T)
{
	return((IdxMax - IdxMin) + 1);
};

IdxType GetFirstIdx (TabInt T)
{
	return(IdxMin);
};

IdxType GetLastIdx (TabInt T)
{
	return((IdxMin + NbElmt(T)) - 1);
};

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
{
	return((i >= IdxMin) && (i <= IdxMax));
};

boolean IsIdxEff (TabInt T, IdxType i)
{
	return((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
};

/* ********** TEST KOSONG/PENUH ********** */
boolean IsEmpty (TabInt T)
{	
	return(NbElmt(T) == 0);
};

boolean IsFull (TabInt T)
{
	return(NbElmt(T) == IdxMax);
};
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void BacaIsi (TabInt * T)
{
	/* Kamus Lokal */
	ElType N;
	IdxType i;
	
	/* Algoritma */
	MakeEmpty(T);
	do
	{
		scanf("%d",&N);
	}
	while ((N<0) || (N > MaxNbEl(*T)));

		Neff(*T) = N;
		for(i = IdxMin; i <= Neff(*T); i++)
		{
			scanf("%d",&Elmt(*T,i));
		};

};

void BacaIsiTab (TabInt * T)
{
	/* Kamus Lokal */
	IdxType i = IdxMin;
	ElType input;
	
	/*ALgoritma*/
	MakeEmpty(T);
	
	do
	{
		scanf("%d",&input);
		if (input != -9999)
		{
			Elmt(*T,i) = input;
			i = i + 1;
		};
	}
	while((input != -9999)&&(i <= MaxNbEl(*T)));
	
	Neff(*T) = i-1;
};

void TulisIsi (TabInt T)
{
	IdxType i;
	
	if(Neff(T) == 0)
	{
		printf("Tabel kosong\n");
	}
	else // Tabel tidak kosong
	{
		for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			printf("[%d]",i);
			printf("%d\n",Elmt(T,i));
		};
	};
};

void TulisIsiTab (TabInt T)
{
	IdxType i;
	
	printf("[");
	for (i = GetFirstIdx(T); i <= (GetLastIdx(T) - 1); i++)
	{
		printf("%d,",Elmt(T,i));
	};
	printf("%d",Elmt(T,NbElmt(T)));
	printf("]\n");
	
};

TabInt PlusTab (TabInt T1, TabInt T2)
{
	IdxType i;
	TabInt T;
	
	MakeEmpty(&T);
	
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
	{
		Elmt(T,i) = Elmt(T1,i) + Elmt(T2,i);
	};
	Neff(T) = NbElmt(T1);
	return(T);
};

TabInt MinusTab (TabInt T1, TabInt T2)
{
	IdxType i;
	TabInt T;
	
	MakeEmpty(&T);
	
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
	{
		Elmt(T,i) = Elmt(T1,i) - Elmt(T2,i);
	};
	Neff(T) = NbElmt(T1);
	return(T);
};

TabInt KaliTab (TabInt T1, TabInt T2)
{
	IdxType i;
	TabInt T;
	
	MakeEmpty(&T);
	
	for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
	{
		Elmt(T,i) = Elmt(T1,i) * Elmt(T2,i);
	};
	Neff(T) = NbElmt(T1);
	return(T);
};

TabInt KaliKons (TabInt Tin, ElType c)
{
	IdxType i;
	TabInt T;
	
	MakeEmpty(&T);
	
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
	{
		Elmt(T,i) = Elmt(Tin,i) * c;
	};
	Neff(T) = NbElmt(Tin);
	return(T);
};

boolean IsEQ (TabInt T1, TabInt T2)
{
	boolean cek;
	IdxType i = IdxMin;
	if(NbElmt(T1) == NbElmt(T2))
	{
		cek = 1;
		for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		{
			if (Elmt(T1,i) != Elmt(T2,i))
			{
				cek = 0;
			};
		};
	}
	else //jumalh elemen T1 dan T2 tidak sama
	{
		cek = 0;
	};
	
	return(cek);
};
	
boolean IsLess (TabInt T1, TabInt T2)
{
	boolean cek;
	IdxType i = IdxMin;
	if(NbElmt(T1) <= NbElmt(T2))
	{
		cek = 1;
		for(i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
		{
			if (Elmt(T1,i) > Elmt(T2,i))
			{
				cek = 0;
			};
		};
	}
	else //jumalh elemen T1 > T2 tidak sama
	{
		
		cek = 1;
		for(i = GetFirstIdx(T2); i <= GetLastIdx(T2); i++)
		{
			if (Elmt(T1,i) > Elmt(T2,i))
			{
				cek = 0;
			};
		};
	};
	
	return(cek);
};

IdxType Search1 (TabInt T, ElType X)
{
	IdxType hasil, i = IdxMin;
	if (IsEmpty(T))
	{
		hasil = IdxUndef;
	}
	else //Tabel tidak kosong
	{
		while(X != Elmt(T,i) && (i <= GetLastIdx(T)+1))
		{
			i = i + 1;
		};
		if(i <= NbElmt(T))
		{
			hasil = i;
		}
		else
		{
			hasil = IdxUndef;
		};
	};
	return(hasil);
};

IdxType Search2 (TabInt T, ElType X)
{
	IdxType hasil, i = IdxMin;
	boolean found;
	
	if (IsEmpty(T))
	{
		hasil = IdxUndef;
	}
	else //Tabel tidak kosong
	{
		found = false;
		while((found == false) && (i <= GetLastIdx(T) + 1))
		{
			if (Elmt(T,i) == X)
			{		
				found = true;
			};
			i = i + 1;
		};
		i = i - 1;
		if(i <= NbElmt(T))
		{
			hasil = i;
		}
		else
		{
			hasil = IdxUndef;
		};
	};
	return(hasil);
};

boolean SearchB (TabInt T, ElType X)
{
	return(Search1(T,X) != IdxUndef);
};

boolean SearchSentinel (TabInt T, ElType X)
{
	boolean cek;
    IdxType i, hasil;

    cek = false;
    Elmt(T,0) = X;
    for (i=GetFirstIdx(T)-1; i<=GetLastIdx(T); i++)
    {
        if (Elmt(T,i) == X)
        {
            hasil = i;
        }
    }
    if (hasil == 0)
    {
        cek = false;
    }
    else
    {
        cek = true;
    }
    return (cek);
};

ElType ValMax (TabInt T)
{
	ElType maks;
	IdxType i;
	
	maks = Elmt(T, GetFirstIdx(T));
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
	{
		if (maks < Elmt(T,i))
		{
			maks = Elmt(T,i);
		};
	};
	
	return(maks);
};

ElType ValMin (TabInt T)
{
	ElType min;
	IdxType i;
	
	min = Elmt(T, GetFirstIdx(T));
	for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
	{
		if (min > Elmt(T,i))
		{
			min = Elmt(T,i);
		};
	};
	
	return(min);
};

IdxType IdxMaxTab (TabInt T)
{
	return(Search1(T,ValMax(T)));
};

IdxType IdxMinTab (TabInt T)
{
	return(Search1(T,ValMin(T)));
};

void CopyTab (TabInt Tin, TabInt * Tout)
{
	IdxType i;
	
	MakeEmpty(Tout);
	Neff(*Tout) = NbElmt(Tin);
	for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++)
	{
		Elmt(*Tout,i) = Elmt(Tin, i);
	};
};

TabInt InverseTab (TabInt T)
{
	TabInt hasil;
	IdxType i;
	
	if(IsEmpty(T))
	{
		MakeEmpty(&hasil);
	}
	else//T tidak kosong
	{
		Neff(hasil) = NbElmt(T);
		for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
		{
			Elmt(hasil,(NbElmt(hasil)+1 - i)) = Elmt(T,i);
		};
	};
	
	return(hasil);
};

boolean IsSimetris (TabInt T)
{
	boolean cek;
	TabInt T2;
	if(IsEmpty(T))
	{
		cek = 1;
	}
	else//T tidak kosong
	{
		T2 = InverseTab(T);
		if(IsEQ(T,T2))
		{
			cek = 1;
		}
		else
		{
			cek = 0;
		};
	};
	
	return (cek);
};

/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
{
	TabInt *T1 = T;
	IdxType i = GetFirstIdx(*T1), N = GetLastIdx(*T1), j = i+1;
	ElType temp;
	
	while (i<N)
	{
		j = i + 1;
		while(j <= N)
		{
			if(Elmt(*T1,j) > Elmt(*T1,i))
			{
				temp = Elmt(*T1,j);
				Elmt(*T1,j) = Elmt(*T1,i);
				Elmt(*T1,i) = temp;
			};
			j++;
		};
		i++;
	};
	*T = *T1;
};

void InsSortAsc (TabInt * T)
{
	TabInt *T1 = T;
	MaxSortDesc(T1);
	*T = InverseTab(*T1);
	
};

/* ********** MENAMBAH ELEMEN ********** */
void AddAsLastEl (TabInt * T, ElType X)
{
		Neff(*T) = NbElmt(*T) + 1;
		Elmt(*T,NbElmt(*T)) = X;
};

void AddEli (TabInt * T, ElType X, IdxType i)
{
	IdxType igeser = GetLastIdx(*T);
    while(igeser >= i)
    {
		Elmt(*T,igeser+1) = Elmt(*T,igeser);
		igeser = igeser - 1;
    };
    Elmt(*T,i) = X;
	
};

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
{
	*X = Elmt(*T, GetLastIdx(*T));
	Neff(*T) = NbElmt(*T) - 1;
};

void DelEli (TabInt * T, IdxType i, ElType * X)
{
	IdxType igeser;
	*X = Elmt(*T, i);
    for(igeser=i; igeser<=GetLastIdx(*T); igeser++)
    {
        Elmt(*T,igeser)=Elmt(*T,igeser+1);
    };
	Neff(*T) = NbElmt(*T) - 1;
};

/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
{
	if(SearchB(*T,X))
	{
		printf("nilai sudah ada\n");
	}
	else//T unik
	{
		AddAsLastEl(T,X);
		Neff(*T) = NbElmt(*T) + 1;
	};
};

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
{
	InsSortAsc(&T);
	return(Search1(T,X));
};

ElType MaxUrut (TabInt T)
{
    return (Elmt(T,GetLastIdx(T)));
};

ElType MinUrut (TabInt T)
{
    return (Elmt(T,GetFirstIdx(T)));
};

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
{
	InsSortAsc(&T);
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X)
{
    IdxType i;
	
	
    if (!IsFull(*T))
    {
        AddAsLastEl(T, X);
    };
	InsSortAsc(T);
}
void Del1Urut (TabInt * T, ElType X)
{
    IdxType i = Search1(*T,X);

	if( i != IdxUndef)
	{
    DelEli(T,i,&X);
	};
}
