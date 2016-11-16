
#include <stdio.h>
#include "mesintoken.h"

char CC;
Token CToken;
boolean EndToken = false;

//********** DEFINISI PROTOTIPE PRIMITIF **********

void Ignore() 
{
	while ((CC=='_'||CC=='\n'))
		ADV();
}

void STARTTOKEN() 
{
	START();
	Ignore();
	
	if (EOP||(CC=='_'||CC=='\n'))
		EndToken = true;
	else
		SalinToken();
}

void ADVTOKEN()
// I.S. : EndToken = false  CC adalah karakter sesudah karakter terakhir dari Token yg sudah diakuisisi
// F.S. : Jika CC = MARK, maka EndToken = true atau EndToken = false, CToken adalah Token terakhir yang sudah diakuisisi
{
	Ignore();
	if (!EOP)
		SalinToken();
	else
		EndToken = true;
}

// CC karakter pertama sesudah karakter terakhir Token
void SalinToken() 
// Mengakuisisi Token, menyimpan dalam CToken
// I.S. : CC adalah karakter pertama dari Token
// F.S. : CToken berisi Token yang sudah diakuisisi
// jika karakternya melebihi NMax, sisa "Token" dibuang  CC = BLANK atau CC = MARK
// CC adalah karakter sesudah karakter terakhir yang diakuisisi  
{
	int i = 0;
	char temp[NMax];
	
	if (CC<'0')
	{
		while (!EndToken&&!EOP)
		{
			CToken.Huruf[i] = CC;
			ADV();
			i++;
		}
	}
	else // CC> '0'
	{
		while (!EndToken&&!EOP)
		{
			temp[i] = CC;
			ADV();
			i++;
		}
		while (i>0)
		{
			CToken.Angka += temp[i]*(10^(i-1));
			i--;
		}
	}
}