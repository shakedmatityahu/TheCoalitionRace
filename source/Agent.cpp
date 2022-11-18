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
    vector<int> neighbors=sim.getGraph().getNeighbors(sim.getCoalitioByAgent(mAgentId)); //returns vector with all his neighbors
    for (int x:neighbors)
    {
        //if(sim.getParty(x).getState()="Waiting" or sim.getParty(x).getState()="CollectingOffers")
            //do something....

    }

    // TODO: implement this method
}




