#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H

#include <string>
#include <fstream>
#include <map>
#include <unordered_map>

// A Huffman Tree will be made up of special nodes: leaf nodes and internal nodes.
// We want to store them in one big tree using pointers, so let's use inheritance!
// We can use HTreeNode to mean both LeafNode and InternalNode.
// We'll differentiate between LeafNodes and InternalNodes by calling the
// isLeaf() member function. After that, we'll know whether our HTreeNode 
// has a character or a left/right pointer inside of it.
class HTreeNode {
public:
  // All nodes in a Huffman Tree will have a frequency
  // The base class's constructor will take care of setting the frequency
  HTreeNode(int frequency) : frequency(frequency) {}

  // we'll never need to override this getter, so it doesn't need to be virtual
  int getFrequency() const { return frequency; }
  
  // The default implementation of this function will be for non-leafs
  // So the LeafNode class must override it.
  virtual bool isLeaf() { return false; }

  // "pure" virtual destructor--there's no implementation, so we cannot
  // construct a plain HTreeNode. We are forced to only construct subclasses
  // of it.
  virtual ~HTreeNode() = 0;

  // Useless getters that will be overridden as necessary--
  // putting these here just ensures that these functions exist 
  // no matter which subclass we're using.
  virtual char getCharacter() const { return -1; }
  virtual HTreeNode* getLeft() const { return nullptr; }
  virtual HTreeNode* getRight() const { return nullptr; }

protected: // *not* private!
  int frequency;
};

class LeafNode : public HTreeNode {
public:
  // LeafNodes store a frequency and a character
  LeafNode(int frequency, char character) :
    HTreeNode(frequency), character(character) {}
  
  // FІХΜE: override the useless getter in the base class

  // FІХΜE: this node is a leaf, so override the isLeaf method

  // trivial destructor
  ~LeafNode() {}

private:
  char character;
};

class InternalNode : public HTreeNode {
public:
  // InternalNodes store a frequency and left/right pointers
  InternalNode(int frequency, HTreeNode* left, HTreeNode* right) :
    HTreeNode(frequency), left(left), right(right) {}
  
  // FІХΜE: override the useless getters from the base class
  
  // FІХΜE: implement the destructor
  // The destructor for InternalNodes is nontrivial, because all 
  // HTreeNodes will be made on the heap. You have to delete your children.

private:
  // the left and right children will be made on the heap, so we need
  // to delete them in the destructor
  HTreeNode* left;
  HTreeNode* right;
};

// This HuffmanCoding class packages up all the operations from the textbook.
class HuffmanCoding {
public:
  // constructor takes the file that we want to compress
  HuffmanCoding(std::ifstream& ifs);
  ~HuffmanCoding();
  std::map<char, std::string> getCodes();
  std::string compress(const std::map<char, std::string>& codes, std::ifstream& ifs);

private:
  void buildCharFreqTable(std::ifstream& ifs);
  void buildTree(std::ifstream& ifs);
  void getCodesRecursive(HTreeNode* node, std::string prefix, std::map<char, std::string>& output);
  
  // our character frequency table, taking characters to their frequencies
  std::unordered_map<char, int> charFreqTable;

  // The root of our tree of HTreeNodes
  HTreeNode* treeRoot;
};

#endif /* HUFFMANCODING_H */
