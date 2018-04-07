#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "reversi.h"
#include "cartes.h"

#define ERREUR_ALLOCATION_MEMOIRE 1

//renvoie une main de cartes tirees aleatoirements
carte *pioche(int nbcartes)
{
  srand(time(NULL));
  carte *hand;

  hand=malloc(nbcartes*sizeof(carte));
  if(hand==NULL){
    free(hand);
    exit(ERREUR_ALLOCATION_MEMOIRE);
  }

  for(int i=0;i<nbcartes;i++){
    hand[i]=rand()%7;
  }
  return(hand);
}
