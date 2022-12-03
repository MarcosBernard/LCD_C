#include <xc.h>
#include "functions.h"

void WriteChar(char character);

void main(void) {
    while(1){
        InitApp();
        //TEST_PORTS();
        
        RS = 1;
        __delay_ms(1000);
        SendCMD(0b00110000);
        RS =0;
        
        
        //WriteChar('0');
    }
}

void WriteChar(char character){
    RS = 1;
    __delay_ms(1000);
    SendCMD(character);
    __delay_ms(1000);
    RS = 0;
}