#include "../include/Party.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : timer(0), mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting)
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
int Party:: getTimer() const
{
    return timer;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
}



