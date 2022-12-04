#include <xc.h>
#include "functions.h"

void SendChar(char character);

void main(void) {
    //__delay_ms(1000);
    InitApp();
    SendChar('0');
    while(1){
        
        //TEST_PORT();
        
    }
}

/*
 * Sending command control PORT
 */

void SendChar(char character){     
    RS = 1;
    //__delay_ms(3000);
    SendCMD(character);
    //__delay_ms(3000);
    RS = 0;
}