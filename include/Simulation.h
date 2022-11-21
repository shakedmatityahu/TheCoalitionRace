#pragma once
#include <vector>
#include "../include/Graph.h"

using std::string;
using std::vector;
class Agent;
class Party;

class Simulation
{
public:

    Simulation(Graph g, vector<Agent> agents);

    void init();
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    vector<int> getCoalitionByAgent(int agentId) ;

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> PartiesByCoalition;

};
