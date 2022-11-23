Week 02 Notes 

# Week 02 - Segment 1 : File Descriptors
File descriptor or File handle is a small, non-negative int which identifies a file to the kernel.

stdin   0 connected to keyboard by default.
stdout  1 connected to terminal by default. 
stderr  2 connected to terminal by default.

File descriptors are finite resource. 

How many files , a process is allowed to open. 
It depends on OS being used. 

program - openmax.c

See how errno is set to zero. Set it to zero, otherwise it could be an error number 

The resource limitation is per processes basis.

Iterate over all the file descriptors and check which one is open.

man getdtablesize

# Week 02 - : open and close system calls



All file IO can be performed by open, close, read, write, lseek. These sys calls do all the work.



creat system call - to create a new file - creat returns a file descriptor in write only mode.
creat call is obsoleted by open system call. 

openat call is supported by some linux systems. 





# Segment - 03 



lseek : you can seek to a ngative, offset . Think rewinding a tape.
| call      |  Args     |Description |
| ----------- | -----------| ----------- |
| [open](https://man7.org/linux/man-pages/man2/open.2.html)      | const char *pathname, int flags, mode_t mode)| opens a specified file       |
| openat| -args- | Supported by some linux envs|   
|lseek|fd, offset, whence| lseek does |




# TODO : 
1. clean up notes here 
2. Class example rwex.c
3. Class example sync-cat.c
4. Take notes on File descriptor (int) vs File Stream (FILE *)