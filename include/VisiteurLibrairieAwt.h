//
// Created by Anwender on 27/02/2022.
//

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
    const void *visite(const Formes * forme, Socket * s) const;
};

#endif //PROJET_VISITEURLIBRAIRIEAWT_H
