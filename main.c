/* #include <stddef.h>   /1* Declarations of integer sizes and the like, part 1 *1/ */
/* #include <stdint.h>   /1* Declarations of integer sizes and the like, part 2 *1/ */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */

#define PRESCALE (7) //sätter timer2 till prescale 64 
#define PR2VALUE (80000000 / 256 / 1) //100 ms


int counter = 0;
void isr_routine(void)
{
    /* SPI */
    if()
    //clock
    if(IFS(0) & (1<<8))
    {
        counter++;
        if(counter = 10);
        {
        PORTDINV = (1<<1);
        IFSCLR(0) = (1<<8);
        counter = 0;
        }
    }
    return;
}

void setup(void)
{
    /* --------------SPI SETTINGS------------------- */
    SPI2CON = 0; //clear spi
    SPI2CONSET = (1<<28); //MSSEN not avaliable?
    SPI2CONSET = (1<<5); // master mode

    /* ------spi flags ---------- */
    IFSCLR(2) = (1<<6); //tx flag 
    IECSET(1) = (1<<6); //tx interupt
    IPCSET(7) = (7<<26); //highest priority
    IPCSET(7) = (3<<24);


    SPI2CONSET = (1<<15); //SPI ON

    /* gpio */
    TRISDCLR = (1<<1);


    //timer
    T2CON = 0;
    T2CONSET = PRESCALE << 4; //sätt prescale rätt
    PR2 = PR2VALUE; //timeoutvärde
    IEC(0) = (1 << 8);
    TMR2 = 0; //nollställ timer
    T2CONSET = (1 << 15); //starta timer

    enable_interrupt();
    return;
}

int main(){
    PORTDSET = (1<<1);
    setup();

    while(1)
    {};

return 0;
}

