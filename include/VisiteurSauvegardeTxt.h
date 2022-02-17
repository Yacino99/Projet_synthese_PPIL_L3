//
// Created by Anwender on 12/02/2022.
//

#ifndef PROJETT_VISITEURSAUVEGARDETXT_H
#define PROJETT_VISITEURSAUVEGARDETXT_H


#include "VisiteurSauvegarde.h"
#include <iostream>
#include <string>
#include <fstream>

class VisiteurSauvegardeTxt : public VisiteurSauvegarde
{
public:
    void *sauvegarde(const Triangle * triangle) const;
    void *sauvegarde(const Rond * rond) const;
    void *sauvegarde(const Croix * croix) const;
    void *sauvegarde(const Polygone * polygone) const;
};

#endif //PROJET_SYNTHESE_PPIL_L3_VISITEURSAUVEGARDETXT_H
