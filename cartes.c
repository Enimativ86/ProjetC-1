#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "reversi.h"
#include "cartes.h"

#define ERREUR_ALLOCATION_MEMOIRE 1

//initialise une main
hand inithand()
{
  hand h=NULL;
  return(h);
}

//desallouage d'une main entiere
//s'effectue à partir de n'importe quelle carte d'une main
void freehand(hand h)
{
  hand h1=h,h2=h;

  while(h1!=NULL){
    h=h1;
    h1=h1->suiv;
    free(h);
  }
  while(h2!=NULL){
    h=h2;
    h2=h2->prec;
    free(h);
  }
}

//pioche une carte au hasard que l'on ajoute au debut d'une main
void ajoutercarte(hand h)
{
  srand(time(NULL));
  hand h1=malloc(sizeof(struct cell));

  if(h1==NULL){
    exit(ERREUR_ALLOCATION_MEMOIRE);
  }

  h1->prec=NULL;
  h1->suiv=h;
  h->prec=h1;
  h=h1;
  h->c=rand()%7;
}

//renvoie une main de cartes tirees aleatoirements
hand piochemain(int nbcartes)
{
  hand h=inithand();

  for(int i=0;i<nbcartes;i++){
    ajoutercarte(h);
  }
  return(h);
}

//on retire d'une main une carte passee en parametre
hand enlevercarte(hand h)
{
  hand h1;

  h->suiv->prec=h->prec;
  h1=h->prec->suiv=h->suiv;
  free(h);
  return(h1);
}

//affiche une carte
void affichercarte(carte c)
{
    switch(c){
      case 0 : printf("%d : Changement De Camp : Tout les pions changent de couleur\n",0);break;
      case 1 : printf("%d : Conversion : Change un pion adverse en allie\n",1);break;
      case 2 : printf("%d : Bannissement : Retire un pion adverse du plateau\n",2);break;
      case 3 : printf("%d : Acceleration : Jouer deux fois d'affilé\n",3);break;
      case 4 : printf("%d : Effondrement : Rend une case inutilisable\n",4);break;
      case 5 : printf("%d : Immunite : Desamorcez la prochaine bombe que vous auriez du declencher",5);break;
      case 6 : printf("%d : Pose Libre : Posez un pion n'importe ou",6);break;
    }
}

//afficher l'intégralité d'une main
void affichermain(hand h)
{
  hand h1=h;

  printf("Voici votre main\n");
  while(h1!=NULL){
    affichercarte(h1->c);
    h1=h1->prec;
  }
  h1=h->suiv;
  while(h1!=NULL){
    affichercarte(h1->c);
    h1=h1->suiv;
  }
}

void jouercarte(cellule c, hand Vcartes, hand Rcartes)
{
  int rep;
  //XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  //XXXCOULEURS NON GENERIQUESXXX
  //XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
  if((c==vert && Vcartes!=NULL) || (c==rouge && Rcartes!=NULL)){
    do{
      printf("Jouer une carte ? 1=Oui 0=Non\n");
      scanf("%d",&rep);
    }while(rep!=1 && rep!=0);
    if(rep){
      if(c==vert){
        affichermain(Vcartes);
      }else if(c==rouge){
        affichermain(Rcartes);
      }
      printf("Laquelle voulez-vous jouer ?\n");
      scanf("%d",&rep);
    }
  }
}
