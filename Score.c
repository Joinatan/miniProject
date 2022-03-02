
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
float scoreBassAmp [8][4];
float scoreTenorAmp [8][4];
float scoreAltAmp [8][4];


void make_score(void)
{
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
scoreBass[4][0] = (G * root) ;
scoreBass[4][1] = (G * root) ;
scoreBass[4][2] = (G * root) ;
scoreBass[4][3] = (Bb * root);

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
scoreAlt2[7][2] =(Bb * root)*1;
scoreAlt2[7][3] =(Bb * root)*1;

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

    /* --------------BASS AMP--------------- */

scoreBassAmp[0][0] = 1;
scoreBassAmp[0][1] = 1.5;
scoreBassAmp[0][2] = 1.5;
scoreBassAmp[0][3] = 1;

scoreBassAmp[1][0] = 1.5;
scoreBassAmp[1][1] = 1.5;
scoreBassAmp[1][2] = 1;
scoreBassAmp[1][3] = 1.5;

scoreBassAmp[2][0] = 1;
scoreBassAmp[2][1] = 0.5;
scoreBassAmp[2][2] = 0.5;
scoreBassAmp[2][3] = 1;

scoreBassAmp[3][0] = 0.5;
scoreBassAmp[3][1] = 0.5;
scoreBassAmp[3][2] = 1;
scoreBassAmp[3][3] = 0.5;

//g
//
scoreBassAmp[4][0] = 1;
scoreBassAmp[4][1] = 0.5;
scoreBassAmp[4][2] = 0.5;
scoreBassAmp[4][3] = 1;

scoreBassAmp[5][0] = 0.5;
scoreBassAmp[5][1] = 0.5;
scoreBassAmp[5][2] = 1;
scoreBassAmp[5][3] = 0.5;

scoreBassAmp[6][0] = 1;
scoreBassAmp[6][1] = 0.5;
scoreBassAmp[6][2] = 0.5;
scoreBassAmp[6][3] = 1;

scoreBassAmp[7][0] = 0;
scoreBassAmp[7][1] = 0;
scoreBassAmp[7][2] = 0;
scoreBassAmp[7][3] = 0;

    /* --------------TENOR AMP--------------- */

scoreTenorAmp[0][0] = 1;
scoreTenorAmp[0][1] = 0.2;
scoreTenorAmp[0][2] = 0;
scoreTenorAmp[0][3] = 1;

scoreTenorAmp[1][0] = 0;
scoreTenorAmp[1][1] = 0;
scoreTenorAmp[1][2] = 0;
scoreTenorAmp[1][3] = 0;

scoreTenorAmp[2][0] = 1;
scoreTenorAmp[2][1] = 0.2;
scoreTenorAmp[2][2] = 0;
scoreTenorAmp[2][3] = 1;

scoreTenorAmp[3][0] = 0;
scoreTenorAmp[3][1] = 0;
scoreTenorAmp[3][2] = 0;
scoreTenorAmp[3][3] = 0;

//g
scoreTenorAmp[4][0] = 1;
scoreTenorAmp[4][1] = 0.2;
scoreTenorAmp[4][2] = 0;
scoreTenorAmp[4][3] = 1;

scoreTenorAmp[5][0] = 0;
scoreTenorAmp[5][1] = 0;
scoreTenorAmp[5][2] = 0;
scoreTenorAmp[5][3] = 0;

scoreTenorAmp[6][0] = 1;
scoreTenorAmp[6][1] = 0.2;
scoreTenorAmp[6][2] = 0;
scoreTenorAmp[6][3] = 1;

scoreTenorAmp[7][0] = 0;
scoreTenorAmp[7][1] = 0;
scoreTenorAmp[7][2] = 0;
scoreTenorAmp[7][3] = 0;

/* -------------ALT AMP----------------- */

scoreAltAmp[0][0] = 1;
scoreAltAmp[0][1] = 0.2;
scoreAltAmp[0][2] = 0;
scoreAltAmp[0][3] = 1;

scoreAltAmp[1][0] = 0;
scoreAltAmp[1][1] = 0;
scoreAltAmp[1][2] = 0;
scoreAltAmp[1][3] = 0;

scoreAltAmp[2][0] = 1;
scoreAltAmp[2][1] = 0.2;
scoreAltAmp[2][2] = 0;
scoreAltAmp[2][3] = 1;

scoreAltAmp[3][0] = 0;
scoreAltAmp[3][1] = 0;
scoreAltAmp[3][2] = 0;
scoreAltAmp[3][3] = 0;

//g
scoreAltAmp[4][0] = 1;
scoreAltAmp[4][1] = 0.2;
scoreAltAmp[4][2] = 0;
scoreAltAmp[4][3] = 1;

scoreAltAmp[5][0] = 0;
scoreAltAmp[5][1] = 0;
scoreAltAmp[5][2] = 0;
scoreAltAmp[5][3] = 0;

scoreAltAmp[6][0] = 1;
scoreAltAmp[6][1] = 0.2;
scoreAltAmp[6][2] = 0;
scoreAltAmp[6][3] = 1;

scoreAltAmp[7][0] = 0;
scoreAltAmp[7][1] = 0;
scoreAltAmp[7][2] = 1;
scoreAltAmp[7][3] = 1;
}
