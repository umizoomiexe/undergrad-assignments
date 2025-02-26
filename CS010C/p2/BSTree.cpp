#include "BSTree.h"

#include <iostream>
#include <stdexcept>

using namespace std;

void BSTree::insert(const string& key) {
  //Edge case: tree is empty.
    if (root == nullptr) {
        root = new Node(key);
    
    } else {
        Node* current = root;
        while (true) {
            if (key == current->key) {
                //Edge case: if we find the key in the tree, just increment its count.
                current->count++;
                return;
            //Typical case: we find a hole where this key belongs.
            } else if (key < current->key) {
                if (current->left == nullptr) {
                    current->left = new Node(key);
                    return;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = new Node(key);
                    return;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

bool BSTree::search(const string& key) const {
    Node* current = root;
    while (current != nullptr) {
        if (key == current->key) {
            return true; // key Found!
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false; // key not found :/
}

string BSTree::largest() const {
    if (root == nullptr)
        return ""; // if tree is empty

    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->key;
}

string BSTree::smallest() const {
    if (root == nullptr)
        return ""; // tree is empty

    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->key;
}

int BSTree::height(const string& key) const {
    Node* current = root;
    int height = -1; // height of the root node is 0, so initialize to -1 for empty tree

    while (current != nullptr) {
        if (key == current->key) {
            return height_of(current); // call helper function to compute height
        } else if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
        height++;
    }
    return -1; // key not found
}

void BSTree::preOrder() const {
    preOrder(root);
    cout << endl; 
}

void BSTree::postOrder() const {
    postOrder(root);
    cout << endl; 
}

void BSTree::inOrder() const {
    inOrder(root);
    cout << endl; 
}

void BSTree::remove(const string& key) {
    remove(nullptr, root, key);
}

void BSTree::remove(Node* parent, Node* tree, const string& key) {
    if (tree == nullptr)
        return; // key not found
    if (key < tree->key) {
        remove(tree, tree->left, key);
    } else if (key > tree->key) {
        remove(tree, tree->right, key);
    } else { // found the node to remove
        if (tree->count > 1) {
            tree->count--; // decrease count if count > 1
        } else {
            if (tree->left == nullptr && tree->right == nullptr) {
                // Case 1: Leaf node (good) 
                if (parent == nullptr) {
                    delete root;
                    root = nullptr;
                } else if (parent->left == tree) {
                    delete tree;
                    parent->left = nullptr;
                } else {
                    delete tree;
                    parent->right = nullptr;
                }
            } else if (tree->left != nullptr) {
                // Case 2: Node with left child
                Node* largestLeft = tree->left;
                while (largestLeft->right != nullptr) {
                    largestLeft = largestLeft->right;
                }
                tree->key = largestLeft->key;
                tree->count = largestLeft->count; // Update count
                remove(tree, tree->left, largestLeft->key);
            } else {
                // Case 3: Node with right child or no child
                Node* smallestRight = tree->right;
                while (smallestRight->left != nullptr) {
                    smallestRight = smallestRight->left;
                }
                tree->key = smallestRight->key;
                tree->count = smallestRight->count; // Update count
                remove(tree, tree->right, smallestRight->key);
            }
        }
    }
}

int BSTree::height_of(Node* tree) const {
    if (tree == nullptr)
        return -1; // height of an empty tree is -1

    int leftHeight = height_of(tree->left);
    int rightHeight = height_of(tree->right);

    return 1 + max(leftHeight, rightHeight);
}

void BSTree::preOrder(Node* tree) const {
    if (tree != nullptr) {
        cout << tree->key << "(" << tree->count << "), ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void BSTree::inOrder(Node* tree) const {
    if (tree != nullptr) {
        inOrder(tree->left);
        cout << tree->key << "(" << tree->count << "), ";
        inOrder(tree->right);
    }
}

void BSTree::postOrder(Node* tree) const {
    if (tree != nullptr) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->key << "(" << tree->count << "), ";
    }
}

//END OF BSTREE.CPP
