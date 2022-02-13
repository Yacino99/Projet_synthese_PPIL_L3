//
// Created by user on 06/02/2022.
//

#ifndef PROJETT_INITRESEAUX_H
#define PROJETT_INITRESEAUX_H


#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include "Erreur.h"

// on se debrouille pour que cette classe soit instancié que une fois

class InitReseaux {


private:
    int r;
    WSADATA wsadata;

    InitReseaux() : r(WSAStartup(MAKEWORD(2, 0), &wsadata))
    {
        // tester le r puis faire seulement un throw
        if (r) throw Erreur("L'initialisation de la connexion a echoué");

    }


public:

    virtual ~InitReseaux()
    {
        WSACleanup();
    }



    static InitReseaux* initiateur;

    int getR() { return r; }

    static InitReseaux* getInitReseaux()
    {
        if (initiateur == NULL)
            initiateur = new InitReseaux();

        return initiateur;
    }
};


#endif //PROJETT_INITRESEAUX_H
