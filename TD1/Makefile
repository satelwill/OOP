CC=g++
CFLAGS=-Wall -O0 -g3 -I. -MMD -MP

PROG=testPoint testDroite testTriangle

all: $(PROG)

testPoint_SRCS := testPoint.cpp point.cpp 
testPoint_OBJS := $(testPoint_SRCS:.cpp=.o)
testPoint_DEPS := $(testPoint_SRCS:.cpp=.d)
testPoint: $(testPoint_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

testDroite_SRCS := testDroite.cpp point.cpp droite.cpp
testDroite_OBJS := $(testDroite_SRCS:.cpp=.o)
testDroite_DEPS := $(testDroite_SRCS:.cpp=.d)
testDroite: $(testDroite_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

testTriangle_SRCS := testTriangle.cpp point.cpp droite.cpp triangle.cpp
testTriangle_OBJS := $(testTriangle_SRCS:.cpp=.o)
testTriangle_DEPS := $(testTriangle_SRCS:.cpp=.d)
testTriangle: $(testTriangle_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf *.o *.d $(PROG)

-include $(testPoint_DEPS) $(testDroite_DEPS) $(testTriangle_DEPS)