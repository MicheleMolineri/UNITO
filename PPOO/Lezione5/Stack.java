
// Classe per modellare uno stack di interi con capacita' non 
// modificabile. Deve essere pubblica, trattandosi di una libreria
// La salviamo in Stack.java

public class Stack {
 private int[] stack;// inizialmente stack e' l’array vuoto (null), 
//non fissiamo subito una massima dimensione per tutti gli stack
 private int size=0;
// size=numero elementi inseriti: chiediamo 0 <= size <= stack.length
 					
public Stack(int capacity){
 assert capacity >= 0: 
 "la capacita' dello stack doveva essere >=0 invece vale" + capacity;

 /* Notate che la falsita' della condizione capacity >=0 non dipende da un eventuale errore di programmazione (della libreria Stack stessa o del codice Client), ma da un eventuale dato errato inserito da chi usa il programma. Questa condizione, in particolare, dovrà essere gestita in modo che il programma non fallisca a runtime se vengono inseriti dati sbagliati. A tal fine impareremo a usare il meccanismo delle 'eccezioni'. Per ora, ci concentriamo a trovare i casi in cui un programma potrebbe fallire a runtime e usiamo le assert come primo meccanismo per segnalare questi casi di errore a tempo di esecuzione. */

 // Adesso fissiamo: massimo numero elementi stack = capacity
 stack = new int[capacity];
 // size = numero di elementi inseriti; all'inizio e' 0
 size = 0;
}

// È conveniente mettere a disposizione due operazioni per sapere
// se lo stack e' vuoto o pieno. Cio' consente all'utilizzatore
// dello stack di sapere quando un'operazione push/pop e' lecita

public boolean empty(){ return size == 0; }

public boolean full() { return size == stack.length; }

public void push(int x){
 assert !full(): 
 "tentativo push in uno stack pieno di elementi: " + size;
 stack[size] = x; size++;
}

 public int pop(){
  assert !empty():
  "tentativo pop da uno stack vuoto";
  --size; return stack[size];
}

/** Per fare esperimenti con gli stack, definiamo un metodo equals 
che controlla se due stack sono identici in tutto: stessa capienza, 
stesso numero size di elementi utilizzati, stessi elementi tra quelli 
di indice 0, ..., size-1. In questo modo possiamo controllare se uno 
stack contiene gli elementi che dovrebbe contenere */
 public boolean equals(Stack altroStack){
   if (this.size != altroStack.size) return false;
  if (this.stack.length != altroStack.stack.length) return false;
    int i=0;
    // while (i<stack.length) sarebbe scorretto! La dimensione 
    // dello stack e' size, non l’intera lunghezza del vettore stack:
    while (i<size){
      if ((this.stack)[i] != (altroStack.stack)[i]) return false;
      i++;
    }
    return true;
   }
}
