//Frazione.java
public class Frazione {
    /** Frazioni ridotte ai minimi termini e con denominatore >0*/
    /** Metodo statico MCD per il calcolo del Massimo Comun Divisore per interi a,b non entrambi nulli.

     Chi ha progettato la classe Frazione ha deciso di definire MCD come metodo statico perché MCD è un metodo che viene applicato *direttamente* a due int e solo *indirettamente* a un oggetto di tipo Frazione. Per esempio, il metodo dinamico semplifica(), definito sotto, chiama MCD e lo applica al numeratore e denominatore di una frazione, visti come valori di tipo int. */
    private int num, den;
    /** Metodo statico per il calcolo del Massimo Comun Divisore per interi a,b non entrambi nulli. */
    private static int MCD(int a, int b)
    {int r; while (b!=0) {r=a%b;a=b;b=r;} return Math.abs(a);}
    /** Questo algoritmo viene detto l'algoritmo di Euclide */

    /** Il prossimo metodo semplifica la frazione e rende positivo il denominatore */
    private void semplifica(){
        int m=MCD(num,den); num=num/m;den=den/m;
        if (den<0){num=-num;den=-den;}
        /** Rendo il denominatore > 0 */
    }

    /** Costruttore: crea una frazione, la semplifica, e forza il
     denominatore a essere positivo. */
    public Frazione(int num, int den){
        assert den!=0: "denominatore frazione deve essere diverso da 0";
        /** blocchiamo l'esecuzione quando il numeratore e' 0 */
        this.num=num; this.den=den; this.semplifica();
    }

    /** metodo set: semplifica e rende positivo il denominatore */
    public void setFrazione(int num, int den){
        assert den!=0: "denominatore frazione deve essere diverso da 0";
        /** blocchiamo l'esecuzione quando il numeratore e' 0 */
        this.num=num; this.den=den; this.semplifica();
    }

    /** Metodo di conversion frazione --> stringa */
    public String toString(){
        if (den != 1)
            return num + "/" + den;
        else /* den=1 */
            return num + "";
        /* Al posto di (num/1) scrivo num, trasformato in stringa grazie a una concatenazione con "" */
    }

    /** Metodo di eguaglianza: funziona anche se la frazione non e' semplificata */
    public boolean equals(Frazione f)
    {return (this.num * f.den == this.den * f.num);}

    /** Metodo di somma: il risultato viene creato semplificato */
    public Frazione somma(Frazione f){
        int n= this.num*f.den + this.den * f.num;
        int d= this.den*f.den;
        return new Frazione(n,d);
    }

    /** Il prossimo metodo sommaS è una versione statica del metodo di somma tra due frazioni. SommaS usa lo stesso algoritmo di Somma, ma SommaS non ha il this e un parametro esplicito f di tipo Frazione, bensì due parametri espliciti a,b di tipo Frazione. Cambia quindi la modalità di chiamata: per un esempio, si vedano i test inclusi nella classe FrazioneDemo.java. Nella classe Frazione preferiamo però la versione "dinamica" Somma, perché privilegiamo la progettazione object-oriented. Torneremo su questi argomenti più volte nel corso. */

    public static Frazione sommaS(Frazione a, Frazione b){
        int n= a.num*b.den + a.den * b.num;
        int d= a.den*b.den;
        return new Frazione(n,d);
    }

    /** Metodo di prodotto: il risultato viene creato semplificato */
    public Frazione prodotto(Frazione f){
        int n= this.num*f.num; int d= this.den*f.den;
        return new Frazione(n,d);
    }
}
