//
// Created by Anwender on 03/03/2022.
//

#ifndef PROJET_EXPERTCHARGEMENTGROUPECOR_H
#define PROJET_EXPERTCHARGEMENTGROUPECOR_H

#include "ExpertChargementCOR.h"
#include "Formes.h"
#include "GroupeFormes.h"

#include "Formes.h"
#include "ExpertChargementCOR.h"
#include "ExpertChargementCroixCOR.h"
#include "ExpertChargementRondCOR.h"
#include "ExpertChargementPolygoneCOR.h"
#include "ExpertChargementTriangleCOR.h"

using namespace std;

class ExpertChargementGroupeCOR : public ExpertChargementCOR
{
public:
    ExpertChargementGroupeCOR(ExpertChargementCOR *suivant) : ExpertChargementCOR(suivant) {}

    Formes *resoudre1(const string &d) const
    {
        const string cherche = "groupe";
        string::size_type pos = d.find(cherche);
        while (pos != string::npos)
        {
            // "groupe" trouvé

            // on extrait tout ce qui se trouve entre les crochets => liste des formes du groupe
            unsigned firstCrochet = d.find("[");
            unsigned lastCrochet = d.find("]");
            string coordonnees = d.substr (firstCrochet + 1, lastCrochet - firstCrochet - 1);
            istringstream is(coordonnees );

            // String lue entre les crochets
            // cout << "string lue : " << coordonnees << endl; //  triangle ( -0.3 , 1.7 , 2.8 , -2.5 , 4.3 , 5.2 ) purple, rond ( 5 , -3 , 1.2 ) purple,

            string delimiter = ";";
            vector<string> words{};
            size_t pos = 0;

            while ((pos = coordonnees.find(delimiter)) != string::npos)
            {
                words.push_back(coordonnees.substr(0, pos));
                coordonnees.erase(0, pos + delimiter.length());
            }

            vector<Formes*> res;
            ExpertChargementCOR* expert;
            expert = new ExpertChargementCroixCOR(NULL);
            expert = new ExpertChargementPolygoneCOR(expert);
            expert = new ExpertChargementRondCOR(expert);
            expert = new ExpertChargementTriangleCOR(expert);

            // affichage des strings des formes du groupe de forme lue
            for (const auto &str : words)
            {
                //cout << "string : " << str << endl;
                Formes* forme = expert->resoudre(str);
                // groupe de forme de groupe de forme ICI
                if (forme != NULL)
                {
                    res.push_back(forme);
                }
            }

            GroupeFormes *g2 = new GroupeFormes();

            // affichage des formes + construction du groupe de forme
            for (const auto &str : res)
            {
                //cout << "forme : " << str << endl;
                g2->addForme(str);
            }

            // Récupération et attribution de la couleur
            string couleur = d.substr(lastCrochet + 1, d.size());
            g2->setCouleur(couleur);

            // Affichage du groupe de forme créé
            cout << *g2 << endl;

            // Retour du groupe de Forme
            return g2;
        }

        return NULL;
    };
};//z

#endif //PROJET_EXPERTCHARGEMENTGROUPECOR_H
