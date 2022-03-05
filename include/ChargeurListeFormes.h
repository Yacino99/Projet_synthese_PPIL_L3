/**
 * \file      ChargeurListeFormes.h
 * \date      04 mars 2022
 * \brief     Chargement de formes
 * \details    Cette classe charge le fichier "sauvegardeForme.txt" et analyse les formes de ce fichier
 *                  grâce au Design Pattern Chain Of Responsability pour les extraires.
 */

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
#include "ExpertChargementSegmentCOR.h"
#include "ExpertChargementRondCOR.h"
#include "ExpertChargementPolygoneCOR.h"
#include "ExpertChargementTriangleCOR.h"
#include "ExpertChargementGroupeCOR.h"

class ChargeurListeFormes
{
public:

    /**
     * \details    Fonction qui charge et appelle le DP COR en appelant tous les Experts
     * \param      ifs   un fichier texte
     * \return     Un vecteur de Formes contenant toutes les formes du fichier texte ifs
     */
    static vector<Formes*> charge(ifstream& ifs)
    {
        vector<Formes*> res;
        ExpertChargementCOR* expert;
        expert = new ExpertChargementSegmentCOR(NULL);
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
