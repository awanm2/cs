
/*
  * CS631 APUE - Week -02
 * This trivial program illustrates how to open files.  We present the
 * following use cases:
 *
 * - create a non-existent file
 * - "create" an existing file
 * - fail to create an existing file
 * - open an existing file
 * - fail to open a non-existing file
 * - truncate an existing file
 */

#include <sys/stat.h>

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef SLEEP
#define SLEEP 10
#endif


/**
 * @brief Create a File object, but donot close the file descriptor.
 * 
 */

void createFile(void) {
    int fd; // File descriptor is just an integer. 
   
    printf("Checking if './newfile' exists...\n");
    /* system : execute a shell command */
    int rvalSys = system("ls -l ./newfile");
    printf("Trying to create './newfile' with O_RDONLY | O_CREAT...\n");

    /*
     * open : const char * pathname , int flags, mode_t  
     */
    if((fd = open("./newfile", O_RDONLY | O_CREAT, S_IRUSR|S_IWUSR)) == -1){
        fprintf(stderr, "Unable to create './newfile': %s\n ", strerror(errno));
        exit(EXIT_FAILURE);
    }

   printf("'./newfile' created. File descriptor is: %d\n", fd);

	/* We are leaking a file descriptor here to illustrate that they
	 * are increasing as we open more files.  Normally, we would call
	 * close(2) whenever we're done using the decriptor. */

}

/**
 * @brief 
 * 
 */

void failExclFileCreation() {
	int fd;

	printf("Checking if './newfile' exists...\n");
	int rvalSys = system("ls -l ./newfile");
	printf("Trying to create './newfile' with O_RDONLY | O_CREAT | O_EXCL...\n");

    /*If both O_CREAT and O_EXCL are set, then open fails if the specified file already exists.*/
	if ((fd = open("./newfile", O_RDONLY | O_CREAT | O_EXCL,
					S_IRUSR | S_IWUSR)) == -1) {
		fprintf(stderr, "Unable to create './newfile': %s\n",
				strerror(errno));
	}

	/* We expect this to fail! */
	if (close(fd) == -1) {
		fprintf(stderr, "Closing failed: %s\n", strerror(errno));
	}
}


void 
failOpenNonexistingFile() {
	int fd;
 
	printf("Trying to open (non-existant) './nosuchfile' with O_RDONLY...\n");

	if ((fd = open("./nosuchfile", O_RDONLY)) == -1) {
		fprintf(stderr, "Unable to open './nosuchfile': %s\n",
				strerror(errno));
	}

	/* We know this is going to fail, but no need to complain. */
	(void)close(fd);
}

/**
 * @brief : open a file in read only mode.
 */

void openFile() {
	int fd;

	printf("Trying to open './openex.c' with O_RDONLY...\n");
  
	if ((fd = open("./openex.c", O_RDONLY)) == -1) {
		fprintf(stderr, "Unable to open './openex.c': %s\n",
				strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("'./openex.c' opened. File descriptor is: %d\n", fd);

	if (close(fd) == 0) {
		printf("'./openex.c' closed again\n");
	}
}

void truncateFile() {
	int fd;

	int rvalSys = system("cp openex.c newfile");
	printf("Copied 'openex.c' to 'newfile'.\n");
	rvalSys = system("ls -l newfile");

	printf("Trying to open './newfile' with O_RDONLY | O_TRUNC...\n");
    
	/*Truncate the file to zero length. This option is only useful for regular files*/
	if ((fd = open("./newfile", O_RDONLY | O_TRUNC)) == -1) {
		fprintf(stderr, "Unable to open './newfile': %s\n",
				strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("'./newfile' opened. File descriptor is: %d\n", fd);
	printf("'./newfile' truncated -- see 'ls -l newfile'\n");
	rvalSys = system("ls -l newfile");

	(void)close(fd);
}



int
main() {

    printf("--1-- Create a file\n");
	createFile();
	int rvalSys =  system("ls -l newfile");
	printf("\n");
	sleep(SLEEP);

    printf("--2-- Try to create the file we created previously \n");

	createFile();
	rvalSys = system("ls -l newfile");
	printf("\n");
	sleep(SLEEP);

    printf("--3-- Try to create the file we created previously with O_EXCL\n");

	failExclFileCreation();
	printf("\n");
	sleep(SLEEP);

    printf("--4-- Open a file\n");

	openFile();
	printf("\n");
	sleep(SLEEP);

    printf("--5-- Open a non existing file\n");


	failOpenNonexistingFile();
	printf("\n");
	sleep(SLEEP);

    printf("--6-- Truncate a file\n");

	truncateFile();

	return 0;
}