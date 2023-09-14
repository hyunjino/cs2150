#include <iostream>
#include<fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "hashTable.h"
#include "timer.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
int numFound = 0;


// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
string output(int direction);


int main(int argc, char* argv[]){

  timer t;


  int rows, cols;
  int count = 0;
   bool result = readInGrid(argv[2], rows, cols);
    // if there is an error, report it
    if (!result) {
        cout << "Error reading in file!" << endl;
        return 1;
    }

    // Get a word (of length 10), starting at position (2,2) in the
    // array, in each of the 8 directions

    ifstream f(argv[1]);

    string w;
    while(getline(f, w)){
      if(w.size()>0){
	count++;
      }
    }


    f.close();
    
    hashTable myDictionary = hashTable(count);
    //cout<<myDictionary.getCap()<<endl;
    
    ifstream f2(argv[1]);

    string y;
    while(getline(f2, y)){
      if(y.size()>0){
	int x = myDictionary.hashFunction(y);
	myDictionary.insert(x, y);
      }
    }

    f2.close();

    //vector<string>::iterator it;
    t.start();
    
  for(int a = 0; a < rows; a++){
    for(int b = 0; b < cols; b++){
      for(int c = 0; c < 8; c++){
	for(int d = 3; d < 23; d++){
	  string word = getWordInGrid(a, b, c, d, rows, cols);
	  if(word.size()==d){
	    if(myDictionary.find(word)){
	      numFound++;
	    //it = find(dictionary.begin(), dictionary.end(), word);
	    //if(it != dictionary.end()){
	    
	      cout<<output(c)<<"("<<a<<", "<<b<<"): "<<word<<endl;
	      //break;
	    }
	      //}
	  }
	}
      }
    }
  }
  cout<<numFound<<" words found"<<endl;
  t.stop();
  //cout<<t.getTime()<<endl;
    
  return 0;
}




/** The main() function shows how to call both the readInGrid()
 * function as well as the getWordInGrid() function.
 */

/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columns as specified in the input file;
 *             as this is a reference, it is set by the function.
 */

string output(int d){
  string x;
  if(d == 0){
    x = "N";
  }
  if(d == 1){
    x = "NE";
  }
  if(d == 2){
    x = "E";
  }
  if(d == 3){
    x = "SE";
  }
  if(d == 4){
    x = "S";
  }
  if(d == 5){
    x = "SW";
  }
  if(d == 6){
    x = "W";
  }
  if(d == 7){
    x = "NW";
  }
  return x;
}
    


bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    return true;
}

/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static string variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A STATIC string containing the letters in the provided direction.
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}


