#include <stdio.h>
#include "record.h"

int nrRejVal(char* s) {
	int i = 0;
	if( s[7]!='\0' ){
		printf("Zly numer rejestracyjny!\n");
        	return 1;
	}
	for ( ; i<3; i++ ) {
		if ( s[i]<'A' || s[i]>'Z' ) { 			
			printf("Zly numer rejestracyjny!\n");
                        return 1;
                }
	}
	for ( i=3; i<7; i++ ) {
		if ( s[i]<'0' || s[i]>'9' ) {
			printf("Zly numer rejestracyjny!\n");
			return 1;
		}
	}
	return 0;
}

void nrRejEnter(record* r, char* s) {
	int i =0;
	for ( ; i<3; i++ ) r->nrRejestracji.letters[i]=s[i];
	for ( i=3; i<7; i++ ) r->nrRejestracji.numbers[i-3]=s[i];
}

void nrRejGet(record* r){
	char buff[124];
	do{
		printf("Podaj numer rejestracyjny w formacie AAD2241\n");
		scanf("%s", buff);
	}while(nrRejVal(buff));
	nrRejEnter(r, buff);
}

void nrRejPrint(record* r){
	printf("%.3s ", r->nrRejestracji.letters);
	printf("%.4s ", r->nrRejestracji.numbers);
}
