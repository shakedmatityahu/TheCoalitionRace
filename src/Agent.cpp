#include <iostream>
#include "../include/Agent.h"
#include "Simulation.h"
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
    for (int x:neighbors)
    {
        if(sim.getParty(x).getState()==0 or sim.getParty(x).getState()==1)
            //do something....

    }

    // TODO: implement this method
}




