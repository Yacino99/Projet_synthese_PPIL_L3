/**  @file
 *   @brief This file is marvelous.
 */


/**
 * \file      Croix.h
 * \version   1.0
 * \date      04 mars 2022
 * \brief     La classe de la forme Croix
 */

#ifndef PROJETT_CROIX_H
#define PROJETT_CROIX_H

#include "Formes.h"
#include <string>
#include "Socket.h"
#include <sstream>
#include <string>
#include <math.h>
#include "Vecteur2D.h"
#include "Matrice22.h"

using namespace std;

class Croix : public Formes{

private :

    Vecteur2D a, b;

public:

    Croix(double g, double h, double d, double b, const string& couleur = " ") : Formes(couleur) , a(g,h),b(d,b) {}
    Croix(Vecteur2D a, Vecteur2D b,  Socket* s, const string& couleur = " ") : Formes(couleur), a(a),b(b) {}

    /**
     * \brief       Fonction qui charge et appelle le DP COR
     * \details    Fonction qui charge et appelle le DP COR en appelant tous les Experts
     * \param    ifs         le fichier texte récupéré
     * \return    Un vecteur de Formes contenant toutes les formes du fichier .txt
     */
    double calculerAire() const;

    /**
     * \brief       Fonction qui charge
     * \details    Fonction qui charge ll
     * \return    Un vecteur de Formes contenant toutes ier .txt
     */
    Vecteur2D getCentreSymetrie() const;


    Croix* clone() const { return new Croix(*this); }
    virtual ~Croix() {}
    friend ostream& operator << (ostream& os, const Croix& m);
    operator string() const;


    /**
 *  \fn void translation(const Vecteur2D)
 */
    void translation(const Vecteur2D &u);
    void homothetie(const Vecteur2D& u,double k) ;
    void rotation(const Vecteur2D &u, const double angle );

    // DP Visitor
    /**
 * \brief       Calcule la distance entre deux points
 * \details    La distance entre les \a point1 et \a point2 est calculée par l'intermédiaire
 *                  des coordonnées des points. (cf #Point)
 * \param    point1         Point 1 pour le calcul de distance.
 * \param    point2         Point 2 pour le calcul de distance.
 * \return    Un \e float représentant la distance calculée.
 */
    const void *sauvegarde(const VisiteurSauvegarde * visiteur) const;
    const void *dessine(const VisiteurLibrairie * visiteur, Socket * s) const;
};

/**
* \brief       Calcule la distance entre deux points
* \details    La distance entre les \a point1 et \a point2 est calculée par l'intermédiaire
*                  des coordonnées des points. (cf #Point)
* \param    point1         Point 1 pour le calcul de distance.
* \param    point2         Point 2 pour le calcul de distance.
* \return    Un \e float représentant la distance calculée.
*/
inline ostream& operator << (ostream& os, const Croix& m)
{
    return os << (string)m;
}

#endif //PROJETT_CROIX_H
