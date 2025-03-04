#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2]; // array di due interi per i descrittori della pipe
    pid_t pid;
    
    if (pipe(pipefd) == -1) {
        perror("Errore nella creazione della pipe");
        exit(EXIT_FAILURE);
    }
    
    pid = fork();
    
    if (pid == -1) {
        perror("Errore nella fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid > 0) {  // Processo padre (scrittore)
        close(pipefd[0]);  // Chiude l'end di lettura
        
        int n = 0;
        // Scrive 10 numeri nella pipe
        for(int i = 0; i < 10; i++) {
            write(pipefd[1], &n, sizeof(n));
            printf("PADRE: ho scritto n = %d\n", n);
            n++;
            // Piccola pausa per sincronizzazione
            sleep(1);  // 100ms
        }
        
        close(pipefd[1]);  // Chiude l'end di scrittura
        wait(NULL);  // Aspetta che il figlio termini
        printf("Padre: Processo terminato\n");
    }
    else {  // Processo figlio (lettore)
        close(pipefd[1]);  // Chiude l'end di scrittura
        
        int number;
        // Legge fino a quando la pipe viene chiusa
        for(int i = 0; i < 10; i++) {
            ssize_t bytes_letti = read(pipefd[0], &number, sizeof(number));
            
            if (bytes_letti > 0) {
                printf("Figlio: Numero ricevuto: %d\n", number);
                sleep(1); 

            }
        }
        
        close(pipefd[0]);  // Chiude l'end di lettura
        printf("Figlio: Processo terminato\n");
        exit(EXIT_SUCCESS);
    }
    
    return EXIT_SUCCESS;
}