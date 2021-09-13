#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <map>

#include "edge.h"
#include "graph.h"

using namespace std;

class Djikstra {
public:
  Djikstra(Graph g, Vertex initialV, Vertex destination);

  map<Vertex,int> getPath() const;

  vector<Vertex> getPathVertices() const;
private:
  map<Vertex,int> path;
  vector<Vertex> path_vertices;
};
