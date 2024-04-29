#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Déclaration des structures
typedef struct {
    int x;
    int y;
} POINT;

typedef struct {
    double x_cercle;
    double y_cercle;
    double rayon_cercle;
} CERCLE;

// Prototypes de fonctions
void findCircle_deux_points(POINT p1, POINT p2, double *centerX, double *centerY, double *rayon, double *centerX_dessin, double *centerY_dessin, double *rayondessin, int inf, int sup);
void findCircle(POINT p1, POINT p2, POINT p3, double *centerX, double *centerY, double *rayon, double *centerX_dessin, double *centerY_dessin, double *rayondessin, int inf, int sup);
int verification(POINT* tab, double *centerX, double *centerY, double *rayon, int N);
char* dessinerPoint(FILE *file, POINT p, int r);
char* dessinerCercle(FILE *file, double x, double y, double r);
void ecritureSVG(POINT tab[], FILE* file, int N, int inf, int sup, double *centerX, double *centerY, double *rayon);
void GenerationFichierSVG(POINT* tab, int N,int inf, int sup, double *centerX, double *centerY, double *rayon);
void trouver_c(POINT tab[], FILE* file, int N, double *centerX, double *centerY, double *rayon);
double distance(POINT p1, POINT p2);
int pointInsideCircle(POINT p, CERCLE c);
CERCLE welz(POINT* tab, int n);
int rand_a_b(int a, int b);
void algo_naif(FILE *file, POINT* tab, int N, int inf, int sup);

#endif /* STRUCTURES_H */
