#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mesinkata.h"

typedef struct {
	int Harga;
	int Efek;
	char Nama[NMax]; 
	char Tipe[NMax]; 
} ItemType;

typedef struct {
ItemType Item[NMax];
int Jumlah;
} Barang;

void Load(Barang *B,char s[]);


void Load(Barang *B,char s[])
{
	STARTKATA(s);
	int i=1;
	while(!EndKata){
	strcpy((*B).Item[i].Tipe,CKata.TabKata);
	ADVKATA();
	strcpy((*B).Item[i].Nama,CKata.TabKata);
	ADVKATA();
	(*B).Item[i].Harga = atoi(CKata.TabKata);
	ADVKATA();
	(*B).Item[i].Efek = atoi(CKata.TabKata);
	ADVKATA();
	i++;
	}
	(*B).Jumlah = i-1;
}

int main() {
	Barang Brg;
	char sBrg[] = "toko.txt";
	
	Load(&Brg,sBrg);
	printf("\n jumlahnya ada %d",Brg.Item[3].Harga);
	
	return 0;
}
