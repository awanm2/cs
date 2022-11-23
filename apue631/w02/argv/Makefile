CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= argv.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	argv

clean:
	-rm -f *.o *.d
	-rm -f argv

argv: argv.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
