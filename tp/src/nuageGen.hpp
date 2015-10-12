// Gardien //---------------------------------------------------------------------------------------
#ifndef _NUAGEGEN_HPP_
#define _NUAGEGEN_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <vector>
#include <cartesien.hpp>
#include <polaire.hpp>

template typedef<T>;

// Declarations anticipees //-----------------------------------------------------------------------
class NuageGen;

// Declarations fonctions //------------------------------------------------------------------------
Cartesien barycentre(const NuageGen &);

// Classe  N u a g e //-----------------------------------------------------------------------------
class NuageGen {
 //---------------------------------------------------------------------------------------------Type
 public: typedef std::vector<T *>::const_iterator iterator;
 //----------------------------------------------------------------------------------------Attributs
 protected: std::vector<T *> points_;
 //---------------------------------------------------------------------------------------Accesseurs
 public: std::vector<T *>::const_iterator begin() const { return points_.begin(); }
 public: std::vector<T *>::const_iterator end() const { return points_.end(); }
 //-------------------------------------------------------------------------------Methodes publiques
 public: void ajouter(T * point) { points_.push_back(point); }
};

// Classe  B a r y c e n t r e C a r t e s i e n //-------------------------------------------------
class BarycentreCartesien {
 public: Cartesien operator () (const NuageGen & nuage) { return barycentre(nuage); }
};

// Classe  B a r y c e n t r e P o l a i r e //-----------------------------------------------------
class BarycentrePolaire {
 public: Polaire operator () (const NuageGen & nuage) { return Polaire(barycentre(nuage)); }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
