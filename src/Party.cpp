#include "../include/Party.h"
#include "../include/Offer.h"
#include <vector>

Party::Party(int id, string name, int mandates, JoinPolicy *jp, vector<Offer> offs) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), offers(offs), timer(0)
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

vector<Offer> & Party::getOffers() const
{
    return offers;
}

void Party::step(Simulation &s)
{
    if (mState == CollectingOffers) {
        if (timer > 2) {
            // JOIN

        }
        else {
            timer++;
        }
    }
}



