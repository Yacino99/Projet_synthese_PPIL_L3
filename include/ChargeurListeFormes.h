//
// Created by Anwender on 18/02/2022.
//

#ifndef PROJET_CHARGEURLISTEFORMES_H
#define PROJET_CHARGEURLISTEFORMES_H

#pragma once
using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "Formes.h"
#include "ExpertChargementCOR.h"
#include "ExpertChargementCroixCOR.h"
#include "ExpertChargementRondCOR.h"
#include "ExpertChargementPolygoneCOR.h"
#include "ExpertChargementTriangleCOR.h"

class ChargeurListeFormes
{
public:
    static vector<Formes*> charge(ifstream& ifs, Socket *socket)
    {
        vector<Formes*> res;
        ExpertChargementCOR* expert;
        expert = new ExpertChargementCroixCOR(NULL, socket);
        expert = new ExpertChargementPolygoneCOR(expert, socket);
        expert = new ExpertChargementRondCOR(expert, socket);
        expert = new ExpertChargementTriangleCOR(expert, socket);

        string tmp;
        while (getline(ifs, tmp))
        {
            cout << "ligne lue : " << tmp << endl;
            Formes* forme = expert->resoudre(tmp, socket);
            if (forme != NULL)
            {
                res.push_back(forme);
                cout << "ligne ajoutee au vector" << endl;
            }
        }

        return res;
    };
};

#endif //PROJET_CHARGEURLISTEFORMES_H
