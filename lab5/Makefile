CXX=g++
CXXFLAGS=-g

BINARIES=testDeque testStack

all: $(BINARIES)

testDeque.o : testDeque.cpp Deque.h
	$(CXX) $(CXXFLAGS) -c $<

testStack.o : testStack.cpp Deque.h Stack.h
	$(CXX) $(CXXFLAGS) -c $<

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

testDeque: testDeque.o testing.o Deque.h
	$(CXX) $(CXXFLAGS) testDeque.o testing.o -o $@

testStack: testStack.o testing.o Deque.h Stack.h
	$(CXX) $(CXXFLAGS) testStack.o testing.o -o $@

clean:
	rm -f $(BINARIES) *.o
