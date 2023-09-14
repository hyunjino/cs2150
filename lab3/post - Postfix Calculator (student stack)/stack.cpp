#include "stack.h"

stack::stack(){
  List numList;
}

int stack:: top(){
  ListItr last = numList.last();
  return last.retrieve();
}

void stack::pop(){
  numList.removeLast();
}

void stack::push(int x){
  numList.insertAtTail(x);
}

