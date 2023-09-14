// Hyunjin Kang, hk4tnh, 9/13/2021

#include "postfixCalculator.h"

postfixCalculator::postfixCalculator(){
  stack numStack;
}
postfixCalculator::~postfixCalculator(){}

void postfixCalculator::push_in(int x){
  numStack.push(x);
}

int postfixCalculator::getTop(){
  return numStack.top();
}

void postfixCalculator::pop_out(){
  numStack.pop();
}

void postfixCalculator::addition(){
  int x = numStack.top();
  numStack.pop();
  int y  = numStack.top();
  numStack.pop();
  numStack.push(y+x);
}
void postfixCalculator::subtraction(){
  int x = numStack.top();
  numStack.pop();
  int y = numStack.top();
  numStack.pop();
  numStack.push(y-x);
}
void postfixCalculator::multiplication(){
  int x = numStack.top();
  numStack.pop();
  int y = numStack.top();
  numStack.pop();
  numStack.push(y*x);
}
void postfixCalculator::division(){
  int x = numStack.top();
  numStack.pop();
  int y = numStack.top();
  numStack.pop();
  numStack.push(y/x);
}
void postfixCalculator::negation(){
  int x = numStack.top();
  numStack.pop();
  numStack.push(x*-1);
}
