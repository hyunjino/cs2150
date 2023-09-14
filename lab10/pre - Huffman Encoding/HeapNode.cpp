#include "HeapNode.h"

HeapNode::HeapNode(char val, int freq){
  value = val;
  frequency = freq;
  prefix = "";
  left = NULL;
  right = NULL;
}
