package Serveur;

import ChainOfResponsability.*;
import Serveur.Convertisseur.Config;
import Serveur.Convertisseur.Vecteur2D;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.util.ArrayList;

/**
 * \brief : classe interlocuteur qui permet de gerer le serveur java
 * elle recoit les requetes des client et appelle la chaine de responsabilite
 * afin de dessiner des formes
 */
public class Interlocuteur extends Thread{

    private int numClient;
    BufferedReader fluxEntrant ;
    PrintStream fluxSortant ;
    private Handler expert;
    public String[] formes = {};

    /**
     * \brief constructeur d'un interlocuteur
     * @param socket :le socket avec qui on va echanger
     * @param noClient : le numero du client car on peut on avoir plusieurs
     * @param expert : l'expert sur lequelle il s'occupe de dessiner les requetes
     * @throws IOException : Erreur de thread et de connexion
     */

    public Interlocuteur(Socket socket , int noClient, Handler expert) throws IOException {
        this.numClient=noClient;
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.expert=expert;
    }

    /**
     * \brief activer le thread de la classe pour interagir avec le client
     */

    @Override
    public void run() {
        try {


            while (!Thread.interrupted()) {

                String requete = fluxEntrant.readLine();
                System.out.println("le client numero : +" + this.numClient + " " + " a envoye " + requete);

                CadreDessin cadreDessin = new CadreDessin("cadre dessin",60,60, Config.LARGEUR,Config.HAUTEUR);
                cadreDessin.setResizable(false);

                expert.handle(requete,cadreDessin,false,null,null);

                cadreDessin.getBufferStrategy().show();
            }



        } catch (IOException e) {
            e.printStackTrace();
        }
        catch (InterruptedException e1)
        {
            e1.printStackTrace();
        }
    }

}
