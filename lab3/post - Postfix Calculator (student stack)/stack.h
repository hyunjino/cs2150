#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

#include "List.h"

using namespace std;

class stack {
 public:
  stack();

  int top();
  void pop();
  void push(int x);

 private:
  List numList;
};

#endif
