/**
 * \file      VisiteurSauvegarde.h
 * \date      04 mars 2022
 * \brief     Classe VisiteurSauvegarde
 */

#ifndef PROJETT_VISITEURSAUVEGARDE_H
#define PROJETT_VISITEURSAUVEGARDE_H

#include "Formes.h"

class VisiteurSauvegarde
{
public :
    /**
    * \brief      Méthode visite() du Design Pattern Visitor
    * \details    Méthode visite() qui permet de sauvegarder une forme dans un fichier de sauvegarde quelconque grâce au Design Pattern Visitor
    * \param      *forme la forme à sauvegardé
    */
    virtual const void *visite(const Formes * forme) const = 0;
};

#endif //PROJET_SYNTHESE_PPIL_L3_VISITEURSAUVEGARDE_H