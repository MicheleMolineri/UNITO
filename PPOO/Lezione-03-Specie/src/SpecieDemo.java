import java.util.Scanner;

class Specie {
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

    public String getNome() {
        return nome;
    }

    public int getPopolazione() {
        return popolazione;
    }

    public double getTassoCrescita() {
        return tassoCrescita;
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
        return " nome = " + nome + "\n popolazione = " +
                popolazione + "\n tasso crescita = " +
                tassoCrescita;
    }

    public int prediciPopolazione(int anni) {
        double p = popolazione;
        while (anni > 0) {
            p = p + p * tassoCrescita / 100;
            --anni;
        }
        return (int) p;
    }
}

public class SpecieDemo {
    public static void main(String[] args) {
        Specie bufaloTerrestre = new Specie();

        System.out.println("BufaloTerrestre prima inserimento dati \n" +
                bufaloTerrestre);

        System.out.println("Inserisci dati BufaloTerrestre");
        bufaloTerrestre.leggiInput();

        System.out.println("Dati inseriti BufaloTerrestre \n" +
                bufaloTerrestre);

        System.out.println("BufaloTerrestre dopo 10 anni = "
                + bufaloTerrestre.prediciPopolazione(10));

        Specie bufaloKlingon = new Specie();
        System.out.println("Inserisco dati BufaloKlingon usando set");
        bufaloKlingon.setSpecie("BK", 1000, 10);

        System.out.println("Dati inseriti BufaloKlingon \n" +
                bufaloKlingon);
        System.out.println("Bufalo Klingon dopo 10 anni = "
                + bufaloKlingon.prediciPopolazione(10));

        System.out.println("Identifico Bufalo terrestre e Klingon");
        bufaloTerrestre = bufaloKlingon;
        System.out.println(bufaloTerrestre);
        System.out.println(bufaloKlingon);
    }
}