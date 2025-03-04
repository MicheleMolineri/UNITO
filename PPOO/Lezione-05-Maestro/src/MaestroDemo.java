//salveremo tutto nel file: MaestroDemo.java
import java.util.Scanner;

class Maestro { //classe non eseguibile
    private String vecchiaRisposta = "la risposta è nel tuo cuore";
    private String nuovaRisposta;
    private String domanda;
    private static Scanner tastiera = new Scanner(System.in);

    public void parla(){
        String continua = "si";
        while (continua.charAt(0)=='s' || continua.charAt(0)=='S'){
            System.out.println( "Cosa vuoi chiedere?" );
            domanda = tastiera.nextLine();
            rispondi();
            // il metodo rispondi() è chiamato sull’oggetto this;
            // this = oggetto su cui viene chiamato il metodo
            // dinamico rispondi() (this lasciato implicito)
     /* Scrivere
          this.rispondi(); // this esplicito
      sarebbe corretto, perché equivalente alla versione precedente,
      solo con il this sintatticamente esplicito. */
     /* Invece scrivere: yoda.rispondi();
      sarebbe proprio SBAGLIATO, perché 'yoda' è un nome (una
      variabile locale) del main, quindi non è visibile al
      metodo parla(). Ricordiamo che this è una variabile
      speciale di ogni metodo dinamico, che assume il valore
      dell'oggetto su cui viene chiamato il metodo stesso nel
      chiamante (nel nostro main, per esempio, this assume il valore
      = l'indirizzo dell'oggetto puntato dalla variabile 'yoda'). */

            aggiorna(); //oppure: this.aggiorna
            // il metodo aggiorna() è chiamato sull’oggetto this
            System.out.println( "Vuoi continuare?" );
            continua = tastiera.nextLine();
        }
        System.out.println( "Il maestro ora riposa" );
    }

    /* I metodi che seguono sono considerati come metodi di servizio, per cui dichiarati 'private': non visibili al codice client.*/
    private void rispondi(){
        System.out.println
                ("Avrei bisogno di un suggerimento: cosa mi suggerisci?");
        nuovaRisposta = tastiera.nextLine();
        System.out.println( "Hai posto la domanda : " + domanda);
        System.out.println( "Ecco la tua risposta : " + vecchiaRisposta);
    }

    private void aggiorna()
    {vecchiaRisposta = nuovaRisposta;}
}

public class MaestroDemo{
    // Classe eseguibile pubblica. Salvare in: MaestroDemo.java
    public static void main(String[] args){
// Costruiamo un singolo maestro e iniziamo a parlare con lui
        Maestro yoda = new Maestro();
        yoda.parla();
    }
}
