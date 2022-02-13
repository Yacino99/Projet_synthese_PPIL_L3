package ChainOfResponsability;

import java.awt.*;
import java.util.HashMap;

public class DrawPolygonHandler extends Handler{

    HashMap<String, Color> map=new HashMap<String,Color>();

    public DrawPolygonHandler() {
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


        if(message.toLowerCase().trim().contains("triangle") || message.toLowerCase().trim().contains("polygone"))
        {

            int parOuvrante = message.indexOf("(");
            int parFermante = message.indexOf(")");
            String cordString = message.substring(parOuvrante+1,parFermante);
            String couleur = message.substring(parFermante+1).trim().toLowerCase();

            String cords[] = cordString.split(",");
            int[] x = new int[cords.length];
            int[] y = new int[cords.length];
            //System.out.println(cordString);

            for(int i = 0 ,j=0,k=1 ; i < cords.length ; i+=2,j++,k+=2){
                x[j]= (int) Double.parseDouble(cords[i].trim());
                y[j]= (int) Double.parseDouble(cords[k].trim());
               // System.out.print(x[j]+" "+y[j]+" ");
            }

            System.out.println("y lenght = "+y.length +"x length = " +x.length );
            Polygon p = new Polygon(x,y,y.length/2);
            if(map.containsKey(couleur))
                cadreDessin.graphics.setColor(map.get(couleur));

            cadreDessin.graphics.fillPolygon(p);;

        }


        return handleNext(message,cadreDessin);
    }
}
