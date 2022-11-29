 /**
  * CS 631 APUE W02 
  * https://stevens.netmeister.org/631
  */
 
 /**
 * @file simpleCopy.c
 * @author 
 * @brief A simple copy program. copies from STDIN to STDOUT
 * @version 0.1
 * @date 2022-11-25
 * 
 * @
 * 
 */

 #include <errno.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

#define BUFF_SIZE 4096

int main (void)
{
    int n;

    /*Our local buffer on the stack*/
    char buf[BUFF_SIZE]; 
    /*Read from STDIN to buf */ 
    while( (n = read( STDIN_FILENO, buf, BUFF_SIZE)) > 0)
    {  
        /* */
        if(n < 0)
        {
            exit(EXIT_SUCCESS);
        }
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            fprintf(stderr, "Unable to write %d bytes %s ", n, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }
    
    exit(EXIT_SUCCESS);

}