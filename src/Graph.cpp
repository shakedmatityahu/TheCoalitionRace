#include <algorithm>
#include "../include/Graph.h"

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

vector<int> Graph::getNeighbors(vector<int> agnetCoalition) const
{
    vector<int> neighbors;
    std::vector<int>::iterator it;

    for(int i=0;i<agnetCoalition.size();i++)
    {
        for(int k=0;k<mEdges.size();k++)
        {
            if((mEdges[agnetCoalition[i]][k]==1)&&(k!=i))
            it = std::find (neighbors.begin(), neighbors.end(), k); //checks if element k in the neighbors already
            if (it == neighbors.end())
                neighbors.push_back(k);
        }

    }
    return neighbors;

}

