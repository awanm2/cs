/*
 * This program illustrates the usefulness of openat(2) to avoid
 * certain race conditions:
 *
 * Assume that you want to open the files "file1" and "file2" found
 * in the directory "../dir".  You might start out using
 *
 * fd1 = open("../dir/file1", ...)
 * fd2 = open("../dir/file2", ...)
 * 
 * Race condition : 
 * However, in between these two calls, another process might have
 * renamed the directory "../dir" to "../dir2", then created "../dir"
 * and placed a different file named "file2" into it.  Your program
 * now has opened two files from two different directories.
 *
 * With openat(2), you could guarantee that the call to open "file2"
 * will use the same directory as the call to open "file1":
 *
 * dfd = open("../dir/", O_DIRECTORY ...)
 * fd1 = openat(dfd, "file1", ...)
 * fd2 = openat(dfd, "file2", ...)
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief : systemLocal is a wrapper around the system call
 *          if there is an error, we put the error on the 
 * 
 * @param command 
 */
void systemLocal(const char *command)
{
	if(system(command) == -1){
        fprintf(stderr, "Unable to execute the command : %s  error :  %s\n ",command,  strerror(errno));
        exit(EXIT_FAILURE);
    }

}

/**
 * @brief read data from a given file descriptor.
 * 
 * @param fd 
 */

void readData(int fd) {
	int n;
	char buf[BUFSIZ];
	memset(buf, '\0', BUFSIZ);

	if ((n = read(fd, buf, BUFSIZ)) == -1) {
		(void)fprintf(stderr, "Unable to read data from fd %d: %s\n",
				fd, strerror(errno));
		exit(EXIT_FAILURE);
	}

	(void)printf("Read data: %s", buf);
}

/**
 * @brief read data from a file descriptor using openat
 * 
 * @param dfd 
 * @param f : buffer where data will be read
 */

void readFileUsingOpenat(const int dfd, const char *f) {
	int fd;

	(void)printf("Opening '%s' using openat(2)...\n", f);

    // Open file using openat
	if ((fd = openat(dfd, f, O_RDONLY)) == -1) {
		(void)fprintf(stderr, "Unable to open '%s': %s\n",
				f, strerror(errno));
		exit(EXIT_FAILURE);
	}

	// Mow actually read the data
	readData(fd);

}

/**
 * @brief read data from a file descriptor using open
 * 
 * @param f : file name 
 */

void readFileUsingOpen(const char *f) {
	int fd;

	(void)printf("Opening '%s'...\n", f);

	if ((fd = open(f, O_RDONLY)) == -1) {
		(void)fprintf(stderr, "Unable to open '%s': %s\n",
				f, strerror(errno));
		exit(EXIT_FAILURE);
	}

	readData(fd);
}

void reset() {
	systemLocal("rm -fr ../dir");
	systemLocal("mv ../dir2 ../dir");
}

void  makeFiles() {
}

void setup() {
	/* Trivial setup via system(3) because we're lazy. */
	systemLocal("mkdir -p ./t ./dir");
	systemLocal("echo file1 > ./dir/file1");
	systemLocal("echo file2 > ./dir/file2");

	if (chdir("./t") < 0) {
		(void)fprintf(stderr, "Unable to cd to './t': %s\n", strerror(errno));
		exit(EXIT_FAILURE);
		/* NOTREACHED */
	}
}

void simulateRaceCondition() {
	(void)printf("Simulating race condition by renaming '../dir'...\n");
	systemLocal("mv ../dir ../dir2");
	systemLocal("mkdir ../dir");
	systemLocal("echo notfile2 > ../dir/file2");
}

void cleanup() { 
	if (chdir("..") < 0) {
		(void)fprintf(stderr, "Unable to register exit handler: %s\n",
				strerror(errno));
	} else {
		systemLocal("rm -fr t dir dir2");
	}
}

int main() {

    /*atexit : register a function to be called at normal process termination*/
	if (atexit(cleanup) < 0) {
		(void)fprintf(stderr, "Unable to register exit handler: %s\n",
				strerror(errno));
		exit(EXIT_FAILURE);
	}

	setup();

	readFileUsingOpen("../dir/file1");
	simulateRaceCondition();
	readFileUsingOpen("../dir/file2");

	reset();

	(void)printf("\nLet's try again...\n\n");

	int dfd;
	if ((dfd = open("../dir", O_RDONLY | O_DIRECTORY)) == -1) {
		(void)fprintf(stderr, "Unable to open directory '../dir': %s\n",
				strerror(errno));
		exit(EXIT_FAILURE);
	}

	readFileUsingOpenat(dfd, "file1");
	simulateRaceCondition();
	readFileUsingOpenat(dfd, "file2");

	return EXIT_SUCCESS;
}