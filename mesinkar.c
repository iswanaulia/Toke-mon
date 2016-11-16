/* File  : mesinkar1.c */ 
/* Body mesinkar1.h  */ 
#include <assert.h> 
#include <stdio.h> 
#include "mesinkar.h" 

/* definisi states  */ 
char CC;
boolean EOP = false;

/* definisi pita  */ 
 
static FILE *FILEKU; 
static int retval; 

void START()
{
	FILEKU = fopen("toko.txt","r"); 
	ADV();
}

void ADV()
{
	retval  = fscanf(FILEKU,"%c",&CC); 
	EOP = (CC==MARK);
	if  (EOP)
		fclose(FILEKU);
} 

void PrintToken()
{
	START();
	while (!EOP)
	{
		if (CC=='_')
			printf("\t");
		else
			printf("%c",CC);
		ADV(); //Char berikutnya
	}
}