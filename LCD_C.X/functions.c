#include "functions.h"

void TEST_PORT(void){
    for(char i = 1; i == 10; i++){
        //PORTEbits.RE0 = 0;
        RS = 1;
        EN = 1;
        __delay_ms(500);
        //PORTEbits.RE0 = 1;
        EN = 0;
        RS = 0;
        __delay_ms(500);
    }
}

void SendCMD(char cmd){
    PORT = cmd;
    EN = 1;
    __delay_ms(1);
    EN = 0;
    PORT = 0;
}

void InitApp(void){
    TRISPORT = 0X00;
    PORT = 0X00;
    TRISRW = 0;
    RW = 0;
    TRISRS  = 0;
    RS = 0;    
    TRISEN = 0;
    EN = 0;
    // Cursor config.
    SendCMD(on_off_control | on_display | cursor_on | blink_on); 
}