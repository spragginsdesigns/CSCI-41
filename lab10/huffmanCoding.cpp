#include "huffmanCoding.h"
#include <queue> // for priority_queue
using namespace std;

// Pure virtual destructors are required to have an implementation
// in C++ for no good reason.
// The line below is equivalent to: HTreeNode::~HTreeNode() {}, 
// but it's more hip to do it this way.
HTreeNode::~HTreeNode() = default;

// Eventually, we're going to put HTreeNode*s inside a priority_queue,
// so we need to tell the pq how to compare those pointers.
// We want to prefer HTreeNodes with smaller frequencies, so 
// we'll use the following custom comparison class.
class CompareHTreeNodePointer {
public:
  bool operator()(HTreeNode* p1, HTreeNode* p2) {
    // FІХΜE: return true when p2's frequency is smaller than p1's
    // (it's backwards because std::priority_queue is backwards)
    return true;
  }
};

// FІХΜE: implement the constructor to build the tree

// FІХΜE: implement the destructor to remove the tree

// FІХΜE: implement the buildCharFreqTable method
// This is BuildCharacterFrequencyTable from your book
// We'll use an ifstream instead of a string
  // The table is a member variable, so it's already constructed
  // and there's no need to return it. You just have to add to it.

// FІХΜE: implement the buildTree method
// This is the HuffmanBuildTree from your book
  // we want to compare HTreeNode*s using frequency, with the smallest
  // frequencies having the largest priority

// FІХΜE: implement the getCodes method
// calls getCodesRecursive with the correct starting values

// FІХΜE: implement the getCodesRecursive method
// This is HuffmanGetCodes from your book

// FІХΜE: implement the compress method
// This is HuffmanCompress from your book
  // go back to the beginning of the file using:
   // ifs.clear();
   // ifs.seekg(0);