import java.util.Scanner;

public class SpecieNuova {
    private String nome;
    private int popolazione;
    private double tassoCrescita;

    public void setSpecie(String n, int p, double t) {
        nome = n;
        if (p < 0)
            System.out.println("Valori negativi popolazione non accettati");
        else
            popolazione = p;
        tassoCrescita = t;
    }

    public String getSpecie() {
        return nome;
    }

    private static Scanner tastiera = new Scanner(System.in);

    public void leggiInput() {
        System.out.println(" nome = ");
        nome = tastiera.nextLine();

        System.out.println(" popolazione = ");
        popolazione = tastiera.nextInt();
        tastiera.nextLine();

        System.out.println(" tasso di crescita = ");
        tassoCrescita = tastiera.nextDouble();
        tastiera.nextLine();
    }

    public String toString() {
        return " nome = " + nome + "\n popolazione = " + popolazione + "\n tasso crescita = " + tassoCrescita;
    }

    public int prediciPopolazione(int anni) {
        double p = popolazione;
        while (anni > 0) {
            p = p + p * tassoCrescita / 100;
            --anni;
        }
        return (int) p;
    }

    public void cambia(SpecieNuova s) {
        s.nome = this.nome;
        s.popolazione = this.popolazione;
        s.tassoCrescita = this.tassoCrescita;
    }

    public boolean equals(SpecieNuova altraSpecie) {
        return (nome.equalsIgnoreCase(altraSpecie.nome))
                && (popolazione == altraSpecie.popolazione)
                && (tassoCrescita == altraSpecie.tassoCrescita);
    }

}
