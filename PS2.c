#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "Score.h"
#include "VOICE.h"

void check_ps2_value(unsigned char ps2, VOICE voice_array[]){
    /* if(ps2 == 0x1c){ */
    //a = c
    if(ps2 == 0x38){
        /* voice_array[0].freq = 30 * C; */
        /* voice_array[0].amp = 1; */
    }
    //u = 
    if(ps2 == 0x3c){
        T2CONSET = (1<<15);
    }
    // ',' pause
    if(ps2 == 0x82){
        T2CONCLR = (1<<15);
    }
    // '.' play
    if(ps2 == 0x92){
        T2CONSET = (1<<15);
    }
    /* if(ps2 == 0x1c){ */
    /*     T2CONCLR = (1<<15); */
    /* } */
    return;
}
