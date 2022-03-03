//
// Created by Anwender on 27/02/2022.
//

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


