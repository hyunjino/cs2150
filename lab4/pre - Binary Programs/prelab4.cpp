#include <iostream>
#include <climits>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) <<endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow(){
  unsigned int max_number = UINT_MAX;
  unsigned int result = max_number + 1;
  cout << max_number << " + 1 = "<< result<< endl;
}


void outputBinary(unsigned int dec){
  string number;
  while (dec !=0){
    int r = dec % 2;
    number += to_string(r);
    dec = floor(dec/2);
  }
  while (number.length() < 32){
    number += "0";
  }
  reverse(number.begin(), number.end());
  cout<<number<<endl;
}

int main(){
  unsigned int x;
  cin>>x;
  sizeOfTest();
  overflow();
  outputBinary(x);
}
  


