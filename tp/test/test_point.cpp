// Entetes //---------------------------------------------------------------------------------------
#include <vector>
#include <cartesien.hpp>
#include <polaire.hpp>
#include <nuage.hpp>

// Fonction principale //---------------------------------------------------------------------------
int main(void) {
 Cartesien p1;
 Polaire p2;

 std::cout << "Saisir cartesien p1" << std::endl;
 std::cin >> p1;

 std::cout << "Saisir polaire p2" << std::endl;
 std::cin >> p2;

 Polaire p3(p1);
 Cartesien p4(p2);

 std::cout << std::endl;
 std::cout << "p1 en cartesien = " << p1 << std::endl;
 std::cout << "p1 en polaire = " << p3 << std::endl;
 std::cout << "p2 en polaire = " << p2 << std::endl;
 std::cout << "p2 en cartesien = " << p4 << std::endl;

 // std::vector<Point> v;
 // v.push_back(p1); v.push_back(p2); v.push_back(p3); v.push_back(p4);
 //
 // Cette version ne marche pas, car cartesiens et polaires retransformes en points.
 // En plus, la classe "Point" est abstraite !

 std::vector<Point *> v;
 v.push_back(&p1); v.push_back(&p2); v.push_back(&p3); v.push_back(&p4);

 std::cout << std::endl << "vector<Point *> = ";
 for (size_t i=0; i<v.size(); ++i) std::cout << *(v[i]) << " ";
 std::cout << std::endl;

 Nuage n1;
 n1.ajouter(&p1); n1.ajouter(&p2); n1.ajouter(&p3); n1.ajouter(&p4);

 std::cout << std::endl << "nuage = ";
 for (Nuage::iterator i = n1.begin(); i!=n1.end(); ++i) std::cout << **i << " ";
 std::cout << std::endl;

 std::cout << "barycentre = " << BarycentreCartesien()(n1) << std::endl;
 std::cout << "barycentre = " << BarycentrePolaire()(n1) << std::endl;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
