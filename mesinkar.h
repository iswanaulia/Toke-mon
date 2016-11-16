#ifndef _MESIN_KAR_
#define _MESIN_KAR_

#define true 1
#define false 0
#define boolean unsigned char

// ********** Mesin Karakter dengan asersi dan primitif read **********
// ** Pita karakter diambil dari file "pitakar.txt" **

#define MARK '.'

// State mesin
extern char CC;
extern boolean EOP;
// ********** DEFINISI PROTOTIPE PRIMITIF **********

void START();
// I.S. sembarang
// F.S. CC adalah karakter pertama pitakar
// Jika CC == MARK, EOP menyala (true)
// Jika CC != MARK, EOP padam (false)

void ADV();
// I.S CC != MARK
// F.S. CC adalah karakter berikutnya dari CC pada I.S.
// Jika CC == MARK, EOP menyala (true)

void PrintToken();

#endif