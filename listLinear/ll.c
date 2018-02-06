    #include "list.h"
    boolean IsListEmpty (List L){
    	return (First(L)==Nil);
    }
    void CreateList (List *L){
    	L->First=Nil;
    }
    address Alokasi (infotype X){
    	address temp;
    	temp=(address)malloc(sizeof(ElmtList));
    	if (temp!=Nil){
    		Info(temp)=X;
    		Next(temp)=Nil;
    	}
    	return (temp);
    }
    void Dealokasi (address *P){
    	free(P);
    }
    address Search (List L, infotype X){
    	if (First(L)!=Nil){
    		address P;
    		P=First(L);
    		while (P!=Nil){
    			if (Info(P)==X)
    				return P;
    			P=Next(P);
    		}
    		return Nil;
    	}
    	else return Nil;
    }
    boolean FSearch (List L, address P){
    	if (First(L)!=Nil){
    		address temp;
    		temp=First(L);
    		while (P!=Nil){
    			if (Next(temp)==P)
    				return true;
    			P=Next(P);
    		}
    		return false;
    	}
    	else return false;
    }
    address SearchPrec(List L, infotype X){
    	if (Search(L,X)!=Nil){
    		address P;
    		P=First(L);
    		if (Info(P)==X)
    			return Nil;
    		while (Info(Next(P))!=X){
    			P=Next(P);
    		}
    		return P;
    	}
    	else return Nil;
    }
    void InsVFirst (List *L, infotype X){
    	address temp;
    	temp=Alokasi(X);
    	Next(temp)=First(*L);
    	First(*L)=temp;
    }
    void InsVLast (List *L, infotype X){
    	address P;
    	P=First(*L);
    	if (P!=Nil){
    		while (Next(P)!=Nil)
    			P=Next(P);
    		Next(P)=Alokasi(X);
    	}
    	else First(*L)=Alokasi(X);
    }
    void DelVFirst (List *L, infotype *X){
    	address temp;
    	temp=First(*L);
    	(*X)=Info(temp);
    	First(*L)=Next(First(*L));
    	Dealokasi(&temp);
    }
    void DelVLast (List *L, infotype *X){
    	address P,Q;
    	P=First(*L);
    	Q=Next(P);
    	if (Q!=Nil){
    		while (Next(Q)!=Nil){
    			P=Next(P);
    			Q=Next(Q);
    		}
    		(*X)=Info(Q);
    		Next(P)=Nil;
    	}
    	else{
    		(*X)=Info(P);
    		First(*L)=Nil;
    	}
    }
    void InsertFirst (List *L, address P){
    	address temp;
    	temp=First(*L);
    	First(*L)=P;
    	Next(P)=temp;
    }
    void InsertAfter (List *L, address P, address Prec){
    	address temp;
    	Next(P)=Next(Prec);
    	Next(Prec)=P;
    }
    void InsertLast(List *L, address P){
    	if (First(*L)!=Nil){
    		address temp;
    		temp=First(*L);
    		while (Next(temp)!=Nil)
    			temp=Next(temp);
    		Next(temp)=P;
    	}
    	else First(*L)=P;
    }
    void DeleteFirst (List *L, address *P){
    	(*P)=First(*L);
    	First(*L)=Next(First(*L));
    }
    void DeleteP (List *L, infotype X){
    	if (Search(*L,X)){
    		address temp;
    		temp=First(*L);
    		if (Info(temp)!=X){
    			while (Info(Next(temp))!=X)
    				temp=Next(temp);
    			address del;
    			del=Next(temp);
    			Next(temp)=Next(del);
    			Dealokasi(&del);
    		}
    		else
    			DeleteFirst(L,&temp);
    	}
    }
    void DeleteLast (List *L, address *P){
    	if (Next(First(*L))!=Nil){
    		address temp;
    		temp=First(*L);
    		while (Next(Next(temp))!=Nil)
    			temp=Next(temp);
    		(*P)=Next(temp);
    		Next(temp)=Nil;
    	}
    	else {
    		(*P)=First(*L);
    		First(*L)=Nil;
    	}
    }
    void DeleteAfter (List *L, address *Pdel, address Prec){
    	(*Pdel)=Next(Prec);
    	Next(Prec)=Next((*Pdel));
    }
    void PrintInfo (List L){
    	address temp;
    	temp=First(L);
    	while (temp!=Nil){
    		printf("%d\n",Info(temp));
    		temp=Next(temp);
    	}
    }
    int NbElmt (List L){
    	int count;
    	count=0;
     
    	address temp;
    	temp=First(L);
    	while (temp!=Nil){
    		count++;
    		temp=Next(temp);
    	}
    	return count;
    }
    infotype Max (List L){
    	int Maxi;
    	Maxi=-2147483648;
     
    	address temp;
    	temp=First(L);
    	while (temp!=Nil){
    		Maxi=(Maxi>Info(temp))?Maxi:Info(temp);
    		temp=Next(temp);
    	}
    	return Maxi;
    }
    address AdrMax (List L){
    	int Maxi;
    	Maxi=-2147483648;
    	address Maxt;
     
    	address temp;
    	temp=First(L);
    	while (temp!=Nil){
    		if (Info(temp)>Maxi){
    			Maxi=Info(temp);
    			Maxt=temp;
    		}
    		temp=Next(temp);
    	}
    	return Maxt;
    }
    infotype Min (List L){
    	int Mini;
    	Mini=2147483647;
     
    	address temp;
    	temp=First(L);
    	while (temp!=Nil){
    		Mini=(Mini<Info(temp))?Mini:Info(temp);
    		temp=Next(temp);
    	}
    	return Mini;
    }
    address AdrMin (List L){
    	int Mini;
    	Mini=2147483647;
    	address Mint;
     
    	address temp;
    	temp=First(L);
    	while (temp!=Nil){
    		if (Mini>Info(temp)){
    			Mini=Info(temp);
    			Mint=temp;
    		}
    		temp=Next(temp);
    	}
    	return Mint;
    }
    float Average (List L){
    	address temp;
    	temp=First(L);
     
    	long long sum=0,count=0;
    	while (temp!=Nil){
    		sum+=Info(temp);
    		count++;
    		temp=Next(temp);
    	}
    	if (count!=0)
    		return (sum/count);
    	return 0.00;
    }
    void DeleteAll (List *L){
    	address dummy;
    	while (First(*L)!=Nil){
    		DeleteFirst(L,&dummy);
    		Dealokasi(&dummy);
    	}
    }
    void InversList (List *L){
    	if (First(*L)!=Nil){
    		address P,Q,N;
    		P=First(*L);
    		Q=Next(P);
    		Next(P)=Nil;
    		while (Q!=Nil){
    			N=Next(Q);
    			Next(Q)=P;
    			P=Q;
    			Q=N;
    		}
    		First(*L)=P;
    	}
    }
    List FInversList (List L){
    	List res;
    	CreateList(&res);
    	res=FCopyList(L);
    	InversList(&res);
    	return res;
    }
    void CopyList (List *L1, List *L2){
    	First((*L2))=First(*L1);
    }
    List FCopyList (List L){
    	List res;
    	CreateList(&res);
     
    	address P;
    	P=First(L);
    	while (P!=Nil){
    		InsVLast(&res,Info(P));
    		P=Next(P);
    	}
    	return res;
    }
    void CpAlokList (List Lin, List *Lout){
    	(*Lout)=FCopyList(Lin);
    }
    void Concat (List L1, List L2, List *L3){
    	List res;
    	CreateList(&res);
     
    	address P;
    	P=First(L1);
    	while (P!=Nil){
    		InsVFirst(&res,Info(P));
    		P=Next(P);
    	}
    	P=First(L2);
    	while (P!=Nil){
    		InsVFirst(&res,Info(P));
    		P=Next(P);
    	}
    	InversList(&res);
    	(*L3)=res;
    }
    void Concat1 (List *L1, List *L2, List *L3){
    	if (First(*L1)=Nil){
    		First(*L1)=First(*L2);
    	}
    	else {
    		address P;
    		P=First(*L1);
    		while (Next(P)!=Nil){
    			P=Next(P);
    		}
    		Next(P)=First(*L2);
    	}
    	First(*L2)=Nil;
    	First(*L3)=First(*L1);
    }
    void PecahList (List *L1, List *L2, List L){
    	CreateList(L1);
    	CreateList(L2);
    	int a,b;
    	a=b=(NbElmt(L))/2;
     
    	address P;
    	P=First(L);
    	while (a!=0){
    		InsVLast(L1,Info(P));
    		P=Next(P);
    		a--;
    	}
    	while (b!=0){
    		InsVLast(L2,Info(P));
    		P=Next(P);
    		b--;
    	}
    }