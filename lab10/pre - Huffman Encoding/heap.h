// Code adapted from binary_heap.h written by Aaron Bloomfield, 2014
// code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "HeapNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<HeapNode*> vec);
    ~heap();

    void insert(HeapNode* node);
  void prefix(HeapNode* node, string pre) const;
  void find(HeapNode* node, char target);
    HeapNode* findMin();
    HeapNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
  double getCompressedBits();

private:
    vector<HeapNode*> h;
  double compressedBits;
    unsigned int h_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
