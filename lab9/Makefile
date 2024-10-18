CXX=g++
CXXFLAGS=-g

BINARIES=testPriorityQueue

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

testPriorityQueue.o: testPriorityQueue.cpp priorityQueue.h
	$(CXX) $(CXXFLAGS) -c $<

testPriorityQueue: testPriorityQueue.o testing.o movieData.o
	$(CXX) $(CXXFLAGS) testPriorityQueue.o testing.o movieData.o -o $@

clean:
	rm -f $(BINARIES) *.o
