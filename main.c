#include <stddef.h>   /* Declarations of integer sizes and the like, part 1 */
#include <stdint.h>   /* Declarations of integer sizes and the like, part 2 */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
/* #include </opt/mcb32tools/include/math.h> */
#include <math.h>
#include "VOICE.h"
#include "Score.h"


#define PRESCALE2 (4) //sätter timer2 till prescale 64 
/* #define PR2VALUE ((80000000 / 16 ) / 51100 ) //grund 50Hz */
#define PR2VALUE ((80000000 / 16 ) / 20000 ) //grund 50Hz
/* #define PR2VALUE ((80000000 / 16 ) / 991000 ) //grund 50Hz */
#define PRESCALE3 (7) //sätter timer2 till prescale 64 
#define PR3VALUE ((80000000 / 256 ) * 0.5 ) //grund 50Hz
/* #define PR2VALUE ((80000000 / 16 ) / 511 ) //grund 50Hz */
/* #define bufSize (1024) */
#define bufSize (1024 * 3)
#define maxAmp (0xfff)

unsigned int sineBuf[bufSize];
/* unsigned int triangleBuf[bufSize]; */
/* unsigned int squareBuf[bufSize]; */
int count = 0;
int beat = 0;
int bar = 0;
/* int frame = 0; */
/* int *frameP = &frame; */
/* int frame2 = 0; */
/* int *frameP2 = &frame2; */
int dummyRecieve;
int counter = 0;
unsigned int mix = 0;
/* unsigned int dummyMix = 0; */
char triangleFlag = 0;
unsigned int triangle = 0;

VOICE bass;
VOICE tenor;
VOICE alt;
VOICE alt2;
VOICE test[4];

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
unsigned int mixer(VOICE voiceArray[], int len)
{
    //mixer for att mixa ihop en array av VOICE
    long int out = 0;
    int i = 0;
    for(i; i < len; i++) 
    {
        out += make_sound(&voiceArray[i]);
    }
    out = out/(i+1);
    return (unsigned int) out;
}

/* unsigned int mixer_old(int freq, unsigned int buf[]) */
/* { */
/*     unsigned int y = buf[frame] + buf[frame2]; */
/*     /1* y += (buf[frame2]); *1/ */
/*     y = (unsigned int) (y * 0.3); */
/*     frame += freq; */
/*     frame2 += (unsigned int)(freq*1.55); */

/*     if(*frameP >= bufSize) */
/*     { */
/*         unsigned int rest = frame - bufSize; */
/*         frame = rest; */
/*     } */
/*     if(frame2 >= bufSize) */
/*     { */
/*         unsigned int rest = frame2 - bufSize; */
/*         frame2 = rest; */
/*     } */

/*     return y; */
/* } */

void isr_routine(void)
{
    //cleara flaggan
    /* if(IFS(1) & (1<<7)) */
    /* if(SPI2STAT & (0<<7)) //om spi-transfer ar klar */
    /* if(IFS(1) & (1<<7)) */
    if(PIC32_SPISTAT_SPIRBF & 1) //om spi-transfer ar klar
    {
        PORTDSET = (1<<1);
        dummyRecieve = SPI2BUF;
        IFSCLR(1) = (1<<7);
    }

    //clock
    if(IFS(0) & (1<<8))
    {
        IFSCLR(0) = (1<<8);
        count ++;
        //check beat
        if(PIC32_SPISTAT_SPITBE & (1<<3)){ //kolla att tx buffer ar tom
            counter = 1;
            /* IFSCLR(1) = (1<<6); */
            PORTDCLR = (1<<1);

            SPI2BUF = mix;
            dummyRecieve = SPI2BUF;

            /* if(beat == 0){ */
            mix = mixer(test, 4);
            /* }else{ */
            /* } */

            /* if(count >= 51100/4){ */
            if(count >= 20000/4){
                count = 0;
                beat ++;
                if(beat > 3)
                {
                    beat = 0;
                    bar ++;
                    if(bar > 7)
                        bar = 0;
                }
                test[0].freq = scoreBass[bar][beat];
                test[0].amp = scoreBassAmp[bar][beat];
                test[1].freq = scoreTenor[bar][beat];
                test[1].amp = scoreTenorAmp[bar][beat];
                test[2].freq = scoreAlt[bar][beat];
                test[2].amp = scoreAltAmp[bar][beat];
                test[3].freq = scoreAlt2[bar][beat];
                test[3].amp = scoreAltAmp[bar][beat];
                /* test[0].freq = score[0][2]; */

            }
            /* dummyMix = mixer_old(4, sineBuf); */
        }
        return;
    }
    /* if(IFS(0) & (1<<12)) //flag timer3 */
    /* { */
    /*     IFSCLR(0) = (1<<12); */
    /* } */
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
        /* triangleBuf[i] = fillTriangleBuffer(i); */
        /* squareBuf[i] = fillSquareBuffer(i); */
    }
    i=0;
    /* bass = {sineBuf, 0, 0, 0, 0}; */
    /* tenor = {sineBuf, 0, 0, 0, 0}; */
    bass.buffer = sineBuf;
    bass.freq = 5;
    bass.amp = 1;
    tenor.buffer = sineBuf;
    tenor.freq = 3 * 1.6;
    tenor.amp = 1;
    alt.buffer = sineBuf;
    alt.freq = 3*2.5;
    alt.amp = 1;
    alt2.buffer = sineBuf;
    /* alt.freq = 3*2.5; */
    alt.amp = 1;
    test[0] = bass;
    test[1] = tenor;
    test[2] = alt;
    test[3] = alt2;
    /* VOICE bass; */
    /* bass.buffer = sineBuf; */

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
    /* SPI2STATSET = (1<<3); */
    /* SPI2BRG = 511; // */
    /* SPI2CONSET = (1<<2); */
    SPI2CONSET = (1<<15); //SPI ON

    dummyRecieve = SPI2BUF;
    /* ------spi flags ---------- */
    /* IECSET(1) = (1<<6); //tx interupt */
    /* IECSET(1) = (1<<6); */ //tx flag
    IECSET(1) = (1<<7); //rx flag
    IFSCLR(1) = (1<<6); //tx flag 
    IFSCLR(1) = (1<<7); //tx flag 
    IPCSET(7) = (7<<26); //highest priority
    IPCSET(7) = (3<<24);



    /* gpio */
    TRISDCLR = (1<<1);
    PORTD = 0;


    //timer2
    T2CONCLR = 0xFFFFFFFF;
    IFSCLR(0) = (1<<8); //cleara flaggan 
    T2CONCLR = (1<<15);
    T2CONSET = PRESCALE2 << 4; //sätt prescale rätt
    PR2 = PR2VALUE; //timeoutvärde
    TMR2 = 0; //nollställ timer
    T2CONSET = (1 << 15); //starta timer

    IEC(0) = (1 << 8);
    /* IECSET(0) = (1<<8); //satta for timer 2 */
    IPCSET(2) = (7<<2); //hogsta prioritet
    IPCSET(2) = 0x3; //hogsta prioritet

    //timer3
    /* T3CONCLR = 0xFFFFFFFF; */
    /* IFSCLR(0) = (1<<12); //cleara flaggan */ 
    /* T3CONCLR = (1<<15); */
    /* T3CONSET = PRESCALE3 << 4; //sätt prescale rätt */
    /* PR3 = PR3VALUE; //timeoutvärde */
    /* TMR3 = 0; //nollställ timer */
    /* T3CONSET = (1 << 15); //starta timer */

    /* /1* IEC(0) = (1 << 12); //enable interrupt timer 3 *1/ */
    /* IPCSET(3) = (7<<2); //hogsta prioritet */
    /* IPCSET(3) = 0x2; //hogsta prioritet */

    enable_interrupt();
    return;
}

int main(){

make_score();
setup();

    SPI2BUF = 0x0F;
    dummyRecieve = SPI2BUF;
    while(1)
    {
        if(counter == 1)
        {
            counter = 0;
        }
    };

    return 0;
}

