// Code is adapted from binary_heap.cpp written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <vector>
#include "heap.h"
#include "HeapNode.h"
using namespace std;

// default constructor

heap::heap() : h_size(0) {
    h.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<HeapNode*> vec) : h_size(vec.size()) {
    h = vec;
    h.push_back(h[0]);
    h[0] = 0;
    for (int i = h_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(HeapNode* node) {
    // a vector push_back will resize as necessary
    h.push_back(node);
    // move it up into the right position
    percolateUp(++h_size);
}

void heap::prefix(HeapNode* node, string pre) const{
  if(node !=NULL){
    prefix(node->left, pre + "0");
    prefix(node->right, pre + "1");
    if(node->left == NULL && node->right == NULL){
      node->prefix = pre;
      if(node->value == ' '){
	cout<<"space "<< node->prefix<<endl;
      }
      else{
	cout<<node->value<<" "<<node->prefix<<endl;
      }
	
    }
  }
}

string total = "";

void heap::find(HeapNode* node, char target){
  if(node!=NULL){
    find(node->left, target);
    find(node->right, target);
    if(node->value == target){
      total += node->prefix;
      cout<<node->prefix;
    }
  }
  compressedBits = total.length();
}



void heap::percolateUp(int hole) {
  
    // get the value just inserted
    HeapNode* node = h[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (node->frequency < h[hole/2]->frequency); hole /= 2) {
        h[hole] = h[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    h[hole] = node;
}

HeapNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (h_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    HeapNode* ret = h[1];
    // move the last inserted position into the root
    h[1] = h[h_size--];
    // make sure the vector knows that there is one less element
    h.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    HeapNode* node = h[hole];
    // while there is a left child...
    while (hole*2 <= h_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= h_size) && (h[child+1]->frequency < h[child]->frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (node->frequency > h[child]->frequency) {
            h[hole] = h[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    h[hole] = node;
}

HeapNode* heap::findMin() {
    if (h_size == 0) {
        throw "findMin() called on empty heap";
    }
    return h[1];
}

unsigned int heap::size() {
    return h_size;
}

void heap::makeEmpty() {
    h_size = 0;
    h.resize(1);
}

bool heap::isEmpty() {
    return h_size == 0;
}

void heap::print() {
    cout << "(" << h[0] << ") ";
    for (int i = 1; i <= h_size; i++) {
        cout << h[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

double heap::getCompressedBits(){
  return compressedBits;
}
