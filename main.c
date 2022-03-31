#include <stddef.h>   /* Declarations of integer sizes and the like, part 1 */
#include <stdint.h>   /* Declarations of integer sizes and the like, part 2 */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
/* #include </opt/mcb32tools/include/math.h> */
#include <math.h>
#include "VOICE.h"
#include "Score.h"
#include "PS2.h"


#define PRESCALE2 (4) //sätter timer2 till prescale 64 
#define PR2VALUE ((80000000 / 16 ) / 20000 ) //grund 50Hz
#define bufSize (1024 * 3)
#define maxAmp (0xfff)

unsigned int sineBuf[bufSize];
/* unsigned int triangleBuf[bufSize]; */
/* unsigned int squareBuf[bufSize]; */
int count = 0;
int beat = 0;
int bar = 0;
int melodyPlay = 0;
int slag = 0;

int dummyRecieve;
int counter = 0;
unsigned int mix = 0;
unsigned int mix2 = 0;
/* unsigned int dummyMix = 0; */
char triangleFlag = 0;
unsigned int triangle = 0;
unsigned char ps_reg = 0;
char ps_counter = 0;
char have_i_sampled = 0;

char key_pressed = 0;
char *key_pressedP = &key_pressed;
char note_off = 0;
char note_off_counter = 0;
/* char *note_offP = & */

VOICE bass;
VOICE tenor;
VOICE alt;
VOICE alt2;
VOICE melody;
VOICE test[5];

VOICE piano0;
VOICE piano1;
VOICE piano2;
VOICE piano3;
VOICE PIANO[4];

/* ------------funktion for en sinuskurva------------- */
unsigned int fillSineBuffer(float x)
{
    unsigned int y = ( unsigned int ) (((sinf(x)*0.5)+0.5) * maxAmp) ;
    return y;
}

/* ------------funktion for en triangel------------- */
unsigned int fillTriangleBuffer(int x)
{
    unsigned int y = 0;
    if(x >= bufSize/2 )
    {
        triangle -= 3;
        y = triangle;
        triangleFlag = 1;
        return y;
    }
    if(triangleFlag == 0)
    {
        triangle += 3;
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

/* ------------funktion for en fyrkantsvag------------- */
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

//mixer for den forprogrammerade laten
unsigned int mixer(VOICE voiceArray[], int len)
{
    //mixer for att mixa ihop en array av VOICE
    long int out = 0;
    int i = 0;
    for(i; i < len; i++) 
    {
        //mixa ihop signalerna
        out += make_sound(&voiceArray[i]);
    }
    //skala ner amplituden
    out = out/(i+1);
    return (unsigned int) out;
}

//mixer for pianot
unsigned int mixer2(VOICE voiceArray[], int len)
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


//interrupt
void isr_routine(void)
{
    if(IFS(0) & (1<<7))
    {
        while(ps_counter < 11) //11 interrupts per
        {
            if(IFS(0) & (1<<7)){
                IFSCLR(0) = (1<<7); //PS/2 flag
                if(ps_counter<9){

                    ps_reg = (ps_reg<<1); //shifta left 
                    ps_reg |= (PORTE & 0x2)>>1; 
                }
                ps_counter ++;
            }
        }

        ps_counter = 0;
        check_ps2_value(ps_reg, PIANO, key_pressedP, &note_off);
        ps_reg = 0;
        }
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

                if(key_pressed == 1){
                    SPI2BUF = mix2;
                    mix2 = mixer2(PIANO, 4);
                    dummyRecieve = SPI2BUF;
                    count = 0;
                }else{
                    SPI2BUF = mix;
                    mix = mixer(test, 5);
                    dummyRecieve = SPI2BUF;
                }

                /* if(count >= 51100/4){ */
                if(count >= 20000/4){
                    count = 0;
                    beat ++;
                    if(beat > 3)
                    {
                        beat = 0;
                        bar ++;
                        slag ++;
                        if(bar > 7)
                        {
                            bar = 0;
                            //alt
                            //spela melodi 
                        }
                        if(slag > 31)
                            slag = 0;
                    }
                    test[0].freq = scoreBass[bar][beat];
                    test[0].amp = scoreBassAmp[bar][beat];
                    test[1].freq = scoreTenor[bar][beat];
                    test[2].freq = scoreAlt[bar][beat];
                    test[3].freq = scoreAlt2[bar][beat];
                    test[4].freq = scoreMelody[bar][beat];

                    if(slag > 15 && slag < 31)
                    {
                        test[4].amp = scoreMelodyAmp[bar][beat];
                    }else{
                        test[4].amp = 0;
                    }
                    if(slag < 7)
                    {
                        test[1].amp = 0;
                        test[2].amp = 0;
                        test[3].amp = 0;
                    }else{
                        test[1].amp = scoreTenorAmp[bar][beat];
                        test[2].amp = scoreAltAmp[bar][beat];
                        test[3].amp = scoreAltAmp[bar][beat];
                    } 

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
            //fill buffers
            for(i; i < bufSize; i++)
            {
                //------------fill sine
                /* sineBuf[i] = fillSineBuffer(radians); //fill buffer */
                radians += (2* 3.1415)/bufSize;

                //------------fill triangle
                sineBuf[i] = fillTriangleBuffer(i);

                //-----------fill square
                /* sineBuf[i] = fillSquareBuffer(i); */
            }

            /* ------------- voices for song --------------- */
            bass.buffer = sineBuf;
            bass.freq = 5;
            bass.amp = 0;
            tenor.buffer = sineBuf;
            tenor.freq = 3 * 1.6;
            tenor.amp = 0;
            alt.buffer = sineBuf;
            alt.freq = 3*2.5;
            alt.amp = 0;
            alt2.buffer = sineBuf;
            melody.buffer = sineBuf;
            /* alt.freq = 3*2.5; */
            alt.amp = 0;
            test[0] = bass;
            test[1] = tenor;
            test[2] = alt;
            test[3] = alt2;
            test[4] = melody;
            /* ----------------------voices for piano------------------- */
            PIANO[0] = piano0;
            PIANO[1] = piano1;
            PIANO[2] = piano2;
            PIANO[3] = piano3;
            i=0;
            for(i; i<4; i++)
            {
                PIANO[i].buffer = sineBuf;
                PIANO[i].amp = 1;
            }

            /* --------------SPI SETTINGS------------------- */
            SPI2CONCLR = 0xFFFFFFFF; //clear spi
            SPI2CONSET = (1<<28); //MSSEN not avaliable?
            SPI2CONSET = (1<<7); // master mode
            SPI2CONSET = (1<<5); // master mode
            SPI2CONSET = (1<<10); // 16 bit
            SPI2BRG = 15; //baud rate 2.5MHz
            SPI2STATCLR = (1<<6);
            SPI2CONSET = (1<<15); //SPI ON

            dummyRecieve = SPI2BUF;
            /* ------spi flags ---------- */
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
            IPCSET(2) = (7<<2); //hogsta prioritet
            IPCSET(2) = 0x3; //hogsta prioritet

            /* --------------PS/2 ports---------------- */
            TRISDSET = (1<<8); //port26 input
            TRISESET = (1<<1); //port27 input

            /* --------------PS/2 INTERRUPTS-------- */

            IFSCLR(0) = (1<<7);
            IECSET(0) = (1<<7); //interrupt clock port 2 int1
            INTCONCLR = (1<<1); //falling edge
            IPCSET(1) = (7<<26); //priority
            IPCSET(1) = (3<<24);

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
            };

            return 0;
        }

