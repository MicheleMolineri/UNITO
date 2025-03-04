class Animal {
    private String nome;
    private int eta;
    private double peso;

    public Animal() {
        nome = "nessun nome";
        eta = 0;
        peso = 0;
    }

    public Animal(String n, int e, double p) {
        nome = n;
        eta = e;
        peso = p;
    }

    public void setAnimal(String n, int e, double p) {
        nome = n;
        eta = e;
        peso = p;
    }

    public String getNome() {
        return nome;
    }

    public int getEta() {
        return eta;
    }

    public double getPeso() {
        return peso;
    }

    public void setNome(String n) {
        nome = n;
    }

    public void setEta(int e) {
        if (e >= 0)
            eta = e;
        else
            System.out.println("L'eta' deve essere non negativa");
    }

    public void setPeso(double p) {
        if (peso >= 0)
            peso = p;
        else
            System.out.println("Il peso deve essere non negativo");
    }

    public String toString() {
        return " nome " + nome + "\n eta'  " + eta + "\n peso " + peso;
    }

    public void assegna(Animal altroAnimale) {
        this.nome = altroAnimale.nome;
        this.eta = altroAnimale.eta;
        this.peso = altroAnimale.peso;
    }

    public boolean equals(Animal altroAnimale) {
        return (this.nome.equalsIgnoreCase(altroAnimale.nome))
                && (this.eta == altroAnimale.eta)
                && (this.peso == altroAnimale.peso);
    }
}

public class AnimalDemo {
    public static void main(String[] args) {
        Animal tramot = new Animal("Tramot", 10, 5.0);
        Animal galileo = new Animal();

        System.out.println("1. Tramot");
        System.out.println(tramot);
        System.out.println("2. Galileo");
        System.out.println(galileo);
        System.out.println("3. Tramot e' uguale a Galileo?" + tramot.equals(galileo));
        System.out.println("4. Assegno gli attributi di Tramot a Galileo ");
        galileo.assegna(tramot);
        System.out.println("5. Tramot e' uguale a Galileo?" + tramot.equals(galileo));
        System.out.println("6. Tramot == Galileo? " + (tramot == galileo));
    }
}