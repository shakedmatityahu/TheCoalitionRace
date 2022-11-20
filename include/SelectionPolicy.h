#pragma once
#include "Simulation.h"
#include "Party.h"
class SelectionPolicy {

public:
    virtual int select(vector<int> neighbors, Simulation& sim, int partyId)=0;

};

class MandatesSelectionPolicy: public SelectionPolicy{

    public: int select (vector<int> neighbors, Simulation& sim,int partyId)
    {
        int maxMandates=0;
        int maxParty;
        for(int i=0;i<neighbors.size();i++)
        {
            if(sim.getParty(i).getMandates()>maxMandates)
                maxParty=i;
        }
        return maxParty;
    }
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{

    public: int select (vector<int> neighbors, Simulation& sim,int partyId)
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


};