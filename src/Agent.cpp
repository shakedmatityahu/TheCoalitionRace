#include <iostream>
#include "../include/Agent.h"
#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"
#include "../include/Party.h"
#include <algorithm>

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
    coalitionId = agentId;
}

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int coaId) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalitionId(coaId) {
}
Agent:: ~Agent() //destructor
{
    if(mSelectionPolicy)
        delete mSelectionPolicy;
}

Agent:: Agent(const Agent& other)//copy constructor
{
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy; //?
}

Agent& Agent:: operator=(const Agent& other)//copy assignment operator
{
    if(this!=&other) {
        if (mSelectionPolicy)
            delete mSelectionPolicy;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy=other.mSelectionPolicy; //?
    }
    return *this;
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

SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}




