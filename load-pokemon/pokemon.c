#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "mesinkata.h"


typedef struct {
	int Max, Min;
} Range;

typedef struct {
	char Nama[NMax];
	char Tipe[NMax];
	int HP;
	Range Attack;
	Range EXP;
	Range Money;
	int Catch;
} Pokemon;

Range Konversi(char *K);

Range Konversi(char *K){
	Range R;
	int i = 1, flag=0, min=0, max=0;
	while (flag==0) {
		if (K[i] == '-')
			flag = 1;
		else if (K[i] == '>')
			flag = 2;
		i++;
	}
	if (flag==1){
		min = atoi(strtok(K,"-"));
		max = atoi(strtok(NULL,"-"));
		R.Max = max;
		R.Min = min;
	}
	else {
		R.Max = 99999;
		R.Min = atoi(strtok(K,">"));
	}
	return R;
}

void MakePokemon(Pokemon *P);

void Load(char *s, Pokemon *P);

void Load(char *s, Pokemon *P) {
	//Print(s);
	int i=1;
	
	STARTKATA(s);
	while (!EndKata) {
		strcpy(P[i].Nama,CKata.TabKata); 
		//printf("Pokemon ke-%d = %s\n",i,P[i].Nama);
		ADVKATA();
		strcpy(P[i].Tipe,CKata.TabKata); 
		//printf("Tipenya = %s\n",P[i].Tipe);
		ADVKATA();
		P[i].HP = atoi(CKata.TabKata); 
		//printf("HP = %d\n",P[i].HP);
		ADVKATA();
		P[i].Attack = Konversi(CKata.TabKata);
		//printf("ATT Range = %d - %d\n",P[i].Attack.Min,P[i].Attack.Max);
		ADVKATA();
		P[i].EXP = Konversi(CKata.TabKata);
		//printf("EXP Range = %d - %d\n",P[i].EXP.Min,P[i].EXP.Max);
		ADVKATA();
		P[i].Money = Konversi(CKata.TabKata);
		//printf("Money Range = %d - %d\n",P[i].Money.Min,P[i].Money.Max);
		ADVKATA();
		P[i].Catch = atoi(CKata.TabKata);
		//printf("Catch Rate = %d\n",P[i].Catch);
		ADVKATA();
		i++;
		//printf("\n");
	}
}

int main() {
	Pokemon *P = malloc (sizeof(Pokemon));
	char *s = "pokemon.txt";
	Load(s,P);
	return 0;
}
