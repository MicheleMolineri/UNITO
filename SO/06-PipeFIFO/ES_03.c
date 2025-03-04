#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid1, pid2;
    
    // Creazione della pipe prima delle fork
    if (pipe(pipefd) == -1) {
        perror("Errore nella creazione della pipe");
        exit(EXIT_FAILURE);
    }
    
    // Creazione del primo figlio (scrittore)
    pid1 = fork();
    
    if (pid1 == -1) {
        perror("Errore nella prima fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid1 == 0) {  // Primo figlio (scrittore)
        close(pipefd[0]);  // Chiude l'end di lettura
        
        const char *messaggio = "Ciao dal primo fratello!";
        write(pipefd[1], messaggio, strlen(messaggio) + 1);  // +1 per includere il terminatore
        
        printf("Primo figlio: Ho inviato il messaggio\n");
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }
    
    // Il padre crea il secondo figlio (lettore)
    pid2 = fork();
    
    if (pid2 == -1) {
        perror("Errore nella seconda fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid2 == 0) {  // Secondo figlio (lettore)
        close(pipefd[1]);  // Chiude l'end di scrittura
        
        char buffer[100];
        ssize_t bytes_letti = read(pipefd[0], buffer, sizeof(buffer));
        
        if (bytes_letti > 0) {
            printf("Secondo figlio: Ho ricevuto il messaggio: '%s'\n", buffer);
        }
        
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
    
    // Processo padre
    // Chiude entrambi gli end della pipe poiché non li usa
    close(pipefd[0]);
    close(pipefd[1]);
    
    // Attende la terminazione di entrambi i figli
    wait(NULL);
    wait(NULL);
    
    printf("Padre: Entrambi i figli hanno terminato\n");
    
    return EXIT_SUCCESS;
}