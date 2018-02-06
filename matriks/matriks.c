//Nama File : matriks.c
//Isi : implikasi dari file matriks.h

#include<stdio.h>
#include"matriks.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M)
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}; 

boolean IsIdxValid (int i, int j)
{
	return((i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax));
};

indeks GetFirstIdxBrs (MATRIKS M)
{
	return(BrsMin);
};

indeks GetFirstIdxKol (MATRIKS M)
{
	return(KolMin);
};

indeks GetLastIdxBrs (MATRIKS M)
{
	return(BrsMin + NBrsEff(M) - 1);
};

indeks GetLastIdxKol (MATRIKS M)
{
	return(KolMin + NKolEff(M) - 1);
};

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
{
	return((i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M)));
};

ElType GetElmtDiagonal (MATRIKS M, indeks i)
{
	return(Elmt(M,i,i));
};

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
{
	MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
	*MHsl = MIn;
};

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
{
	indeks i, j;
	
	if(IsIdxValid(NB,NK))
	{
		MakeMATRIKS(NB,NK,M);
		for(i = GetFirstIdxBrs(*M); i <= NB; i++)
		{
			for (j = GetFirstIdxKol(*M); j <= NK; j++)
			{
				scanf("%d",&Elmt(*M,i,j));
			};
		};
	};
};

void TulisMATRIKS (MATRIKS M)
{
	indeks i, j;
	
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
		{
			if(j == GetLastIdxKol(M))
			{
				printf("%d",Elmt(M,i,j));
			}
			else
			{
				printf("%d ",Elmt(M,i,j));
			};
		};
		if(i != GetLastIdxBrs(M))
		{
			printf("\n");
		};
	};
};

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
{
	MATRIKS MHsl;
	indeks i,j;
	
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHsl);
	for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
		{
			for (j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
			{
				Elmt(MHsl,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
			};
		};
	
	return(MHsl);
};

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
{
	MATRIKS MHsl;
	indeks i,j;
	
	MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&MHsl);
	for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
		{
			for (j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
			{
				Elmt(MHsl,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
			};
		};
	
	return(MHsl);
};

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
{
	MATRIKS MHsl;
	indeks i,j,k;
	
	MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&MHsl);
	for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M2); i++)
		{
			for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++)
			{
				Elmt(MHsl,i,j) = 0;
				for(k = GetFirstIdxBrs(M1); k <= GetLastIdxBrs(M1); k++)
				{
					Elmt(MHsl,i,j) = Elmt(MHsl,i,j) + (Elmt(M1,i,k) * Elmt(M2,k,j));
				};
			};
		};
	
	return(MHsl);
};

MATRIKS KaliKons (MATRIKS M, ElType X)
{
	MATRIKS MHsl;
	indeks i,j;
	
	MakeMATRIKS(NBrsEff(M),NKolEff(M),&MHsl);
		for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
		{
			for (j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
			{
				Elmt(MHsl,i,j) = Elmt(M,i,j) * X;
			};
		};
	
	return(MHsl);

};

void PKaliKons (MATRIKS * M, ElType K)
{
	*M = KaliKons(*M,K);
};

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
{
	boolean cek;
	indeks i, j;
	if(NBElmt(M1) == NBElmt(M2))
	{
		cek = true;
		i = GetFirstIdxBrs(M1);
		while(cek && (i <= GetLastIdxBrs(M1)))
		{
			j = GetFirstIdxKol(M1);	
			while(cek && (j <= GetLastIdxKol(M1)))
			{
				if(Elmt(M1,i,j) != Elmt(M2,i,j))
				{
					cek = false;
				};
				j++;
			};
			i++;
		};
	}
	else//tidak sama
	{
		cek = false;
	};
	
	return cek;
};

boolean NEQ (MATRIKS M1, MATRIKS M2)
{
	return(!EQ(M1,M2));
};

boolean EQSize (MATRIKS M1, MATRIKS M2)
{
	return((NBrsEff(M1) == NBrsEff (M2)) && (NKolEff (M1) == NKolEff (M2)));
};

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
{
	return(NBrsEff(M) * NKolEff(M));
};

boolean IsBujurSangkar (MATRIKS M)
{
	return(NBrsEff(M) == NKolEff(M));
};

boolean IsSimetri (MATRIKS M)
{
	boolean cek;
	int i = GetFirstIdxBrs(M),j = GetFirstIdxKol(M);
	
	if(IsBujurSangkar(M))
	{
		cek = true;
		while(cek && (i <= GetLastIdxBrs(M)))
		{
			j = GetFirstIdxKol(M);
			while(cek && (j <= GetLastIdxKol(M)))
			{
				if(Elmt(M,i,j) != Elmt(M,j,i))
				{
					cek = false;
				};
				j++;
			};
			i++;
		};
	}
	else
	{
		cek = false;
	};
	
	return cek;
};

boolean IsSatuan (MATRIKS M)
{
	boolean cek;
	int i ,j = GetFirstIdxKol(M);
	
	if(IsBujurSangkar(M))
	{
		cek = true;
		i = GetFirstIdxBrs(M);
        while ((cek)&&(i<=GetLastIdxBrs(M)))
        {
            j = GetFirstIdxKol(M);
            while ((cek)&&(j<=GetLastIdxKol(M)))
            {
               if (i!=j)
               {
                   if (Elmt(M,i,j)!=0)
                   {
                       cek = false;
                   };
               }
               else
               {
                   if (Elmt(M,i,j)!=1)
                   {
                       cek = false;
                   };
               };
               j++;
            };
            i++;
        };
	}
	else
	{
		cek = false;
	};
	
	return cek;
};

boolean IsSparse (MATRIKS M)
{
	int count=0, i, j;
	boolean cek;
	
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++)
    {
        for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++)
        {
            if (Elmt(M,i,j)!=0)
            {
                count = count + 1;
            };
        };
    };
	
	if(count <= 0.05 * NBElmt(M))
	{
		cek = true;
	}
	else
	{
		cek = false;
	};
	
	return cek;
};

MATRIKS Inverse1 (MATRIKS M)
{
	return(KaliKons(M,-1));
};

float Determinan (MATRIKS M)
{
	int sign,det=0; //sign untuk mengubah positif atau negatif dari hasil determinan
	indeks j,p,q,r,s,t; //indeks
	MATRIKS b; //Matriks Minor dari matriks M
	int c[BrsMax]; //kofaktor
	if(NBrsEff(M)==2)
	{
		det=(Elmt(M,1,1) * Elmt(M,2,2))-(Elmt(M,1,2) * Elmt(M,2,1));
	}
	else
	{
		for(j=GetFirstIdxBrs(M);j<=GetLastIdxBrs(M);j++)
		{       
			r = 1; s = 1;
			for(p=GetFirstIdxKol(M);p<=GetLastIdxKol(M);p++)
			{
				for(q=1;q<=GetLastIdxBrs(M);q++)
				{
					if(p!=1&&q!=j)
					{
						MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&b);
						Elmt(b,r,s) = Elmt(M,p,q);
						s++;
						if(s > NBrsEff(M)-1)
						{
						r++;
						s=1;
						};
					};
				};
			};
			for(t=1,sign=1;t<=(1+j);t++)
			{
				sign = (-1) * sign;
				c[j] = sign * Determinan(b);
			};
		};
		for(j=GetFirstIdxBrs(M);j<=GetLastIdxBrs(M);j++)
		{
			det=det+(Elmt(M,1,j)*c[j]);
		};
	};
     return(det);
};

void PInverse1 (MATRIKS * M)
{
	*M = Inverse1(*M);
};

void Transpose (MATRIKS * M)
{
	indeks i,j;
	MATRIKS MHsl;
	
	MakeMATRIKS(NBrsEff(*M),NKolEff(*M),&MHsl);
		for(i = GetFirstIdxBrs(MHsl); i <= GetLastIdxBrs(MHsl); i++)
		{
			for (j = GetFirstIdxKol(MHsl); j <= GetLastIdxKol(MHsl); j++)
			{
				Elmt(MHsl,i,j) = Elmt(*M,j,i);
			};
		};
		
	*M = MHsl;
};

float RataBrs (MATRIKS M, indeks i)
{
	int j;
	float jumlah = 0;
	
	for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
	{
		jumlah += Elmt(M,i,j);
	};
	
	return(jumlah/NKolEff(M));
};

float RataKol (MATRIKS M, indeks j)
{
	int i;
	float jumlah = 0;
	
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		jumlah += Elmt(M,i,j);
	};
	
	return(jumlah/NBrsEff(M));
};

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
{
	int j;
	
	*max = Elmt(M,i,1);
	*min = Elmt(M,i,1);
	
	for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
	{
		if (*max < Elmt(M,i,j))
		{
			*max = Elmt(M,i,j);
		};
		if (*min > Elmt(M,i,j))
		{
			*min = Elmt(M,i,j);
		};
	};
};

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
{
	int i;
	
	*max = Elmt(M,1,j);
	*min = Elmt(M,1,j);
	
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		if (*max < Elmt(M,i,j))
		{
			*max = Elmt(M,i,j);
		};
		if (*min > Elmt(M,i,j))
		{
			*min = Elmt(M,i,j);
		};
	};
};

int CountXBrs (MATRIKS M, indeks i, ElType X)
{
	int j, count =0;
	
	for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
	{
		if(X == Elmt(M,i,j))
		{
			count++;
		};
	};
	
	return count;
};

int CountXKol (MATRIKS M, indeks j, ElType X)
{
	int i, count =0;
	
	for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
	{
		if(X == Elmt(M,i,j))
		{
			count++;
		};
	};
	
	return count;

};

