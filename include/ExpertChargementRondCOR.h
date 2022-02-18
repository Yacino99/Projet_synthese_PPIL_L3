//
// Created by Anwender on 18/02/2022.
//

#ifndef PROJET_EXPERTCHARGEMENTRONDCOR_H
#define PROJET_EXPERTCHARGEMENTRONDCOR_H

#include "ExpertChargementCOR.h"
#include "Formes.h"

using namespace std;

class ExpertChargementRondCOR : public ExpertChargementCOR
{
public:
    ExpertChargementRondCOR(ExpertChargementCOR *suivant, Socket *pSocket) : ExpertChargementCOR(suivant) {}

    Formes *resoudre1(const string &d, Socket *pSocket) const
    {
        string cherche = "rond";
        string::size_type pos = d.find(cherche);
        while (pos != string::npos)
        {
            // Found!
            cout << "found at : " << pos << endl;
            pos = d.find(cherche, pos + 1);

            return new Rond (300, 300, 30.0, pSocket, "blue");
        }

        return NULL;
    };
};

#endif //PROJET_EXPERTCHARGEMENTRONDCOR_H
