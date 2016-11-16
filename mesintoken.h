#ifndef _MESIN_Token_
#define _MESIN_Token_
#include "mesinkar.h"

// ***** Konstanta *****  
#define NEWLINE '\n'
#define UNDER '_'
#define NMax 30 // jumlah maksimum karakter suatu Token  

typedef struct {
	char Huruf[NMax];
	int Angka;
} Token;

// ***** Definisi State Mesin Token *****  
extern Token CToken; // Token yang sudah diakuisisi dan akan diproses 
extern boolean EndToken;

// ***** Primitif-Primitif Mesin Token *****

void Ignore();
// Mengabaikan satu atau beberapa UNDERSCORE
// I.S. : CC sembarang
// F.S. : CC ≠ UNDERSCORE atau CC = MARK  

void STARTTOKEN();
// I.S. : CC sembarang  
// F.S. : EndToken = true, dan CC = Mark;  
// atau EndToken = false, CToken adalah Token yang sudah diakuisisi, CC karakter pertama sesudah karakter terakhir Token

void ADVTOKEN();
// I.S. : EndToken = false; CC adalah karakter sesudah karakter terakhir dari Token yg sudah diakuisisi
// F.S. : Jika CC = MARK, maka EndToken = true atau EndToken = false, CToken adalah Token terakhir yang sudah diakuisisi
// CC karakter pertama sesudah karakter terakhir Token

void SalinToken();
// Mengakuisisi Token, menyimpan dalam CToken
// I.S. : CC adalah karakter pertama dari Token
// F.S. : CToken berisi Token yang sudah diakuisisi
// jika karakternya melebihi NMax, sisa "Token" dibuang; CC = BLANK atau CC = MARK
// CC adalah karakter sesudah karakter terakhir yang diakuisisi  

int conv(char *s);

#endif
