CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= fds.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	fds

clean:
	-rm -f *.o *.d
	-rm -f fds

fds: fds.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
