#include <iostream>
#include "../include/Agent.h"
#include "Simulation.h"
#include <algorithm>
#include "Party.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalitionId(agentId)
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

int Agent::getCoalitionId() const
{
    return coalitionId;
}

void Agent::step(Simulation& sim)
{

    static int i=0; //self- check
    std::cout <<"agent id " << mAgentId << " Party id "<<mPartyId<<  " step " << ++i<<std::endl;

    vector<int> neighbors=sim.getGraph().getNeighbors(mPartyId); //returns vector with all his neighbors
    for (int x=0;x<neighbors.size();x++)
    {
        if(sim.getParty(x).getState()==2)
            neighbors.erase(neighbors.begin()+x+1); //remove all the element that arent "waiting" or "collectingOffers"
         for(int i=0;i<sim.getParty(x).getOffers().size();x++) //remove parties thay my coalition already asked to join
         {
             if(sim.getParty(x).getOffers()[i]==getCoalitionId())
             {
                 neighbors.erase(neighbors.begin()+i+1);
                 break;
             }
         }
    }
    //now the agents need to select which party he will ask to join
    int selectP=mSelectionPolicy->select(neighbors,sim,mPartyId);
    sim.getParty(selectP).getOffers().push_back(getCoalitionId());
}




