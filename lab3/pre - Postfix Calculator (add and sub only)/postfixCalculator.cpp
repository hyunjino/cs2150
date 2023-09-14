// Hyunjin Kang, hk4tnh, 9/13/2021

#include "postfixCalculator.h"

postfixCalculator::postfixCalculator(){
  stack<int> numbers;
}
postfixCalculator::~postfixCalculator(){}

void postfixCalculator::push_in(int x){
  numbers.push(x);
}

int postfixCalculator::getTop(){
  return numbers.top();
}

void postfixCalculator::pop_out(){
  numbers.pop();
}

void postfixCalculator::addition(){
  int x = numbers.top();
  numbers.pop();
  int y = numbers.top();
  numbers.pop();
  numbers.push(x+y);
}
void postfixCalculator::subtraction(){
  int x = numbers.top();
  numbers.pop();
  int y = numbers.top();
  numbers.pop();
  numbers.push(y-x);
}


