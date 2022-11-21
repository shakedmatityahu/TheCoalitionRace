#pragma once

#include <vector>
#include "Graph.h"
#include "Party.h"
#include "SelectionPolicy.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int coaId);

    int getPartyId() const;
    int getId() const;
    int getCoalitionId() const;
    void step(Simulation &);
    SelectionPolicy *getSelectionPolicy() const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int coalitionId;
};
