

//FrazioneDemo.java   (classe per esperimenti su frazioni)
public class FrazioneDemo {
    public static void main(String[] args) {
        Frazione t = new Frazione(2,3), u = new Frazione(1,6),
                v = new Frazione(1,6); //t=2/3, u=1/6, v=1/6
        System.out.println( "\n t,u,v valgono" );
        System.out.println(t + "\n" + u + "\n" + v);

        //t+u+v=(2/3)+(1/6)+(1/6)=((4+1+1)/6)=(6/6)=1
        System.out.println( "\n t+u+v deve fare 1:" );
        Frazione w = (t.somma(u)).somma(v);
        System.out.println(w);

        //Chiamata della versione statica sommaS della somma
        //della somma:
        Frazione h = Frazione.sommaS(Frazione.sommaS(t,u), v);
        System.out.println(h);

        //t*u*v=((2*1*1)/(3*6*6))=(2/108)=(1/54)
        System.out.println( "\n t*u*v deve fare (1/54)" );
        Frazione z = (t.prodotto(u)).prodotto(v); System.out.println(z);

        // Controllo che a=3/4 e b=30/40 siano uguali
        System.out.println( "\n Controllo che 3/4 = 30/40");
        Frazione a = new Frazione(3,4), b = new Frazione(30,40);
        System.out.println( "a=new Frazione(3,4)   vale: " + a);
        System.out.println( "b=new Frazione(30,40) vale: " + b);
        System.out.println( "a.equals(b)="+a.equals(b));

        System.out.println
                ( "\n Invece a= " + a + " e v=" + v + " sono diversi");
        System.out.println( "a.equals(v)="+a.equals(v));

    }
}