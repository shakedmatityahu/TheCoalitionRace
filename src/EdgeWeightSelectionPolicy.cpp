#pragma once
#include "SelectionPolicy.h"
int EdgeWeightSelectionPolicy:: select (vector<int> neighbors, Simulation& sim,int partyId)
{
    int maxEdge=0;
    int maxParty;
    for(int i=0;i<neighbors.size();i++)
    {
        if(sim.getGraph().getEdgeWeight(i,partyId)>maxEdge)
            maxParty=i;
    }
    return maxParty;
}