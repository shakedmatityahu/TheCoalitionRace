#pragma once
#include <vector>
#include "Party.h"
#include "Agent.h"

//using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    Graph();
    Graph& operator= (const Graph& other); // copy assignment operator
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    vector<int> getNeighbors(int partyAgentId) const;

private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
