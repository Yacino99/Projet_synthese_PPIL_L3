/**
 * \file      ExpertChargementRondCOR.h
 * \date      04 mars 2022
 * \brief     Classe ExpertChargementRondCOR
 * \details   Cette expert essaie de trouver un rond parmi les formes qui lui sont données
 */
#ifndef PROJET_EXPERTCHARGEMENTRONDCOR_H
#define PROJET_EXPERTCHARGEMENTRONDCOR_H

#include "ExpertChargementCOR.h"
#include "Formes.h"

using namespace std;

class ExpertChargementRondCOR : public ExpertChargementCOR
{
public:
    ExpertChargementRondCOR(ExpertChargementCOR *suivant) : ExpertChargementCOR(suivant) {}

    /**
     * \brief      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre1() va essayer de résoudre le problème. S'il le résoud, il retourne la forme trouvé sinon il retourne NULL et l'expert suivant est appelé.
     * \param      *d le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     */
    Formes *resoudre1(const string &d) const
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

            // création de la forme en des données du fichier de visite
            return new Rond (points[0], points[1], points[2], couleur);
        }
        return NULL;
    };
};

#endif //PROJET_EXPERTCHARGEMENTRONDCOR_H
