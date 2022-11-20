#include <iostream>
#include "../include/Agent.h"
#include "Simulation.h"
#include "Offer.h"
#include <algorithm>
#include "vector"
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
        vector <Offer> offs =sim.getParty(x).getOffers();
        if(sim.getParty(x).getState()==2) //check if state is already join
            neighbors.erase(neighbors.begin()+k); //remove all the element that arent "waiting" or "collectingOffers"
        for(int i=0;i<offs.size();i++) //loop to check  a neighbor party already asked to join
        {
            if(offs[i].getOfferingAgent().getId()==mAgentId) //get the agent id with the vector of offers and compare to the agentId
                neighbors.erase(neighbors.begin()+k);
        }
    }
    //select

    // TODO: implement this method
}






