#ifndef voice_h
#define voice_h

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

unsigned int make_sound(VOICE* self)
{
    (*self).y = (*self).buffer[(*self).position] * (*self).amp;
    /* (*self).position +=  ((*self).freq) + 3; */
    (*self).position += (unsigned int) ((*self).freq);
    if((*self).position >= 1024*3)
    {
       unsigned int rest = (*self).position - (1024*3);
       (*self).position = rest;
       /* (*self).position = 0; */
    }
    return (*self).y;
}

#endif
