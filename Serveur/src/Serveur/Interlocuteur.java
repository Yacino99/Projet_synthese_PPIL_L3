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
   // static int type = 0;
   //  Frame f1AR;

    public Interlocuteur(Socket socket , int noClient,CadreDessin cadreDessin) throws IOException {
        this.numClient=noClient;
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.cadreDessin=cadreDessin;

    }


    @Override
    public void run() {
        try {

            //CadreDessin cadreDessin = new CadreDessin("cadre dessin",60,60,400,400);
            Handler h1 = new DrawCircleHandler();
            Handler h2 = new DrawLineHandler();
            Handler h3 = new DrawPolygonHandler();
            h1.setNextChain(h2);
            h2.setNextChain(h3);
            while (!Thread.interrupted()) {

                String requete = fluxEntrant.readLine();
                System.out.println("le client numero : +" + this.numClient + " " + " a envoye " + requete);

                Thread.sleep(150);

                h1.handle(requete,cadreDessin);
                h2.handle(requete,cadreDessin);
                h3.handle(requete,cadreDessin);
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
