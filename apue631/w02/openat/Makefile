CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= openat.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	openat

clean:
	-rm -f *.o *.d
	-rm -f openat

openat: openat.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
