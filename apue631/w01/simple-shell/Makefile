CC=gcc

CFLAGS= -O3  -Wall -Werror -Wextra $(CDEFS)
CFILES= simple-shell.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	simple-shell

clean:
	-rm -f *.o *.d
	-rm -f simple-shell

simple-shell: simple-shell.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
