
float C = 1;
float Db = 1.059;
float D = 1.122;
float Eb = 1.189;
float E = 1.26;
float F = 1.335;
float Gb = 1.414;
float G = 1.498;
float Ab = 1.587;
float A = 1.682;
float Bb = 1.782;
float B = 1.888;
int root = 50;

float scoreBass [8][4];
float scoreTenor [8][4];
float scoreAlt2 [8][4];
float scoreAlt [8][4];
float scoreMelody [8][4];
float scoreBassAmp [8][4];
float scoreTenorAmp [8][4];
float scoreAltAmp [8][4];
float scoreMelodyAmp [8][4];


void make_score(void)
{
    /* -------------Melody------------- */
    //1 C 
scoreMelody[0][0] = (Eb * root) * 1;
scoreMelody[0][1] = (E * root) * 1;
scoreMelody[0][2] = (G * root) * 1;
scoreMelody[0][3] = (Eb * root) * 2;

scoreMelody[1][0] = (E * root) * 2;
scoreMelody[1][1] = (G * root) * 2;
scoreMelody[1][2] = (Eb * root) * 4;
scoreMelody[1][3] = (E * root) * 4;

scoreMelody[2][0] = (G * root) * 4;
scoreMelody[2][1] = (Eb * root) * 8;
scoreMelody[2][2] = (E * root) * 8;
scoreMelody[2][3] = (G * root) * 8;

scoreMelody[3][0] = (Eb * root) * 9;
scoreMelody[3][1] = (E * root) * 9;
scoreMelody[3][2] = (G * root) * 7;
scoreMelody[3][3] = (G * root) ;

    //2 G
scoreMelody[4][0] = (A * root) * 4;
scoreMelody[4][1] = (Bb * root) * 4;
scoreMelody[4][2] = (F * root) * 8;
scoreMelody[4][3] = (A * root) * 2;

scoreMelody[5][0] = (Bb * root) * 2;
scoreMelody[5][1] = (F * root) * 4;
scoreMelody[5][2] = (A * root) * 1;
scoreMelody[5][3] = (Bb * root) * 1;

scoreMelody[6][0] = (F * root) * 2;
scoreMelody[6][1] = (A * root) * 0.5;
scoreMelody[6][2] = (Bb * root) * 0.5;
scoreMelody[6][3] = (F * root) * 1;

scoreMelody[7][0] = (F * root) * 1;
scoreMelody[7][1] = (Bb * root) * 1;
scoreMelody[7][2] = (F * root)  * 1;
scoreMelody[7][3] = (D * root)  ;

    /* -------------BASS------------- */
    //1 C 
scoreBass[0][0] = (C * root) ;
scoreBass[0][1] = (C * root) ;
scoreBass[0][2] = (C * root) ;
scoreBass[0][3] = (E * root) ;

scoreBass[1][0] = (E * root) ;
scoreBass[1][1] = (E * root) ;
scoreBass[1][2] = (G * root) ;
scoreBass[1][3] = (G * root) ;

scoreBass[2][0] = (C * root) ;
scoreBass[2][1] = (C * root) ;
scoreBass[2][2] = (C * root) ;
scoreBass[2][3] = (E * root) ;

scoreBass[3][0] = (E * root) ;
scoreBass[3][1] = (E * root) ;
scoreBass[3][2] = (G * root) ;
scoreBass[3][3] = (G * root) ;

    //2 G
scoreBass[4][0] = (G * root) * 0.5;
scoreBass[4][1] = (G * root) * 0.5;
scoreBass[4][2] = (G * root) * 0.5;
scoreBass[4][3] = (Bb * root) * 0.5;

scoreBass[5][0] = (Bb * root) * 0.5;
scoreBass[5][1] = (Bb * root) * 0.5;
scoreBass[5][2] = (D * root)  ;
scoreBass[5][3] = (D * root)  ;

scoreBass[6][0] = (G * root) * 0.5;
scoreBass[6][1] = (G * root) * 0.5;
scoreBass[6][2] = (G * root) * 0.5;
scoreBass[6][3] = (Bb * root) * 0.5;

scoreBass[7][0] = (Bb * root) * 0.5;
scoreBass[7][1] = (Bb * root) * 0.5;
scoreBass[7][2] = (D * root)  ;
scoreBass[7][3] = (D * root)  ;

    /* --------------TENOR---------------- */
//c
scoreTenor[0][0] =(G * root)*1;
scoreTenor[0][1] =(G * root)*1;
scoreTenor[0][2] =(G * root)*1;
scoreTenor[0][3] =(G * root)*1;

scoreTenor[1][0] =(G * root)*1;
scoreTenor[1][1] =(G * root)*1;
scoreTenor[1][2] =(G * root)*1;
scoreTenor[1][3] =(G * root)*1;

scoreTenor[2][0] =(G * root)*1;
scoreTenor[2][1] =(G * root)*1;
scoreTenor[2][2] =(G * root)*1;
scoreTenor[2][3] =(G * root)*1;

scoreTenor[3][0] =(G * root)*1;
scoreTenor[3][1] =(G * root)*1;
scoreTenor[3][2] =(G * root)*1;
scoreTenor[3][3] =(G * root)*1;

//g
scoreTenor[4][0] =(F * root)*1;
scoreTenor[4][1] =(F * root)*1;
scoreTenor[4][2] =(F * root)*1;
scoreTenor[4][3] =(F * root)*1;

scoreTenor[5][0] =(F * root)*1;
scoreTenor[5][1] =(F * root)*1;
scoreTenor[5][2] =(F * root)*1;
scoreTenor[5][3] =(F * root)*1;

scoreTenor[6][0] =(F * root)*1;
scoreTenor[6][1] =(F * root)*1;
scoreTenor[6][2] =(F * root)*1;
scoreTenor[6][3] =(F * root)*1;

scoreTenor[7][0] =(F * root)*1;
scoreTenor[7][1] =(F * root)*1;
scoreTenor[7][2] =(F * root)*1;
scoreTenor[7][3] =(F * root)*1;

    /* ------------ALT22222------------ */
//c
scoreAlt2[0][0] =(B * root)*1;
scoreAlt2[0][1] =(B * root)*1;
scoreAlt2[0][2] =(B * root)*1;
scoreAlt2[0][3] =(B * root)*1;

scoreAlt2[1][0] =(B * root)*1;
scoreAlt2[1][1] =(B * root)*1;
scoreAlt2[1][2] =(B * root)*1;
scoreAlt2[1][3] =(B * root)*1;

scoreAlt2[2][0] =(B * root)*1;
scoreAlt2[2][1] =(B * root)*1;
scoreAlt2[2][2] =(B * root)*1;
scoreAlt2[2][3] =(B * root)*1;

scoreAlt2[3][0] =(B * root)*1;
scoreAlt2[3][1] =(B * root)*1;
scoreAlt2[3][2] =(B * root)*1;
scoreAlt2[3][3] =(B * root)*1;

//g
scoreAlt2[4][0] =(Bb * root)*1;
scoreAlt2[4][1] =(Bb * root)*1;
scoreAlt2[4][2] =(Bb * root)*1;
scoreAlt2[4][3] =(Bb * root)*1;

scoreAlt2[5][0] =(Bb * root)*1;
scoreAlt2[5][1] =(Bb * root)*1;
scoreAlt2[5][2] =(Bb * root)*1;
scoreAlt2[5][3] =(Bb * root)*1;

scoreAlt2[6][0] =(Bb * root)*1;
scoreAlt2[6][1] =(Bb * root)*1;
scoreAlt2[6][2] =(Bb * root)*1;
scoreAlt2[6][3] =(Bb * root)*1;

scoreAlt2[7][0] =(Bb * root)*1;
scoreAlt2[7][1] =(Bb * root)*1;
scoreAlt2[7][2] =(B * root)*1;
scoreAlt2[7][3] =(B * root)*1;

    /* ------------ALT------------ */
//c
scoreAlt[0][0] =(E * root)*2;
scoreAlt[0][1] =(E * root)*2;
scoreAlt[0][2] =(E * root)*2;
scoreAlt[0][3] =(E * root)*2;

scoreAlt[1][0] =(E * root)*2;
scoreAlt[1][1] =(E * root)*2;
scoreAlt[1][2] =(E * root)*2;
scoreAlt[1][3] =(E * root)*2;

scoreAlt[2][0] =(E * root)*2;
scoreAlt[2][1] =(E * root)*2;
scoreAlt[2][2] =(E * root)*2;
scoreAlt[2][3] =(E * root)*2;

scoreAlt[3][0] =(E * root)*2;
scoreAlt[3][1] =(E * root)*2;
scoreAlt[3][2] =(E * root)*2;
scoreAlt[3][3] =(E * root)*2;

//g
scoreAlt[4][0] =(D * root)*2;
scoreAlt[4][1] =(D * root)*2;
scoreAlt[4][2] =(D * root)*2;
scoreAlt[4][3] =(D * root)*2;

scoreAlt[5][0] =(D * root)*2;
scoreAlt[5][1] =(D * root)*2;
scoreAlt[5][2] =(D * root)*2;
scoreAlt[5][3] =(D * root)*2;

scoreAlt[6][0] =(D * root)*2;
scoreAlt[6][1] =(D * root)*2;
scoreAlt[6][2] =(D * root)*2;
scoreAlt[6][3] =(D * root)*2;

scoreAlt[7][0] =(D * root)*2;
scoreAlt[7][1] =(D * root)*2;
scoreAlt[7][2] =(Eb * root)*2;
scoreAlt[7][3] =(Eb * root)*2;

    /* --------------Melody AMP--------------- */

scoreMelodyAmp[0][0] = 1.5;
scoreMelodyAmp[0][1] = 1;
scoreMelodyAmp[0][2] = 1;
scoreMelodyAmp[0][3] = 1;

scoreMelodyAmp[1][0] = 1;
scoreMelodyAmp[1][1] = 1;
scoreMelodyAmp[1][2] = 1;
scoreMelodyAmp[1][3] = 1;

scoreMelodyAmp[2][0] = 1;
scoreMelodyAmp[2][1] = 0.7;
scoreMelodyAmp[2][2] = 0.5;
scoreMelodyAmp[2][3] = 0.3;

scoreMelodyAmp[3][0] = 0.4;
scoreMelodyAmp[3][1] = 0.4;
scoreMelodyAmp[3][2] = 0.41;
scoreMelodyAmp[3][3] = 0.41;

//g
//
scoreMelodyAmp[4][0] = 0.8;
scoreMelodyAmp[4][1] = 0.81;
scoreMelodyAmp[4][2] = 0.5;
scoreMelodyAmp[4][3] = 1;

scoreMelodyAmp[5][0] = 1;
scoreMelodyAmp[5][1] = 0.6;
scoreMelodyAmp[5][2] = 1;
scoreMelodyAmp[5][3] = 1;

scoreMelodyAmp[6][0] = 1;
scoreMelodyAmp[6][1] = 2;
scoreMelodyAmp[6][2] = 2;
scoreMelodyAmp[6][3] = 2;

scoreMelodyAmp[7][0] = 2;
scoreMelodyAmp[7][1] = 0;
scoreMelodyAmp[7][2] = 0;
scoreMelodyAmp[7][3] = 0;

    /* --------------BASS AMP--------------- */

scoreBassAmp[0][0] = 2;
scoreBassAmp[0][1] = 2;
scoreBassAmp[0][2] = 0;
scoreBassAmp[0][3] = 2;

scoreBassAmp[1][0] = 0;
scoreBassAmp[1][1] = 0;
scoreBassAmp[1][2] = 2;
scoreBassAmp[1][3] = 0;

scoreBassAmp[2][0] = 2;
scoreBassAmp[2][1] = 2;
scoreBassAmp[2][2] = 0;
scoreBassAmp[2][3] = 2;

scoreBassAmp[3][0] = 0;
scoreBassAmp[3][1] = 0;
scoreBassAmp[3][2] = 2;
scoreBassAmp[3][3] = 0;

//g
//
scoreBassAmp[4][0] = 2;
scoreBassAmp[4][1] = 2;
scoreBassAmp[4][2] = 0;
scoreBassAmp[4][3] = 2;

scoreBassAmp[5][0] = 0;
scoreBassAmp[5][1] = 0;
scoreBassAmp[5][2] = 2;
scoreBassAmp[5][3] = 0;

scoreBassAmp[6][0] = 2;
scoreBassAmp[6][1] = 2;
scoreBassAmp[6][2] = 0;
scoreBassAmp[6][3] = 2;

scoreBassAmp[7][0] = 0;
scoreBassAmp[7][1] = 0;
scoreBassAmp[7][2] = 0;
scoreBassAmp[7][3] = 0;

    /* --------------TENOR AMP--------------- */

scoreTenorAmp[0][0] = 1;
scoreTenorAmp[0][1] = 0.2;
scoreTenorAmp[0][2] = 0;
scoreTenorAmp[0][3] = 0.6;

scoreTenorAmp[1][0] = 0;
scoreTenorAmp[1][1] = 0;
scoreTenorAmp[1][2] = 0;
scoreTenorAmp[1][3] = 0;

scoreTenorAmp[2][0] = 1;
scoreTenorAmp[2][1] = 0.2;
scoreTenorAmp[2][2] = 0;
scoreTenorAmp[2][3] = 0.6;

scoreTenorAmp[3][0] = 0;
scoreTenorAmp[3][1] = 0;
scoreTenorAmp[3][2] = 0;
scoreTenorAmp[3][3] = 0;

//g
scoreTenorAmp[4][0] = 1;
scoreTenorAmp[4][1] = 0.2;
scoreTenorAmp[4][2] = 0;
scoreTenorAmp[4][3] = 0.6;

scoreTenorAmp[5][0] = 0;
scoreTenorAmp[5][1] = 0;
scoreTenorAmp[5][2] = 0;
scoreTenorAmp[5][3] = 0;

scoreTenorAmp[6][0] = 1;
scoreTenorAmp[6][1] = 0.2;
scoreTenorAmp[6][2] = 0;
scoreTenorAmp[6][3] = 0.6;

scoreTenorAmp[7][0] = 0;
scoreTenorAmp[7][1] = 0;
scoreTenorAmp[7][2] = 1.2;
scoreTenorAmp[7][3] = 1.2;

/* -------------ALT AMP----------------- */

scoreAltAmp[0][0] = 1;
scoreAltAmp[0][1] = 0.2;
scoreAltAmp[0][2] = 0;
scoreAltAmp[0][3] = 0.6;

scoreAltAmp[1][0] = 0;
scoreAltAmp[1][1] = 0;
scoreAltAmp[1][2] = 0;
scoreAltAmp[1][3] = 0;

scoreAltAmp[2][0] = 1;
scoreAltAmp[2][1] = 0.2;
scoreAltAmp[2][2] = 0;
scoreAltAmp[2][3] = 0.6;

scoreAltAmp[3][0] = 0;
scoreAltAmp[3][1] = 0;
scoreAltAmp[3][2] = 0;
scoreAltAmp[3][3] = 0;

//g
scoreAltAmp[4][0] = 1;
scoreAltAmp[4][1] = 0.2;
scoreAltAmp[4][2] = 0;
scoreAltAmp[4][3] = 0.6;

scoreAltAmp[5][0] = 0;
scoreAltAmp[5][1] = 0;
scoreAltAmp[5][2] = 0;
scoreAltAmp[5][3] = 0;

scoreAltAmp[6][0] = 1;
scoreAltAmp[6][1] = 0.2;
scoreAltAmp[6][2] = 0;
scoreAltAmp[6][3] = 0.2;

scoreAltAmp[7][0] = 0;
scoreAltAmp[7][1] = 0;
scoreAltAmp[7][2] = 1.2;
scoreAltAmp[7][3] = 1.2;
}
