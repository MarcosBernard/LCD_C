#include <xc.h>
#include "functions.h"

void main(void) {
    while(1){
        InitApp();
        //TEST_PORTS();
        SendCMD(on_off_control | on_display | cursor_on | blink_on);        
    }

}
