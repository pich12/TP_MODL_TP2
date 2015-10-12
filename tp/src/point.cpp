// Entetes //---------------------------------------------------------------------------------------
#include <point.hpp>

// Fonctions //-------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------Operateur <<
std::ostream & operator << (std::ostream & flux,const Point & point) {
 point.afficher(flux);
 return flux;
}

//--------------------------------------------------------------------------------------Operateur >>
std::istream & operator >> (std::istream & flux,Point & point) {
 point.charger(flux);
 return flux;
}

// Fin //-------------------------------------------------------------------------------------------
