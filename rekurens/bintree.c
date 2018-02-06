/*	NIM				: 13515041 */
/*	Nama			: Leo Lambarita Nadeak */
/*	Tanggal			: 16 November 2016 */
/*	Topik Praktikum	: Pohon Biner */
/*	Deskripsi		: Implikasi dari bintree.h */

#include<stdio.h>
#include<stdlib.h>
#include "bintree.h"

/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R)
{
	BinTree P;
	
	P = AlokNode(Akar);
	if (P != NULL)
	{
		Akar(P) = Akar;
		Left(P) = L;
		Right(P) = R;
	}
	return P;
} 

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
{
	*P = Tree(Akar,L,R);
};

		
/* Manajemen Memory */
addrNode AlokNode (infotype X)
{
	addrNode P;
	
	P = (addrNode) malloc (sizeof(Node));
	if (P != NULL)
	{
		Akar(P) = X;
		Left(P) = Nil;
		Right(P) = Nil;
	}
	
	return P;
};

void DealokNode (addrNode P)
{
	free(P);
};

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
{
	return (P == Nil);
};


boolean IsTreeOneElmt (BinTree P)
{
	if (!IsTreeEmpty(P))
	{
		return (Left(P) == Nil && Right(P) == Nil);
	}
	else{
		return false;
	}
}

boolean IsUnerLeft (BinTree P)
{
	return (Left(P) != Nil && Right(P) == Nil);
}

boolean IsUnerRight (BinTree P)
{
	return (Left(P) == Nil && Right(P) != Nil);
}

boolean IsBiner (BinTree P)
{
	return (Left(P) != Nil && Right(P) != Nil);
};

/* *** Traversal *** */
void PrintPreorder (BinTree P)
{
	if (IsTreeEmpty(P))		//Basis
	{
		printf("()");
	}
	else{
		printf("(%d",Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
		printf(")");
	}
}

void PrintInorder (BinTree P)
{
	if (IsTreeEmpty(P))
	{
		printf("()");
	}
	else
	{
		printf("(");
		PrintInorder(Left(P));
		printf("%d",Akar(P));
		PrintInorder(Right(P));
		printf(")");
	}
};

void PrintPostorder (BinTree P)
{
	if (IsTreeEmpty(P))
	{
		printf("()");
	}
	else{
		printf("(");
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d)",Akar(P));
	}
};

void PrintTree (BinTree P, int h)
{
	/* Prosedur Antara */
	void cetakSpasi(int h, int *n)
	{
		int i;
		for (i = 1; i <= h; i++)
		{
			printf(" ");
		}
		*n = h;
	}
	
	int n;
	
	if (!IsTreeEmpty(P))
	{
		printf("%d\n",Akar(P));
		if (!IsTreeEmpty(Left(P)))
		{
			cetakSpasi(h,&n);
			PrintTree(Left(P),n + h);
		};
		if (!IsTreeEmpty(Right(P)))
		{
			cetakSpasi(h,&n);
			PrintTree(Right(P), n + h);
		}
	}
};

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X)
{
	if (IsTreeEmpty(P))
	{
		return false;
	}
	else
	{
		if (Akar(P) == X)
		{
			return true;
		}
		else
		{
			return (SearchTree(Left(P),X) || SearchTree(Right(P),X));
		}
	}
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (BinTree P)
{
	if (IsTreeEmpty(P))
	{
		return 0;
	}
	else if(IsTreeOneElmt(P))
	{
		return 1;
	}
	else
	{
		return (NbElmt(Left(P)) + NbElmt(Right(P)));
	}
}

int NbDaun (BinTree P)
{
	if(IsTreeOneElmt(P))		//Prekondisi : P tidak kosong
	{
		return 1;
	}
	else
	{
		return (NbElmt(Left(P)) + NbElmt(Right(P)));
	}	
}

boolean IsSkewLeft (BinTree P)
{
	if (IsTreeEmpty(P) || IsTreeOneElmt(P))
	{
		return true;
	}
	else
	{
		return (IsUnerLeft(P) && IsSkewLeft(Left(P)));
	}
}

boolean IsSkewRight (BinTree P)
{
	if (IsTreeEmpty(P) || IsTreeOneElmt(P))
	{
		return true;
	}
	else
	{
		return (IsUnerRight(P) && IsSkewLeft(Right(P)));
	}
}

int Level (BinTree P, infotype X)
{
	if (IsTreeOneElmt(P) || (Akar(P) == X))
	{
		return 1;
	}
	else
	{
		if (SearchTree(Left(P),X))
		{
			return (1 + Level(Left(P),X));
		}
		else if (SearchTree(Right(P),X))
		{
			return (1 + Level(Right(P),X));
		}
	}
}

int Tinggi (BinTree P)
{
	if (IsTreeEmpty(P))
	{
		return 0;
	}
	else
	{
		if (Tinggi(Left(P)) > Tinggi(Right(P)))
		{
			return (1 + Tinggi(Left(P)));
		}
		else
		{
			return (1 + Tinggi(Right(P)));
		}
	}
}

/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, infotype X)
{
	if (IsTreeEmpty(*P))
	{
		MakeTree(X,Nil,Nil,P);
	}
	else{
		AddDaunTerkiri(&Left(*P),X);
	}
}

void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri)
{
	if(IsTreeOneElmt(*P))
	{
		if (Kiri)
		{
			Left(*P) = AlokNode(Y);
		}
		else
		{
			Right(*P) = AlokNode(Y);
		}
	}
	else
	{
		if (SearchTree(Left(*P),X))
		{
			AddDaun(&Left(*P),X,Y,Kiri);
		}
		else
		{
			AddDaun(&Right(*P),X,Y,Kiri);
		}
	}
}

void DelDaunTerkiri (BinTree *P, infotype *X)
{
	addrNode Ptemp;
	
	if (IsTreeOneElmt(*P))
	{
		*X = Akar(*P);
		Ptemp = *P;
		*P = Nil;
		DealokNode(Ptemp);
	}
	else
	{
		if (IsUnerRight(*P))
		{
			DelDaunTerkiri(&Right(*P),X);
		}
		else
		{
			DelDaunTerkiri(&Left(*P),X);
		}
	}
}

void DelDaun (BinTree *P, infotype X)
{
	BinTree Ptemp;
	
	if (IsTreeOneElmt(*P))
	{
		if (Akar(*P) == X)
		{
			Ptemp = *P;
			*P = Nil;
			DealokNode(Ptemp);
		}
	}
	else{
		if (IsUnerRight(*P)){
			DelDaun(&Right(*P), X);
		}
		else if (IsUnerLeft(*P)){
			DelDaun(&Left(*P), X);
		}
		else{
			DelDaun(&Right(*P), X);
			DelDaun(&Left(*P), X);
		}
	}
}

List MakeListDaun (BinTree P)
{
	if (IsTreeEmpty(P))
	{
		return Nil;
	}
	else
	{
		if (IsTreeOneElmt(P))
		{
			return Alokasi(Akar(P));
		}
		else if (IsUnerLeft(P))
		{
			return MakeListDaun(Left(P));
		}
		else if (IsUnerRight(P))
		{
			return MakeListDaun(Right(P));
		}
		else
		{
			return Concat(MakeListDaun(Left(P)),MakeListDaun(Right(P)));
		}
	}
}

List MakeListPreorder (BinTree P)
{
	address L;
	
	if (IsTreeEmpty(P))
	{
		return Nil;
	}
	else
	{
		L = Alokasi(Akar(P));
		if (L != Nil)
		{
			Next(L) = MakeListPreorder(Left(P));
			return Concat(L,MakeListPreorder(Right(P)));
		}
		else
		{
			return Nil;
		}
	}
}

List MakeListLevel (BinTree P, int N)
{
	List L;
	
	if (IsTreeEmpty(P))
	{
		return Nil;
	}
	else
	{
		if (N == 1)
		{
			L = Alokasi(Akar(P));
			return L;
		}	
		else
		{
			return Concat(MakeListLevel(Left(P), N - 1), MakeListLevel(Right(P),N - 1));
		}
	}
}
