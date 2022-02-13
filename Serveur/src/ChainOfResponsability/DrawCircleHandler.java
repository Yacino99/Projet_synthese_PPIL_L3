package ChainOfResponsability;

import java.awt.*;
import java.util.HashMap;

public class DrawCircleHandler extends Handler{

    HashMap<String,Color> map=new HashMap<String,Color>();

    public DrawCircleHandler(){

        map.put("red",Color.red);
        map.put("blue",Color.BLUE);
        map.put("yellow",Color.yellow);
        map.put("green",Color.green);
        map.put("orange",Color.ORANGE);
        map.put("magenta",Color.MAGENTA);
        map.put("cyan",Color.CYAN);
        map.put("pink",Color.PINK);
        map.put("gray",Color.GRAY);
        map.put("",Color.black);


    }


    @Override
    public boolean handle(String message, CadreDessin cadreDessin) throws InterruptedException {

        if(message.trim().contains("rond"))
        {


            int parOuvrante = message.indexOf("(");
            int parFermante = message.indexOf(")");
            String part1 = message.substring(parOuvrante+1,parFermante);
            String couleur = message.substring(parFermante+1).trim().toLowerCase();

            String[] splited =  part1.split(",");
            double Xcentre = Double.parseDouble(splited[0].trim());
            double Ycentre = Double.parseDouble(splited[1].trim());
            double rayon = Double.parseDouble(splited[2].trim());

            int x = (int)Xcentre;
            int y = (int)Ycentre;
            int r = (int)rayon;


            if(map.containsKey(couleur))
                cadreDessin.graphics.setColor(map.get(couleur));

            cadreDessin.graphics.fillOval(x,y,r,r);
            System.out.println("i drawed a circle");
        }

        return handleNext(message,cadreDessin);
    }


}
