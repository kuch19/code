#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/structures.h"
#include "../include/calculs.h"
#include "../include/dessin.h"

int N, xmin, xmax, ymin, ymax, inf, sup; // Déclaration des variables globales
double centre_x, centre_y, rayon;

int main(int argc, char* argv[]) {
    // Votre code principal ici
    srand(time(NULL));
    if (argc != 6) {
        printf("Nombre invalide d'arguments\n");
        printf("Usage: %s <nbDePoints> <xmin> <xmax> <ymin> <ymax>\n", argv[0]);
        return 1;
    }
    N = atoi(argv[1]);
    printf("%d \n", N); // Affichage nb de points générés
    xmin = atoi(argv[2]);
    xmax = atoi(argv[3]);
    ymin = atoi(argv[4]);
    ymax = atoi(argv[5]);
    int i;
    int x, y;
    double res_rayon = INFINITY; // Déclaration de res_rayon
    inf = xmin;
    sup = xmax;
    if (ymax > sup) {
        sup = ymax;
    }
    if (ymin < inf) {
        inf = ymin;
    }
    POINT* tab = malloc(sizeof(POINT) * N);
    for (i = 0; i < N; i++) {
        if (xmin != xmax) {
            x = rand_a_b(xmin, xmax);
        } else {
            x = xmin;
        }
        if (ymin != ymax) {
            y = rand_a_b(ymin, ymax);
        } else {
            y = ymin;
        }
        tab[i].x = x;
        tab[i].y = y;
        printf("%d , %d \n", x, y);
    }
    if (inf == sup) {
        inf = sup - 1;
        sup = sup + 1;
    }
    GenerationFichierSVG(tab, N, inf, sup, &centre_x, &centre_y, &rayon);
    // Implémentation de WELZ
    CERCLE res_welz = welz(tab, N);
    printf("Centre du cercle minimum : (%.2f, %.2f)\n", res_welz.x_cercle, res_welz.y_cercle);
    printf("Rayon du cercle minimum : %.2f\n", res_welz.rayon_cercle);

    return 0;
}
