package ChainOfResponsability;

import java.awt.*;
import java.util.HashMap;

public class DrawLineHandler extends Handler {


    @Override
    public boolean handle(String message , CadreDessin cadreDessin) throws InterruptedException {

        if(message.toLowerCase().trim().contains("croix"))
        {

            int parOuvrante = message.indexOf("(");
            int parFermante = message.indexOf(")");
            String part1 = message.substring(parOuvrante+1,parFermante);
            String couleur = message.substring(parFermante+1).trim().toLowerCase();

            String[] splited =  part1.split(",");

            int gauche = (int) Double.parseDouble(splited[0].trim());
            int haut = (int) Double.parseDouble(splited[1].trim());
            int droit = (int) Double.parseDouble(splited[2].trim());
            int bas = (int) Double.parseDouble(splited[3].trim());

            if(map.containsKey(couleur))
                cadreDessin.graphics.setColor(map.get(couleur));

            cadreDessin.graphics.drawLine(gauche, bas, droit, haut);
            cadreDessin.graphics.drawLine(gauche, haut, droit, bas);

            System.out.println("i drawed a cross");

        }

        return handleNext(message,cadreDessin);
    }
}
