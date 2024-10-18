CXX=g++
CXXFLAGS=-g

BINARIES=expressionsTests

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

expressionsTests: expressionsTests.o expressions.o testing.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINARIES) *.o
