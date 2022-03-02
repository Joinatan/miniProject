#ifndef voice_h
#define voice_h

typedef struct VOICE
{
    unsigned int buffer[1024];
    /* unsigned int freq = 1; */
    unsigned int position = 0;
    float amp = 1;
    unsigned int y = 0;

} VOICE;

/* unsigned int sound(const VOICE* self) */
/* { */
/*     (*self).y = (*self).buffer[(*self).position] * (*self).amp; */
/*     (*self.position) += (*self).freq; */
/*     return (*self).y; */
/* } */

#endif
