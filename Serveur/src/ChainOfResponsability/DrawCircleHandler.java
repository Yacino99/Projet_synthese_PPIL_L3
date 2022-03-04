package ChainOfResponsability;

import java.awt.*;
import java.util.HashMap;

public class DrawCircleHandler extends Handler{


    @Override
    public boolean handle(String message, CadreDessin cadreDessin) throws InterruptedException {

        if(message.toLowerCase().contains("rond"))
        {
            int parOuvrante = message.indexOf("(");

            String type = message.substring(0,parOuvrante);

            if(type.trim().contains("rond") && !type.contains("group") )
            {

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
                //cadreDessin.getBufferStrategy().show();
                System.out.println("i drawed a circle");
            }
        }


        return handleNext(message,cadreDessin);
    }


}
