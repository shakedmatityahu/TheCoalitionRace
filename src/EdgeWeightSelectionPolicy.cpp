#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"

int EdgeWeightSelectionPolicy:: select (vector<int> neighbors, Simulation& sim,int partyId)
{
    int maxEdge=0;
    int maxParty;
    int neighborsSize=neighbors.size();
    for(int i=0;i<neighborsSize;i++)
    {
        if(sim.getGraph().getEdgeWeight(i,partyId)>maxEdge)
            maxParty=i;
    }
    return maxParty;
}
char EdgeWeightSelectionPolicy:: whoAmI()
{
    return 'E';
}