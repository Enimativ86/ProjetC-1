#ifndef __CARTES__
#define __CARTES__


  typedef enum{changementdecamp=0,conversion,ban,acceleration,effondrement,immunite,poselibre}carte;
  struct cell{
    struct cell *suiv, *prec;
    carte c;
  };
  typedef struct cell *hand;

  hand inithand();
  void freehand(hand h);
  void ajoutercarte(hand h);
  hand piochemain(int nbcartes);
  void affichercarte(carte c);
  void affichermain(hand h);
  void jouercarte(cellule c, hand Vcartes, hand Rcartes);

#endif
