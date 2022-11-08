/*
  * CS631 : APUE 
 * World's simplest shell.
 * Loops, reads input and tries to execute it.
 * Note: no tokenization, can be ^C'd, but does look at PATH
 *
 * ./simple-shell
 * $$ ls
 * $$ ls -l # error
 * $$ ^C
 *
 */

#include <sys/types.h>
#include <sys/wait.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>


/*
* Description : Get input from stdin and store into the buffer.
*/

char * getinput(char *buffer, size_t buflen) 
{
    printf("$<simple-Shell>$ ");
	/*
	 * fgets reads atmost one less than  character from the 'stream'.
	 * The reading of the stream stops either with EOF or new line.
	*/
    return fgets(buffer, buflen, stdin);
}



/*
 * This will execute ls but not ls -l
*/

int main(int argc, char **argv) 
{
    char buf[BUFSIZ];
    
	pid_t pid;
	int status;
	

	/* cast to void to silence compiler warnings */
	(void)argc;
	(void)argv;

	while (getinput(buf, sizeof(buf))) {
		
		
		// Put NULL char at the end of the string to terminate the string.

		buf[strlen(buf) - 1] = '\0';


        /* 
		 * fork 
		 * fork here creates a child process 
		 * Child process is created by duplicating the parent process.
		 * Child process has it's own PID.
		 * Further Reading :  man fork
		 */
		 
		/*
		 * pid of child process is returned in parents thread of execution 
		 * a 0 is returned in childs thread of execution. 
		*/ 
		if((pid=fork()) == -1) {

			/*
			 * printf write output to stdout
			 * frpintf write output to given output stream.
			 * Here we are writing to stderr stream.
			*/
			fprintf(stderr, "shell: can't fork: %s\n",
			        /*
					 * strerror : returns a pointer to string describing the error here
					 * errno : error number of last error.
					 */ 
					strerror(errno));

			continue;
		} else if (pid == 0) {   /* child */
		    /*
			 *  execute the file pointed by the buf
			*/
			execlp(buf, /* name of the file that is to be executed, here file is of type const char */ 
			       buf, /* Argument[0] , by convention this is same as file above.*/
				        /* Note here we donot have any arguments */
				   (char *)0); /*Last argument is always NULL*/

			fprintf(stderr, "shell: couldn't exec %s: %s\n", buf,
					strerror(errno));
			exit(EX_UNAVAILABLE);
		}

		/* 
		 * parent waits for the state change of the child.
		 * state change can be child being resumed or chid being terminated. 
		*/
		if ((pid=waitpid(pid, &status, 0)) < 0) {
			fprintf(stderr, "shell: waitpid error: %s\n",
					strerror(errno));
		}
	}

	exit(EX_OK);
}
