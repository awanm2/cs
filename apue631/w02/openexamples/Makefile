CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= openex.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	openex

clean:
	-rm -f *.o *.d
	-rm -f openex
	-rm newfile

openex: openex.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
