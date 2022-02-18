//
// Created by Anwender on 18/02/2022.
//

#ifndef PROJET_EXPERTCHARGEMENTPOLYGONECOR_H
#define PROJET_EXPERTCHARGEMENTPOLYGONECOR_H

#include "ExpertChargementCOR.h"
#include "Formes.h"
#include "Polygone.h"

using namespace std;

class ExpertChargementPolygoneCOR : public ExpertChargementCOR
{
public:
    ExpertChargementPolygoneCOR(ExpertChargementCOR *suivant, Socket *pSocket) : ExpertChargementCOR(suivant) {}

    Formes *resoudre1(const string &d, Socket *pSocket) const
    {
        string cherche = "polygone";
        string::size_type pos = d.find(cherche);
        while (pos != string::npos)
        {
            // Found!
            cout << "found at : " << pos << endl;
            pos = d.find(cherche, pos + 1);

            return new Polygone(pSocket);
        }

        return NULL;
    };
};

#endif //PROJET_EXPERTCHARGEMENTPOLYGONECOR_H
