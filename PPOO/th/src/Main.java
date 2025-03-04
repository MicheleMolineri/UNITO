import java.util.Scanner;

public class SpecieNuovaDemo {

    // Metodo per mettere in pausa l'esecuzione fino alla pressione di Invio
    private static void pause() {
        Scanner tastiera = new Scanner(System.in);
        System.out.println("............. premi Invio per continuare");
        tastiera.nextLine();
        // Chiudere Scanner potrebbe chiudere System.in, quindi evitiamo di chiuderlo qui
    }

    public static void main(String[] args) {
        SpecieNuova specieTerrestre = new SpecieNuova(); // Primo oggetto
        System.out.println("\n 1. Inserisco specieTerrestre usando un metodo di set");
        specieTerrestre.setSpecie("Bufalo Nero", 500, 3);

        System.out.println("\n 2. Dati inseriti specieTerrestre");
        System.out.println(specieTerrestre);
        pause();

        SpecieNuova specieKlingon = new SpecieNuova(); // Secondo oggetto
        System.out.println("\n 3. Inserisco specieKlingon usando un metodo di set");
        specieKlingon.setSpecie("Bufalo Klingon", 1000, 10);

        System.out.println("\n 4. Dati inseriti specieKlingon");
        System.out.println(specieKlingon);
        pause();

        System.out.println("\n 5. Assegno specieTerrestre = specieKlingon");
        specieTerrestre = specieKlingon;
        System.out.println("Ora le due variabili puntano allo stesso oggetto:");
        System.out.println(specieTerrestre);
        System.out.println(specieKlingon);

        System.out.println("\n 6. Per rendermi conto che le due variabili sono un alias dello stesso oggetto: ");
        System.out.println("se modifico la specieTerrestre in Elefante, modifico anche il Klingon");
        specieTerrestre.setSpecie("Elefante", 100, 2);
        System.out.println(specieTerrestre);
        System.out.println(specieKlingon);
        pause();

        System.out.println("\n 7. Vediamo ora un altro modo di modificare gli oggetti");
        System.out.println("Creo \"specieAfricana\" e le assegno i valori di Elefante");
        SpecieNuova specieAfricana = new SpecieNuova(); // Terzo oggetto
        specieTerrestre.cambia(specieAfricana);
        System.out.println(specieAfricana);
        pause();

        System.out.println("\n 8. La prima e la seconda variabile puntano allo stesso oggetto: (specieTerrestre == specieKlingon) vale: "
                + (specieTerrestre == specieKlingon));

        System.out.println("\n 9. Invece la prima e la terza variabile no: (specieTerrestre == specieAfricana) vale: "
                + (specieTerrestre == specieAfricana));

        System.out.println("\n 10. Pero' gli attributi degli oggetti puntati dalle due variabili hanno gli stessi valori: (specieTerrestre.equals(specieAfricana)) vale: "
                + (specieTerrestre.equals(specieAfricana)));
        pause();

        System.out.println("\n 11. Una controprova: modifico la specieAfricana in Elefante Africano.");
        specieAfricana.setSpecie("Elefante Africano", 100, 2);
        System.out.println(specieAfricana);

        System.out.println("\n 12. NON ho modificato l’oggetto puntato da specieTerrestre e specieKlingon perche' ha un diverso indirizzo: ");
        System.out.println(specieKlingon);
    }
}