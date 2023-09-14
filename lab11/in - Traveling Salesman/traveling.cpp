#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
 *@brief main method
 *
 *@return no return
 *@param argc number of arguments
 *@param argv command line parameters that take in information about the world we are about to build 
 *@todo write this doxygen comment
 *@author Hyunjin Kang
 */

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    string start = dests[0];
    dests.erase(dests.begin());

    float minDist = 5000000.0;
    vector<string> minPath;
    
    sort(dests.begin(), dests.end());
    do{
      float x = computeDistance(me, start, dests);
      if(x<minDist){
	minDist = x;
	minPath = dests;
      }
    } while (next_permutation(dests.begin(), dests.end()));

    
    cout<<"Minimum path has distance "<<minDist<<": ";
    printRoute(start, minPath);
    
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.

/**
 *@brief gets the total distance traveled for multiple cities
 *
 *@return float total distance
 *@param me middle earth 
 *@param start starting city
 *@param dests other cities to visit
 *@todo write the method body
 *@author Hyunjin Kang
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
  float sum = 0.0;
    // TODO: YOUR CODE HERE
  sum += me.getDistance(start, dests[0]);
  for(int i = 1; i<dests.size(); i++){
    sum += me.getDistance(dests[i-1], dests[i]);
  }

  sum += me.getDistance(dests[dests.size()-1], start);
  return sum;
  
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor

/**
 *@brief prints out the route for an itinerary of cities visited
 *
 *@return no return
 *@param start starting city
 *@param dests other cities to visit
 *@todo write the method body
 *@author Hyunjin Kang
 */
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
    cout<<start<<"->";
    for(int i = 0; i < dests.size(); i++){
      cout<<dests[i]<<"->";
    }
    cout<<start<<endl;
}
