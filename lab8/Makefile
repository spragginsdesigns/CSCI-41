CXX=g++
CXXFLAGS=-g

BINARIES=bstTests

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

bstTests: bstTests.o bst.o testing.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
