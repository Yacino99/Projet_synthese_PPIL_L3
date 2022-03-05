/**
 * \file      VisiteurSauvegardeTxt.h
 * \date      04 mars 2022
 * \brief     Classe VisiteurSauvegardeTxt
 */

#ifndef PROJETT_VISITEURSAUVEGARDETXT_H
#define PROJETT_VISITEURSAUVEGARDETXT_H

#include "VisiteurSauvegarde.h"
#include <iostream>
#include <string>
#include <fstream>

class VisiteurSauvegardeTxt : public VisiteurSauvegarde
{
public:
    /**
    * \brief      Méthode visite() du Design Pattern Visitor
    * \details    Méthode visite() qui permet de sauvegarder une forme dans un fichier de sauvegarde au format .txt grâce au Design Pattern Visitor
    * \param      *forme la forme à sauvegardé
    */
    const void *visite(const Formes * forme) const;
};

#endif //PROJET_SYNTHESE_PPIL_L3_VISITEURSAUVEGARDETXT_H
