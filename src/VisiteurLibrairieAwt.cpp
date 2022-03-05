/**
 * \file      VisiteurLibrairieAwt.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe VisiteurLibrairieAwt
 */

using namespace std;

#include "VisiteurLibrairieAwt.h"
#include <string>

const void *VisiteurLibrairieAwt::visite(const Formes * forme, Socket * s) const
{
    ostringstream oss;
    oss << (string)*forme;
    string requete = oss.str();
    s->sendMessage(requete.c_str());

    return 0;
}


