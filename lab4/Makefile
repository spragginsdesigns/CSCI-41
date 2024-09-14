CXX=g++
# we're gonna pass the -g flag so that you can use GDB
CXXFLAGS=-g

BINARIES=segfault linkedListTests snake

all: $(BINARIES)

segfault.o: segfault.cpp
	$(CXX) $(CXXFLAGS) -c $^

segfault: segfault.o
	$(CXX) $(CXXFLAGS) $^ -o $@

linkedListTests.o: linkedListTests.cpp
	$(CXX) $(CXXFLAGS) -c $^

list.o: list.cpp
	$(CXX) $(CXXFLAGS) -c $^

point2D.o: point2D.cpp
	$(CXX) $(CXXFLAGS) -c $^

testing.o: testing.cpp
	$(CXX) $(CXXFLAGS) -c $^

snake.o: snake.cpp
	$(CXX) $(CXXFLAGS) -c $^

linkedListTests: linkedListTests.o list.o point2D.o testing.o
	$(CXX) $(CXXFLAGS) $^ -o $@

snake: snake.o point2D.o list.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
