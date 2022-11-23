CC=gcc

CFLAGS= -O3  -Wall -Werror -Wextra -Wno-unused $(CDEFS)
CFILES= openmax.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	openmax

clean:
	-rm -f *.o *.d
	-rm -f openmax

openmax: openmax.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
