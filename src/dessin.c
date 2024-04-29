#include "../include/dessin.h"
#include "../include/calculs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fonction pour dessiner un point en SVG
char* dessinerPoint(FILE *file, POINT p, int r) {
    char* codePoint = malloc(sizeof(*codePoint) * 500);
    sprintf(codePoint, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"black\" stroke-width=\"1\" fill=\"black\"/>", p.x, p.y, r);
    fprintf(file, "%s\n", codePoint);
    return codePoint;
}

// Fonction pour dessiner un cercle en SVG
char* dessinerCercle(FILE *file, double x, double y, double r) {
    char* codeCercle = malloc(sizeof(*codeCercle) * 500);
    sprintf(codeCercle, "<circle cx=\"%f\" cy=\"%f\" r=\"%f\" stroke=\"red\" stroke-width=\"3\" fill=\"transparent\" fill-opacity=\"0\" />", x, y, r);
    fprintf(file, "%s\n", codeCercle);
    return codeCercle;
}


// Fonction pour écrire le contenu SVG
void ecritureSVG(POINT tab[], FILE* file, int N, int inf, int sup, double *centerX, double *centerY, double *rayon) {
    for (int i = 0; i < N; i++) {
        POINT p;
        p.x = ((tab[i].x - inf) * 1800 / (sup - inf)) + 100;
        p.y = ((tab[i].y - inf) * 1800 / (sup - inf)) + 100;
        dessinerPoint(file, p, TAILLEPOINT);
    }
    trouver_c(tab, file, N, centerX, centerY, rayon);
}

// Fonction pour générer le fichier SVG final
void GenerationFichierSVG(POINT* tab, int N, int inf, int sup, double *centerX, double *centerY, double *rayon) {
    // Création et ouverture du fichier
    FILE *file;
    file = fopen("Points.svg", "w");
  
    // Écriture de l'entête SVG
    fprintf(file, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    fprintf(file, "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
    fprintf(file, "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
    fprintf(file, "<svg width=\"2000\" height=\"2000\" version=\"1.1\"\n");
    fprintf(file, "xmlns=\"http://www.w3.org/2000/svg\" style=\"background-color: white\">\n");
    fprintf(file, "<rect x=\"0\" y=\"0\" width=\"2000\" height=\"2000\" fill=\"#ffffff\" />\n");

    fprintf(file, "<line x1=\"100\" y1=\"100\" x2=\"1900\" y2=\"100\" stroke=\"black\" />\n"); // Axe x

    fprintf(file, "<text x=\"1900\" y=\"100\" font-family=\"Arial\" font-size=\"20\">%d</text>\n", sup);

    fprintf(file, "<line x1=\"100\" y1=\"100\" x2=\"100\" y2=\"1900\" stroke=\"black\" />\n"); // Axe y
    fprintf(file, "<text x=\"100\" y=\"100\" font-family=\"Arial\" font-size=\"20\">%d</text>\n", inf);
    fprintf(file, "<text x=\"100\" y=\"1900\" font-family=\"Arial\" font-size=\"20\">%d</text>\n", sup);    

    // Écriture du contenu SVG
    ecritureSVG(tab, file, N, inf, sup, centerX, centerY, rayon);

    // Fin du programme et fermeture du fichier
    fprintf(file, "</svg>\n");
    fclose(file);
}
