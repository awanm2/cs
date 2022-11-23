CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= hole.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	hole

clean:
	-rm -f *.o *.d
	-rm -f hole
	-rm -f file.hole

hole: hole.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
