#include <stdio.h>
#include "record.h"

int nrRejVal(char* s) {
	int i = 0;
	if( s[7]!='\n' ){
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
		fgets(buff,124, stdin);
	}while(nrRejVal(buff));
	nrRejEnter(r, buff);
}

void nrRejPrint(record* r){
	printf("%.3s ", r->nrRejestracji.letters);
	printf("%.4s", r->nrRejestracji.numbers);
}

int nazwImieVal(char* s){
	int i = 0;	
	while( s[i]!='\n' ){
		if (!( (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || s[i]==' ' || s[i]=='-' )) return 1;
		i++;
	}
	s[i]='\0';	
	return 0;	
}

void nazwImieEnter(record* r, char* s) {
	int i =0;
	for ( ; i<30 && s[i]!='\0'; i++)	
		r->nazwImie[i]=s[i];
}

void nazwImieGet(record* r){
	char buff[124];
	do{
		printf("Podaj Imię i Nazwisko\n");
		fgets(buff,124, stdin);
	}while(nazwImieVal(buff));
	nazwImieEnter(r, buff);
}

void nazwImiePrint(record* r){
	fputs(r->nazwImie, stdout);
}

int rodzajPojVal(char* c){
	if ( c[1]!='\n' ) return 1;
	if ( c[0]>='1' && c[0]<='4' ) return 0;
	else return 1;
}

void rodzajPojEnter(record* r, int s) {	
	r->rodzajPoj=s;
}

void rodzajPojGet(record* r){
	char buff[124];
	do{
		printf("Podaj typ pojazdu:\n\t1 = Rower\n\t2 = Osobowy\n\t3 = Ciezarowy\n\t4 = Motocykl\n");
		fgets(buff,124, stdin);
	}while(rodzajPojVal(buff));
	rodzajPojEnter(r, buff[0]-48);
}


void rodzajPojPrint(record* r){
	switch ( r->rodzajPoj ){
		case ROWER: fputs("Rower", stdout);
			break;	
		case OSOBOWY: fputs("Osobowy", stdout);
			break;	
		case CIEZAROWY: fputs("Ciezarowy", stdout);
			break;	
		case MOTOCYKL: fputs("Motocykl", stdout);
			break;
	}
}

int rokProdVal(char* s){
	int i=1;
	for ( ; i<4; i++){
		if (!( s[i]>='0' && s[i]<='9' )) return 1;		
	}
	if ( s[4]!='\n' ) return 1;
	if ( s[0]!='1' && s[0]!='2' ) return 1;
	int v = (s[0]-48)*1000 + (s[1]-48)*100 + (s[2]-48)*10 + (s[3]-48)*1;
	if ( v < 1900 || v > 2020 ) return 1;
	return 0;
}

void rokProdEnter(record* r, char* s){
	int v = (s[0]-48)*1000 + (s[1]-48)*100 + (s[2]-48)*10 + (s[3]-48)*1;
	r->rokProd=v;
}

void rokProdGet(record* r){
	char buff[124];
	do{
		printf("Podaj rok produkcji pojazdu:\n");
		fgets(buff,124, stdin);
	}while(rokProdVal(buff));
	rokProdEnter(r, buff);
}

void rokProdPrint(record* r){
	printf("%i", r->rokProd);
}
