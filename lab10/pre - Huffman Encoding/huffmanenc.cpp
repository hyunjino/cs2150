#include <unordered_map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "heap.h"
#include "HeapNode.h"
using namespace std;

int main(int argc, char** argv) {
  double numSymbols = 0;
  double  numDistinctSymbols = 0;
  double  originalBits;
  double compressedRatio;
  double bitsPerChar;
    // verify the correct number of parameters
  unordered_map<char, int> freq_map;
  //unordered_man<char, string> prefix_map;
  heap h;
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    while (file.get(g)) {
      if ((int)g>=32 && int(g)<=126){
	numSymbols++;
	if(freq_map.find(g) !=freq_map.end()){
	  freq_map[g]++;
	}
	else{
	  numDistinctSymbols++;
	  freq_map.insert(pair<char, int>(g, 1));
	}
      }
    }
    
   
    unordered_map<char, int>::iterator iter;
    for(iter = freq_map.begin(); iter != freq_map.end(); ++iter){
      HeapNode* node = new HeapNode(iter->first, iter->second);
      h.insert(node);
    }
    
    //create huffman tree
    while(h.size() != 1){
      HeapNode* dummyNode = new HeapNode('~', 0);
      HeapNode* leftChild = h.deleteMin();
      HeapNode* rightChild = h.deleteMin();
      dummyNode->left = leftChild;
      dummyNode->right = rightChild;
      dummyNode->frequency = leftChild->frequency + rightChild->frequency;
      h.insert(dummyNode);
    }
    HeapNode* root = h.findMin();
    h.prefix(root, "");
    
   cout << "----------------------------------------" << endl;

   

   
   
   

   
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // Read the file again, and print to the screen
   
    while (file.get(g)) {
      if ((int)g>=32 && int(g)<=126){
        h.find(root, g);
      }
    }
    cout<<endl;

    cout << "----------------------------------------" << endl;
    originalBits = numSymbols*8;
    compressedRatio = originalBits/h.getCompressedBits();
    bitsPerChar = h.getCompressedBits()/numSymbols;
    cout<<"There are a total of "<< numSymbols <<" symbols that are encoded."<<endl;
    cout<<"There are "<< numDistinctSymbols <<" distinct symbols used."<<endl;
    cout<<"There were "<< originalBits <<" bits in the original file."<<endl;
    cout<<"There were "<<h.getCompressedBits() <<" bits in the compressed file."<<endl;
    cout<<"This gives a compression ratio of "<< compressedRatio <<endl;
    cout<<"The cost of the Huffman tree is "<< bitsPerChar <<" bits per character."<<endl;
    
    // close the file
    file.close();
   
    return 0;
}
