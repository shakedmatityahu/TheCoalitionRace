#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"

int MandatesSelectionPolicy:: select (vector<int> neighbors, Simulation& sim, int partyId)
{
    int maxMandates=0;
    int maxParty=-1;
    int neighborsSize=neighbors.size();
    for(int i=0;i<neighborsSize;i++)
    {
        if(sim.getParty(neighbors[i]).getMandates()>maxMandates)
        {
            maxParty=neighbors[i];
            maxMandates=sim.getParty(neighbors[i]).getMandates();
        }
    }
    return maxParty;
}

MandatesSelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy(*this);
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

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy(*this);
}