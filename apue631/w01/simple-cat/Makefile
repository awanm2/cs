CC=gcc

CFLAGS= -O3  -Wall -Werror -Wextra $(CDEFS)
CFILES= simple-cat.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	simple-cat

clean:
	-rm -f *.o *.d
	-rm -f simple-cat

simple-cat: simple-cat.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
