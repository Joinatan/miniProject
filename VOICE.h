#ifndef VOICE_h
#define VOICE_h

/* struct VOICE; */
typedef struct VOICE
{
    unsigned int *buffer;
    float freq;
    int position;
    float amp;
    unsigned int y;

} VOICE;

unsigned int make_sound(VOICE* self);

#endif
