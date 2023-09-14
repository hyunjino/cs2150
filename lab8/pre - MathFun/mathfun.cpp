#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product(long, long);
extern "C" long power(long, long);

int main(){
  long a, b;
  cout<<"Enter Interger 1: "<<endl;
  cin>>a;
  cout<<"Enter Integer 2: "<<endl;
  cin>>b;

  cout<<"Product: "<< product(a, b)<<endl;
  cout<<"Power: " <<power(a, b)<<endl;

  return 0;
}
