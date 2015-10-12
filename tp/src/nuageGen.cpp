// Entetes //---------------------------------------------------------------------------------------
#include <nuageGen.hpp>

// Fonctions //-------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------Barycentre
Cartesien barycentre(const NuageGen & nuage) {
 Cartesien c;
 double x = 0.0;
 double y = 0.0;
 int n = 0;

 for (NuageGen::iterator i = nuage.begin(); i<nuage.end(); ++i) {
  (*i)->convertir(c);
  x+=c.getX();
  y+=c.getY();
  ++n;
 }

 return Cartesien(x/n,y/n);
}

// Fin //-------------------------------------------------------------------------------------------
