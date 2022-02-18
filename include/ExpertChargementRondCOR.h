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
        const string cherche = "rond";
        string::size_type pos = d.find(cherche);
        while (pos != string::npos)
        {
            // "rond" trouvé
            vector<double> points;

            // on extrait tout ce qui se trouve entre les parenthèses
            unsigned firstParenthesis = d.find("(");
            unsigned lastParenthesis = d.find(")");
            string coordonnees = d.substr (firstParenthesis + 1, lastParenthesis - firstParenthesis - 1);
            istringstream is(coordonnees );

            // on enlève toutes les virgules et on stocke les nombres dans un vecteur
            string t;
            while ( getline( is, t, ',' ) ) points.push_back(stod(t));

            // récupération de la couuleur
            string couleur = d.substr(lastParenthesis + 1, d.size());

            // création de la forme en des données du fichier de sauvegarde
            return new Rond (points[0], points[1], points[2], pSocket, couleur);
        }

        return NULL;
    };
};

#endif //PROJET_EXPERTCHARGEMENTRONDCOR_H
