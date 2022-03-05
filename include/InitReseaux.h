/**
 * \file      InitReseaux.h
 * \date      04 mars 2022
 * \brief     Classe InitReseaux
 * \details   Classe singleton qui s'execute une seule fois pour initialiser TCP/IP
 */

#ifndef PROJETT_INITRESEAUX_H
#define PROJETT_INITRESEAUX_H


#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include "Erreur.h"

class InitReseaux
{
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
