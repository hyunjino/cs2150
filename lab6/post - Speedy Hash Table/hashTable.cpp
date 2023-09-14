#include "hashTable.h"
#include <math.h>

hashTable::hashTable(){
  cap = 13;
  dictionary = vector<list<string>>(cap);
}

hashTable::hashTable(int numWords){
  cap = setCap(numWords);
  dictionary = vector<list<string>>(cap);
  int y = 1;
  v.push_back(y);
  for(int j=22; j > 0; j--){
    int z = v.back() * 37;
    v.push_back(z);
  }
}

unsigned int hashTable::hashFunction(string key){
  unsigned int x = 0;
  for (int i=0; i < key.size(); i++){
    x += key[i] * (v[i]);
  }
  return x % cap;
}

void hashTable::insert(int index, string word){
  dictionary.at(index).push_front(word);
}

 bool hashTable::find(string word){
   bool find = false;
   int index = hashFunction(word);
   list<string>::iterator f;
   for(f = dictionary[index].begin(); f != dictionary[index].end(); ++f){
     if(*f == word){
       find = true;
     }
   }
   return find;
 }


 bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

  
int hashTable::setCap(int numWords){
  int c = 33259;
  while(numWords/c >= 0.75){
    c = getNextPrime(c);
  }
  return c;
}

int hashTable::getCap(){
  return cap;
}
  
