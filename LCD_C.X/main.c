#include <xc.h>
#include "functions.h"

char mensaje[5] = {'H','O','L','A','!'};

void print(char *chardir);

void main(void) {
    InitApp();
    print(&mensaje[0]);
    while(1){
        
    }
}

void print(char *chardir){ //*chardir: la primera letra ---- chardir: la dirección de la primera letra
    while(*chardir != 0){
        SendChar(*chardir);
        chardir++;
    }
}

