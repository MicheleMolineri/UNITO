#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>

/* 
Scrivere un semplice programma che crei una pipe, chiudendo i file descriptors
inutilizzati nei due processi che seguono dopo una fork(). 
Il padre deve essere configurato come scrittore ed il figlio come lettore. 
*/

int main() {
    int pipefd[2];  // Array per i file descriptors della pipe
    pid_t pid;
    
    // Creazione della pipe
    if (pipe(pipefd) == -1) {
        perror("Errore nella creazione della pipe");
        exit(EXIT_FAILURE);
    }
    
    // Creazione del processo figlio
    pid = fork();
    
    if (pid == -1) {
        perror("Errore nella fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid > 0) {  // Processo padre (scrittore)
        // Chiude l'end di lettura perché non serve al padre
        close(pipefd[0]);
        
        // Esempio di scrittura nella pipe
        const char *messaggio = "Hello dal processo padre!";
        write(pipefd[1], messaggio, strlen(messaggio));
        
        // Chiude l'end di scrittura quando ha finito
        close(pipefd[1]);
        
        // Aspetta che il figlio termini
        wait(NULL);
        
        printf("Padre: Messaggio inviato e processo terminato\n");
    }
    else {  // Processo figlio (lettore)
        // Chiude l'end di scrittura perché non serve al figlio
        close(pipefd[1]);
        
        // Legge dalla pipe
        char buffer[100];
        ssize_t bytes_letti = read(pipefd[0], buffer, sizeof(buffer));
        
        if (bytes_letti > 0) {
            buffer[bytes_letti] = '\0';  // Termina la stringa
            printf("Figlio: Messaggio ricevuto: %s\n", buffer);
        }
        
        // Chiude l'end di lettura quando ha finito
        close(pipefd[0]);
        
        printf("Figlio: Processo terminato\n");
    }
    
    return EXIT_SUCCESS;
}