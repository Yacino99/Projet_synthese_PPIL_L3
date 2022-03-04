/**  @file
 *   @brief This file is marvelous.
 */


/**
 * \file      ChargeurListeFormes.h
 * \version   1.0
 * \date      04 mars 2022
 * \brief     Charge la liste des formes d'un fichier .txt
 *
 * \details    Cette classe charge le fichier "sauvegardeForme.txt" et analyse les formes de ce fichier
 *                  grâce au Design Pattern Chain Of Responsability
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
#include "ExpertChargementCroixCOR.h"
#include "ExpertChargementRondCOR.h"
#include "ExpertChargementPolygoneCOR.h"
#include "ExpertChargementTriangleCOR.h"
#include "ExpertChargementGroupeCOR.h"

class ChargeurListeFormes
{
public:

    /**
     * \brief       Fonction qui charge et appelle le DP COR
     * \details    Fonction qui charge et appelle le DP COR en appelant tous les Experts
     * \param    ifs         le fichier texte récupéré
     * \return    Un vecteur de Formes contenant toutes les formes du fichier .txt
     */
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
