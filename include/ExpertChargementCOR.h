/**
 * \file      ExpertChargementCOR.h
 * \date      04 mars 2022
 * \brief     Classe ExpertChargementCOR
 */

#include "Expert.h"
#ifndef PROJET_EXPERTCHARGEMENTCOR_H
#define PROJET_EXPERTCHARGEMENTCOR_H

class ExpertChargementCOR : public Expert
{
    ExpertChargementCOR* _suivant;

protected :
    virtual Formes *resoudre1(const string &d) const = 0;

public :
    ExpertChargementCOR(ExpertChargementCOR* suivant) : _suivant(suivant) {}

    /**
     * \brief      Méthode du Design Pattern Chain of Responsibility
     * \details    Cette méthode resoudre() permet de céterminer la forme lue en le passant à l'expert adéquat grâce au Design Pattern Chain of Responsibility.
     * \param      *d le problème à résoudre, ici une ligne lue depuis le fichier de sauvegarde réprésentant une forme
     */
    Formes* resoudre(const string& d) const
    {
        Formes * forme = resoudre1(d);
        if (forme != NULL)
            return forme;

        if (_suivant != NULL)
            return _suivant->resoudre(d);

        return NULL;
    }
};

#endif //PROJET_EXPERTCHARGEMENTCOR_H