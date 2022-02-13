package ChainOfResponsability;

import java.awt.*;
import java.io.BufferedReader;
import java.io.PrintStream;

public abstract class  Handler {
    private Handler next;

    protected BufferedReader fluxEntrant ;
    protected PrintStream fluxSortant ;
    protected Frame f1AR;

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
