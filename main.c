// Nama/NIM		: Iswan Aulia/18215017
// Tanggal		: 23 Oktober 2016
// Nama file	: P05-18215017-231016-01-main.c
// Deskripsi	: driver/program utama ADT Mesin Token

#include <stdio.h>
#include "mesintoken.h"

int main()
{
	int NBToken = 0;
	
	//ALGORITMA
	printf("\n=== TELEGRAM ===\n");
	printf("Isi Telegram : \n");
	
	PrintToken(); //Menampilkan isi pitakar.txt ke layar
	STARTTOKEN();
	//printf("%s",&CToken.Huruf);
	//ADVTOKEN();
	return 0;
}
