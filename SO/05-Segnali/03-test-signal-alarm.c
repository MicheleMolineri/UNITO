#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#if 1
#define HANDLE_ALRM /* handle division by zero */
#endif

#define TIME 7
#define STEP 1

int time=TIME;

#ifdef HANDLE_ALRM
void alarmHandler(int sig) {
  	printf("Allarme ricevuto e trattato\n");
  	time=TIME;
  	alarm(TIME);
}
#endif

int main() {
	struct sigaction sa;

#ifdef HANDLE_ALRM
	bzero(&sa, sizeof(sa)); /* set all bytes to zero */
	/* a pointer to the function handling the signal */
	sa.sa_handler = alarmHandler;
	/* Now, setting the handler */
	sigaction (SIGALRM, &sa, NULL);
#endif

	alarm(TIME);

	printf("Quindi\n");

  	while(1) {
    	printf("tic\n");
    	printf("mancano %d secondi\n",alarm(time-=STEP));
    	sleep(STEP);
  	};

  	printf("FINE\n");
}