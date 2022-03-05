/**
 * \file      VisiteurLibrairie.h
 * \date      04 mars 2022
 * \brief     Classe VisiteurLibrairie
 */

#ifndef PROJET_VISITEURLIBRAIRIE_H
#define PROJET_VISITEURLIBRAIRIE_H

#include "Formes.h"

class VisiteurLibrairie
{
public :

    /**
    * \brief      Méthode visite() du Design Pattern Visitor
    * \details    Méthode visite() qui permet de dessiner une forme avec n'importe quelle librairie graphique grâce au Design Pattern Visitor
    * \param      *forme la forme visité
    * \param      *s socket nécessaire pour l'envoie d'un dessin en C++ avec TCP/IP
    */
    virtual const void *visite(const Formes * forme, Socket * s) const = 0;
};

#endif //PROJET_VISITEURLIBRAIRIE_H
