/**
 * \file      GroupeFormes.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe GroupeFormes
 */

#include "GroupeFormes.h"
#include "Formes.h"
#include "Erreur.h"
#include "VisiteurLibrairieAwt.h"
#include "VisiteurSauvegarde.h"

using namespace std;

GroupeFormes::~GroupeFormes()
{
    for (int i = 0; i < formes.size(); ++i)
    {
        delete formes[i];
    }
}

Formes *GroupeFormes::getForme(int i) const
{
    if (i < 0 || i >= formes.size())
    {
        throw Erreur("indice invalide");
    }
    else
    {
        return formes[i];
    }
}

void GroupeFormes::setCouleur(const string &color)
{
    couleur = color;
    for (int i = 0; i < formes.size(); ++i)
    {
        formes[i]->setColor(color);
    }
}

GroupeFormes::operator string() const
{
    ostringstream os;

    os << "groupe : [ ";
    for (int i = 0; i < formes.size(); ++i)
    {
        os << formes[i] << " ; ";
    }
    os << " ] " << this->couleur;
    return os.str();
}

/**
 * \brief      Méthode qui ajoute une forme au groupe actuel
 * \details    Cette méthode ajoute une nouvelle forme au groupe de forme actuel.
 * \param      *f la forme à ajouté
 * \return     Un GroupeFormes
 */
GroupeFormes &GroupeFormes::addForme(const Formes *f)
{
    Formes * newF = f->clone();
    newF->setColor(couleur);
    formes.push_back(newF);
    return (*this);
}

void GroupeFormes::appliquerTranslation(const Vecteur2D &u, bool centreSymetrie)
{
    for (int i = 0; i < formes.size(); ++i)
    {
        if (centreSymetrie)
        {
            formes[i]->translation(formes[i]->getCentreSymetrie());
        }
        else
        {
            formes[i]->translation(u);
        }
    }
}

void GroupeFormes::appliquerHomothetie(const Vecteur2D &u, const double k, bool centreSymetrie)
{
    for (int i = 0; i < formes.size(); ++i)
    {
        if (centreSymetrie)
        {
            formes[i]->homothetie(formes[i]->getCentreSymetrie(),k);
        }
        else
        {
            formes[i]->homothetie(u,k);
        }
    }
}

void GroupeFormes::appliquerRotation(const Vecteur2D &u, const double angle, bool centreSymetrie)
{
    for (int i = 0; i < formes.size(); ++i)
    {
        if (centreSymetrie)
        {
            formes[i]->rotation(formes[i]->getCentreSymetrie(),angle);
        }
        else
        {
            formes[i]->rotation(u,angle);
        }
    }
}

void GroupeFormes::translation(const Vecteur2D &u)
{
    appliquerTranslation(u, false);
}

void GroupeFormes::homothetie(const Vecteur2D &u, double k)
{
    appliquerHomothetie(u, k, false);
}

Vecteur2D GroupeFormes::getCentreSymetrie() const
{
    return Vecteur2D();
}

/**
 * \brief      Méthode qui retourne la somme des aires
 * \details    Cette méthode retourne la somme des aires de toutes les formes du groupe
 * \return     Un double
 */
double GroupeFormes::calculerAire() const
{
    double somme = 0;
    for (int i = 0; i < formes.size(); ++i)
    {
        somme += formes[i]->calculerAire();
    }
    return somme;
}

void GroupeFormes::rotation(const Vecteur2D &u, const double angle)
{
    appliquerRotation(u, angle, false);
}

/**
 * \brief      Méthode du Design Pattern Visitor
 * \details    Cette méthode sauvegarde() permet de visiter cette forme et d'appliquer
 *             l'opération de sauvegarde associée à celle-ci grâce au Design Pattern Visitor.
 * \param      *visiteur instance de VisiteurSauvegarde
 */
const void *GroupeFormes::sauvegarde(const VisiteurSauvegarde *visiteur) const
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
const void *GroupeFormes::dessine(const VisiteurLibrairie *visiteur, Socket *s) const
{
    return visiteur->visite(this, s);
}