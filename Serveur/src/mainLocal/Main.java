package mainLocal;

import ChainOfResponsability.CadreDessin;
import ChainOfResponsability.DrawCircleHandler;
import ChainOfResponsability.DrawLineHandler;
import ChainOfResponsability.Handler;

public class Main {

    public static void main(String[] args) {
	// write your code here

        Handler h1 = new DrawCircleHandler();
        Handler h2 = new DrawLineHandler();

        h1.setNextChain(h2);
        System.out.println("le push");
        System.out.println("before");

        try{
            CadreDessin cadreDessin = new CadreDessin("cadre dessin",60,60,12000,12000);
            h1.handle("rond(200,200,50,50)",cadreDessin);
            h2.handle("croix(140,100,30,70)",cadreDessin);



        }catch (InterruptedException e){
            e.printStackTrace();
        }

        System.out.println("after");
    }
}
