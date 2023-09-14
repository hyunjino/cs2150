// Hyunjin Kang, hk4tnh, 9/13/2021

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();
  ~postfixCalculator();

  void addition();
  void subtraction();
  void multiplication();
  void division();
  void negation();

  void push_in(int x);
  int getTop();
  void pop_out();

 private:
  stack numStack;
};

#endif
