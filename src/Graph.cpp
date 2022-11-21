#include <algorithm>
#include "../include/Graph.h"
#include "../include/Party.h"
#include <vector>

Graph::Graph(){}

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

vector<int> Graph::getNeighbors(int partyAgentId) const
{
    vector<int> neighbors;
    std::vector<int>::iterator it;


        for(int k=0;k<mEdges.size();k++)
        {
            if((mEdges[partyAgentId][k]==1)&&(k!=partyAgentId))
                neighbors.push_back(k);
        }

    return neighbors;
}

void Graph::stepParty(Simulation &s)
{
    for(int i=0; i<mVertices.size(); i++)
    {
        mVertices[i].step(s);
    }
}


