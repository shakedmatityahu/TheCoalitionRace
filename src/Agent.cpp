#include <iostream>
#include "../include/Agent.h"
#include "Simulation.h"
#include <algorithm>
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{

    static int i=0; //self- check
    std::cout <<"agent id " << mAgentId << " Party id "<<mPartyId<<  " step " << ++i<<std::endl;

    vector<int> neighbors=sim.getGraph().getNeighbors(mPartyId); //returns vector with all his neighbors
    int k=1;
    for (int x:neighbors)
    {
        if(sim.getParty(x).getState()==2)
            neighbors.erase(neighbors.begin()+k); //reomove all the element that arent "waiting" or "collectingOffers"
    }

    // TODO: implement this method
}




