//
// Created by Anwender on 18/02/2022.
//

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
