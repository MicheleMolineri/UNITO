class Calcolatrice {
    private int[] stack = new int[100];
    private int size = 0;

    private void push(int x) {
        stack[size] = x;
        size++;
    }

    private int pop() {
        size--;
        return stack[size];
    }

    public int esegui(String istruzioni) {
        int numeroIstruzioni = istruzioni.length();
        int pc = 0;
        while (pc < numeroIstruzioni) {
            char c = istruzioni.charAt(pc);
            if (c >= '0' && c <= '9') {
                push(c - '0');
            } else if (c == '+') {
                int ultimo = pop();
                int penultimo = pop();
                push(penultimo + ultimo);
            } else if (c == '*') {
                int ultimo = pop();
                int penultimo = pop();
                push(penultimo * ultimo);
            }
            pc++;
        }
        return pop();
    }
}

public class CalcolatriceDemo {
    public static void main(String[] args) {
        Calcolatrice C = new Calcolatrice();

        System.out.println("Eseguo istruzioni 23+ (due piu' tre) ");
        System.out.println(C.esegui("23+") + "\n");

        System.out.println("Eseguo istruzioni 23* (due  per tre) ");
        System.out.println(C.esegui("23*") + "\n");

        System.out.println("Eseguo istruzioni 23*9+ (due  per tre piu' nove) ");
        System.out.println(C.esegui("23*9+") + "\n");

        System.out.println("Eseguo istruzioni 99*9* (nove per nove per nove) ");
        System.out.println(C.esegui("99*9*") + "\n");

        System.out.println("Eseguo istruzioni 99*9*1+ (nove per nove per nove piu' uno) ");
        System.out.println(C.esegui("99*9*1+") + "\n");
    }
}