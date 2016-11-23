#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "mesinkata.h"

typedef struct {
	int Max, Min;
} Range;

typedef struct {
	int current;
	Range gain;
} Level;

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

int main() {
	char s[20] = "pemetaan-level.txt";
	//Print(s);
	Level L[10];
	int i=1;
	
	STARTKATA(s);
	while (!EndKata) {
		ADVKATA();
		L[i].current = atoi(CKata.TabKata);
		ADVKATA();
		L[i].gain = Konversi(CKata.TabKata);
		ADVKATA();
		i++;
	}
	return 0;
}