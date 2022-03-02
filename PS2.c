#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
void check_ps2_value(char ps2){
    /* if(ps2 == 0x1c){ */
    if(ps2 == 0x38){
        T2CONCLR = (1<<15);
    }
    if(ps2 == 0x1c){
        T2CONCLR = (1<<15);
    }
    if(ps2 == 0x00){
        T2CONCLR = (1<<15);
    }
    return;
}
