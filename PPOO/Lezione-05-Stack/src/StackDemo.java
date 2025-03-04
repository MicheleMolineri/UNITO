// StackDemo.java  (sperimentiamo la classe Stack)
public class StackDemo {
    public static void main(String[] args) {
        Stack s = new Stack(3), t = new Stack(3);
        System.out.println("s,t stacks con capacita' 3 entrambi vuoti");
        s.push(10);
        s.push(20);
        s.push(30);
        System.out.println("s={10,20,30} pieno, diverso da t={} vuoto");
        System.out.println(" s.full()    = " + s.full());
        System.out.println(" s.empty()   = " + s.empty());
        System.out.println(" s.equals(t) = " + s.equals(t));

        System.out.println("Eliminiamo uno alla volta gli elementi in s");
        System.out.println(" s.pop() = " + s.pop());
        System.out.println(" s.pop() = " + s.pop());
        System.out.println(" s.pop() = " + s.pop());

        System.out.println("Adesso s e' vuoto e uguale a t");
        System.out.println(" s.full()    = " + s.full());
        System.out.println(" s.empty()   = " + s.empty());
        System.out.println(" s.equals(t) = " + s.equals(t));

        System.out.println("Pongo s={40,50} e t={40,60}: s,t diversi");
        s.push(40);
        s.push(50);
        t.push(40);
        t.push(60);
        System.out.println(" s.full()    = " + s.full());
        System.out.println(" s.empty()   = " + s.empty());
        System.out.println(" s.equals(t) = " + s.equals(t));

        Stack r = new Stack(3);
        r.push(0);
        r.push(0);
        r.push(0);
        Stack q = new Stack(3);
        System.out.println("r non è vuoto!");
        System.out.println(" r.full()    = " + r.full());
        System.out.println(" r.empty()   = " + r.empty());
        System.out.println(" r.equals(q) = " + r.equals(q));
    /* LO STACK r contiene 3 elementi, tutti uguali a 0;
       LO STACK q non contiene elementi (il suo array 'stack'
       contiene 3 zeri ma non sono raggiungibili, perché la sua size è 0).
     */
    }
}
