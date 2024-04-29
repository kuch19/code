#ifndef CALCULS_H
#define CALCULS_H
#include "structures.h"

// Déclaration des prototypes de fonctions présentes dans calculs.c
void findCircle_deux_points(POINT p1, POINT p2, double *centerX, double *centerY, double *rayon, double *centerX_dessin, double *centerY_dessin, double *rayondessin, int inf, int sup);
void findCircle(POINT p1, POINT p2, POINT p3, double *centerX, double *centerY, double *rayon, double *centerX_dessin, double *centerY_dessin, double *rayondessin, int inf, int sup);
int verification(POINT* tab, double *centerX, double *centerY, double *rayon, int N);
int rand_a_b(int a, int b);
void algo_naif(FILE *file, POINT* tab, int N, int inf, int sup);

#endif /* CALCULS_H */
