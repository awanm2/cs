CC=gcc
CXX=g++

CPPFLAGS = -Wall -Werror -Wextra
CPPFILES= sets-examples.cpp

SRCS= ${CPPFILES}
OBJS= ${CPPFILES:.cpp=.o}

all:	sets-examples

clean:
	-rm -f *.o *.d
	-rm -f sets-examples

sets-examples: sets-examples.o
	$(CXX) $(CPPFLAGS) -o $@ $@.o
.cpp.o:
	$(CXX) $(CPPFLAGS) -c $<
