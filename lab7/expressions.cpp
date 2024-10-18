#include "expressions.h"
#include <queue> // where will you use this?
using namespace std;

// You must use recursion for every function except for breadthFirst

// FІХΜE: implement the evaluation function to perform the operations
//        represented by the expression tree
int evaluate(ExpressionNode *root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return root->data;

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    switch(root->op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        default: return 0;
    }
}

// FІХΜE: implement preorder traversal for expression trees, outputting a string.
//        For each node, your string should contain the data (leaf nodes) or the
//        op (interior nodes). You should put spaces between each node value.
std::string preOrder(ExpressionNode* root) {
    if (root == nullptr) return "";
    std::string result;
    if (root->left == nullptr && root->right == nullptr) {
        result = std::to_string(root->data);
    } else {
        result = root->op;
    }
    if (root->left) result += " " + preOrder(root->left);
    if (root->right) result += " " + preOrder(root->right);
    return result;
}

// FІХΜE: implement postorder traversal for expression trees, with the same output style as preOrder
std::string postOrder(ExpressionNode* root) {
    if (root == nullptr) return "";
    std::string result;
    if (root->left) result += postOrder(root->left) + " ";
    if (root->right) result += postOrder(root->right) + " ";
    if (root->left == nullptr && root->right == nullptr) {
        result += std::to_string(root->data);
    } else {
        result += root->op;
    }
    return result;
}

// FІХΜE: implement inorder traversal for expression trees, with the same output style as preOrder
std::string inOrder(ExpressionNode* root) {
    if (root == nullptr) return "";
    std::string result;
    if (root->left) result += inOrder(root->left) + " ";
    if (root->left == nullptr && root->right == nullptr) {
        result += std::to_string(root->data);
    } else {
        result += root->op;
    }
    if (root->right) result += " " + inOrder(root->right);
    return result;
}

// THIS IS THE ONLY NON-RECURSIVE FUNCTION
// FІХΜE: implement breadth-first order traversal for expression trees, with the same output style as preOrder
std::string breadthFirst(ExpressionNode* root) {
    if (root == nullptr) return "";
    std::queue<ExpressionNode*> q;
    q.push(root);
    std::string result;
    while (!q.empty()) {
        ExpressionNode* current = q.front();
        q.pop();
        if (current->left == nullptr && current->right == nullptr) {
            result += std::to_string(current->data) + " ";
        } else {
            result += current->op;
            result += " ";
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return result.substr(0, result.length() - 1);  // Remove trailing space
}

// FІХΜE: calculate the height of a tree by finding the maximum-length
//        path from the root
int height(ExpressionNode* root) {
    if (root == nullptr) return -1;
    return 1 + std::max(height(root->left), height(root->right));
}

// FІХΜE: mirror all the nodes in the tree (i.e., make it so that
//        every left child becomes the right child, and vice-versa)
void reverse(ExpressionNode* root) {
    if (root == nullptr) return;
    std::swap(root->left, root->right);
    reverse(root->left);
    reverse(root->right);
}
