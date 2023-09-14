#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include <vector>
#include <list>

using namespace std;

class hashTable{

 public:
  hashTable();
  hashTable(int numWords);
  bool find(string word);
  void insert(int index, string word);
  unsigned int hashFunction(string key);
  int setCap(int numWords);
  int getCap();
  

 private:
  vector<list<string>> dictionary;
  int cap;
  vector<int> v;
};
  

#endif

