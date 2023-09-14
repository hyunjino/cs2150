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
  makeEmpty();
  delete head;
  delete tail;
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
  if(head->next == tail && tail->previous == head && count == 0){
  return true;
  } else {
    return false;
  }
}

void List::makeEmpty(){
  ListItr delItr = ListItr(head->next);
  for(int i = 0; i < count; i++){
    delItr.moveForward();
    ListItr d = ListItr(delItr.current->previous);
    delItr.current->previous = head;
    head->next = delItr.current;
    delete d.current;
  }
  count = 0;
}

ListItr List::first(){
  ListItr first = ListItr(head->next);
  return first;
}

ListItr List::last(){
  ListItr last = ListItr(tail->previous);
  return last;
}

void List::insertAfter(int x, ListItr position){
  ListNode* newNode = new ListNode;
  newNode->value = x;
  newNode->previous = position.current;
  newNode->next = position.current->next;
  position.current->next = newNode;
  newNode->next->previous = newNode;
  count++;
}

void List::insertBefore(int x, ListItr position){
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->next = position.current;
  newNode->previous = position.current->previous;
  position.current->previous = newNode;
  newNode->previous->next = newNode;
  count++;
}

void List::insertAtTail(int x){
  ListNode* newNode = new ListNode();
  newNode->value = x;
  newNode->previous = tail->previous;
  newNode->previous->next = newNode;
  newNode->next = tail;
  tail->previous = newNode;
  count++;
}

ListItr List::find(int x){
  ListItr target = ListItr(head->next);
  while(target.current->value != x && !target.isPastEnd()){
    target = target.current->next;
  }
  return target;
}

void List::remove(int x){
  ListItr target = ListItr(find(x).current);
  if(!target.isPastEnd()){
    target.current->previous->next = target.current->next;
    target.current->next->previous = target.current->previous;
    delete target.current;
    count--;
  }
}

void List::removeLast(){
  ListItr target = ListItr(last().current);
  if(!target.isPastEnd()){
    target.current->previous->next = target.current->next;
    target.current->next->previous = target.current->previous;
    delete target.current;
    count--;
  }
}
  

int List::size() const{
  return count;
}

void printList(List& source, bool forward){
  if(forward==true){
    ListItr iter = ListItr(source.first());
    while(!iter.isPastEnd()){
      cout<< iter.retrieve() <<" ";
      iter.moveForward();
    }
  }
  else {
    ListItr iter = ListItr(source.last());
    while(!iter.isPastBeginning()){
      cout<< iter.retrieve() <<" ";
      iter.moveBackward();
    }
  }
    cout<< endl;
}
