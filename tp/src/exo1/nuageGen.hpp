// Gardien //---------------------------------------------------------------------------------------
#ifndef _NUAGEGEN_HPP_
#define _NUAGEGEN_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <vector>
#include <cartesien.hpp>
#include <polaire.hpp>

template <typename T>

// Declarations fonctions //------------------------------------------------------------------------
//T barycentre(const NuageGen &);

// Classe  NuageGen //-----------------------------------------------------------------------------
class NuageGen {

 //---------------------------------------------------------------------------------------------Type
 public: typedef typename std::vector<T *>::const_iterator iterator;
 //----------------------------------------------------------------------------------------Attributs
 protected: std::vector<T *> points_;
 //---------------------------------------------------------------------------------------Accesseurs
 public: iterator begin() const { return points_.begin(); }
 public: iterator end() const { return points_.end(); }
 //-------------------------------------------------------------------------------Methodes publiques
 public: void ajouter(T * point) { points_.push_back(point); }
};

// Classe  Barycentre Cartesien //-------------------------------------------------
template <typename T>
class BarycentreCartesien {
 public: Cartesien operator () (const NuageGen<T> & nuage) { return barycentre(nuage); }
};

// Classe  Baryentre Polaire //-----------------------------------------------------
template <typename T>
class BarycentrePolaire {
 public: Polaire operator () (const NuageGen<T> & nuage) { return Polaire(barycentre(nuage)); }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
