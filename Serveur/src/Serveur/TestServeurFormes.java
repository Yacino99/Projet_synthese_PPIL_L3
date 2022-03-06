package Serveur;

import ChainOfResponsability.*;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * @brief : classe main qui appelles la classe interlocteur et la chaine de responsabilite
 */
public class TestServeurFormes {

    public static void main(String[] args) {

        try{

            // initialisation de la chaine de responsabilite

            Handler h1 = new DrawCircleHandler();
            Handler h2 = new DrawLineHandler();
            Handler h3 = new DrawPolygonHandler();
            Handler h4 = new DrawGroupeHandler();
            h1.setNextChain(h2);
            h2.setNextChain(h3);
            h3.setNextChain(h4);

            int portServeur=9111;
            ServerSocket serveur = new ServerSocket(portServeur);

            System.out.print("serveur de Formes cree "+serveur);
            int noClient = 1;
            while(true)
            {
                Socket socket = serveur.accept();
                System.out.println("connexion reussi avec le client numero "+noClient);
                
                //on cree un cadre dessin pour chaque requete
                Interlocuteur interlocuteur = new Interlocuteur(socket, noClient,h1 );
                System.out.println("----------debut requete : -----------------");
                ++noClient;
                interlocuteur.start();

            }
        }catch (IOException  e){
            e.printStackTrace();
        }

        System.out.println("fin du programme");
    }

}
