#ifndef DESSIN_H
#define DESSIN_H

#include "structures.h"
#define TAILLEPOINT 8
// Déclaration des prototypes de fonctions présentes dans dessin.c
char* dessinerPoint(FILE *file, POINT p, int r);
char* dessinerCercle(FILE *file, double x, double y, double r);
void ecritureSVG(POINT tab[], FILE* file, int N, int inf, int sup, double *centerX, double *centerY, double *rayon);
void GenerationFichierSVG(POINT* tab, int N,int inf, int sup, double *centerX, double *centerY, double *rayon);
void trouver_c(POINT tab[], FILE* file, int N, double *centerX, double *centerY, double *rayon);

#endif /* DESSIN_H */
