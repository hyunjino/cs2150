// Hyunjin Kang, hk4tnh, 9/13/2021

#include "postfixCalculator.h"
#include<cstdlib>

using namespace std;

int main(){
  string token;
  postfixCalculator postfix;
  while (cin >> token){
    if (token == "+"){
      postfix.addition();
    }
    else if (token == "-"){
      postfix.subtraction();
    }
    else if (token == "*"){
      postfix.multiplication();
    }
    else if (token == "/"){
      postfix.division();
    }
    else if (token == "~"){
      postfix.negation();
    }
    else {
      postfix.push_in(stoi(token));
    }
  }
  cout  << postfix.getTop() << endl;
  return 0;
}
