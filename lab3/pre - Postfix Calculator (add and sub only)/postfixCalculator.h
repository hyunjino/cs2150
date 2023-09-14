// Hyunjin Kang, hk4tnh, 9/13/2021

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();
  ~postfixCalculator();

  void addition();
  void subtraction();

  void push_in(int x);
  int getTop();
  void pop_out();

 private:
  stack<int> numbers;
};

#endif
