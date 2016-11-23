
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "mesinkata.h"

boolean Koma();

boolean Koma(){
	boolean found = false;
	int i = 0;
	while ((i<CKata.Length)&&(!found)){
		i++;
		if (CKata.TabKata[i] == ',')
			found = true;
	}	
	return found;		
}

int main() {
	char s[20] = "ability.txt";
	//Print(s);
	int i = 0, j = 0, x=0;
	float ability[7][7], temp1, temp;
	char *arr, *arr2;

	STARTKATA(s);
	while (!EndKata){
		while (i<7) {
			while (j<7) {
				if (!Koma()){
					ability[i][j] = atof(CKata.TabKata);
					printf("bulat %.0f\n",ability[i][j]);
				}
				else {
					arr = strtok(CKata.TabKata,",");
					//temp1 = atof(arr);
					arr2 = strtok(NULL,",");
					//temp2 = atof(arr2);
					//printf("%c\n",arr2[0]);
					//printf("%s\n%s\n",arr,arr2);
					//printf("%.2f desimal\n",temp1);
					//printf("%.2f desimal\n",temp);
					ability[i][j] = atof(arr)+ atof(arr2)*(1/(10^(strlen(arr2))));
					printf("%.2f desimal\n",ability[i][j]);
				}
				ADVKATA();
				j++;
			}
			i++;
			printf("\n");
		}
	}
	
	return 0;
}
