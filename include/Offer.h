#pragma once

class Party;
class Agent;

class Offer
{
public:
    Offer(Party &offParty, Agent &offAgent, Party &party);

    Party getOfferingParty() const;
    Agent getOfferingAgent() const;
    Party getPotentialParty() const;

private:
    Party &offeringParty;
    Agent &offeringAgent;
    Party &potentialParty;
};
