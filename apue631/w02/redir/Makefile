CC=gcc

CFLAGS= -O3   -Werror -Wextra  $(CDEFS)
CFILES= redir.c

SRCS= ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	redir

clean:
	-rm -f *.o *.d
	-rm -f redir

redir: redir.o
	$(CC) $(CFLAGS) -o $@ $@.o
.c.o:
	$(CC) $(CFLAGS) -c $<
