//
// Created by Anwender on 27/02/2022.
//

#ifndef PROJET_VISITEURLIBRAIRIE_H
#define PROJET_VISITEURLIBRAIRIE_H

#include "Formes.h"

class VisiteurLibrairie
{
public :
    virtual const void *visite(const Formes * forme, Socket * s) const = 0;
};

#endif //PROJET_VISITEURLIBRAIRIE_H
