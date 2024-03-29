#pragma once
#include <vector>

class SelectionPolicy;
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy, int coaId);
    // Rule of 5 5
    ~Agent() ;//destructor
    Agent(const Agent& other);//copy constructor
    Agent& operator=(const Agent& other);//copy assignment operator
    Agent (Agent && other);//move constructor
    Agent& operator=(Agent&& other);//move assignment operator
    int getPartyId() const;
    int getId() const;
    int getCoalitionId() const;
    void step(Simulation &sim);
    SelectionPolicy *getSelectionPolicy() const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int coalitionId;
};
