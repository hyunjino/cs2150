#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// we want to use parameters
/**
 *@brief 
 *
 *@param argc number of arguments
 *@param argv command line arguments that takes in the input file
 *@return no return
 *@todo create a topological sorting method
 *@author Hyunjin Kang
 *@date 12/1/2021
 */
int main(int argc, char** argv) {
  unordered_map<string, vector<string>> adj_list;
  unordered_map<string, int> indegrees;
  vector<string> classes;
  vector<string> top_sort;
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings
    while (!file.eof()){
      string s1, s2;
      file >> s1;
      file >> s2;
      if(s1=="0" && s2 == "0"){
	break;
      }
      else{
	if(find(classes.begin(), classes.end(), s1) == classes.end()){
	  classes.push_back(s1);
	}
	if(find(classes.begin(), classes.end(), s2) == classes.end()){
	  classes.push_back(s2);
	}


	for(int i = 0; i<classes.size(); i++){
	    indegrees.insert(pair<string, int>(classes[i], 0));
	  }

	if(indegrees.find(s2) != indegrees.end()){
	  indegrees[s2]++;
	}
	if(adj_list.find(s1) != adj_list.end()){
	  adj_list[s1].push_back(s2);
	}
	else{
	  adj_list.insert(pair<string, vector<string>>(s1, vector<string>()));
	  adj_list[s1].push_back(s2);
	}
      }
    }


    
    
    int size = indegrees.size();
    int count = 0;
    while(count != size){
      //cout<<"indegrees size: "<<indegrees.size()<<endl;
      unordered_map<string, vector<string>>:: iterator iter;
      vector<string>:: iterator iter2;
      unordered_map<string, int>::iterator iter3;
      for(iter3 = indegrees.begin(); iter3 != indegrees.end(); iter3++){
	if(iter3->second == 0){
	  top_sort.push_back(iter3->first);
	  //top_sort.push_back(",");
	  //cout<<"top: "<<iter3->first<<endl;
	  
	  for(iter = adj_list.begin(); iter != adj_list.end(); iter++){
	    if(iter->first == iter3->first){
	      for(iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++){
		//cout<<"vertex s it was pointint to: "<<*iter2<<endl;
		if(indegrees.find(*iter2) != indegrees.end()){
		  indegrees[*iter2]--;
		}
	      }
	    }
	  }
	  iter3->second--;
	  count++;
	}
      }
    }

    
    for(int i = 0; i != top_sort.size(); i++){
      cout<<top_sort[i]<<" ";
    }
    cout<<endl;
    













    


    /*
    unordered_map<string, vector<string>>:: iterator iter;
    vector<string>:: iterator iter2;
    for(iter = adj_list.begin(); iter != adj_list.end(); iter++){
      cout<<"first: "<<iter->first<<endl;
      for(iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++){
	cout<<" "<<*iter2<<endl;
      }
      cout<<endl;
    }
   
    unordered_map<string, int>::iterator iter3;
    for(iter3 = indegrees.begin(); iter3 != indegrees.end(); iter3++){
      cout<<iter3->first<<" "<<iter3->second<<endl;
    }
      
    */
    // output those strings
;

    // close the file before exiting
    
    file.close();
}

