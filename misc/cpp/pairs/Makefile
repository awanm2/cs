CC=gcc
CXX=g++

CPPFLAGS = -Wall -Werror -Wextra
CPPFILES= pairs-examples.cpp

SRCS= ${CPPFILES}
OBJS= ${CPPFILES:.cpp=.o}

all:	pairs-examples

clean:
	-rm -f *.o *.d
	-rm -f pairs-examples

pairs-examples: pairs-examples.o
	$(CXX) $(CPPFLAGS) -o $@ $@.o
.cpp.o:
	$(CXX) $(CPPFLAGS) -c $<
