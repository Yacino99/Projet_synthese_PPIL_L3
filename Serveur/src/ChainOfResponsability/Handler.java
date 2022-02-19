package ChainOfResponsability;

import java.awt.*;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.util.HashMap;

public abstract class  Handler {
    private Handler next;

    protected BufferedReader fluxEntrant ;
    protected PrintStream fluxSortant ;
    protected Frame f1AR;

    protected HashMap<String,Color> map=new HashMap<String,Color>();

    protected Handler(){
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
    public abstract boolean handle(String message, CadreDessin cadreDessin) throws InterruptedException;

    public void setNextChain(Handler nextChain){
        next = nextChain;
    }

    protected boolean handleNext(String message, CadreDessin cadreDessin){
        if(next == null)
            return true;

        try {
            return next.handle(message,cadreDessin);
        }catch (InterruptedException e) {
            e.printStackTrace();
        }

        return true;

    }
}
