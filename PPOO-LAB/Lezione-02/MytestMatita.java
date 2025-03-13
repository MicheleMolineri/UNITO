class Matita {
    // attributi matita 
    // static indica che appartengo alla classe e non all'oggetto
    // final indica che è una costante
    public static final int minStelo = 10;
    public static final int maxStelo = 200;
    public static final int maxPunta = 5;

    // attributi oggetto matita
    private int stelo;
    private int punta;

    // Il costruttore di Matita consente di costruire una 
    // matita con punta di lunghezza massima dato lo stelo. Un assert 
    // impedisce lunghezze non accettabili dello stelo.
    public Matita(int stelo){
        assert stelo >= minStelo && stelo <= maxStelo;
        this.punta = maxPunta;
        this.stelo = stelo;
    } 

    // La  classe  ha  i  metodi  get  per  stelo e punta e nessun 
    // metodo  set:  non  consento  di  cambiare  la  lunghezza  a  una 
    // matita. 

    public int getPunta(){
        return this.punta;
    }

    public int getStelo(){
        return this.stelo;
    }

    // Un metodo “disegna” restituisce “true” (successo) se la 
    // matita  ha  almeno  1mm  di  punta,  e  “false”  (fallimento) 
    // altrimenti.  Nel  primo  caso  usa  la  matita  fino  a  ridurne  la 
    // punta di un 1mm.
    public boolean disegna(){
        if( this.punta >= 1 ){
            this.punta--;
            return true;
        } else {
            return false;
        }
    }

    // Un  metodo  “tempera”  restituisce  “true”  (successo) se la 
    // matita  è  più  lunga  del  minimo  e  “false”  (fallimento) 
    // altrimenti. 
    // Nel primo caso riduce lo stelo di 1mm e allunga la 
    // punta  di 1mm, a meno che la lunghezza della punta sia già il 
    // massimo.  In  questo  caso  la  matita  si  accorcia  ma  la  punta 
    // resta invariata.
    public boolean tempera(){
        if(this.stelo > minStelo){
            this.stelo--;
            if(this.punta < maxPunta){
                this.punta++;
            }
            return true;
        }
        return false;
    }
    
}

public class MytestMatita {
    public static void main(String[] args){ 
        Matita m = new Matita(Matita.maxStelo); 
        int s = m.getStelo(), p = m.getPunta();
        System.out.println("Matita di stelo " + s + " e punta " + p); 
        System.out.println("Disegno per " + 2*p + " volte:"); 
        System.out.println("dopo " + p + " volte il disegno fallisce");
        for (int i = 0; i < 2*p; i++)
         System.out.println(" Successo disegno n."+i+" = "+m.disegna());
        System.out.println("Tempero di 1mm la matita"); m.tempera();
        System.out.println(" nuova lunghezza punta = " + m.getPunta());
        System.out.println(" nuova lunghezza stelo = " + m.getStelo());
        System.out.println("Stampo la matita m. Ottengo \"Matita@\" seguito dall'indirizzo dell'oggetto (in esadecimale): " + m);
        }
}