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
    virtual Formes *resoudre1(const string &d, Socket *pSocket) const = 0;

public :
    ExpertChargementCOR(ExpertChargementCOR* suivant) : _suivant(suivant) {}

    Formes* resoudre(const string& d, Socket *socket) const
    {
        Formes * forme = resoudre1(d, socket);
        if (forme != NULL)
            return forme;

        if (_suivant != NULL)
            return _suivant->resoudre(d, socket);

        return NULL;
    }
};


#endif //PROJET_EXPERTCHARGEMENTCOR_H
