//
// Created by Anwender on 18/02/2022.
//

#ifndef PROJET_EXPERTCHARGEMENTPOLYGONECOR_H
#define PROJET_EXPERTCHARGEMENTPOLYGONECOR_H

#include "ExpertChargementCOR.h"
#include "Formes.h"
#include "Polygone.h"

using namespace std;

class ExpertChargementPolygoneCOR : public ExpertChargementCOR
{
public:
    ExpertChargementPolygoneCOR(ExpertChargementCOR *suivant) : ExpertChargementCOR(suivant) {}

    Formes *resoudre1(const string &d) const
    {
        const string cherche = "polygone";
        string::size_type pos = d.find(cherche);
        while (pos != string::npos)
        {
            // "polygone" trouvé
            vector<double> points;

            // on extrait tout ce qui se trouve entre les parenthèses
            unsigned firstParenthesis = d.find("(");
            unsigned lastParenthesis = d.find(")");
            string coordonnees = d.substr (firstParenthesis + 1, lastParenthesis - firstParenthesis - 1);
            istringstream is(coordonnees );

            // on enlève toutes les virgules et on stocke les nombres dans un vecteur
            string t;
            while ( getline( is, t, ',' ) ) points.push_back(stod(t));

            // tab de vecteurs
            vector<Vecteur2D*> vecteurs;

            for(int x=0, y=1; y < points.size(); x+=2, y+=2)
                vecteurs.push_back(new Vecteur2D(points[x], points[y]));

            // récupération de la couuleur
            string couleur = d.substr(lastParenthesis + 1, d.size());

            // création de la forme en des données du fichier de visite
            return new Polygone(vecteurs, couleur);
        }

        return NULL;
    };
};

#endif //PROJET_EXPERTCHARGEMENTPOLYGONECOR_H
