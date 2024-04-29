#include "../include/calculs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void findCircle_deux_points(POINT p1, POINT p2, double *centerX, double *centerY, double *rayon, double *centerX_dessin, double *centerY_dessin, double *rayondessin, int inf, int sup) {
    // Calcul des coordonnées du centre potentiel du cercle
    *centerX = (p1.x + p2.x) /2;
    *centerY = (p1.y + p2.y) /2;
    
    *rayon = sqrt(pow(*centerX - p1.x, 2) + pow(*centerY - p1.y, 2));
    // Calcul du rayon du cercle
    *centerX_dessin = ((*centerX-inf)*1800/(sup-inf))+100;
    *centerY_dessin = ((*centerY-inf)*1800/(sup-inf))+100;
    double n_pix = ((p1.x-inf)*1800/(sup-inf))+100;
    double n_piy = ((p1.y-inf)*1800/(sup-inf))+100;
    *rayondessin = sqrt(pow(*centerX_dessin - n_pix, 2) + pow(*centerY_dessin - n_piy, 2));
}

// Fonction pour calculer le centre et le rayon du cercle passant par trois points
void findCircle(POINT p1, POINT p2, POINT p3, double *centerX, double *centerY, double *rayon, double *centerX_dessin, double *centerY_dessin, double *rayondessin, int inf, int sup) {
    // Calcul des coordonnées du centre potentiel du cercle
    double m1 = (p2.y - p1.y) / (p2.x - p1.x);
    double m2 = (p3.y - p2.y) / (p3.x - p2.x);

    *centerX = (m1 * m2 * (p3.y - p1.y) + m1 * (p2.x + p3.x) - m2 * (p1.x + p2.x)) / (2 * (m1 - m2));
    *centerY = -1 * (*centerX - (p1.x + p2.x) / 2) / m1 + (p1.y + p2.y) / 2;
    // Calcul du rayon du cercle
    *rayon = sqrt(pow(*centerX - p1.x, 2) + pow(*centerY - p1.y, 2));
    *centerX_dessin = ((*centerX-inf)*1800/(sup-inf))+100;
    *centerY_dessin = ((*centerY-inf)*1800/(sup-inf))+100;
    double n_pix = ((p1.x-inf)*1800/(sup-inf))+100;
    double n_piy = ((p1.y-inf)*1800/(sup-inf))+100;
    *rayondessin = sqrt(pow(*centerX_dessin - n_pix, 2) + pow(*centerY_dessin - n_piy, 2));
}

// Fonction de vérification si tous les points sont à l'intérieur du cercle
int verification(POINT* tab, double *centerX, double *centerY, double *rayon, int N) {
    for (int i = 0; i < N; i++) {
        POINT p;
        p.x = tab[i].x;
        p.y = tab[i].y;
        double distance = sqrt(pow(*centerX - p.x, 2) + pow(*centerY - p.y, 2));
        if (distance > *rayon) {
            return 0;
        }
    }
    return 1;
}

// Fonction de génération de nombre aléatoire dans un intervalle
int rand_a_b (int a, int b) {
    return rand() % (b - a) + a;
}

void algo_naif(FILE *file, POINT* tab, int N, int inf, int sup) {
    double centerX, centerY, rayon;
    double centerX_dessin, centerY_dessin, rayondessin;
    double res_x, res_y, res_rayon;
    double res_x_dessin, res_y_dessin, res_rayon_dessin;
    
    res_rayon = INFINITY;

    for (int i = 0; i < N-1; i++) {
        POINT p;
        p.x = tab[i].x;
        p.y = tab[i].y;
        for (int j = i+1; j < N; j++) {
            POINT q;
            q.x = tab[j].x;
            q.y = tab[j].y;
            findCircle_deux_points(p, q, &centerX, &centerY, &rayon, &centerX_dessin, &centerY_dessin, &rayondessin, inf, sup);
            // Vérification des points
            if (verification(tab, &centerX, &centerY, &rayon,N) == 1){
                dessinerCercle(file, centerX_dessin, centerY_dessin, rayondessin);
                return;
            }
        }
    }
  
    for (int i = 0; i < N-2; i++) {
        POINT p;
        p.x = tab[i].x;
        p.y = tab[i].y;
        for (int j = i+1; j < N-1; j++) {
            POINT q;
            q.x = tab[j].x;
            q.y = tab[j].y;
            for (int k = j+1; k < N; k++) {
                POINT r;
                r.x = tab[k].x;
                r.y = tab[k].y;
                double d = (p.x * (q.y - r.y) + q.x * (r.y - p.y) + r.x * (p.y - q.y)) * 2;
                if (d == 0) {
                    printf("Pas de cercle possible passant par ces 3 points");
                } else {
                    findCircle(p, q, r, &centerX, &centerY, &rayon, &centerX_dessin, &centerY_dessin, &rayondessin, inf, sup);
                    if (verification(tab, &centerX, &centerY, &rayon,N) == 1 && rayon < res_rayon) {
                        res_x = centerX;
                        res_y = centerY;
                        res_rayon = rayon;
                        res_x_dessin = centerX_dessin;
                        res_y_dessin = centerY_dessin;
                        res_rayon_dessin = rayondessin;
                    }
                }
            }
        }
    }
  
    dessinerCercle(file, res_x_dessin, res_y_dessin, res_rayon_dessin);
}
