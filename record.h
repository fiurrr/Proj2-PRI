#ifndef _RECORD_H_
#define _RECORD_H

enum VehicleType {
	ROWER=1, 
	OSOBOWY, 
	CIEZAROWY, 
	MOTOCYKL
};

struct RegNum {
        char letters[3];
        char numbers[4];
};

struct Record {
    struct RegNum registrationNumber;
	char name[30];
	enum VehicleType vehicleType;
	int productionYear;
};

typedef struct Record Record;

int isRegistrationNumberValid(char* s);
void setRegistrationNumber(record* r, char* s);
void getRegistrationNumber(record* r);
void printRegistrationNumber(record* r);

int isNameValid(char* s);
void setName(record* r, char* s);
void getName(record* r);
void printName(record* r);

int isVehicleTypeValid(char* s);
void setVehicleType(record* r, int s);
void getVehicleType(record* r);
void printVehicleType(record* r);

int isProductionYearValid(char* s);
void setProductionYear(record* r, char* s);
void getProductionYear(record* r);
void printProductionYear(record* r);

#endif