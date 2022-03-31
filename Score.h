#ifndef Score_h
#define Score_h
/* --------------header for sangen samt tonalitet----------- */
extern float C, Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B;
extern int root;

extern float scoreBass [8][4];
extern float scoreTenor [8][4];
extern float scoreAlt2 [8][4];
extern float scoreAlt [8][4];
extern float scoreMelody [8][4];
extern float scoreBassAmp [8][4];
extern float scoreTenorAmp [8][4];
extern float scoreAltAmp [8][4];
extern float scoreMelodyAmp [8][4];
void make_score(void);



#endif
