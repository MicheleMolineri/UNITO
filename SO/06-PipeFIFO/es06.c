#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#include <limits.h>

#define NUM_KIDS 5       // Numero di processi figli
#define NUM_MAX 100      // Numero massimo estraibile

// Struttura per gestire i dettagli dei figli
typedef struct {
    pid_t pid;           // PID del figlio
    int pipe_fd;         // Descrittore di lettura della pipe
    int last_number;     // Ultimo numero estratto
} ChildInfo;

// Dichiarazione delle funzioni
void child_process(int write_pipe, int child_index);
void parent_process(ChildInfo children[], int num_children);

int main() {
    int pipes[NUM_KIDS][2];
    ChildInfo children[NUM_KIDS];

    printf("[PADRE] Inizio programma di comunicazione tra processi\n");

    // Inizializzazione del generatore di numeri casuali del padre
    srand(time(NULL));

    // Creazione delle pipe
    for (int i = 0; i < NUM_KIDS; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("Errore nella creazione della pipe");
            exit(1);
        }
    }

    // Fork dei processi figli
    for (int i = 0; i < NUM_KIDS; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("Errore nella fork");
            exit(1);
        }

        if (pid == 0) {
            // Processo figlio
            // Chiudi pipe non utilizzate
            for (int j = 0; j < NUM_KIDS; j++) {
                if (j != i) {
                    close(pipes[j][0]);
                    close(pipes[j][1]);
                }
            }

            printf("[FIGLIO %d] Processo figlio creato. PID: %d\n", i, getpid());
            
            // Passa l'indice del figlio per un seed diverso
            child_process(pipes[i][1], i);
            exit(0);
        } else {
            // Processo padre
            close(pipes[i][1]);  // Chiudi lato scrittura
            children[i].pid = pid;
            children[i].pipe_fd = pipes[i][0];
            children[i].last_number = -1;
        }
    }

    // Processo padre
    printf("[PADRE] Avvio comunicazione con %d figli\n", NUM_KIDS);
    parent_process(children, NUM_KIDS);

    // Attendi la terminazione di tutti i figli
    for (int i = 0; i < NUM_KIDS; i++) {
        waitpid(children[i].pid, NULL, 0);
        printf("[PADRE] Figlio %d terminato\n", i);
    }

    printf("[PADRE] Tutti i figli terminati. Fine programma.\n");
    return 0;
}

void child_process(int write_pipe, int child_index) {
    int random_num;
    sigset_t mask, original_mask;

    // Usa un seed diverso per ogni figlio basato sul suo indice e PID
    // Questo garantisce numeri casuali diversi per ogni figlio
    srand(time(NULL) + getpid() + child_index * 1000);

    // Maschera tutti i segnali
    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, &original_mask);

    while (1) {
        // Estrai un numero casuale
        random_num = rand() % (NUM_MAX + 1);

        printf("[FIGLIO %d - PID %d] Estratto numero: %d\n", child_index, getpid(), random_num);

        // Invia il numero al padre
        write(write_pipe, &random_num, sizeof(int));

        // Aspetta un segnale con sigsuspend
        printf("[FIGLIO %d - PID %d] In attesa di segnale...\n", child_index, getpid());
        sigsuspend(&original_mask);

        // Se arriva SIGINT, termina
        if (sigismember(&original_mask, SIGINT)) {
            printf("[FIGLIO %d - PID %d] Ricevuto SIGINT. Termino.\n", child_index, getpid());
            close(write_pipe);
            exit(0);
        } else if (sigismember(&original_mask, SIGUSR1)) {
            printf("[FIGLIO %d - PID %d] Ricevuto SIGUSR1. Continuo.\n", child_index, getpid());
        }
    }
}

void parent_process(ChildInfo children[], int num_children) {
    int min_num, min_index;
    int numbers[num_children];

    // Leggi i numeri da tutti i figli
    for (int i = 0; i < num_children; i++) {
        read(children[i].pipe_fd, &numbers[i], sizeof(int));
        children[i].last_number = numbers[i];
        printf("[PADRE] Ricevuto numero %d dal figlio %d (PID: %d)\n", 
               numbers[i], i, children[i].pid);
    }

    // Trova l'indice del numero minimo
    min_num = numbers[0];
    min_index = 0;
    for (int i = 1; i < num_children; i++) {
        if (numbers[i] < min_num) {
            min_num = numbers[i];
            min_index = i;
        }
    }

    printf("[PADRE] Numero minimo: %d (estratto dal figlio %d)\n", min_num, min_index);

    // Gestisci i casi di ex-equo (scegli il primo)
    for (int i = 0; i < num_children; i++) {
        if (i == min_index) {
            // Invia SIGINT al figlio con numero minimo
            printf("[PADRE] Invio SIGINT al figlio %d (PID: %d)\n", i, children[i].pid);
            kill(children[i].pid, SIGINT);
        } else {
            // Invia SIGUSR1 agli altri figli
            printf("[PADRE] Invio SIGUSR1 al figlio %d (PID: %d)\n", i, children[i].pid);
            kill(children[i].pid, SIGUSR1);
        }
    }

    // Ripeti il processo finché tutti i figli non sono terminati
    while (1) {
        int active_children = 0;
        
        // Leggi nuovi numeri
        for (int i = 0; i < num_children; i++) {
            if (children[i].last_number != -1) {
                read(children[i].pipe_fd, &numbers[i], sizeof(int));
                children[i].last_number = numbers[i];
                printf("[PADRE] Ricevuto nuovo numero %d dal figlio %d (PID: %d)\n", 
                       numbers[i], i, children[i].pid);
                active_children++;
            }
        }

        // Se non ci sono più figli attivi, esci
        if (active_children == 0) {
            printf("[PADRE] Nessun figlio attivo. Termine ciclo.\n");
            break;
        }

        // Trova il numero minimo tra i figli attivi
        min_num = INT_MAX;
        min_index = -1;
        for (int i = 0; i < num_children; i++) {
            if (children[i].last_number != -1 && 
                children[i].last_number < min_num) {
                min_num = children[i].last_number;
                min_index = i;
            }
        }

        printf("[PADRE] Nuovo numero minimo: %d (estratto dal figlio %d)\n", min_num, min_index);

        // Gestisci i casi di ex-equo
        for (int i = 0; i < num_children; i++) {
            if (i == min_index) {
                kill(children[i].pid, SIGINT);
                printf("[PADRE] Invio SIGINT al figlio %d (PID: %d)\n", i, children[i].pid);
                children[i].last_number = -1;
            } else if (children[i].last_number != -1) {
                kill(children[i].pid, SIGUSR1);
                printf("[PADRE] Invio SIGUSR1 al figlio %d (PID: %d)\n", i, children[i].pid);
            }
        }
    }

    // Chiudi le pipe
    for (int i = 0; i < num_children; i++) {
        close(children[i].pipe_fd);
    }
}