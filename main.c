/* #include <stddef.h>   /1* Declarations of integer sizes and the like, part 1 *1/ */
/* #include <stdint.h>   /1* Declarations of integer sizes and the like, part 2 *1/ */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */

#define PRESCALE (7) //sätter timer2 till prescale 64 
#define PR2VALUE (80000000 / 256 / 1) //100 ms


int freq = 40;
int counter = 0;
void isr_routine(void)
{
    /* SPI */
    if(IFS(1) & (1<<6))
    {
        IFSCLR(1) = (1<<6);
        counter++;
        if(counter > (freq/2)){

        PORTDCLR = (1<<1);
        SPI2BUF = 0xFF;
        PORTDSET = (1<<1);
        }else{

        PORTDCLR = (1<<1);
        SPI2BUF = 0x00;
        PORTDSET = (1<<1);
        }
        if(counter == freq){
            counter = 0;
        }


        /* SPI2BUF = 0x00; */
        PORTDCLR = (1<<1);
    }
    //clock
    /* if(IFS(0) & (1<<8)) */
    /* { */
    /*     IFSCLR(0) = (1<<8); */
    /*     counter++; */

    /*     if(counter == 10); */
    /*     { */
    /*     /1* PORTDINV = (1<<1); *1/ */
    /*     counter = 0; */
    /*     } */
    /* } */
    return;
}

void setup(void)
{
    /* --------------SPI SETTINGS------------------- */
    /* SPI2CONCLR = 0xFFFFFFFF; //clear spi */
    SPI2CONCLR = (1<<31);
    SPI2CONSET = (1<<28); //MSSEN not avaliable?
    /* SPI2CONSET = (1<<16); // master mode */
    SPI2CONSET = (1<<7); // master mode
    SPI2CONSET = (1<<5); // master mode
    /* SPI2CONSET = (1<<23); */
    SPI2BRG = 85; //baud rate 2.5MHz
    SPI2CONSET = (0<<2);
    SPI2CONSET = (1<<15); //SPI ON

    /* ------spi flags ---------- */
    IECSET(1) = (1<<6); //tx interupt
    IFSCLR(1) = (1<<6); //tx flag 
    IPCSET(7) = (7<<26); //highest priority
    IPCSET(7) = (3<<24);



    /* gpio */
    TRISDCLR = (1<<1);
    PORTD = 0;


    //timer
    T2CON = 0;
    IFSCLR(0) = (1<<8); //cleara flaggan 
    T2CONCLR = (1<<15);
    T2CONSET = PRESCALE << 4; //sätt prescale rätt
    PR2 = PR2VALUE; //timeoutvärde
    TMR2 = 0; //nollställ timer
    T2CONSET = (1 << 15); //starta timer

    IEC(0) = (1 << 8);
    IECSET(0) = (1<<8); //satta for timer 2
    IPCSET(2) = (5<<2); //hogsta prioritet
    IPCSET(2) = 0x3; //hogsta prioritet

    enable_interrupt();
    return;
}

int main(){
    setup();
    /* PORTDSET = (1<<1); */

    SPI2BUF = 0x0F;
    while(1)
    {};

return 0;
}

