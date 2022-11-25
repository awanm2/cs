/* This file is part of the sample code and exercises
 * used by the class "Advanced Programming in the UNIX
 * Environment" taught by Jan Schaumann
 * <jschauma@netmeister.org> at Stevens Institute of
 * Technology.
 *
 * This file is in the public domain.
 *
 * https://stevens.netmeister.org/631/
 */

/*
 * This simple program creates a file with a hole in it, a so-called
 * sparse file.  Use hexdump(1) or od(1) to verify that there is no data
 * in between the two strings; then copy the file to to another and
 * observe that the kernel supplied zeros to fill the hole.
 */

#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

#define BIGNUM 10240000

int
main(void) {
	int fd;
     
	 /*Create a file */
	if ((fd = creat("file.hole", S_IRUSR | S_IWUSR)) < 0) {
		perror("creat error");
		return EXIT_FAILURE;
	}

    /*write buf1 the ten bytes*/
	if (write(fd, buf1, strlen(buf1)) != sizeof(buf1) - 1) {
		perror("error writing buf1");
		return EXIT_FAILURE;
	}

    /*Now lseek beyond end of file*/
	if (lseek(fd, BIGNUM, SEEK_CUR) == -1) {
		perror("lseek error");
		return EXIT_FAILURE;
	}
    /* Now write the second buffer of ten bytes to the seeked
	 * position. 
	 */
	if (write(fd, buf2, strlen(buf2)) != sizeof(buf2) - 1) {
		perror("error writing buf2");
		return EXIT_FAILURE;
	}

	/*wait a little bit*/
	sleep(30);

	(void)close(fd);
	return EXIT_SUCCESS;
}
