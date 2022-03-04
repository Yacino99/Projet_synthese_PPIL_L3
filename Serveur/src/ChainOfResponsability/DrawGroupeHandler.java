package ChainOfResponsability;

public class DrawGroupeHandler extends Handler{
    @Override
    public boolean handle(String message , CadreDessin cadreDessin) throws InterruptedException {

        if (message.toLowerCase().contains("group"))
        {
            int parOuvrante = message.indexOf(": [");
            String type = message.substring(0, parOuvrante).trim().toLowerCase();

            if (type.contains("groupe"))
            {
                int crochetOuvrant = message.indexOf("[");
                int crocherFermant = message.indexOf("]");
                String part1= message.substring(parOuvrante+1).trim().toLowerCase();
                String entreCrochet = message.substring(crochetOuvrant+1,crocherFermant);

                System.out.println("type = "+type);
                System.out.println("part1 ="+part1);
                System.out.println("entre crochet ="+entreCrochet);

                String formes[] = entreCrochet.split(";");

                Handler h1 = new DrawCircleHandler();
                Handler h2 = new DrawLineHandler();
                Handler h3 = new DrawPolygonHandler();
                Handler h4 = new DrawGroupeHandler();
                h1.setNextChain(h2);
                h2.setNextChain(h3);
                //h3.setNextChain(h4);

                CadreDessin cadreDessin2 = new CadreDessin(cadreDessin.getTitle(),cadreDessin.bordGauche,
                        cadreDessin.bordSuperieur, cadreDessin.getWidth(),cadreDessin.getHeight());
                for (int i = 0 ; i < formes.length -1 ; i++) {
                    System.out.println(formes[i]);
                    h1.handle(formes[i],cadreDessin2);

                }

                cadreDessin2.getBufferStrategy().show();
                System.out.println("i drawed a group");
            }


        }

        return handleNext(message,cadreDessin);
        //return false;
    }

}
