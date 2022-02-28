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
    ExpertChargementTriangleCOR(ExpertChargementCOR *suivant) : ExpertChargementCOR(suivant) {}

    Formes *resoudre1(const string &d) const
    {
        const string cherche = "triangle";
        string::size_type pos = d.find(cherche);
        while (pos != string::npos)
        {
            // "triangle" trouvé
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

            // création de la forme en des données du fichier de visite
            return new Triangle(points[0], points[1], points[2], points[3], points[4], points[5], couleur);
        }

        return NULL;
    };
};

#endif //PROJET_EXPERTCHARGEMENTTRIANGLECOR_H
