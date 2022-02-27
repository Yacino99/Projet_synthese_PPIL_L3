//
// Created by Anwender on 12/02/2022.
//

#ifndef PROJETT_VISITEURSAUVEGARDE_H
#define PROJETT_VISITEURSAUVEGARDE_H



#include "Formes.h"

class VisiteurSauvegarde
{

public :
    virtual const void *visite(const Formes * forme) const = 0;
};

#endif //PROJET_SYNTHESE_PPIL_L3_VISITEURSAUVEGARDE_H