#include "bankAccount.h"
#include <iostream>
#include <string>

using namespace std;

bankAccount::bankAccount(){}
bankAccount::bankAccount(double amount) : balance(amount){}
bankAccount::~bankAccount(){}

double bankAccount::withdraw(double amount){
  balance -= amount;
  return balance;
}
double bankAccount::deposit(double amount){
  balance += amount;
  return balance;
}
double bankAccount::getBalance(){
  return balance;
}

