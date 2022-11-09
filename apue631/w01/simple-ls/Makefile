CC=gcc

CFLAGS= -O3  -Wall -Werror -Wextra $(CDEFS)
CFILES= simple-ls.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	simple-ls

clean:
	-rm -f *.o *.d
	-rm -f simple-ls

simple-ls: simple-ls.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
