#include <xc.h>

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000

/* ---------
 * LCD PORTS
 * ---------
 */
#define TRISRS  TRISEbits.TRISE0
#define TRISRW  TRISEbits.TRISE1
#define TRISEN  TRISEbits.TRISE2
#define RS  PORTEbits.RE0
#define RW  PORTEbits.RE1
#define EN  PORTEbits.RE2
#define TRISPORT    TRISD
#define PORT    PORTD


void TEST_PORTS(void);
void InitApp(void);
void SendCMD(char cmd);


/* 
 * Send command to LCD
 * 
 * SET command in the instruccion port.
 * SET ON Enable bit unless 1ms.
 * SET OFF Enable bit.
 */

/*--------------
 * Instructions
 * -------------
 */

// 4. Display on/off control
#define on_off_control  0b00001000
#define on_display  0b00000100
#define off_display 0
#define cursor_on   0b00000010
#define cursor_off  0b00000010
#define blink_on  0b00000001
#define blink_off  0