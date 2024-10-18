CXX=g++
CXXFLAGS=-g

BINARIES=compress

all: $(BINARIES)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^

compress: compress.o huffmanCoding.o
	$(CXX) $(CXXFLAGS) $^ -o $@

runCompressTests: compress
	echo "Testing codes with shakespeare:"
	./compress shakespeare.txt codes
	echo ""
	echo "Testing codes with thequickbrownfox"
	./compress thequickbrownfox.txt codes
	echo ""
	echo "Testing compress with thequickbrownfox"
	./compress thequickbrownfox.txt compress

clean:
	rm -f $(BINARIES) *.o
