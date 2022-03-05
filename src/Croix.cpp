/**
 * \file      Croix.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe Croix
 */

#include "Croix.h"
#include "VisiteurSauvegarde.h"
#include "VisiteurLibrairie.h"

/**
 * \brief    Fonction qui retourne le centre de symétrie
 * \return    Un Vecteur2D
 */
Vecteur2D Croix::getCentreSymetrie() const
{
    Vecteur2D g = (a+b)*(1/2.0);
    return g;
}

Croix::operator string() const
{
    ostringstream os;

    os << "croix ( " << a.x << " , " <<
       a.y << " , " << b.x << " , " << b.y << " ) " << this->couleur;

    return os.str();
}

/**
 * \brief    Opération de translation
 */
void Croix::translation(const Vecteur2D &u)
{
    a = a + u;
    b = b + u;
}

/**
 * \brief    Opération d'homothétie
 */
void Croix::homothetie(const Vecteur2D &u, double k)
{
    a =  (a - u)*k  + u;
    b =  (b - u)*k  + u;
}

/**
 * \brief    Opération de rotation
 */
void Croix::rotation(const Vecteur2D &u, const double angle)
{
    Matrice22 M(Vecteur2D(cos(angle),-sin(angle)) , Vecteur2D(sin(angle), cos(angle)));
    b =  M * (b - u) + u ;
    a =  M * (a - u) + u ;
}

/**
 * \brief      Méthode du Design Pattern Visitor
 * \details    Cette méthode sauvegarde() permet de visiter cette forme et d'appliquer
 *             l'opération de sauvegarde associée à celle-ci grâce au Design Pattern Visitor.
 * \param      *visiteur instance de VisiteurSauvegarde
 */
const void *Croix::sauvegarde(const VisiteurSauvegarde *visiteur) const
{
    return visiteur->visite(this);
}

/**
 * \brief      Méthode du Design Pattern Visitor
 * \details    Cette méthode dessine() permet de visiter cette forme et d'appliquer
 *             l'opération de dessin associée à celle-ci grâce au Design Pattern Visitor.
 * \param      *visiteur instance de VisiteurLibrairie
 * \param      *s        socket permettant de dessiner en C++ avec un Client TCP/IP
 */
const void *Croix::dessine(const VisiteurLibrairie *visiteur, Socket *s) const
{
    return visiteur->visite(this, s);
}