/**
 * \file      Socket.h
 * \date      04 mars 2022
 * \brief     Classe Socket
 */

#ifndef PROJETT_SOCKET_H
#define PROJETT_SOCKET_H


#define _WINSOCK_DEPRECATED_NO_WARNINGS


#include <WinSock2.h>
#include "InitReseaux.h"
#include <string.h>
#include <sstream>

#define monL 2048

class Socket
{
private:
    SOCKET sock;
    int familleAdresse;
    int typeSocket;
    int protocole;

    char adresseServeur[50];
    int portServer;
    SOCKADDR_IN sockaddr;

    char message[monL - 1];
    int l;

public:


    Socket(const char *addresseServeurr, int port) : familleAdresse(AF_INET), typeSocket(SOCK_STREAM),protocole(IPPROTO_TCP), portServer(port)
    {
        strcpy_s(this->adresseServeur, addresseServeurr);

        // chargement de la DLL reseau si c'est pas fait

        InitReseaux::getInitReseaux();

        sock = socket(familleAdresse, typeSocket, protocole);
        if(sock == INVALID_SOCKET)
        {
            ostringstream oss;
            oss << "La creation du socket a echoué : code d'erreur = " << WSAGetLastError() << endl;
            throw Erreur(oss.str().c_str());
        }
        cout << "socket cree" << endl;

        sockaddr.sin_family = AF_INET;
        sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);
        sockaddr.sin_port = htons(portServer);

        if (connect(sock, (SOCKADDR*)&sockaddr, sizeof(sockaddr)) == SOCKET_ERROR)
        {
            throw Erreur("La connexion a echoué");
        }
        cout << "La connexion a reussi" << endl;
    }

    virtual ~Socket()
    {
        /*
        int r = shutdown(sock, SD_BOTH);

        if (r == SOCKET_ERROR) throw Erreur("La coupure de connexion a echoue");
        r = closesocket(sock);
        if (r == SOCKET_ERROR) throw Erreur("La fermeture du socket a echoue");

        WSACleanup();
        */
        this->shutItDown();
    }

    void shutItDown()
    {
        int r = shutdown(sock, SD_BOTH);

        if (r == SOCKET_ERROR) throw Erreur("La coupure de connexion a echoue");
        r = closesocket(sock);
        if (r == SOCKET_ERROR) throw Erreur("La fermeture du socket a echoue");

        //WSACleanup();
    }

    void sendMessage(const char* msg)
    {
        strcpy_s(message, msg);

        strcat_s(message, "\r\n");
        l = strlen(message);
        cout << "ton message a ete : " << message << endl;

        int r = send(sock, message, l, 0);
        if (r == SOCKET_ERROR)
            throw Erreur("echec de l'envoie du message");
    }

    void recieveMessage(char reponse[monL])
    {
        int r = recv(sock, reponse, l, 0);

        if (r == SOCKET_ERROR)
            throw Erreur("Reception de la reponse a echoue");

        char* p = strchr(reponse, '\n');
        *(p + 1) = '\0';

        cout << "reponse du serveur : " << reponse;
    }

    //TODO : faire un methode init Fenetre ou bien set Fenetre size pour la taille de la fenetre du serveur

};

#endif //PROJETT_SOCKET_H
