import java.util.Arrays;

public class Rubrica {

    private int numContatti ;
    private Contatto[] contatti;

    public Rubrica(int maxContatti){
        if(maxContatti > 0){
            // inizializzo con numContatti a 0
            this.numContatti = 0;
            contatti = new Contatto[maxContatti];
        }else{
            // ERRORE
        }
    }

    public String toString() {
        String s = "Numero contatti = " + numContatti;
        int i = 0;
        while(i<numContatti){
            s += "\nContatto: " + contatti[i].toString();
            i++;
        }
        return s;
    }

    private int cercaIndice(String nome){
        int i = 0;
        while(i<numContatti){
            if(nome.equals(contatti[i].getNome())){
                return i;
            }
            i++;
        }
        return numContatti;
    }

    public boolean cercaNome(String nome){
        return cercaIndice(nome) < numContatti;
    }

    public String cercaEmail(String email){
        int i = cercaIndice(email);
        if(i < numContatti){
            return contatti[i].getEmail();
        }
        return "";
    }

    public   boolean piena()
    {return (numContatti  == contatti.length);}



}
