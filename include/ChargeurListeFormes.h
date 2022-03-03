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
#include "ExpertChargementGroupeCOR.h"

class ChargeurListeFormes
{
public:
    static vector<Formes*> charge(ifstream& ifs)
    {
        vector<Formes*> res;
        ExpertChargementCOR* expert;
        expert = new ExpertChargementCroixCOR(NULL);
        expert = new ExpertChargementPolygoneCOR(expert);
        expert = new ExpertChargementRondCOR(expert);
        expert = new ExpertChargementTriangleCOR(expert);
        expert = new ExpertChargementGroupeCOR(expert);

        string tmp;
        while (getline(ifs, tmp))
        {
            cout << "ligne lue : " << tmp << endl;

            Formes* forme = expert->resoudre(tmp);
            if (forme != NULL)
            {
                res.push_back(forme);
            }
        }

        return res;
    };
};

#endif //PROJET_CHARGEURLISTEFORMES_H
