#ifndef __INIT__
#define __INIT__

  joueur *initJoueurs();
  fleche *initrose();
  int **initage(int *N);
  cellule **initplateau(int *N, hand Vcartes, hand Rcartes);
  int terminate(cellule **plateau, fleche *rose, int **age, int *N, hand Rcartes, hand Vcartes);

#endif
