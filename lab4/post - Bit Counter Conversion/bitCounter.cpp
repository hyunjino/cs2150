#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int counter = 0;
int x;

void bitCounter(int n){
  if (n % 2 == 1){
    counter++;
  }
  if(n != 1){
    bitCounter(n/2);
  } else if (n == 1 || n == 0){
    cout<< x << " has " << counter<< " bit(s)" << endl;
  }
}

void baseConverter(string n, int startBase, int endBase){
  int dec = 0;
  int z;
  //convert to base 10
  int j = n.length() - 1;
  for(int i = 0; i < n.length(); i++){
    char c = n[i];
    if(isalpha(c)){
      z = (int)(c) - 55;
    }
    if(isdigit(c)){
      z = (int)(c) - 48;
    }
    int y = z * pow(startBase, j);
    dec += y;
    j--;
  }
  //cout<<"this is the number in base 10 "<<dec<<endl;

  //convert from base 10 to end base

  
  string number;
  int base = endBase;
  while (dec !=0){
    int r = dec % base;
    if (r<10){
      number += to_string(r);
    }
    else if (r>10){
      char c = r + 55;
      number += c;
    }
    dec = (dec/base);
  }
  reverse(number.begin(), number.end());
  cout<< n << " (base "<< startBase<< ") = " << number << " (base "<< endBase<< ")"<<endl;
  
  
  
}




int main(int argc, char **argv){
  x = atof(argv[1]);
  bitCounter(x);

  string a = argv[2];
  int b = atof(argv[3]);
  int c = atof(argv[4]);
  baseConverter(a, b, c);
 
  return 0;

}
  
