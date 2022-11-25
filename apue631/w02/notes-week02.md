Week 02 Notes 

The I/O on linux systems can be performed by following five operations.
1. open
2. read
3. write
4. lseek
5. close

Unbuffered IO : read and write invoke a system call. 

File Descriptors 
The kernel refers to all open files by a file descriptor. The file descriptor is 
used to identify a file by the kernel.   
When openning a file or closing a file, the kerel returns a 
file descriptor to the process. 

|File descriptor number|File descriptor typedef| output/input|
|-----------------------|-----------------------|-------|
|0|STDIN_FILENO| the input is taken from the terminal|
|1|STDOUT_FILENO| the output is done to the terminal|
|2|STDERR_FILENO|the output is done to the terminal|

There is a limit on maximum number of open file descriptors. OPEN_MAX is defines 
this value for a particular OS.

# lseek 
lseek only records the current fole offset in the kernel. Neither actual IO is one nor the file is changed on the disk.


1. Say we create a small file. 
2. Now we write the file to the disk.
3. Now we do an lseek with a really large offset, so current file offset is beyond the previous offset and is also beyond the file size. 
4. So now we at the seeked position we write few bytes. 
5. It is up to OS on how to save this file on the disk. OS might create a sparse file with a hole in it or it might create a file with no holes in it.  

# read 
ssize_t read(int fd, void* buf, size_t nbuf);
Returns number of bytes readm , 0 if end of fike and -1 for an error.
Most file systems has read ahead to improve the read performance. 
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
|close|file descriptor|closes a file descriptor|
|lseek|fd, offset, whence| current file offset of an open file can be moved using lseek , pipe, FIFO  and sockets we cannot use lseek adn will retuen -1. |




# TODO : 
1. clean up notes here 
2. Class example rwex.c
3. Class example sync-cat.c
4. Take notes on File descriptor (int) vs File Stream (FILE *)

