#include <stdio.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void Ignore(){
  while ((CC==BLANK||CC==NEWLINE) && (CC!=MARK)){
    ADV();
  }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char s[]){
  START(s);
  ADVKATA();
}
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
	Ignore();
	if (CC==MARK)
		EndKata = true;
	else {
		EndKata = false;
		SalinKata();
	}		
}
  
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
	int i = 0,flag = 0;
	for (;;) {
    if (i<=NMax) {
      CKata.TabKata[i] = CC;
    } else {
      flag = 1;
    }
    ADV();
	if ((CC==NEWLINE)||(CC==BLANK)||(CC==MARK))
		break;
	else
		i++;
	}
  if (flag == 1) {
    CKata.Length = NMax;
  } else {
    CKata.Length = i++;	
  }
  i = i++;
  CKata.TabKata[i] = 0;
}

/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */