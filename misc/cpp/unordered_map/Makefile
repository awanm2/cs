CC=gcc
CXX=g++

CPPFLAGS = -Wall -Werror -Wextra
CPPFILES= unordered_map_examples.cpp

SRCS= ${CPPFILES}
OBJS= ${CPPFILES:.cpp=.o}

all:	unordered_map_examples

clean:
	-rm -f *.o *.d
	-rm -f unordered_map_examples

unordered_map_examples: unordered_map_examples.o
	$(CXX) $(CPPFLAGS) -o $@ $@.o
.cpp.o:
	$(CXX) $(CPPFLAGS) -c $<
