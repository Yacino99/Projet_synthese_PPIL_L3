/**
 * \file      Rond.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe Rond
 */

#include "Rond.h"
#include "Matrice22.h"
#include "VisiteurSauvegarde.h"
#include "VisiteurLibrairie.h"

void Rond::translation(const Vecteur2D& u)
{
    v = v + u;
}

void Rond::homothetie(const Vecteur2D &u, double k)
{
    v = (v - u)*k  + u;
    rayon *= k;
}

Rond::operator string() const
{
    ostringstream os;
    os << "rond ( " << v.x << " , " << v.y << " , " << rayon <<" ) " << this->couleur;
    return os.str();
}

/**
 * \brief      Méthode qui retourne l'aire du rond
 * \return     Un double
 */
double Rond::calculerAire() const
{
    return (rayon * rayon) * PI;
}

void Rond::rotation(const Vecteur2D &u, const double angle)
{

    double m11 = cos(angle);
    double m21 = sin(angle);
    double m12 = -m21;
    double m22 = m11;

    Matrice22 M(m11,m12,m21,m22);

    v =  M * (v - u) + u ;
}

/**
 * \brief      Méthode du Design Pattern Visitor
 * \details    Cette méthode sauvegarde() permet de visiter cette forme et d'appliquer
 *             l'opération de sauvegarde associée à celle-ci grâce au Design Pattern Visitor.
 * \param      *visiteur instance de VisiteurSauvegarde
 */
const void *Rond::sauvegarde(const VisiteurSauvegarde *visiteur) const
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
const void *Rond::dessine(const VisiteurLibrairie *visiteur, Socket *s) const
{
    return visiteur->visite(this, s);
}

Vecteur2D Rond::getMinXMinY() const {
    return Vecteur2D(v.x-rayon,v.y-rayon);
}

Vecteur2D Rond::getMaxXMaxY() const {
    return Vecteur2D(v.x+rayon,v.y+rayon);
}

