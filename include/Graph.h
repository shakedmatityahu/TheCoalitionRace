#pragma once
#include <vector>
#include "../include/Party.h"

class Party;

class Graph
{
public:
    Graph();
    Graph (vector<Party> vertices, vector<vector<int>> edges);
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
