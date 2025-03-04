import java.util.Scanner;

class SpecieNuova {
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

    public void cambia(SpecieNuova altraSpecie) {
        altraSpecie.nome = this.nome;
        altraSpecie.popolazione = this.popolazione;
        altraSpecie.tassoCrescita = this.tassoCrescita;
    }

    public boolean equals(SpecieNuova altraSpecie) {
        return (nome.equalsIgnoreCase(altraSpecie.nome))
                && (popolazione == altraSpecie.popolazione)
                && (tassoCrescita == altraSpecie.tassoCrescita);
    }
}

public class SpecieNuovaDemo {

    private static void pause() {
        Scanner tastiera = new Scanner(System.in);
        System.out.println("............. premi a capo per continuare");
        tastiera.nextLine();
    }

    public static void main(String[] args) {
        SpecieNuova specieTerrestre = new SpecieNuova();
        System.out.println("\n 1. Inserisco specieTerrestre usando un metodo di set");
        specieTerrestre.setSpecie("Bufalo Nero", 500, 3);

        System.out.println("\n 2. Dati inseriti specieTerrestre");
        System.out.println(specieTerrestre);
        pause();

        SpecieNuova specieKlingon = new SpecieNuova();
        System.out.println("\n 3. Inserisco specieKlingon usando un metodo di set");
        specieKlingon.setSpecie("Bufalo Klingon", 1000, 10);

        System.out.println("\n 4. Dati inseriti specieKlingon");
        System.out.println(specieKlingon);
        pause();

        System.out.println("\n 5. Assegno specieterrestre = specieKlingon");
        specieTerrestre = specieKlingon;
        System.out.println("Ora le due variabili puntano allo stesso oggetto:");
        System.out.println(specieTerrestre);
        System.out.println(specieKlingon);

        System.out.println("\n 6. Per rendermi conto che le due variabili sono un alias dello stesso oggetto: ");
        System.out.println("se modifico la specie terrestre in Elefante modifico anche il  Klingon");
        specieTerrestre.setSpecie("Elefante", 100, 2);
        System.out.println(specieTerrestre);
        System.out.println(specieKlingon);
        pause();

        System.out.println("\n 7. Vediamo ora un altro modo di modificare gli oggetti");
        System.out.println("Creo \"specieAfricana\" e le assegno i valori Elefante");
        SpecieNuova specieAfricana = new SpecieNuova();
        specieTerrestre.cambia(specieAfricana);
        System.out.println(specieAfricana);
        pause();

        System.out.println("\n 8. La prima e la seconda variabile puntano allo stesso oggetto: (specieTerrestre == specieKlingon) vale : "
                + (specieTerrestre == specieKlingon));

        System.out.println("\n 9. Invece la prima e la terza variabile no: (specieTerrestre == specieAfricana) vale : "
                + (specieTerrestre == specieAfricana));

        System.out.println("\n 10. Pero' gli attributi degli oggetti puntati dalle due variabili hanno gli stessi valori: (specieTerrestre.equals(specieAfricana)) vale : " + (specieTerrestre.equals(specieAfricana)));
        pause();

        System.out.println("\n 11. Una controprova: modifico la specieAfricana in Elefante Africano.");
        specieAfricana.setSpecie("Elefante Africano", 100, 2);
        System.out.println(specieAfricana);

        System.out.println("\n 12. NON ho modificato l’oggetto puntato da specieTerrestre e specieKlingon perche' ha un diverso indirizzo: ");
        System.out.println(specieKlingon);
    }
}