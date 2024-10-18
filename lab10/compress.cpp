#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cctype>
#include "huffmanCoding.h"
using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " filename codes|compress" << endl;
    exit(1);
  }

  // open the file on which to build the Huffman Tree
  ifstream ifs(argv[1]);

  // we'll either print out the Huffman codes themselves, or a 
  // "binary" version of the compressed file
  string choice = argv[2];

  // build the tree
  HuffmanCoding hc(ifs);

  // get the codes by traversing the tree
  auto codes = hc.getCodes();

  if (choice == "codes") {
    for (const auto& pair : codes) {
      string c = string() + pair.first;
      if (c[0] == ' ') c = "' '";
      else if (c[0] == '\t') c = "'\\t'";
      else if (c[0] == '\n') c = "'\\n'";
      cout << c << ": " << pair.second << endl;
    }
  } else {
    cout << hc.compress(codes, ifs);
  }

  return 0;
}
