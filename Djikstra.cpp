  
#include "Djikstra.h"

using namespace std;


Djikstra::Djikstra(Graph g, Vertex initialV, Vertex destination) {
  path_vertices.clear();
  // Fill this vector^^^
  //As outlined in CS225 PSUEDOCODE
  //Additional thanks to psuedocode of https://www.cs.dartmouth.edu/~thc/cs10/lectures/0509/0509.html
  typedef pair<int,Vertex> standard; 
  std::priority_queue<standard,vector<standard>,greater<standard> >  PQ; //the priority queue


 
  map<Vertex,int> distFSrc; //distance from source, or initial value
  //Vdistance.push_back(make_pair(initialV,0)); //initialize tentative distance value
   
  //PART 1
  map<Vertex, Vertex> previous; // initialize a map that maps current node -> its previous node




  
  auto verticies = g.getVertices();
  
  for (unsigned i = 0; i < verticies.size(); i++) {
    //pair<int, Vertex> otherV = make_pair(INT_MAX, verticies[i]);
    //All other verticies to infinity
    distFSrc[verticies[i]] = INT_MAX;
    previous[verticies[i]] = "";
    //Q.push(otherV);
  }
 
  distFSrc[initialV] = 0; 
  pair<int,Vertex> initial = make_pair(0,initialV);
  PQ.push(initial);// ensure base distance is set to 0;


  previous.insert(make_pair(initialV,"")); 

  //PART 2



  while(!PQ.empty()) {
    Vertex minNode = PQ.top().second;
    PQ.pop();
    //previous.insert(make_pair(minNode));
   // Vertex currentNode = minNode.second;

    //distFSrc[currentNode] = minNode.first; //update distance

    vector<Vertex> adj = g.getAdjacent(minNode);
    for (auto it = adj.begin(); it != adj.end(); it++) {
      Vertex v = *it; 
      double weight = g.getEdgeWeight(minNode,v); 
      if(weight + distFSrc[minNode] < distFSrc[v]) {
        distFSrc[v] = weight + distFSrc[minNode];
        //PQ.push(make_pair(distFSrc[v],v)); 
        previous[v] = minNode; 
      }
      
    }


    /*
    if(g.vertexExists(currentNode.first)) {
      vector<Vertex> neighbors = g.getAdjacent(currentNode.first);
      vector<pair<Vertex,int>> neighbors2;
      for(Vertex neighborPre: neighbors) {
        pair<Vertex, int> neighborReal = make_pair(neighborPre,INT_MAX);
        neighbors2.push_back(neighborReal); //cant use getAdjacent function on pairs, so make new vector
      }
      //vector<pair<Vertex,int>> neighbors2;
      for(pair<Vertex,int> neighbor : neighbors2) {
        //pair<Vertex, int> neighborReal = make_pair(neighbor,INT_MAX);
        if(visited.find(currentNode) != visited.end() && visited[currentNode] == false) {
          if((currentNode.second - neighbor.second) + currentNode.second < neighbor.second) {
            neighbor.second = (currentNode.second - neighbor.second) + currentNode.second;
            visited.insert(make_pair(currentNode,true));
            PQ.push(make_pair(neighbor.first,neighbor.second));
          }
        }
      }
    }
    */
    //distFSrc.push_back(currentNode);
  }
  //cout<<distFSrc;
  path = distFSrc;
  
  for(auto it: previous) {
    path_vertices.push_back(it.first);
  }
} 

map<Vertex,int> Djikstra::getPath() const {
  return path;
}

vector<Vertex> Djikstra::getPathVertices() const {
  return path_vertices;
}
//@TODO: FINISH TESTS, RUN THROUGH MAIN, WRITE README
//@TODO: FINISH TESTS, RUN THROUGH MAIN, WRITE README
