//Hyunjin Kang, hk4tnh, 8/27, xToN.cpp

#include <iostream>
using namespace std;


int xton(int x, int n){
  if(n == 0){
    return 1;
  } else{
    return x * xton(x, n-1);
  }
}


int main(){
  int x, n, y;
  cin>>x;
  cin>>n;
  y = xton(x, n);
  cout<<y<<endl;
  return 0;
}
  
