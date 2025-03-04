#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int tentativi=0;

void alarmHandler(int sig) {
  printf("\nAllarme ricevuto e trattato\n");
  printf("Tempo scaduto! Devi essere più veloce! Non sono bastati %d tentativi...\n",tentativi);
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
	struct sigaction sa;
	int max;
	int time_limit;
	int numero;
	int n;

	if (argc != 3) {
		fprintf(stderr, "Uso del programma: 09-guess MAX_NUM TIME_LIMIT\n");
		exit(EXIT_FAILURE);
	}

	max=atoi(argv[1]);
	time_limit=atoi(argv[2]);

	srand(getpid());
	numero=rand()%max+1;

	//printf("---%d---\n", numero);


	bzero(&sa, sizeof(sa));
	sa.sa_handler = alarmHandler;
	if (sigaction (SIGALRM, &sa, NULL)==-1) {
    	printf("\nErrore della disposizione dell'handler\n");
    	exit(EXIT_FAILURE);
	}

	alarm(time_limit);

	printf("VIA!\n");

	do {
		printf("(%d) Inserisci un numero: ", tentativi+1);
		scanf("%d",&n);
		tentativi++;
		if (numero<n)
			printf("Il numero da indovinare è minore. Riprova.\n");
		else if (numero>n)
			printf("Il numero da indovinare è maggiore. Riprova.\n");
	} while(n!=numero);

	printf("Bravo! Il numero estratto è proprio %d. Lo hai indovinato in %d tentativi.\n", numero, tentativi);

	printf("FINE\n");

}
