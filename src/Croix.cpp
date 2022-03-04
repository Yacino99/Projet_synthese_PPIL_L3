/**  @file
 *   @brief This file is marvelous.
 */

/**
 * \file      Croix.cpp
 * \version   1.0
 * \date      04 mars 2022
 * \brief     La classe .cpp de la forme Croix
 */

#include "Croix.h"
#include "VisiteurSauvegarde.h"
#include "VisiteurLibrairie.h"

double Croix::calculerAire() const
{
    return 0;
}

/**
 * \brief       Fonction qui charge
 * \details    Fonction qui charge ll
 * \return    Un vecteur de Formes contenant toutes ier .txt
 */
Vecteur2D Croix::getCentreSymetrie() const
{
    Vecteur2D g = (a+b)*(1/2.0);
    return g;
}

/**
 * \brief       fct
 * \details    Fonction
 * \return    test
 */
Croix::operator string() const
{
    ostringstream os;

    os << "croix ( " << a.x << " , " <<
       a.y << " , " << b.x << " , " << b.y << " ) " << this->couleur;

    return os.str();
}

void Croix::translation(const Vecteur2D &u)
{
    a = a + u;
    b = b + u;
}
/**
 *  \fn void homothetie(const Vecteur2D, double)
 */
void Croix::homothetie(const Vecteur2D &u, double k)
{
    a =  (a - u)*k  + u;
    b =  (b - u)*k  + u;
}

//Vecteur OB’ = R * (vecteur OB – vecteur OC) + vecteur OC
void Croix::rotation(const Vecteur2D &u, const double angle)
{
    Matrice22 M(Vecteur2D(cos(angle),-sin(angle)) , Vecteur2D(sin(angle), cos(angle)));
    b =  M * (b - u) + u ;
    a =  M * (a - u) + u ;
}

/** \fn Croix sauvegarde(const VisiteurSauvegarde * visiteur)
 * \brief       Calcule la distance entre deux points
 * \details    La distance entre les \a point1 et \a point2 est calculée par l'intermédiaire
 *                  des coordonnées des points. (cf #Point)
 * \param    point1         Point 1 pour le calcul de distance.
 * \param    point2         Point 2 pour le calcul de distance.
 * \return    Un \e float représentant la distance calculée.
 */
const void *Croix::sauvegarde(const VisiteurSauvegarde *visiteur) const
{
    return visiteur->visite(this);
}

const void *Croix::dessine(const VisiteurLibrairie *visiteur, Socket *s) const
{
    return visiteur->visite(this, s);
}