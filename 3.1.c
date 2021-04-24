#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>


int main(void){
	
	void sigquit_handler(int quit);
	void sigtstp_handler(int tstp);
	void sigint_handler(int sig);
	char s[200];

	if(signal(SIGQUIT,sigquit_handler) == SIG_ERR){
		perror("signal");
		exit(1);
	}
	if(signal(SIGTSTP,sigtstp_handler) == SIG_ERR){
		perror("signal");
		exit(1);
	}
	if(signal(SIGINT,sigint_handler) == SIG_ERR){
		perror("signal");
		exit(1);
	}

	printf("Enter a string:\n");

	if(fgets(s,200,stdin) == NULL)
		perror("gets");
	else
		printf("You have entered: %s\n",s);

	return 0;
	}

	void sigquit_handler(int quit){
		printf("This is a special handler for SIGQUIT\n");
		}
	void sigtstp_handler(int tstp){
		printf("This is a special signal handler for SIGTSTP\n");
		}

	void sigint_handler(int sig){
		printf("This is a special signal handler for SIGINT\n");
		}




