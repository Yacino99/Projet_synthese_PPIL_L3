package Serveur;

import ChainOfResponsability.CadreDessin;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class TestServeurFormes {

    public static void main(String[] args) {

        try{
            int portServeur=9111;
            ServerSocket serveur = new ServerSocket(portServeur);

            System.out.print("serveur de Formes cree "+serveur);
            int noClient = 1;
            while(true)
            {
                Socket socket = serveur.accept();
                System.out.println("connexion reussi avec le client numero "+noClient);
                //400 400
                CadreDessin cadreDessin = new CadreDessin("cadre dessin",60,60,800,800);

                Interlocuteur interlocuteur = new Interlocuteur(socket, noClient,cadreDessin);
                // todo : creer un thread par client et le donner en parametre
                // fermer les fentre les unes de autres independament des autres
                ++noClient;
                interlocuteur.start();

            }
        }catch (IOException | InterruptedException e){
            e.printStackTrace();
        }

        System.out.println("fin du programme");
    }

}
