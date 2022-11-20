#include <algorithm>
#include "../include/Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges)
{
    // You can change the implementation of the constructor, but not the signature!
}
Graph::Graph(){}


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

//vector<Party> &Graph::getVertices() {
//    return mVertices;
//}
//
//vector<vector<int>> &Graph::getEdges() {
//    return mEdges;
//}
//
//void Graph::setVertices(Graph &other) {
//    mVertices=other.mVertices;
//}
//
//void Graph::setEdges(Graph &other) {
//    mEdges=other.mEdges;

//}
//copy assignment operator , this method is just for simulation operator=
Graph &Graph::operator=(const Graph &other) {
    mEdges=other.mEdges;
    mVertices=other.mVertices;
    return *this;


}


