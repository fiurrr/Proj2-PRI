#ifndef _RECORD_H_
#define  _RECORD_H

enum vehicleType{ROWER=1, OSOBOWY, CIEZAROWY, MOTOCYKL};
struct nrRej{
        char letters[3];
        char numbers[4];
};

struct record{
        struct nrRej nrRejestracji;
	char nazwImie[30];
	enum vehicleType rodzajPoj;
	int rokProd;
};

typedef struct record record;

int nrRejVal(char* s);
void nrRejEnter(record* r, char* s);
void nrRejGet(record* r);
void nrRejPrint(record* r);

int nazwImieVal(char* s);
void nazwImieEnter(record* r, char* s);
void nazwImieGet(record* r);
void nazwImiePrint(record* r);

int rodzajPojVal(char* s);
void rodzajPojEnter(record* r, int s);
void rodzajPojGet(record* r);
void rodzajPojPrint(record* r);

int rokProdVal(char* s);
void rokProdEnter(record* r, char* s);
void rokProdGet(record* r);
void rokProdPrint(record* r);

#endif
