//
// Created by Anwender on 18/02/2022.
//

#ifndef PROJET_EXPERTCHARGEMENTTRIANGLECOR_H
#define PROJET_EXPERTCHARGEMENTTRIANGLECOR_H

#include "ExpertChargementCOR.h"
#include "Formes.h"
#include "Triangle.h"

using namespace std;

class ExpertChargementTriangleCOR : public ExpertChargementCOR
{
public:
    ExpertChargementTriangleCOR(ExpertChargementCOR *suivant, Socket *pSocket) : ExpertChargementCOR(suivant) {}

    Formes *resoudre1(const string &d, Socket *pSocket) const
    {
        string cherche = "triangle";
        string::size_type pos = d.find(cherche);
        while (pos != string::npos)
        {
            // Found!
            cout << "found at : " << pos << endl;
            pos = d.find(cherche, pos + 1);

            return new Triangle(50, 60, 100, 120, 30, 45, pSocket, "red");
        }

        return NULL;
    };
};

#endif //PROJET_EXPERTCHARGEMENTTRIANGLECOR_H
