//
// Created by Anwender on 12/02/2022.
//

#ifndef PROJETT_VISITEURSAUVEGARDE_H
#define PROJETT_VISITEURSAUVEGARDE_H



#include "Formes.h"
#include "Triangle.h"
#include "Rond.h"
#include "Croix.h"
#include "Polygone.h"

class VisiteurSauvegarde
{

public :
    virtual void *sauvegarde(const Triangle * triangle) const = 0;
    virtual void *sauvegarde(const Rond * rond) const = 0;
    virtual void *sauvegarde(const Croix * croix) const = 0;
    virtual void *sauvegarde(const Polygone * polygone) const = 0;

};

#endif //PROJET_SYNTHESE_PPIL_L3_VISITEURSAUVEGARDE_H