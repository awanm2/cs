CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= lseek.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	lseek

clean:
	-rm -f *.o *.d
	-rm -f lseek

lseek: lseek.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
