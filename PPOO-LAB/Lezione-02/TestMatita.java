// Matita.java
class Matita {
 public static final int minStelo = 10;  //min. lunghezza matita (mm)
 public static final int maxStelo = 200; //max. lunghezza matita (mm)
 public static final int maxPunta =   5; //max. lunghezza punta  (mm)
//Una matita e' uno stelo seguito da una punta
 private int stelo; // 0 <= stelo <= maxStelo 
 private int punta; // 0 <= punta <= maxPunta 
	
 public Matita(int stelo) {
 assert minStelo<=stelo && stelo<=maxStelo:
 "stelo matita non accettabile:" + stelo;
 this.stelo = stelo;
 this.punta = maxPunta;
}

/** disegna restituisce true quando la matita ha ancora punta, e ne riduce la punta di 1 mm. Restituisce false se la punta e' finita. */
 public boolean disegna() {
 if (this.punta > 0) {
     this.punta--;
     return true;
 } 
 else
     return false;
 }

/** "tempera" riduce di un 1mm la matita, e allunga di 1mm la punta
a meno che la lunghezza della punta sia gia' il massimo. */
    public boolean tempera() {
     if (this.stelo > minStelo) {
       this.stelo--;
       this.punta = Math.min(this.punta + 1, maxPunta);
       return true;
     } 
     else return false;
   }

 public int getStelo() {return this.stelo;}
 public int getPunta() {return this.punta;}
}


public class TestMatita {
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
