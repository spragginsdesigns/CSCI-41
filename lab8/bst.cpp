#include "bst.h"

#include <list>
#include <queue>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

std::string to_string(const Pokemon& p) {
  return to_string(p.number) + ": " + p.name + " (" + p.type + ")";
}

// constructor
// Constructor: initializes an empty BST
BST::BST() : root(nullptr) {
    // Tree starts out empty, no need for additional initialization
}

// This is the insert function
// FІХМE: add a new BSTNode (created on the heap) into the current tree
// the key of the new node is p.number, and the data is p
void BST::catchPokemon(const Pokemon& p) {
    std::cout << "Catching Pokemon: " << to_string(p) << std::endl;
    BSTNode* newNode = new BSTNode{p.number, p, nullptr, nullptr, nullptr};

    if (root == nullptr) {
        std::cout << "Setting root node" << std::endl;
        root = newNode;
        return;
    }

    BSTNode* current = root;
    BSTNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (p.number < current->key) {
            current = current->left;
        } else if (p.number > current->key) {
            current = current->right;
        } else {
            // Pokemon already exists
            delete newNode;
            return;
        }
    }

    newNode->parent = parent;
    if (p.number < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
    std::cout << "Pokemon caught successfully" << std::endl;
}

// FІХМЕ: search for a node by key
// return a pointer if you find it
// otherwise return nullptr if the key doesn't exist in the tree
BST::BSTNode* BST::search(int key) const {
    std::cout << "Searching for key: " << key << std::endl;
    BSTNode* current = root;
    while (current != nullptr) {
        if (key == current->key) {
            return current;
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (current == nullptr) {
        std::cout << "Key not found" << std::endl;
    } else {
        std::cout << "Key found" << std::endl;
    }
    return current;
}

// call the search() helper function to do the heavy lifting
const Pokemon* BST::searchForPokemon(int key) const {
  BSTNode* n = search(key);
  if (n == nullptr)
    return nullptr;
  else
    return &n->data;
}

std::string BST::orderedListOfCaughtPokemon() const { return inOrder(root); }

std::string BST::inOrder(BSTNode* root) const {
  if (root == nullptr)
    return "";
  std::string result = inOrder(root->left);
  result += to_string(root->data) + '\n';
  result += inOrder(root->right);
  return result;
}

// FІХМЕ: return the predecessor of a given node
// return nullptr if there is no predecessor
BST::BSTNode* BST::predecessor(BSTNode* n) const {
    if (n == nullptr) return nullptr;

    if (n->left != nullptr) {
        BSTNode* current = n->left;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current;
    }

    BSTNode* parent = n->parent;
    while (parent != nullptr && n == parent->left) {
        n = parent;
        parent = parent->parent;
    }
    return parent;
}

// This is the "remove" function that the user gets to see/use
// FІХМЕ: use the search and remove functions to delete a key if it exists
void BST::releasePokemon(int key) {
    std::cout << "Releasing Pokemon with key: " << key << std::endl;
    BSTNode* node = search(key);
    if (node != nullptr) {
        std::cout << "Pokemon found, removing..." << std::endl;
        remove(node);
    } else {
        std::cout << "Pokemon not found" << std::endl;
    }
}

// FІХМЕ: Implement this method
// deletes a given node from the tree--remember to implement every case!
void BST::remove(BSTNode* n) {
    if (n == nullptr) {
        std::cout << "Attempt to remove null node" << std::endl;
        return;
    }
    std::cout << "Removing node with key: " << n->key << std::endl;

    // Case 1: Node is a leaf
    if (n->left == nullptr && n->right == nullptr) {
        if (n == root) {
            root = nullptr;
        } else {
            if (n == n->parent->left) {
                n->parent->left = nullptr;
            } else {
                n->parent->right = nullptr;
            }
        }
        delete n;
        std::cout << "Case 1: Removing leaf node" << std::endl;
    }
    // Case 2: Node has one child
    else if (n->left == nullptr || n->right == nullptr) {
        BSTNode* child = (n->left != nullptr) ? n->left : n->right;
        if (n == root) {
            root = child;
            child->parent = nullptr;
        } else {
            child->parent = n->parent;
            if (n == n->parent->left) {
                n->parent->left = child;
            } else {
                n->parent->right = child;
            }
        }
        delete n;
        std::cout << "Case 2: Removing node with one child" << std::endl;
    }
    // Case 3: Node has two children
    else {
        BSTNode* pred = predecessor(n);
        n->key = pred->key;
        n->data = pred->data;
        remove(pred);
        std::cout << "Case 3: Removing node with two children" << std::endl;
    }
    std::cout << "Node removed successfully" << std::endl;
}

// use this method to help you debug
// paste the output into http://www.webgraphviz.com/ to visualize your tree
// you can call this method in GDB with "call puts(b.toGraphviz())"
std::string BST::toGraphviz() const {
  if (root == nullptr) {
    return "The root is null--there is no tree to draw!";
  }

  string out =
      "Paste everything between the ===== lines into "
      "http://www.webgraphviz.com/\n"
      "====================================\n"
      "digraph BST {\n"
      "  node [fontname=\"Arial\" ];\n\n";

  vector<BSTNode*> nodes;
  queue<BSTNode*> q;
  q.push(root);
  while (!q.empty()) {
    BSTNode* front = q.front();
    q.pop();
    nodes.push_back(front);
    if (front->left != nullptr) q.push(front->left);
    if (front->right != nullptr) q.push(front->right);
  }

  list<string> nodeDefinitions;
  for (BSTNode* n : nodes) {
    stringstream ss;
    ss << n;
    string nodeName = "n" + ss.str();
    string nodeInfo = "";  // mark which is the root
    if (n == root) {
      nodeInfo = "\\n(root)";
    } else if (n->parent != nullptr) {
      nodeInfo = "\\n(parent is " + to_string(n->parent->key) + ")";
    }

    nodeDefinitions.push_back(nodeName + " [ label = \"" + to_string(n->key) +
                              ": " + n->data.name + nodeInfo + "\" ];");
  }

  vector<string> edges;
  for (BSTNode* n : nodes) {
    stringstream ss;
    ss << n;
    string nodeName = "n" + ss.str();

    string leftNode;
    if (n->left != nullptr) {
      ss.str("");
      ss << n->left;
      leftNode = "n" + ss.str();
    } else {
      // make a null node
      leftNode = "nullleft" + nodeName;
      // this node needs to appear before the right child
      // just put it at the front

      if (n->right != nullptr) {
        // we've already pushed the right node to the nodeDefinitions vector
        // for the correct order this left node needs to appear before it
        nodeDefinitions.push_front(leftNode + " [ shape = point ];");
      } else {
        nodeDefinitions.push_back(leftNode + " [ shape = point ];");
      }
    }

    string rightNode;
    if (n->right != nullptr) {
      ss.str("");
      ss << n->right;
      rightNode = "n" + ss.str();
    } else {
      // make a null node
      rightNode = "nullright" + nodeName;
      nodeDefinitions.push_back(rightNode + " [ shape = point ];");
    }

    // edges.push_back(nodeName + " -> { " + leftNode + " " + rightNode + "
    // };");
    edges.push_back(nodeName + " -> " + leftNode + " [ label = \"left\"] ;");
    edges.push_back(nodeName + " -> " + rightNode + " [ label = \"right\"] ;");
  }

  for (const string& s : nodeDefinitions) {
    out += "  " + s + "\n";
  }
  out += "  }\n"
      "====================================\n";

  return out;
}
