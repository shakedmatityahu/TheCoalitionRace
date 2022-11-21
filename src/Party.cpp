#pragma once
#include "../include/Party.h"
#include "../include/Agent.h"
#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"
#include <vector>

class Simulation;

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), offers(), timer(0)
{
    // You can change the implementation of the constructor, but not the signature!
}
Party:: ~Party() //destructor
{
    if(mJoinPolicy)
        delete mJoinPolicy;
}
//copy constructor
Party:: Party(const Party& other):mId(other.mId),mName(other.mName),mMandates(other.mMandates),mState(other.mState),offers(other.offers),timer(other.timer)
{
    if(other.mJoinPolicy->whoAmI()=='M')
        mJoinPolicy=new MandatesJoinPolicy;
    else
        mJoinPolicy=new LastOfferJoinPolicy;
}

Party& Party:: operator=(const Party& other)//copy assignment operator
{
    if(this!=&other) {
        if (mJoinPolicy)
            delete mJoinPolicy;
        mId=other.mId;
        mName=other.mName;
        mMandates=other.mMandates;
        if(other.mJoinPolicy->whoAmI()=='M')
            mJoinPolicy=new MandatesJoinPolicy;
        else
            mJoinPolicy=new LastOfferJoinPolicy;
        mState=other.mState;
        offers=other.offers;
        timer=other.timer;

    }
    return *this;
}
//move constructor
Party::Party (Party& other):mId(other.mId),mName(other.mName),mMandates(other.mMandates),mState(other.mState),offers(other.offers),timer(other.timer)
{
    mJoinPolicy=other.mJoinPolicy;
    mState=other.mState;
    other.mJoinPolicy= nullptr;
}

Party& Party:: operator=(Party && other)//move assignment operator
{
    if(mJoinPolicy)
        delete mJoinPolicy;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy=other.mJoinPolicy;
    mState=other.mState;
    offers=other.offers;
    timer=other.timer;
    other.mJoinPolicy= nullptr;
    return *this;


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
            int coaIdToJoin = mJoinPolicy->join(offers, s.getPartiesByCoalitions(), s.getGraph());
            mState = Joined;
            // adding this party to the coalitions matrix
            s.addPartyToCoalition(coaIdToJoin,mId);
            // cloning agent
            Agent clonedAgn = Agent(s.getAgents().size(), mId, s.getAgents()[coaIdToJoin].getSelectionPolicy(), coaIdToJoin);
            // adding agent to the vector of agents
            s.addAgentToVector(clonedAgn);
        }
        else {
            timer++;
        }
    }
}



