package Serveur;

import ChainOfResponsability.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

public class Interlocuteur extends Thread{

    private int numClient;
    BufferedReader fluxEntrant ;
    PrintStream fluxSortant ;
    CadreDessin cadreDessin;
    private Handler expert;
    public String[] formes = {};
   // static int type = 0;
   //  Frame f1AR;

    public Interlocuteur(Socket socket , int noClient,CadreDessin cadreDessin, Handler expert) throws IOException {
        this.numClient=noClient;
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.cadreDessin=cadreDessin;
        this.expert=expert;
    }


    @Override
    public void run() {
        try {


            while (!Thread.interrupted()) {

                String requete = fluxEntrant.readLine();
                System.out.println("le client numero : +" + this.numClient + " " + " a envoye " + requete);

                //Thread.sleep(150);

                expert.handle(requete,cadreDessin);

                //this.formes

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
