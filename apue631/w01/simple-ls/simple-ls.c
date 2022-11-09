/*
 * simple-ls.c
 * Extremely low-power ls clone.
 * ./simple-ls .
 */

#include <sys/types.h>

#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    /*
     * DIR is directory stream object
     * dp is pointer to DIR directory stream object.
     */
    DIR *dp;  
    struct dirent *dirp;

    if(argc != 2)
    {
        fprintf(stderr, "usage : %s dir_name\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    /*
     * opendir : opens a directory stream corresponding to the directory name.
                retuens a pointer to the directory stream.
     */
    if((dp = opendir(argv[1])) == NULL){
       fprintf(stderr, "Unable to open '%s' : %s\n", 
                        argv[1], strerror(errno)); 
       exit(EXIT_SUCCESS);                 
    }

    /* 
     * returns a pointer to a dirent structure representing the next 
     * diretory  entry in the directory stream pointed to by dirp.
    */
    while((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }



    (void)closedir(dp);
    return EXIT_SUCCESS;


}