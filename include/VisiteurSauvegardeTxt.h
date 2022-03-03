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
    const void *visite(const Formes * forme) const;
    const void *visite(const GroupeFormes * groupeFormes) const;
};

#endif //PROJET_SYNTHESE_PPIL_L3_VISITEURSAUVEGARDETXT_H
