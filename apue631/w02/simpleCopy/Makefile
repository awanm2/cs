CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= simpleCopy.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	simpleCopy

clean:
	-rm -f *.o *.d
	-rm -f simpleCopy

simpleCopy: simpleCopy.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
