#ifndef VOICE_h
#define VOICE_h

/* struct VOICE; */
typedef struct VOICE
{
    /* unsigned int buffer[1024]; */
    unsigned int *buffer;
    float freq;
    /* unsigned int freq; */
    int position;
    float amp;
    unsigned int y;

} VOICE;

unsigned int make_sound(VOICE* self);
/* { */
/*     (*self).y = (*self).buffer[(*self).position] * (*self).amp; */
/*     /1* (*self).position +=  ((*self).freq) + 3; *1/ */
/*     (*self).position += (unsigned int) ((*self).freq); */
/*     if((*self).position >= 1024*3) */
/*     { */
/*        unsigned int rest = (*self).position - (1024*3); */
/*        (*self).position = rest; */
/*        /1* (*self).position = 0; *1/ */
/*     } */
/*     return (*self).y; */
/* } */

#endif
