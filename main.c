#include <stdio.h>
#include "record.h"

int main(){
	record test[10];

//nrRejGet(&test);
//nrRejPrint(&test);
	rokProdGet(&test[9]);
	rokProdPrint(&test);
	return 0;
}
