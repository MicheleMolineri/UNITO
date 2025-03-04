import java.util.Scanner;

class Gatto {
    public String nome;
    public String razza;
    public int anni;

    private static Scanner tastiera = new Scanner(System.in);

    public void leggiInput() {
        System.out.println(" nome = ");
        this.nome = tastiera.nextLine();
        System.out.println(" razza = ");
        this.razza = tastiera.nextLine();
        System.out.println(" anni = ");
        this.anni = tastiera.nextInt();
        tastiera.nextLine(); // Consuma il return
    }

    public String toString() {
        return " nome  = " + nome + "\n razza = " + razza +
                "\n anni = " + anni;
    }

    public int getEtaInAnniUmani() {
        if (anni <= 2)
            return anni * 11;
        else
            return 22 + (anni - 2) * 5;
    }
}

public class GattoDemo {
    public static void main(String[] args) {
        Gatto pippa = new Gatto();
        System.out.println("pippa prima inserimento dati");
        System.out.println(pippa);
        System.out.println("Inserisci dati pippa");
        pippa.leggiInput();
        System.out.println("Dati inseriti pippa");
        System.out.println(pippa);
        System.out.println("eta' pippa in anni umani  "
                + pippa.getEtaInAnniUmani());

        Gatto galileo = new Gatto();
        System.out.println("Inserisco dati galileo dentro il programma");
        galileo.nome = "Galileo";
        galileo.razza = "Persiano";
        galileo.anni = 5;
        System.out.println(galileo);
    }
}