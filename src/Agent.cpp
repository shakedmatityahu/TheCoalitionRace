#include <iostream>
#include "../include/Agent.h"
#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"
#include <algorithm>

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),coalitionId(agentId)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int coaId) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalitionId(coaId) {
}
Agent:: ~Agent() //destructor
{
    if(mSelectionPolicy)
        delete mSelectionPolicy;
}
//copy constructor
Agent:: Agent(const Agent& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy->clone()),coalitionId(other.coalitionId)
{

}
//copy assignment operator
Agent& Agent:: operator=(const Agent& other)
{
    if(this!=&other) {
        if (mSelectionPolicy)
            delete mSelectionPolicy;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
    }
    return *this;
}
//move constructor
 Agent ::Agent (Agent && other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(),coalitionId(other.coalitionId)
{
    mSelectionPolicy=other.mSelectionPolicy;
    other.mSelectionPolicy= nullptr;
}

Agent& Agent:: operator=(Agent&& other)//move assignment operator
{
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mSelectionPolicy=other.mSelectionPolicy;
    other.mSelectionPolicy= nullptr;
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
    vector<int> partiesToOffer=vector<int>();
    int size=sim.getGraph().getNumVertices();
    for (int x=0;x<size;x++)
    {
        //first condition
        if(sim.getGraph().isNeighbor(mPartyId,x) && x != mPartyId)
        {
            //second condition
            if(sim.getParty(x).getState()!=2) {
                int sizeOffers = sim.getParty(x).getOffers().size();
                bool flag = true;
                for (int i = 0; i < sizeOffers; i++) //remove parties that my coalition already asked to join
                {
                    //third condition
                    if (sim.getParty(x).getOffers()[i] == getCoalitionId()) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    partiesToOffer.push_back(x);
            }
        }
    }
    //now the agents need to select which party he will ask to join
    int selectP=mSelectionPolicy->select(partiesToOffer,sim,mPartyId);
    if(selectP!=-1)
        sim.simAddOffer(coalitionId,selectP);
}

SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}




