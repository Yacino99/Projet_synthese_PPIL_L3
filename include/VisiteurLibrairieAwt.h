/**
 * \file      VisiteurLibrairieAwt.h
 * \date      04 mars 2022
 * \brief     Classe VisiteurLibrairieAwt
 */

#ifndef PROJET_VISITEURLIBRAIRIEAWT_H
#define PROJET_VISITEURLIBRAIRIEAWT_H

#include "VisiteurLibrairie.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Socket.h"

class VisiteurLibrairieAwt : public VisiteurLibrairie
{
public:

    /**
    * \brief      Méthode visite() du Design Pattern Visitor
    * \details    Méthode visite() qui permet de dessiner avec la librairie JAVA Awt grâce au Design Pattern Visitor
    * \param      *forme la forme visité
    * \param      *s socket nécessaire pour l'envoie d'un dessin en C++ avec TCP/IP
    */
    const void *visite(const Formes * forme, Socket * s) const;
};

#endif //PROJET_VISITEURLIBRAIRIEAWT_H
