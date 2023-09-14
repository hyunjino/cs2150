#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int);

int main(){
  int x, y, z;
  timer t;
  cout<<"Enter a number: ";
  cin>>x;
  cout<<"Enter iterations of subroutine: ";
  cin>>y;
  t.start();
  for(int i = 0; i<y+1; i++){
    z = threexplusone(x);
  }
  t.stop();
  cout<<"Steps: "<<z<<endl;

 
  return 0;
}
