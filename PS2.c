#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "Score.h"
#include "VOICE.h"

unsigned int pressed = 0; 
int voice_change = 0;
int voice_array_index[12];
int root2 = 25;
char noteOff = 0;
void check_ps2_value(unsigned char ps2, VOICE voice_array[], char *song_pause, char *note_off)
{
    if(voice_change > 3)
    {
        voice_change = 0;
    }
    if(voice_change < 0)
    {
        voice_change = 3;
    }

    switch(ps2)
    {
        case 0x0f: //note off

            noteOff = 1;
            break;

            //a = c index 0;
        case 0x38:
            if(pressed & 1 && noteOff == 1)
            {
                voice_array[voice_array_index[0]].amp = 0;
                pressed &= ~(1);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if((~pressed) & 1)
            {
                voice_array[voice_change].freq = root2 * C * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 1;
                voice_array_index[0] = voice_change;
                voice_change++;
            }
            break;
            //w = Db
        case 0xb8:
            if(pressed & 2 && noteOff == 1)
            {
                voice_array[voice_array_index[1]].amp = 0;
                pressed &= ~(2);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 2)
            {
                voice_array[voice_change].freq = root2 * Db * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 2;
                voice_array_index[1] = voice_change;
                voice_change++;
            }
            break;

            //s = D
        case 0xd8:
            if(pressed & 4 && noteOff == 1)
            {
                voice_array[voice_array_index[2]].amp = 0;
                pressed &= ~(4);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 4)
            {
                voice_array[voice_change].freq = root2 * D * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 4;
                voice_array_index[2] = voice_change;
                voice_change++;
            }
            break;
            //e = Eb 
        case 0x24:
            if(pressed & 8 && noteOff == 1)
            {
                voice_array[voice_array_index[3]].amp = 0;
                pressed &= ~(8);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 8)
            {
                voice_array[voice_change].freq = root2 * Eb * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 8;
                voice_array_index[3] = voice_change;
                voice_change++;
            }
            break;
            //d = E 
        case 0xc4:
            if(pressed & 16 && noteOff == 1)
            {
                voice_array[voice_array_index[4]].amp = 0;
                pressed &= ~(16);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 16)
            {
                voice_array[voice_change].freq = root2 * E * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 16;
                voice_array_index[4] = voice_change;
                voice_change++;
            }
            break;
            //f = F 
        case 0xd4:
            if(pressed & 32 && noteOff == 1)
            {
                voice_array[voice_array_index[5]].amp = 0;
                pressed &= ~(32);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 32)
            {
                voice_array[voice_change].freq = root2 * F * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 32;
                voice_array_index[5] = voice_change;
                voice_change++;
            }
            break;
            //t = Gb 
        case 0x34:
            if(pressed & 64 && noteOff == 1)
            {
                voice_array[voice_array_index[6]].amp = 0;
                pressed &= ~(64);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 64)
            {
                voice_array[voice_change].freq = root2 * Gb * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 64;
                voice_array_index[6] = voice_change;
                voice_change++;
            }
            break;
            //g = G 
        case 0x2c:
            if(pressed & 128 && noteOff == 1)
            {
                voice_array[voice_array_index[7]].amp = 0;
                pressed &= ~(128);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 128)
            {
                voice_array[voice_change].freq = root2 * G * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 128;
                voice_array_index[7] = voice_change;
                voice_change++;
            }
            break;
            //y = Ab
        case 0xac:
            if(pressed & 256 && noteOff == 1)
            {
                voice_array[voice_array_index[8]].amp = 0;
                pressed &= ~(256);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 256)
            {
                voice_array[voice_change].freq = root2 * Ab * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 256;
                voice_array_index[8] = voice_change;
                voice_change++;
            }
            break;
            //h = A
        case 0xcc:
            if(pressed & 512 && noteOff == 1)
            {
                voice_array[voice_array_index[9]].amp = 0;
                pressed &= ~(512);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 512)
            {
                voice_array[voice_change].freq = root2 * A * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 512;
                voice_array_index[9] = voice_change;
                voice_change++;
            }
            break;
            //u = Bb 
        case 0x3c:
            if(pressed & 1024 && noteOff == 1)
            {
                voice_array[voice_array_index[10]].amp = 0;
                pressed &= ~(1024);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 1024)
            {
                voice_array[voice_change].freq = root2 * Bb * 2;
                voice_array[voice_change].amp = 1;
                pressed |= 1024;
                voice_array_index[10] = voice_change;
                voice_change++;
            }
            break;
            //j = B 
        case 0xdc:
            if(pressed & (2048) && noteOff == 1)
            {
                voice_array[voice_array_index[11]].amp = 0;
                pressed &= ~(2048);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & (2048))
            {
                voice_array[voice_change].freq = root2 * B * 2;
                voice_array[voice_change].amp = 1;
                pressed |= (2048) ;
                voice_array_index[11] = voice_change;
                voice_change++;
            }
            break;
            //k = c2
        case 0x42:
            if(pressed & 4096 && noteOff == 1)
            {
                voice_array[voice_array_index[11]].amp = 0;
                pressed &= ~(4096);
                *note_off = 0;
                noteOff = 0;
                voice_change--;
            }else if(~pressed & 4096)
            {
                voice_array[voice_change].freq = root2 * C * 4;
                voice_array[voice_change].amp = 1;
                pressed |= 4096;
                voice_array_index[11] = voice_change;
                voice_change++;
            }
            break;

            // ',' pause
        case 0x82:
            *song_pause = 1;
            //mutea piano
            pressed = 0;
            int j = 0;
            for(j; j < 4; j++)
                voice_array[j].amp = 0;
            voice_array[j].freq = 0;
            break; 

            // '.' play
        case 0x92:
            *song_pause = 0;
            int i = 0;

            //mutea piano
            pressed = 0;

            for(i; i < 4; i++)
                voice_array[i].amp = 0;
            voice_array[i].freq = 0;
            /* T2CONSET = (1<<15); */
            break;
    }
    return;
}
