CC=gcc

CFLAGS= -O3  -Wall -Werror -Wextra $(CDEFS)
CFILES= welcome.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	welcome

clean:
	-rm -f *.o *.d
	-rm -f welcome

welcome: welcome.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
