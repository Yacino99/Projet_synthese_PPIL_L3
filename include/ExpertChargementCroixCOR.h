//
// Created by Anwender on 18/02/2022.
//

#ifndef PROJET_EXPERTCHARGEMENTCROIXCOR_H
#define PROJET_EXPERTCHARGEMENTCROIXCOR_H

#include "ExpertChargementCOR.h"
#include "Formes.h"

using namespace std;

class ExpertChargementCroixCOR : public ExpertChargementCOR
{
public:
    ExpertChargementCroixCOR(ExpertChargementCOR *suivant, Socket *pSocket) : ExpertChargementCOR(suivant) {}

    Formes *resoudre1(const string &d, Socket *pSocket) const
    {
        string cherche = "croix";
        string::size_type pos = d.find(cherche);
        while (pos != string::npos)
        {
            // Found!
            cout << "found at : " << pos << endl;
            pos = d.find(cherche, pos + 1);

            return new Croix(30, 100, 100, 30, pSocket, "red");
        }

        return NULL;
    };
};


#endif //PROJET_EXPERTCHARGEMENTCROIXCOR_H
