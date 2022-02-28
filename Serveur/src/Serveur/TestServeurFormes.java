package Serveur;

import ChainOfResponsability.*;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class TestServeurFormes {

    public static void main(String[] args) {

        try{

            Handler h1 = new DrawCircleHandler();
            Handler h2 = new DrawLineHandler();
            Handler h3 = new DrawPolygonHandler();
            h1.setNextChain(h2);
            h2.setNextChain(h3);

            int portServeur=9111;
            ServerSocket serveur = new ServerSocket(portServeur);

            System.out.print("serveur de Formes cree "+serveur);
            int noClient = 1;
            while(true)
            {
                Socket socket = serveur.accept();
                System.out.println("connexion reussi avec le client numero "+noClient);
                
                //on cree un cadre dessin pour chaque client
                CadreDessin cadreDessin = new CadreDessin("cadre dessin",60,60,800,800);
                cadreDessin.setResizable(false);
                Interlocuteur interlocuteur = new Interlocuteur(socket, noClient,cadreDessin,h1 );

                ++noClient;
                interlocuteur.start();
                //adsvasdvsdv
            }
        }catch (IOException | InterruptedException e){
            e.printStackTrace();
        }

        System.out.println("fin du programme");
    }

}
