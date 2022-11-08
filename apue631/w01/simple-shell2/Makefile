CC=gcc

CFLAGS= -O3  -Wall -Werror -Wextra $(CDEFS)
CFILES= simple-shell2.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	simple-shell2

clean:
	-rm -f *.o *.d
	-rm -f simple-shell2

simple-shell2: simple-shell2.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
