/*
 * Utilizzo del gioco:
 *
 * (1) modifica la stringa MY_PERSONAL_STRING con qualcosa di
 * personale
 *
 * (2) compila con:
 *
 *     gcc test-rcv-snd.c -o test-rcv-snd -lrt
 * 
 * (3) quando il docente ha creato la coda e ti avvisera` di averlo
 * fatto. A quel punto esegui con:
 *
 *     ./test-rcv-snd
 */

#define MY_PERSONAL_STRING "CIAO"


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

/*
 * Si vuole far circolare fra vari utenti un unico messaggio di tipo
 * "struct message". Questo messaggio ha un campo rec_list che
 * contiene num_recs record. Il processo inizia rimanendo in attesa di
 * ricevere il messaggio. Quando lo riceve, aggiunge un suo record
 * alla lista di record rec_list, incrementa num_recs e poi
 * spedisce. Il formato di un record e` descritto dalla "struct
 * record". Un record contiene il PID del processo che lo ha scritto e
 * una stringa. Per il momento la stringa contiene il timestamp di
 * quando il record e` stato scritto.
 */

/* Struttura del record aggiunto da ogni processo */
struct record {
	pid_t  sender;
	char text[TEXT_LEN];
};

/* Struttura del messaggio */
struct message {
	long mtype;                   /* type of message */
	unsigned int num_recs;        /* number of records */
	struct record rec_list[NUM_RECS];
};


int main()
{
	char * s;
	struct timespec now;
	int queue_id, i;
	struct message my_msg;

	/* 
	 * Ottieni  l'ID di  una  message queue  attraverso la  chiave
	 * condivisa  MY_KEY. La  queue  deve essere  stata creata  da
	 * altri, altrimenti la msgget ritorna -1
	 */
	queue_id = msgget(MY_KEY, 0666);
	TEST_ERROR;
	/* Forever loop: usciremo dall'interno */
	while (1) {
		/* Ricevi (e cancella) il primo messaggio della coda */
		if (msgrcv(queue_id,
			   &my_msg,
			   sizeof(my_msg)-sizeof(long),
			   0, 0) == -1) {
			/* msgrcv failed!! */
			if (errno == EIDRM) {
				/* 
				 * La  coda  e` stata  cancellata  dal
				 * processo che ha trovato l'elenco di
				 * records pieno. Dobbiamo uscire.
				 */
				return 0;
			} else {
				/* Altri errori: inaspettato.
				 * Se accade dobbiamo approfondire
				 */
				TEST_ERROR;
				return 0;
			}
		}

		/* Print type of received message */
		printf("\nGot message of type (= PID of sender)\n%ld\n",
		       my_msg.mtype);
		/* Print content of the list of records retrieved in
		 * the received message */
		for (i=0; i<my_msg.num_recs; i++) {
			printf("%4d: %10d --> \"%s\"\n",
			       i,
			       my_msg.rec_list[i].sender,
			       my_msg.rec_list[i].text);
		}

		/* Check if table is full. Erase the queue if so */
		if (my_msg.num_recs >= NUM_RECS) {
			printf("List of records is full: removing the queue!\n");
			msgctl(queue_id, IPC_RMID, NULL);
			return 0;
		}

		/* Add a new record to the table */
		my_msg.rec_list[my_msg.num_recs].sender = getpid();
		clock_gettime(CLOCK_REALTIME ,&now);
		snprintf(my_msg.rec_list[my_msg.num_recs].text,
			 TEXT_LEN,
			 "%ld,%09ld %s",
			 now.tv_sec, now.tv_nsec, MY_PERSONAL_STRING);
		my_msg.mtype = getpid();
		my_msg.num_recs++;

		/* Sending the new message */
		if (msgsnd(queue_id, &my_msg, sizeof(my_msg)-sizeof(long), 0) == -1) {
			TEST_ERROR;
		}
	}  /* end while(1) */
}
