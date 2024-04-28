#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

#define TAILLEPOINT 1 //Diametre d'un point

//Dessine un point en SVG
char* dessinerPoint(FILE *file, POINT p, int r){ 
  char* codePoint= malloc (sizeof (*codePoint) * 500);
  sprintf(codePoint,"<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"black\" stroke-width=\"1\" fill=\"black\"/>",p.x,p.y,r);
  fprintf(file,"%s\n", codePoint);
  return codePoint;
}

char* dessinerCercle(FILE *file, int x, int y, int r){
  char* codeCercle= malloc (sizeof (*codeCercle) *500);
  sprintf(codeCercle,"<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"red\" stroke-width=\"3\" fill=\"transparent\" fill-opacity=\"0\" />",x,y,r);
  fprintf(file,"%s\n", codeCercle);
  return codeCercle;
}

//Dessine les points et le cercle dans le SVG
void ecritureSVG(POINT tab[], FILE* file , int N){
  //On dessine tous les points dans le SVG
  for(int i=0; i<N; i++){
    dessinerPoint(file, tab[i], TAILLEPOINT);
  }
  dessinerCercle(file, 100, 200, 50);
}

void GenerationFichierSVG(POINT* tab , int N){
  //creation et ouverture du fichier
  FILE *file;
  file= fopen("Points.svg", "w");
  
  //ecriture de l'entete
  fprintf(file,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
  fprintf(file,"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
  fprintf(file,"\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
  fprintf(file,"<svg width=\"500\" height=\"500\" version=\"1.1\"\n");
  fprintf(file,"xmlns=\"http://www.w3.org/2000/svg\">\n");
  
  //ecriture du programme
  ecritureSVG(tab,file,N);
  
  //fin du programme et fermer le fichier
  fprintf(file, "</svg>\n");
  fclose(file);
}

int rand_a_b (int a, int b){
  return rand()%(b-a )+a;
}

int main( int argc, char* argv []){
  int N, xmin , xmax, ymin, ymax; //N=nb  de points et coordonnées du cadre 
  srand(time(NULL));
  if (argc!=6){
    printf ("nb invalide d'arguments\n");
    printf("usage: %s <nbDePoints> <xmin> <xmax> <ymin> <ymax>\n", argv[0]);
    return 1;
  }

  N=atoi(argv[1]);
  printf ("%d \n", N); //Affichage nb de points générés

  xmin=atoi(argv[2]);   
  xmax=atoi(argv[3]);
  ymin=atoi(argv[4]);
  ymax=atoi(argv[5]);
  int i;
  int x, y; 


  POINT* tab=malloc (sizeof(POINT)*N);
  for (i=0;i<N;i++){
    x=rand_a_b(xmin,xmax);
    y=rand_a_b(ymin,ymax);
    tab[i].x= x;
    tab[i].y= y;
  }

  GenerationFichierSVG(tab , N);
  
  return 0; 
}
