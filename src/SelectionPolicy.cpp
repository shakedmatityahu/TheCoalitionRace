#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"

int MandatesSelectionPolicy:: select (vector<int> neighbors, Simulation& sim, int partyId)
{
    int maxMandates=0;
    int maxParty;
    int neighborsSize=neighbors.size();
    for(int i=0;i<neighborsSize;i++)
    {
        if(sim.getParty(i).getMandates()>maxMandates)
            maxParty=i;
    }
    return maxParty;
}

char  MandatesSelectionPolicy:: whoAmI()
{
    return 'M';
}

int EdgeWeightSelectionPolicy:: select (vector<int> neighbors, Simulation& sim,int partyId)
{
    int maxEdge=0;
    int maxParty=-1;
    int neighborsSize=neighbors.size();
    for(int i=0;i<neighborsSize;i++)
    {
        if(sim.getGraph().getEdgeWeight(neighbors[i],partyId)>maxEdge)
        {
            maxEdge=sim.getGraph().getEdgeWeight(neighbors[i],partyId);
            maxParty=neighbors[i];
        }
    }
    return maxParty;
}

char EdgeWeightSelectionPolicy:: whoAmI()
{
    return 'E';
}