#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
#include <iostream>

using namespace std;

List::List(){
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  count = 0;
}
List::List(const List& source){
  head = new ListNode();
  tail = new ListNode();
  head->next = tail;
  tail->previous = head;
  count = 0;

  ListItr iter(source.head->next);
  while (!iter.isPastEnd()){
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}
List::~List(){
}
List& List::operator=(const List& source){
  if (this==&source){
    return *this;
  } else {
    makeEmpty();

    ListItr iter(source.head->next);
    while (!iter.isPastEnd()){
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List::isEmpty() const{
  return true;
}

void List::makeEmpty(){}

ListItr List::first(){
  ListItr first = ListItr(head->next);
  return first;
}

ListItr List::last(){
  ListItr last = ListItr(tail->previous);
  return last;
}

void List::insertAfter(int x, ListItr position){}

void List::insertBefore(int x, ListItr position){}

void List::insertAtTail(int x){
  ListNode* newNode = new ListNode;
  newNode->value = x;
  newNode->previous = tail->previous;
  newNode->previous->next = newNode;
  newNode->next = tail;
  tail->previous = newNode;
  count++;
}

ListItr List::find(int x){
  ListItr target = ListItr(first());
  return target;
}

void List::remove(int x){}

int List::size() const{
  return count;
}

void printList(List& source, bool forward){
  ListItr iter = ListItr(source.first());
  while(!iter.isPastEnd()){
    cout<< iter.retrieve() <<" ";
    iter.moveForward();
  }
  cout<< endl;
}
