/*	NIM				: 13515041 */
/*	Nama			: Leo Lambarita Nadeak */
/*	Tanggal			: 22 November 2016 */
/*	Topik Praktikum	: ADT Binary Tree */
/*	Deskripsi		: Realisasi dari bintree.h */
#include "bintree.h"
#include <stdio.h>
#include <string.h>



void print_postfix(BinTree T);
int pangkat(int a, int b);
int operasi(BinTree T);
BinTree buildTree(char* exp, int *length);


int main(){

    BinTree T;
	char masukan[200];
	int i;

	fgets(masukan,200,stdin);

	if (masukan[0] == '\n'){
		printf("Ekspresi kosong\n");
	}
	else{
		T = buildTree(masukan,&i);
		print_postfix(T);
		printf("\n=%d\n",operasi(T));
	}

	return 0;
}


int operasi(BinTree T){
	if(IsTreeOneElmt(T)){
		return Akar(T);
	}
	else{
		switch (Akar(T)){
			case -1 : return operasi(Left(T)) - operasi(Right(T));
			case -2 : return operasi(Left(T)) + operasi(Right(T));
			case -3 : return operasi(Left(T)) * operasi(Right(T));
			case -4 : return operasi(Left(T)) / operasi(Right(T));
			case -5 : return pangkat(operasi(Left(T)), operasi(Right(T)));
			case -6 : return operasi(Left(T)) % operasi(Right(T));
		}
	}
}


int pangkat(int a, int b){
	int c;

	if (b == 0){
		return 1; //basis
	}

	c = pangkat(a, b/2);

	if (b % 2){
		return c * c * a;
	}
	else{
		return c * c;
	}
}


void print_postfix(BinTree T){
	if (IsTreeOneElmt(T)){
		printf("%d",Akar(T));
	}
	else{
		print_postfix(Left(T));
		print_postfix(Right(T));
		switch (Akar(T)){
			case -1 : printf("-"); break;
			case -2 : printf("+"); break;
			case -3 : printf("*"); break;
			case -4 : printf("/"); break;
			case -5 : printf("^"); break;
			case -6 : printf("%%"); break;
		}
	}
}


BinTree buildTree(char* exp, int *length){
	if (*exp >= '0' && *exp <= '9'){
		return Tree((int) *exp - '0',Nil,Nil);
	}
	else{
		BinTree v1,v2;
		*length = 1;
		int l2;
		if (exp[*length] >= '0' && exp[*length] <= '9'){
			v1 = Tree((int) exp[*length] - '0',Nil,Nil);
			(*length)++;
		}
		else{
			v1 = buildTree(exp+(*length), &l2);
			*length += l2;
		}
		if (exp[*length] >= '0' && exp[*length] <= '9'){
			v2 = Tree((int) exp[*length] - '0',Nil,Nil);
			(*length)++;
		}
		else{
			v2 = buildTree(exp+(*length),&l2);
			*length += l2;
		}
		switch (*exp){
			case '-' : return Tree(-1,v1,v2);
			case '+' : return Tree(-2,v1,v2);
			case '*' : return Tree(-3,v1,v2);
			case '/' : return Tree(-4,v1,v2);
			case '^' : return Tree(-5,v1,v2);
			default  : return Tree(-6,v1,v2);
		}
	}
}
