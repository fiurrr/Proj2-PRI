#include <stdio.h>
#include <math.h>
#include "record.h"

#define TRUE 1
#define FALSE 0
#define ASCII_NUMBER_OFFSET 48
#define STD_IN_BUFFER_SIZE 124

int isRegistrationNumberValid(char* s) {
	int i = 0;
	if(s[7] != '\n') {
		printf("Zly numer rejestracyjny!\n");
        	return FALSE;
	}
	for (; i<3; i++) {
		if ( s[i]<'A' || s[i]>'Z' ) { 			
			printf("Zly numer rejestracyjny!\n");
                        return FALSE;
                }
	}
	for (i=3; i<7; i++) {
		if (s[i]<'0' || s[i]>'9') {
			printf("Zly numer rejestracyjny!\n");
			return FALSE;
		}
	}
	return TRUE;
}

void setRegistrationNumber(record* r, char* s) {
	int i = 0;
	for (; i < 3; i++) r->nrRejestracji.letters[i] = s[i];
	for (i = 3; i < 7; i++) r->nrRejestracji.numbers[i-3] = s[i];
}

void getRegistrationNumber(record* r) {
	char buff[STD_IN_BUFFER_SIZE];
	do {
		printf("Podaj numer rejestracyjny w formacie AAD2241\n");
		fgets(buff, STD_IN_BUFFER_SIZE, stdin);
	} while(!isRegistrationNumberValid(buff));
	setRegistrationNumber(r, buff);
}

void printRegistrationNumber(record* r) {
	printf("%.3s ", r->registrationNumber.letters);
	printf("%.4s", r->registrationNumber.numbers);
}

int isNameValid(char* s) {
	int i = 0;	
	while(s[i] != '\n') {
		if (!((s[i] >= 'A' && s[i] <= 'Z') || 
			(s[i] >= 'a' && s[i] <= 'z') || 
			s[i] == ' ' ||
			s[i] == '-' ))
					return FALSE;
		i++;
	}
	s[i] = '\0';	
	return TRUE;
}

void setName(record* r, char* s) {
	int i =0;
	for (; i<30 && s[i] != '\0'; i++) {
		r->name[i] = s[i];
	}
}

void getName(record* r) {
	char buff[STD_IN_BUFFER_SIZE];
	do {
		printf("Podaj Imię i Nazwisko\n");
		fgets(buff, STD_IN_BUFFER_SIZE, stdin);
	} while(!isNameValid(buff));
	setName(r, buff);
}

void printName(record* r) {
	fputs(r->name, stdout);
}

int isVehicleTypeValid(char* c) {
	if (c[1] != '\n') {
		return FALSE;
	}
	if (c[0] >= '1' && c[0] <= '4') {
		return TRUE;
	} else {
		return FALSE;
	}
}

void setVehicleType(record* r, int s) {	
	r->vehicleType = s;
}

void getVehicleType(record* r) {
	char buff[ STD_IN_BUFFER_SIZE];
	do {
		printf("Podaj typ pojazdu:\n\t");
		printf("1 = Rower\n\t");
		printf("2 = Osobowy\n\t");
		printf("3 = Ciezarowy\n\t");
		printf("4 = Motocykl\n");

		fgets(buff, STD_IN_BUFFER_SIZE, stdin);
	} while(!isVehicleTypeValid(buff));
	setVehicleType(r, buff[0] - ASCII_NUMBER_OFFSET);
}


void printVehicleType(record* r) {
	switch (r->vehicleType) {
		case ROWER: 
		{
			fputs("Rower", stdout);
			break;
		}
		case OSOBOWY: 
		{
			fputs("Osobowy", stdout);
			break;
		}
		case CIEZAROWY:
		{
			fputs("Ciezarowy", stdout);
			break;
		}	
		case MOTOCYKL: 
		{	
			fputs("Motocykl", stdout);
			break;
		}
	}
}

int isProductionYearValid(char* s) {
	int i=1;
	for (; i<4; i++) {
		if (!(s[i] >= '0' && s[i] <= '9')) {
			return FALSE;		
		}
	}
	if ((s[0] != '1' && s[0] != '2') || s[4] != '\n') {
		return FALSE;
	}
	int v = 0;
	for (i = 3; i>=0; i--) {
		v += (s[i] - ASCII_NUMBER_OFFSET)*pow(3-i);
	}
	if ( v < 1900 || v > 2020 ) {
		return FALSE;
	} else {
		return TRUE;
	}
}

void setProductionYear(record* r, char* s) {
	int v = 0;
	for (i = 3; i>=0; i--) {
		v += (s[i] - ASCII_NUMBER_OFFSET)*pow(3-i);
	}
	r->productionYear = v;
}

void getProductionYear(record* r) {
	char buff[STD_IN_BUFFER_SIZE];
	do {
		printf("Podaj rok produkcji pojazdu:\n");
		fgets(buff, STD_IN_BUFFER_SIZE, stdin);
	} while(!isProductionYearValid(buff));
	setProductionYear(r, buff);
}

void printProductionYear(record* r) {
	printf("%i", r->productionYear);
}