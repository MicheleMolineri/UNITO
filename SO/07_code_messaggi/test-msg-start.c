#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define TEXT_LEN 32
#define NUM_RECS 100
#define MY_KEY  384756
#define TEST_ERROR    if (errno) {fprintf(stderr,			\
					  "%s:%d: PID=%5d: Error %d (%s)\n", \
					  __FILE__,			\
					  __LINE__,			\
					  getpid(),			\
					  errno,			\
					  strerror(errno));}

/* Struttura del record aggiunto da ogni processo */
struct record {
	pid_t  sender;
	char text[TEXT_LEN];
};

/* Struttura del messaggio */
struct message {
	long mtype;                   /* type of message */
	unsigned int num_recs;        /* number of records */
	struct record msg_list[NUM_RECS];
};


int main()
{
	char * s;
	struct timespec now;
	int queue_id;
	struct message my_msg;

	/*
	 * Crea la cosa di messaggi. Se per caso ci fosse gia` una
	 * coda con quella chiave, allora ritorna -1 a causa del flag
	 * IPC_EXCL.
	 */
	queue_id = msgget(MY_KEY, IPC_CREAT | IPC_EXCL| 0666);
	TEST_ERROR;

	/* 
	 * Aspetta che i vari processi siano partiti prima di spedire
	 * il primo messaggio.
	 */
	sleep(10);

	/*
	 * Prepara e spedisci il primo messaggio
	 */
	my_msg.mtype = getpid();
	my_msg.num_recs = 0;
	if (msgsnd(queue_id, &my_msg, sizeof(my_msg)-sizeof(long), 0) == -1) {
		TEST_ERROR;
	}
}
