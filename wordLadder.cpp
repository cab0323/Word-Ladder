#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type

//Implement breadth-first search, refer to Lab 10

struct vertex {
    string word;
    vertex *next;
};

unordered_map<string, vertex> pred;
unordered_map<string, int> dis;
unordered_map<string, vertex> edgeList;

void addEdgeList(string key, vertex *v);

class graph {
    public: 
        unordered_map<string, vertex> mapOfVertex;
        int numberOfVertices;
        
        vertex *addVertex(string word){
            vertex *newVertex;
            newVertex->word = word;
            newVertex->next = nullptr;
            mapOfVertex.insert({word, *newVertex});
            return newVertex;
        }
        
        bool found(string key){
            if(mapOfVertex.find(key) != mapOfVertex.end()){
                return true;
            }
            return false;
        }
        
        void addEdge(string firstWord, string secondWord){
            vertex *vertexToAdd;

            //check if vertex for firstWord has already been created, if not then create it
            if(!found(firstWord)){
                vertexToAdd = addVertex(firstWord);
            }
            else {
                vertexToAdd = &mapOfVertex[firstWord];
            }
            //add the edge 
            addEdgeList(secondWord, vertexToAdd);



            if(!found(secondWord)){
                vertexToAdd = addVertex(secondWord);
            }
            else {
                vertexToAdd = &mapOfVertex[secondWord];
            }
            addEdgeList(firstWord, vertexToAdd);
            
            
        }
};

void addEdgeList(string key, vertex *v){
    //if the key already exist add vertex to the list 
    if(edgeList.find(key) != edgeList.end()){
        vertex *it = &edgeList[key];
        while (it->next != nullptr){
            it = it->next;
        }
        it->next = v;
    }
    //if the key is not already in map then add it 
    else {
        edgeList[key] = (*v);
    }
}

string indexBlank(string word, int index){
    string blank = word;
    blank[index] = '_';
    return blank;
}
/*
graph buildGraph(string file){
    
    //declare graph object
    graph graph;
    //open the file to read the words 
    ifstream inFile(file);
    
    //read the words and add them to the vector
    string currentWord;
    while(!inFile.eof()){
        inFile >> currentWord;
        V.push_back(currentWord);
    }
    
    //add words that differ by one 
    //declare the vector first 
    unordered_map<string, vector<string>> similarWords;
    
    for(unsigned int i = 0; i < V.size(); i++){
        for(unsigned int j = 0; j < V[i].length(); j++){
            string wordWithoutLetter = indexBlank(V[i], j);
            similarWords[wordWithoutLetter].push_back(V[i]);
        }
    }
    
    //create the edge for the adjacent words 
    for(auto it = similarWords.begin(); it != similarWords.end(); it++){
        for(unsigned int i = 0; i < it->second.size(); i++){
            for(unsigned int j = 0; j < it->second.size(); j++){
                if(it->second[i] != it->second[j]){
                    graph.addAdjacent(it->second[i], it->second[j]);
                }
            }
        }
    }
    
    return graph; 
}
*/
void wordLadder(string s, string t, int &steps, vector<string> &p)
{
  //call the funciton to create the graph 
 // graph builtGraph = buildGraph("wordlist05.txt");
 steps = 0;
 //graph b = buildGraph();
 graph b = graph();
 b.addVertex("pool");
 b.addVertex("cool");

} 
/*
string indexBlank(string word, int index){
  string blank = word;
  blank[index] = '_';
  return blank;
}
/*
graph buildGraph(string file){
    
    //declare graph object
    graph graph;
    //open the file to read the words 
    ifstream inFile(file);
    
    //read the words and add them to the vector
    string currentWord;
    while(!inFile.eof()){
        inFile >> currentWord;
        V.push_back(currentWord);
    }
    
    //add words that differ by one 
    //declare the vector first 
    unordered_map<string, vector<string>> similarWords;
    
    for(unsigned int i = 0; i < V.size(); i++){
        for(unsigned int j = 0; j < V[i].length(); j++){
            string wordWithoutLetter = indexBlank(V[i], j);
            similarWords[wordWithoutLetter].push_back(V[i]);
        }
    }
    
    //create the edge for the adjacent words 
    for(auto it = similarWords.begin(); it != similarWords.end(); it++){
        for(unsigned int i = 0; i < it->second.size(); i++){
            for(unsigned int j = 0; j < it->second.size(); j++){
                if(it->second[i] != it->second[j]){
                    graph.addAdjacent(it->second[i], it->second[j]);
                }
            }
        }
    }
    
    return graph; 
}*/

int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
      cout << "No path!\n";
  }
  else
  {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
  }
  return 0;
}
