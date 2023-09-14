#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
    count = 0;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  insert(root, x);
  //cout<<root<<endl;
  
}

void AVLTree::insert(AVLNode*&i, const string& x){
  if(i == NULL){
    i = new AVLNode();
    i->value = x;
    count++;
    if(count == 1){
      root = i;
    }
    //cout<<"root is"<< root->value<<endl;
  

  }
  else if(x<i->value){
    insert(i->left, x);
  }
  else if (x>i->value){
    insert(i->right, x);
  }
  else;

  i->height = calcHeight(i);
   i->balFact = (height(i->right) - height(i->left));

  
  if(abs(i->balFact) == 2){
    balance(i);
  }
  //printTree();

}

 

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
    count--;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.

string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  //cout<<"about to find path"<<endl;
  //cout<<"root is: "<< root->value<<endl;
  
  if (find(root, x) == true){
    //cout<<"root is: " << root->value<<endl;
    return pathTo(root, x);
  }
  else {
    return " ";
  }

}

string AVLTree::pathTo(AVLNode* p, const string& x) const{
  if(x == p->value){
      return x;
  }
  if(x<p->value){
    return p->value + " " + pathTo(p->left, x);
  }
  else if(x>p->value){
    return p->value + " " + pathTo(p->right, x);
  }
  return " ";
}


// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return find(root, x);
}

bool AVLTree::find(AVLNode* b, const string& x) const{
  if(b == NULL){
    return false;
  }
  if(b->value == x){
    return true;
  }
  if(x<b->value){
    return find(b->left, x);
  }
  if(x>b->value){
    return find(b->right, x);
  }
  return false;
}
/*
AVLNode* AVLTree:: findParent(const string& x) const{
  return findParent(root, x);
}

AVLNode* AVLTree::findParent(AVLNode* f, const string& x) const{
  if(f->left->value == x || f->right->value == x){
    return f;
  }
  if(x<f->value){
    return findParent(f->left, x);
  }
  if(x>f->value){
    return findParent(f->right, x);
  }
  return NULL;
}
*/



// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return count;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  if(n->balFact == -2){
    if(n->left->balFact == 1){
      n->left = rotateLeft(n->left);
    }
      n = rotateRight(n);
  }

  else if(n->balFact == 2){
    
    if(n->right->balFact == -1){
      n->right = rotateRight(n->right);
    }
    n = rotateLeft(n);
  }
}
  /*
 if (n->balFact == -2){
   if(n->left->balFact == 1){
     //cout<<"rotating left"<<endl;
     rotateLeft(n->left);
    }
   //cout<<"rotating right"<<endl;
   rotateRight(n);
 }
 else if(n->balFact == 2){
   if(n->right->balFact == -1){
     //cout<<"rotating right" <<endl;
     rotateRight(n->right);
   }
   //cout<<"rotating left"<<endl;
   rotateLeft(n);
 }
  */


// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE

  AVLNode* x = n->right;
  n->right = x->left;

  x->left = n;

  n->height = height(n);
  x->height = height(n);

  return x;
  /*
  AVLNode* x = n;
  n = n->right;

  x->right = n->left;
  n->left = x;

  n->height = calcHeight(n);
  x->height = calcHeight(x);
  return n;
  
  
  
  AVLNode* input = n;
  if(input == root){
    root = input->right;
    AVLNode* y = root->left;

    root->left = input;
    input->right = y;
    
  }
  else { 
    AVLNode* x = input->right;
    AVLNode* y = x->left;
    AVLNode* parent = findParent(root, input->value);

    x->left = input;
    input->right = y;
    parent->right = x;   
  }
  */

}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
   // YOUR IMPLEMENTATION GOES HERE

  AVLNode* x = n->left;
  n->left = x->right;

  x->right = n;

  n->height = height(n);
  x->height = height(x);

  return x;
  /*

  AVLNode* x = n;
  n = n->left;

  x->left = n->right;
  n->right = x;

  n->height = calcHeight(n);
  x->height = calcHeight(x);
  
  return n;

  

  AVLNode* input = n;
  if(input == root){
    root = input->left;
    AVLNode* y = root->right;
    root->right = input;
    input->left = y;
    
  }
  else{
    AVLNode* x = input->left;
    AVLNode* y = x->right;
    AVLNode* parent = findParent(root, input->value);

    x->right = input;
    input->left = y;
    parent->left = x;

  }
  */
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  return calcHeight(node);
  /*
    if (node == NULL) {
        return -1;
    }
    return node->height;
  */
}

int AVLTree::calcHeight(AVLNode* t) const{
  if (t == NULL){
    return 0;
  }

  return max(calcHeight(t->left), calcHeight(t->right)) + 1;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
