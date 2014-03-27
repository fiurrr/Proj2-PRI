#ifndef _RECORD_H_
#define  _RECORD_H

enum vehicleType{ROWER, OSOBOWY, CIEZAROWY, MOTOCYKL};
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


#endif
