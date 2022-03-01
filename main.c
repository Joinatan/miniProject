#include <stddef.h>   /* Declarations of integer sizes and the like, part 1 */
#include <stdint.h>   /* Declarations of integer sizes and the like, part 2 */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
/* #include </opt/mcb32tools/include/math.h> */
#include <math.h>

#define PRESCALE (4) //sätter timer2 till prescale 64 
#define PR2VALUE ((80000000 / 16 ) / 51100 ) //grund 50Hz
#define bufSize (1024)
#define maxAmp (0xfff)

unsigned int sineBuf[bufSize];
unsigned int triangleBuf[bufSize];
unsigned int squareBuf[bufSize];
int frame = 0;
int *frameP = &frame;
int frame2 = 0;
int *frameP2 = &frame2;
int dummyRecieve;
int counter = 0;
unsigned int mix = 0;
char triangleFlag = 0;
unsigned int triangle = 0;

unsigned int fillSineBuffer(float x)
{
    unsigned int y = ( unsigned int ) (((sinf(x)*0.5)+0.5) * maxAmp) ;
    return y;
}
unsigned int fillTriangleBuffer(int x)
{
    unsigned int y = 0;
    if(x >= bufSize/2 )
    {
        triangle -= 7;
        y = triangle;
        triangleFlag = 1;
        return y;
    }
    if(triangleFlag == 0)
    {
        triangle += 7;
        y = triangle;
        return y;
    }
    if(triangleFlag == 1)
    {
        triangle--;
        y = triangle;
        return y;
    }
    return y;
}
unsigned int fillSquareBuffer(int x)
{
    unsigned int y = 0;
    y = maxAmp/2;
    if(x >= bufSize/2 )
    {
        y = 0;
        return y;
    }
    return y;
}

/* unsigned int mixer(int freq) */
/* { */
/*     unsigned int mix = (sineBuf[*frameP] * 0.5); */
/*     mix += (sineBuf[*frameP2] * 0.5); */
/*     (*frameP) += freq; */
/*     (*frameP2) += freq*2; */
/*             if(*frameP >= bufSize) */
/*             { */
/*                 *frameP = 0; */
/*             } */
/*             if(*frameP2 >= bufSize) */
/*             { */
/*                 *frameP2 = 0; */
/*             } */

/*     return mix; */
/* } */

void isr_routine(void)
{

    //cleara flaggan
    /* if(IFS(1) & (1<<7)) */
    if(PIC32_SPISTAT_SPIRBF & 1)
    {
        dummyRecieve = SPI2BUF;
        IFSCLR(1) = (1<<7);
        PORTDSET = (1<<1);
    }
    //clock
    if(IFS(0) & (1<<8))
    {

        if(PIC32_SPISTAT_SPIRBF == 1){
            IFSCLR(0) = (1<<8);
            /* PORTDSET = (1<<1); */
            counter++;
            IFSCLR(1) = (1<<6);
            PORTDCLR = (1<<1);
            /* SPI2BUF = buf[mix]; */
            /* mix = mixer(14); */
            SPI2BUF = triangleBuf[*frameP];
            (*frameP)+= 2;
            if(frame >= bufSize)
            {
                int rest = frame - bufSize;
                *frameP = rest;
            }
        }
        return;
    }
}

void setup(void)
{
    /* --------------fill sinewave buffer--------------- */
    float radians = 0;
    int i = 0;
    for(i; i < bufSize; i++)
    {
        //------------fill sine
        sineBuf[i] = fillSineBuffer(radians); //fill buffer
        radians += (2* 3.1415)/bufSize;
        //------------fill triangle
        triangleBuf[i] = fillTriangleBuffer(i);
        squareBuf[i] = fillSquareBuffer(i);
    }

    /* --------------SPI SETTINGS------------------- */
    SPI2CONCLR = 0xFFFFFFFF; //clear spi
    /* SPI2CONSET = (1<<31); */
    SPI2CONSET = (1<<28); //MSSEN not avaliable?
    /* SPI2CONSET = (1<<16); // master mode */
    SPI2CONSET = (1<<7); // master mode
    SPI2CONSET = (1<<5); // master mode
    SPI2CONSET = (1<<10); // 16 bit
    /* SPI2CONSET = (1<<23); */
    SPI2BRG = 15; //baud rate 2.5MHz
    /* SPI2BRG = 85; //baud rate 2.5MHz */
    SPI2STATCLR = (1<<6);
    /* SPI2BRG = 511; // */
    /* SPI2CONSET = (1<<2); */
    SPI2CONSET = (1<<15); //SPI ON

    dummyRecieve = SPI2BUF;
    /* ------spi flags ---------- */
    /* IECSET(1) = (1<<6); //tx interupt */
    IEC(1) = (1<<6);
    IEC(1) = (1<<7);
    IFSCLR(1) = (1<<6); //tx flag 
    IFSCLR(1) = (1<<7); //tx flag 
    IPCSET(7) = (7<<26); //highest priority
    IPCSET(7) = (3<<24);



    /* gpio */
    TRISDCLR = (1<<1);
    PORTD = 0;


    //timer
    T2CONCLR = 0xFFFFFFFF;
    IFSCLR(0) = (1<<8); //cleara flaggan 
    T2CONCLR = (1<<15);
    T2CONSET = PRESCALE << 4; //sätt prescale rätt
    PR2 = PR2VALUE; //timeoutvärde
    TMR2 = 0; //nollställ timer
    T2CONSET = (1 << 15); //starta timer

    IEC(0) = (1 << 8);
    /* IECSET(0) = (1<<8); //satta for timer 2 */
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

