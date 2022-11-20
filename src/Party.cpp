#pragma once
#include "../include/Party.h"
#include "../include/Agent.h"
#include "../include/JoinPolicy.h"
#include <vector>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), offers(), timer(0)
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}


const string & Party::getName() const
{
    return mName;
}

vector<int> Party::getOffers() const
{
    return offers;
}

void Party::step(Simulation &s)
{
    if (mState == CollectingOffers) {
        if (timer > 2) {
            int coaIdToJoin = mJoinPolicy.join(offers, s.getPartiesByCoalitions(), s.getGraph());
            mState = Joined;
            // adding this party to the coalitions matrix
            s.getPartiesByCoalitions()[coaIdToJoin].push_back(mId);
            // cloning agent
            Agent clonedAgn = Agent(s.getAgents().size(), mId, s.getAgents()[coaIdToJoin].getSelectionPolicy(), coaIdToJoin);
            // adding agent to the vector of agents
            s.getAgents().push_back(clonedAgn);
        }
        else {
            timer++;
        }
    }
}



