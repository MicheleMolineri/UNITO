#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <signal.h>

#if 0
#define HANDLE_FPE /* handle division by zero */
#endif

#define ARM

#ifdef HANDLE_FPE
void my_handler(int signum) {
	printf("Could handle signal %d (\"%s\") here\n", signum, strsignal (signum));
}
#endif

int main() {
	int num = 10, den = 0;
	struct sigaction sa;

#ifdef HANDLE_FPE
	bzero(&sa, sizeof(sa)); /* set all bytes to zero */
	/* a pointer to the function handling the signal */
	sa.sa_handler = my_handler;
	/* Now, setting the handler */
	sigaction (SIGFPE, &sa, NULL);
#endif

	printf("%d divided by %d is\n", num, den);
	num = num/den;
#ifdef ARM
	if (den==0)
		raise(SIGFPE);
#endif
	printf("%d\n", num);
	return 0;
}