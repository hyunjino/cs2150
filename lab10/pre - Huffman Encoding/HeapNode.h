#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <string>
using namespace std;

class HeapNode{
 public:
  HeapNode(char val, int freq);
  char value;
  int frequency;
  string prefix;
  HeapNode* left;
  HeapNode* right;
};

#endif
