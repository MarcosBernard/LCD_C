#include "functions.h"

void TEST_PORTS(void){
    PORT = 0XFF;
    __delay_ms(1000);
    PORT = 0;
    __delay_ms(1000);
    EN = 1;RW = 1; RS = 1;
    __delay_ms(1000);
    EN = 0; RW = 0; RS = 0;
    __delay_ms(1000);
}

void SendCMD(char cmd){
    PORT = cmd;
    EN = 1;
    __delay_ms(1000);
    EN = 0;
    PORT = 0;
}

void InitApp(void){
    TRISEN = 0;
    TRISRW = 0;
    TRISRS = 0;    
    TRISPORT = 0X00;
    
    SendCMD(on_off_control | on_display | cursor_on | blink_on); 
}