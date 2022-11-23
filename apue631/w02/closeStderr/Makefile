CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= close-stderr.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	close-stderr

clean:
	-rm -f *.o *.d
	-rm -f close-stderr

close-stderr: close-stderr.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
