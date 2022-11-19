#include "../include/Offer.h"

Offer::Offer(Party &offParty, Agent &offAgent, Party &party) : offeringParty(offParty), offeringAgent(offAgent), potentialParty(party)
{
    // You can change the implementation of the constructor, but not the signature!
}

Party getOfferingParty() const;
{
    return offeringParty;
}

Agent getOfferingAgent() const;
{
    return offeringAgent;
}

Party getPotentialParty() const;
{
    return potentialParty;
}