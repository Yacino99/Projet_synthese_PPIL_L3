package mainLocal;

import ChainOfResponsability.*;
import Serveur.Convertisseur.Vecteur2D;

public class Main2 {
    public static void main(String[] args) {

        /*
        String message = " groupe : [  croix ( 99 , 222 , 204 , 117 ) ; rond ( 448.5 , 468 , 39 )  ; triangle ( 30 , 200 , 90 , 200 , 45 , 50 )  ;  ]";
        String message2=  "croix ( 99 , 222 , 204 , 117 )";
        String message3=  "rond ( 448.5 , 468 , 39 )";

        Handler h1 = new DrawCircleHandler();
        Handler h2 = new DrawLineHandler();
        Handler h3 = new DrawPolygonHandler();
        Handler h4 = new DrawGroupeHandler();
        h1.setNextChain(h2);
        h2.setNextChain(h3);
        //h3.setNextChain(h4);

        //Handler h1 = new DrawGroupeHandler();
        try{
            h1.handle(message3,new CadreDessin("",0,0,800,800));

        }catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        //int parOuvrante = message.indexOf(": [");
        //String type = message.substring(0,parOuvrante);

        //System.out.println(type);

         */

        String message = "groupe : [ rond ( 224.25 , 234 , 19.5 ) red ; segment ( 49.5 , 111 , 102 , 58.5 ) red ; triangle ( 15 , 100 , 45 , 100 , 22.5 , 25 ) red ;  ] red I ( 15, 25) I ( 243.75, 253.5)";

        int crochetFermant = message.indexOf("]");

        String apresCrochetFermant = message.substring(crochetFermant+1);
        System.out.println(apresCrochetFermant);
        String vects[] = apresCrochetFermant.split(" I ");

        for(String s : vects) System.out.println(s);

        Vecteur2D vmin = new Vecteur2D(vects[1]);
        Vecteur2D vmax = new Vecteur2D(vects[2]);

        System.out.println("vmin = "+vmin +"vmax = "+vmax);

        System.out.println("Fin");
    }
}