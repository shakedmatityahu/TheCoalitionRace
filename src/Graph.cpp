#include <algorithm>
#include "../include/Graph.h"
#include "../include/Party.h"
#include <vector>

Graph::Graph() :mVertices(), mEdges()
{}

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

bool Graph::isNeighbor(int partyAgentId,int maybeNeighbor) const {
    if(mEdges[partyAgentId][maybeNeighbor]>0)
        return true;
    return false;
}

void Graph::stepParty(Simulation &s)
{
    int sizeVer=mVertices.size();
    for(int i=0; i<sizeVer; i++)
    {
        mVertices[i].step(s);
    }
}

void Graph::graphAddOffer(int coalitionId,int partyId)
{
    mVertices[partyId].partyAddOffer(coalitionId);
}









